# libiconv for Windows

libiconv for Windows (Microsoft Visual Studio Compiler) based on [GNU libiconv][1]

Solution file update to Visual Studio 2017 only.
Code is updated to libiconv 1.15

Additionally contains [Greek, Cyrillic and Armenian transliteration][4] rejected in base [GNU libiconv repository][5]
and `gentranslit` utility project file.

There are following pre-built configurations:

- Release Win32
- Release Static Win32
- Debug Win32
- Debug Static Win32
- Release x64
- Release Static x64
- Debug x64
- Debug Static x64

Code based on [GNU libiconv][1] and this article：[How to Build libiconv with Microsoft Visual Studio / PARK Youngho][2]

## Licensing

Depends on GNU libiconv [LGPL3.0][3] 

  [1]: https://www.gnu.org/software/libiconv
  [2]: http://www.codeproject.com/Articles/302012/How-to-Build-libiconv-with-Microsoft-Visual-Studio
  [3]: https://www.gnu.org/licenses/lgpl.html
  [4]: https://github.com/yuryleb/iconv-for-windows/commit/0b4f8bcd473260948201de7d042f67d79f6e11cb
  [5]: https://savannah.gnu.org/bugs/?56304
