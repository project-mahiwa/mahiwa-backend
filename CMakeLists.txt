cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

message("Buildするターゲット:${IDF_TARGET}")
set (COMPONENTS ${IDF_TARGET} main freertos esptool_py wamr)

message("wasm-micro-runtime はこのリポジトリのsubmoduleにある${CMAKE_SOURCE_DIR}/wamrを使います．")
list(APPEND EXTRA_COMPONENT_DIRS "${CMAKE_SOURCE_DIR}/wamr/build-scripts/esp-idf")

project(mahiwa-backend)
