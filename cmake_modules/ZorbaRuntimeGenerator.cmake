# Copyright 2006-2008 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# check if zorbacmd exists and works
# the result of this check is used for deciding
# whether we can generate the runtime header and cpp files
SET(ZORBA_WORKS)

# we need the ZORBA_EXE_SCRIPT and the file API
# for the generation of the runtime and codegen
# the Zorba will fail running the test query if the file API dll
# is not found in the correct location
IF (EXISTS ${ZORBA_EXE_PATH})
  IF (WIN32 AND NOT ZORBA_REQUIRED_DLLS_PATH)
    SET(ZORBA_WORKS FALSE)
    MESSAGE(STATUS "[WARNING] Zorba Command Line Utility can only run if the ZORBA_REQUIRED_DLLS_PATH "
                   "variable points to a directory containing the necessary dynamic library "
                   "dependencies. See the Zorba building documentation for more information.")
  ELSE (WIN32 AND NOT ZORBA_REQUIRED_DLLS_PATH)
    EXECUTE_PROCESS(COMMAND ${ZORBA_EXE_SCRIPT}
                            "-q" "import module namespace file = 'http://www.zorba-xquery.com/modules/file'; file:exists( 'a non existant file' )"
                    RESULT_VARIABLE ZORBA_WORKS_RES
                    OUTPUT_VARIABLE ZORBA_WORKS_FOO)
    IF (NOT ZORBA_WORKS_RES EQUAL 0)
      SET(ZORBA_WORKS FALSE)
      MESSAGE(STATUS "[WARNING] Zorba Command Line Utility at \"${ZORBA_EXE_SCRIPT}\ "
                     "does not work properly and cannot generate the runtime source files. "
                     "This will cause the repository version of thiese files to be used.")
    ELSE (NOT ZORBA_WORKS_RES EQUAL 0)
      SET(ZORBA_WORKS TRUE)
    ENDIF (NOT ZORBA_WORKS_RES EQUAL 0)
  ENDIF (WIN32 AND NOT ZORBA_REQUIRED_DLLS_PATH)    
ELSE (EXISTS ${ZORBA_EXE_PATH})
  SET(ZORBA_WORKS FALSE)
  MESSAGE(STATUS "[WARNING] Zorba Command Line Utility was not found at \"${ZORBA_EXE_PATH}\".")
ENDIF (EXISTS ${ZORBA_EXE_PATH})

MACRO(CHECK_OUTPUT_EXISTS OUTPUT)
  IF (EXISTS "${OUTPUT}")
    MESSAGE(STATUS "Using the repository file for ${OUTPUT}. ")
  ELSE (EXISTS "${OUTPUT}")
    MESSAGE(FATAL_ERROR "Neither the Zorba Command Line Utility nor the files ${OUTPUT} are available. "
                        "Can't proceed building Zorba."
                        "(Try running \"svn update\" to restore them?)")
  ENDIF (EXISTS "${OUTPUT}")
ENDMACRO(CHECK_OUTPUT_EXISTS)

# macro used for generating the runtime's header and cpp files out of the xml specifications
MACRO(RUNTIME_GENERATOR CPP_QUERY HEADER_QUERY SPEC_FILE OUTPUT PARAM1 PARAM2)
  SET(CPP_OUTPUT "${CMAKE_SOURCE_DIR}/${OUTPUT}.cpp")
  SET(H_OUTPUT   "${CMAKE_SOURCE_DIR}/${OUTPUT}.h")

  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Added for generation: ${CPP_OUTPUT}")
     ADD_CUSTOM_COMMAND(OUTPUT "${CPP_OUTPUT}"
                        COMMAND ${ZORBA_EXE_SCRIPT} 
                           "-q" "\"${CPP_QUERY}\"" "-f" 
                           "-e" "\"${PARAM1}\"" "-e" "\"${PARAM2}\""
                           "-o" "\"${CPP_OUTPUT}\""
                           "--serialize-text"
                         DEPENDS ${CPP_QUERY} ${SPEC_FILE}
                           "${H_OUTPUT}"
                           "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq") # cpp always depends on .h

     MESSAGE(STATUS "Added for generation: ${H_OUTPUT}")
     ADD_CUSTOM_COMMAND(OUTPUT "${H_OUTPUT}"
                        COMMAND ${ZORBA_EXE_SCRIPT} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-e" "\"${PARAM1}\"" "-e" "\"${PARAM2}\""
                           "-o" "\"${H_OUTPUT}\""
                           "--serialize-text"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILE}
                           "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${CPP_OUTPUT}")
    CHECK_OUTPUT_EXISTS("${H_OUTPUT}")
  ENDIF (ZORBA_WORKS)
ENDMACRO(RUNTIME_GENERATOR)

