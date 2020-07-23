FILE(GLOB LOG_LITE_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/../../tests/C7/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../alg/C7/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../alg/C7/*.hpp
    )

ADD_EXECUTABLE(quick_sort_test
    #quick_sort_test.cpp
    ${LOG_LITE_HEADERS}
    )
