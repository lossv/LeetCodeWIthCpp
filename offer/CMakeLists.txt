aux_source_directory(${PROJECT_SOURCE_DIR}/offer SRC_LIST)

foreach(var ${SRC_LIST})
    string(REGEX REPLACE ".*/" "" var ${var})
    string(REGEX REPLACE ".cpp" "" tgt ${var})
    add_executable(offer.${tgt} ${var})
endforeach(var)