cmake_minimum_required(VERSION 2.8)

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
       IF(NOT ${child} STREQUAL ".git")
         IF(NOT ${child} STREQUAL "build")
           LIST(APPEND dirlist ${child})
	 ENDIF()
       ENDIF()
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()


project (ctci)



SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")


SUBDIRLIST(SUBDIRS /Users/jinyu/workspace/ctci)


FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
