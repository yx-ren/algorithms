FILE(GLOB LOG_LITE_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/../../alg/C4/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../alg/C4/*.hpp
    )

ADD_EXECUTABLE(find_sub_max_arr_test
    find_sub_max_arr.cpp
    ${LOG_LITE_HEADERS}
    )
