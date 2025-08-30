/* Prints the portable name for the current locale's charset. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "localcharset.h"

#include "monolithic_examples.h"

#if defined(BUILD_MONOLITHIC)
#define main   iconv_locale_charset_main
#endif

int main (void)
{
  setlocale(LC_ALL, "");
  printf("%s\n", locale_charset());
  return (0);
}
