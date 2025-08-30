
//implement your copy of `#include "monolithic_main_defs.h"`:
#include "monolithic_examples.h"

// define a name for the monolith
#define USAGE_NAME   "iconv_tools"

// load the monolithic definitions which you need for the dispatch table:
#include "monolithic_main_internal_defs.h"

// declare your own monolith dispatch table:
MONOLITHIC_CMD_TABLE_START()

{ "test_api", { .fa = iconv_test_api_main } },
{ "test_version", { .fa = iconv_test_version_main } },
{ "genaliases", { .fa = iconv_genaliases_main } },
{ "genaliases2", { .fa = iconv_genaliases2_main } },
{ "gentranslit", { .fa = iconv_gentranslit_main } },
{ "cli", { .fa = iconv_cli_main } },
{ "table_from_test", { .fa = iconv_table_from_test_main } },
{ "table_to_test", { .fa = iconv_table_to_test_main } },
{ "uniq_u_test", { .fa = iconv_uniq_u_test_main } },

{ "genflags", { .f = iconv_genflags_main } },
{ "locale_charset", { .f = iconv_locale_charset_main } },
{ "gengb18030_test", { .f = iconv_gengb18030_test_main } },
{ "genutf8_test", { .f = iconv_genutf8_test_main } },
{ "is_native_test", { .f = iconv_is_native_test_main } },
{ "test_bom_state", { .f = iconv_test_bom_state_main } },
{ "test_discard", { .f = iconv_test_discard_main } },
{ "shiftseq_test", { .f = iconv_shiftseq_test_main } },
{ "to_wchar_test", { .f = iconv_to_wchar_test_main } },

MONOLITHIC_CMD_TABLE_END();

// load the monolithic core dispatcher
#include "monolithic_main_tpl.h"
