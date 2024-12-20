/* Copyright (C) 2000, 2004-2005, 2012, 2016 Free Software Foundation, Inc.
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

/* Creates the UTF-8.TXT reference table. */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>

#include "binary-io.h"

#if defined(BUILD_MONOLITHIC)
#define main   iconv_genutf8_test_main
#endif

int main (void)
{
  int i1, i2, i3;

#if O_BINARY
  SET_BINARY(fileno(stdout));
#endif

  /* Range 0x0000..0x007f */
  for (i1 = 0; i1 < 0x80; i1++)
    printf("0x%02X\t0x%04X\n", i1, i1);
  /* Range 0x0080..0x07ff */
  for (i1 = 2; i1 < 32; i1++)
    for (i2 = 0; i2 < 64; i2++)
      printf("0x%02X%02X\t0x%04X\n", 0xc0+i1,0x80+i2, (i1<<6)+i2);
  /* Range 0x0800..0xffff, except 0xd800..0xdfff */
  for (i1 = 0; i1 < 16; i1++)
    for (i2 = (i1==0 ? 32 : 0); i2 < 64; i2++)
      for (i3 = 0; i3 < 64; i3++) {
        int u = (i1<<12)+(i2<<6)+i3;
        if (!(u >= 0xd800 && u < 0xe000))
          printf("0x%02X%02X%02X\t0x%04X\n", 0xe0+i1,0x80+i2,0x80+i3, u);
      }

  if (ferror(stdout) || fclose(stdout))
		return (1);
	return (0);
}
