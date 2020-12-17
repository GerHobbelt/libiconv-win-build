#include <iconv.h>

#include <iostream>

int main()
{
    char src[] = "\xf6";  // iso-8859-1 'ö'
    char dst[5];
    size_t srclen = 1;
    size_t dstlen = 2;

    // create transcoder from iso-8859-1 to utf8
    iconv_t conv = iconv_open("UTF-8", "ISO-8859-1");
    if (conv == (iconv_t)-1)
    {
        std::cerr << "Initialising iconv failed." << std::endl;
        return EXIT_FAILURE;
    }
    const char* pIn = src;
    char* pOut = (char*)dst;
    const auto ret = iconv(conv, &pIn, &srclen, &pOut, &dstlen);
    if (ret == (size_t)-1)
    {
        std::cout << "Conversion failed" << std::endl;
    }
    iconv_close(conv);

    std::cout << "Conversion done successful: Result is " << dst << std::endl;
    return EXIT_SUCCESS;
}
