include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/include/c++/7)

aux_source_directory(. SRC_LIST)

add_executable(bubble ${SRC_LIST})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
