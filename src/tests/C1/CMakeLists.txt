FILE(GLOB LOG_LITE_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/../../alg/C1/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../alg/C1/*.hpp
    )

ADD_EXECUTABLE(alg_c1_test
    main.cpp
    ${LOG_LITE_HEADERS}
    )

ADD_EXECUTABLE(merge_sort_test
    merge_sort_test.cpp
    ${LOG_LITE_HEADERS}
    )
