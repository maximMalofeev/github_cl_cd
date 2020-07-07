cmake_minimum_required(VERSION 3.10)

project(github_ci_cd CXX)

if(CONAN_EXPORTED)
  include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
  conan_basic_setup(TARGETS)
else()
  if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
     message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
     file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.15/conan.cmake"
                   "${CMAKE_BINARY_DIR}/conan.cmake")
  endif()
  include("${CMAKE_BINARY_DIR}/conan.cmake")

  conan_add_remote(NAME conan-center INDEX 1 URL "https://conan.bintray.com")
  conan_add_remote(NAME bincrafters INDEX 2 URL "https://api.bintray.com/conan/bincrafters/public-conan")

  set(CONAN_BUILD_TYPE ${CMAKE_BUILD_TYPE})
  if(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo" OR ${CMAKE_BUILD_TYPE} STREQUAL "MinSizeRel")
    set(CONAN_BUILD_TYPE "Release")
  endif()

  conan_cmake_run(
    REQUIRES catch2/2.12.2
    SETTINGS build_type=${CONAN_BUILD_TYPE}
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
endif()

add_executable(${PROJECT_NAME} main.cpp)

enable_testing()
add_executable(simple_test test.cpp)
target_link_libraries(simple_test PUBLIC CONAN_PKG::catch2)
add_test(NAME simple_test COMMAND simple_test)