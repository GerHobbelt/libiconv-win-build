/* Copyright (C) 2005, 2012 Free Software Foundation, Inc.
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

/* Creates the beyond-BMP part of the GB18030.TXT reference table. */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>

#include "binary-io.h"

#if defined(BUILD_MONOLITHIC)
#define main   iconv_gengb18030_test_main
#endif

int main (void)
{
  int i1, i2, i3, i4, uc;

#if O_BINARY
  SET_BINARY(fileno(stdout));
#endif

  uc = 0x10000;
  for (i1 = 0x90; i1 <= 0xe3; i1++)
    for (i2 = 0x30; i2 <= 0x39; i2++)
      for (i3 = 0x81; i3 <= 0xfe; i3++)
        for (i4 = 0x30; i4 <= 0x39; i4++) {
          printf("0x%02X%02X%02X%02X\t0x%X\n", i1, i2, i3, i4, uc);
          uc++;
          if (uc == 0x110000)
            goto done;
        }
 done:

  if (ferror(stdout) || fclose(stdout))
		return (1);
	return (0);
}
