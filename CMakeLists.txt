# -- CMakeSetup ----------------------------------------------------------------
cmake_minimum_required(VERSION 4.3.0)

# -- ProjectSetup --------------------------------------------------------------
project(watson)

set(BUILD_NAME "dev"
    CACHE STRING
    "The name of the build (i.e. 'Steam', 'dev-remi')")

find_package(Git QUIET)
if(GIT_FOUND)
   execute_process(COMMAND ${GIT_EXECUTABLE} log -1 --pretty=format:%h
                   OUTPUT_VARIABLE BUILD_VERSION
                   OUTPUT_STRIP_TRAILING_WHITESPACE
                   ERROR_QUIET)
else()
   set(BUILD_VERISON "invalid version")
endif()

if(("${CMAKE_BUILD_TYPE}" STREQUAL "Debug") OR
   ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebugInfo"))
  set(BUILD_INTERNAL ON)
else()
  set(BUILD_INTERNAL OFF)
endif()

# -- COptions ------------------------------------------------------------------
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# -- Libraries -----------------------------------------------------------------
set(VENDOR_PATH ${PROJECT_SOURCE_DIR}/vendor)

if(EXISTS ${VENDOR_PATH}/SDL/CMakeLists.txt)
   add_subdirectory(${VENDOR_PATH}/SDL EXCLUDE_FROM_ALL)
else()
   find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

# -- Modules -------------------------------------------------------------------
set(SOURCE_PATH ${PROJECT_SOURCE_DIR}/source)

set(SOURCES
  ${SOURCE_PATH}/w_time.h
  ${SOURCE_PATH}/w_display.h
  ${SOURCE_PATH}/w_main.h
  ${SOURCE_PATH}/watson.c)

add_executable(watson WIN32 ${SOURCES})

target_link_libraries(watson PRIVATE SDL3::SDL3)

# -- Warnings as Errors & SSE4.1 -----------------------------------------------
if(MSVC)
  target_compile_options(watson PRIVATE /W4 /arch:SSE4.1)
else()
  target_compile_options(watson PRIVATE -Wall -Werror -Wpedantic -msse4.1)
endif()

