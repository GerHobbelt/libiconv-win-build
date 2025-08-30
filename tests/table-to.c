/* Copyright (C) 2000-2002, 2004-2005 Free Software Foundation, Inc.
   This file is part of the GNU LIBICONV Library.

   The GNU LIBICONV Library is free software; you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either version 2.1
   of the License, or (at your option) any later version.

   The GNU LIBICONV Library is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU LIBICONV Library; see the file COPYING.LIB.
   If not, see <https://www.gnu.org/licenses/>.  */

/* Create a table from Unicode to CHARSET. */

#include "config.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>
#include <errno.h>

#include "binary-io.h"

#include "monolithic_examples.h"

#if defined(BUILD_MONOLITHIC)
#define main   iconv_table_to_test_main
#endif

int main (int argc, const char** argv)
{
  const char* charset;
  iconv_t cd;
  int bmp_only;

  if (argc != 2) {
    fprintf(stderr,"Usage: table-to charset\n");
		return (1);
  }
  charset = argv[1];

#if O_BINARY
  SET_BINARY(fileno(stdout));
#endif

  cd = iconv_open(charset,"UCS-4-INTERNAL");
  if (cd == (iconv_t)(-1)) {
    perror("iconv_open");
		return (1);
  }

  /* When testing UTF-8, stop at 0x10000, otherwise the output file gets too
     big. */
  bmp_only = (strcmp(charset,"UTF-8") == 0);

  {
    unsigned int i;
    unsigned char buf[10];
    for (i = 0; i < (bmp_only ? 0x10000u : 0x110000u); i++) {
      unsigned int in = i;
      const char* inbuf = (const char*) &in;
      size_t inbytesleft = sizeof(unsigned int);
      char* outbuf = (char*)buf;
      size_t outbytesleft = sizeof(buf);
      size_t result;
      size_t result2 = 0;
      iconv(cd,NULL,NULL,NULL,NULL);
      result = iconv(cd,(ICONV_CONST char**)&inbuf,&inbytesleft,&outbuf,&outbytesleft);
      if (result != (size_t)(-1))
        result2 = iconv(cd,NULL,NULL,&outbuf,&outbytesleft);
      if (result == (size_t)(-1) || result2 == (size_t)(-1)) {
        if (errno != EILSEQ) {
          int saved_errno = errno;
          fprintf(stderr,"0x%02X: iconv error: ",i);
          errno = saved_errno;
          perror("");
					return (1);
        }
      } else if (result == 0) /* ignore conversions with transliteration */ {
        if (inbytesleft == 0 && outbytesleft < sizeof(buf)) {
          unsigned int jmax = sizeof(buf) - outbytesleft;
          unsigned int j;
          printf("0x");
          for (j = 0; j < jmax; j++)
            printf("%02X",buf[j]);
          printf("\t0x%04X\n",i);
        } else if (inbytesleft == 0 && i >= 0xe0000 && i < 0xe0080) {
          /* Language tags may silently be dropped. */
        } else {
          fprintf(stderr,"0x%02X: inbytes = %ld, outbytes = %ld\n",i,(long)(sizeof(unsigned int)-inbytesleft),(long)(sizeof(buf)-outbytesleft));
					return (1);
        }
      }
    }
  }

  if (iconv_close(cd) < 0) {
    perror("iconv_close");
		return (1);
  }

  if (ferror(stdin) || ferror(stdout) || fclose(stdout)) {
    fprintf(stderr,"I/O error\n");
		return (1);
  }

	return (0);
}
