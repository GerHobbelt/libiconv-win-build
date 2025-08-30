
#pragma once

#if defined(BUILD_MONOLITHIC)

#ifdef __cplusplus
extern "C" {
#endif

int iconv_test_api_main(int argc, const char** argv);
int iconv_test_version_main(int argc, const char** argv);
int iconv_genaliases_main(int argc, const char** argv);
int iconv_genaliases2_main(int argc, const char** argv);
int iconv_genflags_main(void);
int iconv_gentranslit_main(int argc, const char** argv);
int iconv_locale_charset_main(void);
int iconv_cli_main(int argc, const char** argv);
int iconv_gengb18030_test_main(void);
int iconv_genutf8_test_main(void);
int iconv_is_native_test_main(void);
int iconv_table_from_test_main(int argc, const char** argv);
int iconv_table_to_test_main(int argc, const char** argv);
int iconv_test_bom_state_main(void);
int iconv_test_discard_main(void);
int iconv_shiftseq_test_main(void);
int iconv_to_wchar_test_main(void);
int iconv_uniq_u_test_main(int argc, const char** argv);

#ifdef __cplusplus
}
#endif

#endif
