CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(log_lite)

MESSAGE("CMAKE_SYSTEM_VERSION: ${CMAKE_SYSTEM_VERSION}")
MESSAGE("CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
MESSAGE("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
MESSAGE("CMAKE_SYSTEM: ${CMAKE_SYSTEM}")
MESSAGE("CMAKE_LIBRARY_ARCHITECTURE: ${CMAKE_LIBRARY_ARCHITECTURE}")

IF (NOT CPU_COUNT)
    SET(CPU_COUNT 4)
ENDIF()

IF (APPLE)
    SET(CMAKE_MACOSX_RPATH 1)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmacosx-version-min=10.9")
    #disable some warnings
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-register -Wno-unused-local-typedef -Wno-macro-redefined")
ENDIF()

IF (NOT WIN32)
    SET(CMAKE_CXX_FLAGS "-Wall -pthread -std=c++0x ${CMAKE_CXX_FLAGS}")
    SET(CMAKE_CXX_FLAGS_DEBUG "-D_DEBUG -g -fprofile-arcs -ftest-coverage")
    SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -fprofile-arcs -ftest-coverage")
ELSE()
    ADD_DEFINITIONS(-DWIN32_LEAN_AND_MEAN)
    SET(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDD /ZI /OB0 /OD /RTC1")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /ZI")
    SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /INCREMENTAL:NO /DEBUG /OPT:REF /OPT:ICF")
    SET(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /INCREMENTAL:NO /DEBUG /OPT:REF /OPT:ICF")
ENDIF()

include_directories(${PROJECT_SOURCE_DIR}/src)
set(CMAKE_VERBOSE_MAKEFILE ON)

ADD_SUBDIRECTORY(src)
