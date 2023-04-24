aux_source_directory(${PROJECT_SOURCE_DIR}/algo SRC_LIST)

foreach(var ${SRC_LIST})
    string(REGEX REPLACE ".*/" "" var ${var})
    string(REGEX REPLACE ".cpp" "" tgt ${var})
    add_executable(algo.${tgt} ${var})
endforeach(var)