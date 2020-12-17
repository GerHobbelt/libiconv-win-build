cmake_minimum_required(VERSION 3.8)
project(LibIconvTest)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_set_find_paths()
conan_set_std()
conan_set_libcxx()

find_package(libiconv REQUIRED QUIET)

# Don't pulluate the RPATH with conan dependencies
# instead we will copy all shared deps in ../lib
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)

if (UNIX) # Assuming the usage of gcc or clang compilers
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
    if (APPLE)
        set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
    else()
        set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -Wl,--disable-new-dtags)
        set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
    endif()
endif()

add_executable(testApp main.cpp)
target_link_libraries(testApp PRIVATE libiconv::iconv)
install(TARGETS testApp RUNTIME DESTINATION "bin")
