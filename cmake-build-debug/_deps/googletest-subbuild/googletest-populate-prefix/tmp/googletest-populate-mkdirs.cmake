# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/baesihyeon/Desktop/satreci/cmake-build-debug/_deps/googletest-src"
  "/Users/baesihyeon/Desktop/satreci/cmake-build-debug/_deps/googletest-build"
  "/Users/baesihyeon/Desktop/satreci/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/baesihyeon/Desktop/satreci/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/baesihyeon/Desktop/satreci/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/baesihyeon/Desktop/satreci/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/baesihyeon/Desktop/satreci/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/baesihyeon/Desktop/satreci/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