MACRO(PRINTER_VISITOR_GENERATOR CPP_QUERY HEADER_QUERY SPEC_FILES OUTPUT PARAM1) 
  SET(CPP_OUTPUT "${CMAKE_SOURCE_DIR}/${OUTPUT}.cpp")
  SET(H_OUTPUT   "${CMAKE_SOURCE_DIR}/${OUTPUT}.h")

  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Added for generation: ${CPP_OUTPUT}")
     ADD_CUSTOM_COMMAND(OUTPUT "${CPP_OUTPUT}"
                        COMMAND ${ZORBA_EXE_SCRIPT} 
                           "-q" "\"${CPP_QUERY}\"" "-f" 
                           "-o" "\"${CPP_OUTPUT}\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                         DEPENDS ${CPP_QUERY} ${SPEC_FILES}
                           "${H_OUTPUT}" # cpp always depends on .h
                           "${CMAKE_SOURCE_DIR}/src/runtime/visitors/planiter_visitor.h"
                           "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq")

     MESSAGE(STATUS "Added for generation: ${H_OUTPUT}")
     ADD_CUSTOM_COMMAND(OUTPUT "${H_OUTPUT}"
                        COMMAND ${ZORBA_EXE_SCRIPT} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-o" "\"${H_OUTPUT}\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILES}
                           "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq"
                         )
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${CPP_OUTPUT}")
    CHECK_OUTPUT_EXISTS("${H_OUTPUT}")
  ENDIF (ZORBA_WORKS)
ENDMACRO(PRINTER_VISITOR_GENERATOR)

MACRO(PLANINTER_VISITOR_GENERATOR HEADER_QUERY SPEC_FILES OUTPUT PARAM1) 
  SET(H_OUTPUT   "${CMAKE_SOURCE_DIR}/${OUTPUT}.h")

  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Added for generation: ${H_OUTPUT}")
     ADD_CUSTOM_COMMAND(OUTPUT "${H_OUTPUT}"
                        COMMAND ${ZORBA_EXE_SCRIPT} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-o" "\"${H_OUTPUT}\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILES}
                           "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${H_OUTPUT}")
  ENDIF (ZORBA_WORKS)
ENDMACRO(PLANINTER_VISITOR_GENERATOR)

MACRO(CODEGEN_GENERATOR CPP_QUERY HEADER_QUERY SPEC_FILE  OUTPUT PARAM1 PARAM2) 
  SET(CPP_OUTPUT "${CMAKE_SOURCE_DIR}/${OUTPUT}.cpp")
  SET(H_OUTPUT   "${CMAKE_SOURCE_DIR}/${OUTPUT}.h")

  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Added for generation: ${CPP_OUTPUT}")
     ADD_CUSTOM_COMMAND(OUTPUT "${CPP_OUTPUT}"
                        COMMAND ${ZORBA_EXE_SCRIPT} 
                           "-q" "\"${CPP_QUERY}\"" "-f" 
                           "-o" "\"${CPP_OUTPUT}\""
                           "-e" "\"${PARAM1}\""
                           "-e" "\"${PARAM2}\""
                           "--serialize-text"
                         DEPENDS ${CPP_QUERY} ${SPEC_FILE} 
                           "${CMAKE_SOURCE_DIR}/src/runtime/spec/mappings.xml"
                           "${H_OUTPUT}" # cpp always depends on .h
                           "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq"
                       )

     MESSAGE(STATUS "Added for generation: ${H_OUTPUT}")
     ADD_CUSTOM_COMMAND(OUTPUT "${H_OUTPUT}"
                        COMMAND ${ZORBA_EXE_SCRIPT} 
                          "-q" "\"${HEADER_QUERY}\"" "-f" 
                          "-o" "\"${H_OUTPUT}\""
                          "-e" "\"${PARAM1}\""
                          "--serialize-text"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILE}
                           "${CMAKE_SOURCE_DIR}/src/runtime/spec/mappings.xml"
                           "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${CPP_OUTPUT}")
    CHECK_OUTPUT_EXISTS("${H_OUTPUT}")
  ENDIF (ZORBA_WORKS)
ENDMACRO(CODEGEN_GENERATOR)

MACRO(FUNCTION_ENUM_GENERATOR HEADER_QUERY SPEC_FILES OUTPUT PARAM1) 
  MESSAGE(STATUS "HELLO!: ${CMAKE_CURRENT_SOURCE_DIR}")
  SET(SRC_OUTPUT   "${CMAKE_SOURCE_DIR}/${OUTPUT}")

  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Added for generation: ${SRC_OUTPUT}")
     ADD_CUSTOM_COMMAND(OUTPUT "${SRC_OUTPUT}"
                        COMMAND ${ZORBA_EXE_SCRIPT} 
                          "-q" "\"${HEADER_QUERY}\"" "-f" 
                          "-o" "\"${SRC_OUTPUT}\""
                          "-e" "\"${PARAM1}\""
                          "--serialize-text"
                        DEPENDS ${HEADER_QUERY} ${SPEC_FILES}
                          "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${SRC_OUTPUT}")
  ENDIF (ZORBA_WORKS)
ENDMACRO(FUNCTION_ENUM_GENERATOR)
