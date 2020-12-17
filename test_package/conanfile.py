import os

from conans import ConanFile, CMake


class LibIconvTestConan(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'cmake'

    def imports(self):
        self.copy('*.dll',    src='bin', dst=os.path.join('install', 'bin'))
        self.copy('*.dylib*', src='lib', dst=os.path.join('install', 'lib'))
        self.copy('*.so*',    src='lib', dst=os.path.join('install', 'lib'))
        self.copy('*.py*',    src='lib', dst=os.path.join('install', 'lib'))

    def build(self):
        cmake = CMake(self)
        cmake_args = {'CMAKE_INSTALL_PREFIX':'install'}
        cmake.configure(defs=cmake_args)
        cmake.build(target='install')

    def test(self):
        self.run(os.path.join('install', 'bin', 'testApp'))
