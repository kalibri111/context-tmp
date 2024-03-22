# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/tmp/switch/cmake-build-debug-switch/_deps/googletest-src"
  "/tmp/switch/cmake-build-debug-switch/_deps/googletest-build"
  "/tmp/switch/cmake-build-debug-switch/_deps/googletest-subbuild/googletest-populate-prefix"
  "/tmp/switch/cmake-build-debug-switch/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/tmp/switch/cmake-build-debug-switch/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/tmp/switch/cmake-build-debug-switch/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/tmp/switch/cmake-build-debug-switch/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/tmp/switch/cmake-build-debug-switch/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/tmp/switch/cmake-build-debug-switch/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
