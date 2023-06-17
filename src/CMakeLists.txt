cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

aux_source_directory(./Json SRC_SUB)

aux_source_directory(. SRC_CUR)

add_executable(main ${SRC_SUB} ${SRC_CUR})

include_directories(../include)