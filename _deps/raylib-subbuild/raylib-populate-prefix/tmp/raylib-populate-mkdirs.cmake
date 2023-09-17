# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/aboude/projects/raylib/test/_deps/raylib-src"
  "/home/aboude/projects/raylib/test/_deps/raylib-build"
  "/home/aboude/projects/raylib/test/_deps/raylib-subbuild/raylib-populate-prefix"
  "/home/aboude/projects/raylib/test/_deps/raylib-subbuild/raylib-populate-prefix/tmp"
  "/home/aboude/projects/raylib/test/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp"
  "/home/aboude/projects/raylib/test/_deps/raylib-subbuild/raylib-populate-prefix/src"
  "/home/aboude/projects/raylib/test/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/aboude/projects/raylib/test/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/aboude/projects/raylib/test/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
