# check if zorbacmd exists and works
# the result of this check is used for deciding
# whether we can generate the runtime header and cpp files
SET(ZORBA_WORKS)

# we need the ZORBA_RUNTIME_GENERATOR and the file API
# for the generation of the runtime and codegen
# the Zorba will fail running the test query if the file API dll
# is not found in the correct location
IF (EXISTS ${ZORBA_RUNTIME_GENERATOR})
  EXECUTE_PROCESS(COMMAND ${ZORBA_RUNTIME_GENERATOR}
                          "-q" "import module namespace file = 'http://www.zorba-xquery.com/modules/file';
                                file:exists( 'a non existant file' )"
                  RESULT_VARIABLE ZORBA_WORKS_RES
                  OUTPUT_VARIABLE ZORBA_WORKS_FOO)
  IF (NOT ZORBA_WORKS_RES EQUAL 0)
    SET(ZORBA_WORKS FALSE)
    MESSAGE(STATUS "Zorba Command Line Utility at \"${ZORBA_RUNTIME_GENERATOR}\ "
                   "does not work properly and cannot generate the runtime source files. "
                   "This will cause the repository version of thiese files to be used.")
  ELSE (NOT ZORBA_WORKS_RES EQUAL 0)
    SET(ZORBA_WORKS TRUE)
  ENDIF (NOT ZORBA_WORKS_RES EQUAL 0)
ELSE (EXISTS ${ZORBA_RUNTIME_GENERATOR})
  SET(ZORBA_WORKS FALSE)
  MESSAGE(STATUS "Zorba Command Line Utility was not found at \"${ZORBA_RUNTIME_GENERATOR}\".")
ENDIF (EXISTS ${ZORBA_RUNTIME_GENERATOR})

MACRO(CHECK_OUTPUT_EXISTS OUTPUT)
  IF (EXISTS "${OUTPUT}")
    MESSAGE(STATUS "Using the repository file for ${OUTPUT}. ")
  ELSE (EXISTS "${OUTPUT}")
    MESSAGE(FATAL_ERROR "Neither the Zorba Command Line Utility nor the files ${OUTPUT} are available. "
                        "Can't proceed building Zorba.")
  ENDIF (EXISTS "${OUTPUT}")
ENDMACRO(CHECK_OUTPUT_EXISTS)

# macro used for generating the runtime's header and cpp files out of the xml specifications
MACRO(RUNTIME_GENERATOR CPP_QUERY HEADER_QUERY SPEC_FILE OUTPUT PARAM1 PARAM2 ZORBA_WORKS) 
  SET(CPP_OUTPUT_BINARY_DIR "${CMAKE_BINARY_DIR}/${OUTPUT}.cpp")
  SET(H_OUTPUT_BINARY_DIR   "${CMAKE_BINARY_DIR}/${OUTPUT}.h")
  SET(CPP_OUTPUT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/${OUTPUT}.cpp")
  SET(H_OUTPUT_SOURCE_DIR   "${CMAKE_SOURCE_DIR}/${OUTPUT}.h")

  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Generating ${CPP_OUTPUT_BINARY_DIR}")
     ADD_CUSTOM_COMMAND(OUTPUT "${CPP_OUTPUT_BINARY_DIR}"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${CPP_QUERY}\"" "-f" 
                           "-e" "\"${PARAM1}\"" "-e" "\"${PARAM2}\""
                           "-o" "\"${CPP_OUTPUT_BINARY_DIR}\""
                           "--serialize-text"
                        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                        "${CPP_OUTPUT_BINARY_DIR}"
                        "${CPP_OUTPUT_SOURCE_DIR}"
                         DEPENDS ${CPP_QUERY} ${SPEC_FILE}
                                 "${H_OUTPUT_BINARY_DIR}"
                                 "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq") # cpp always depends on .h

     MESSAGE(STATUS "Generating ${H_OUTPUT_BINARY_DIR}")
     ADD_CUSTOM_COMMAND(OUTPUT "${H_OUTPUT_BINARY_DIR}"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-e" "\"${PARAM1}\"" "-e" "\"${PARAM2}\""
                           "-o" "\"${H_OUTPUT_BINARY_DIR}\""
                           "--serialize-text"
                        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                        "${H_OUTPUT_BINARY_DIR}"
                        "${H_OUTPUT_SOURCE_DIR}"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILE}
                                 "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${CPP_OUTPUT_SOURCE_DIR}")
    CHECK_OUTPUT_EXISTS("${H_OUTPUT_SOURCE_DIR}")
  ENDIF (ZORBA_WORKS)
ENDMACRO(RUNTIME_GENERATOR)

MACRO(PRINTER_VISITOR_GENERATOR CPP_QUERY HEADER_QUERY SPEC_FILES OUTPUT PARAM1 ZORBA_WORKS) 
  SET(CPP_OUTPUT_BINARY_DIR "${CMAKE_BINARY_DIR}/${OUTPUT}.cpp")
  SET(H_OUTPUT_BINARY_DIR   "${CMAKE_BINARY_DIR}/${OUTPUT}.h")
  SET(CPP_OUTPUT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/${OUTPUT}.cpp")
  SET(H_OUTPUT_SOURCE_DIR   "${CMAKE_SOURCE_DIR}/${OUTPUT}.h")
  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Generating ${CPP_OUTPUT_BINARY_DIR}")
     ADD_CUSTOM_COMMAND(OUTPUT "${CPP_OUTPUT_BINARY_DIR}"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${CPP_QUERY}\"" "-f" 
                           "-o" "\"${CPP_OUTPUT_BINARY_DIR}\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                        "${CPP_OUTPUT_BINARY_DIR}"
                        "${CPP_OUTPUT_SOURCE_DIR}"
                         DEPENDS ${CPP_QUERY} ${SPEC_FILES}
                                 "${H_OUTPUT_BINARY_DIR}" # cpp always depends on .h
                                 "${CMAKE_BINARY_DIR}/src/runtime/visitors/planiter_visitor.h"
                                 "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq")

     MESSAGE(STATUS "Generating ${H_OUTPUT_BINARY_DIR}")
     ADD_CUSTOM_COMMAND(OUTPUT "${H_OUTPUT_BINARY_DIR}"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-o" "\"${H_OUTPUT_BINARY_DIR}\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                        "${H_OUTPUT_BINARY_DIR}"
                        "${H_OUTPUT_SOURCE_DIR}"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILES}
                                 "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq"
                         )
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${CPP_OUTPUT_SOURCE_DIR}")
    CHECK_OUTPUT_EXISTS("${H_OUTPUT_SOURCE_DIR}")
  ENDIF (ZORBA_WORKS)
ENDMACRO(PRINTER_VISITOR_GENERATOR)

MACRO(PLANINTER_VISITOR_GENERATOR HEADER_QUERY SPEC_FILES OUTPUT PARAM1 ZORBA_WORKS) 
  SET(H_OUTPUT_BINARY_DIR   "${CMAKE_BINARY_DIR}/${OUTPUT}.h")
  SET(H_OUTPUT_SOURCE_DIR   "${CMAKE_SOURCE_DIR}/${OUTPUT}.h")
  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Generating planvisitor ${H_OUTPUT_BINARY_DIR}")
     ADD_CUSTOM_COMMAND(OUTPUT "${H_OUTPUT_BINARY_DIR}"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-o" "\"${H_OUTPUT_BINARY_DIR}\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                        "${H_OUTPUT_BINARY_DIR}"
                        "${H_OUTPUT_SOURCE_DIR}"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILES}
                                 "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${H_OUTPUT_SOURCE_DIR}")
  ENDIF (ZORBA_WORKS)
ENDMACRO(PLANINTER_VISITOR_GENERATOR)

MACRO(CODEGEN_GENERATOR CPP_QUERY HEADER_QUERY SPEC_FILE  OUTPUT PARAM1 PARAM2 ZORBA_WORKS) 
  SET(CPP_OUTPUT_BINARY_DIR "${CMAKE_BINARY_DIR}/${OUTPUT}.cpp")
  SET(H_OUTPUT_BINARY_DIR   "${CMAKE_BINARY_DIR}/${OUTPUT}.h")
  SET(CPP_OUTPUT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/${OUTPUT}.cpp")
  SET(H_OUTPUT_SOURCE_DIR   "${CMAKE_SOURCE_DIR}/${OUTPUT}.h")
  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Generating ${CPP_OUTPUT_BINARY_DIR}")
     ADD_CUSTOM_COMMAND(OUTPUT "${CPP_OUTPUT_BINARY_DIR}"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${CPP_QUERY}\"" "-f" 
                           "-o" "\"${CPP_OUTPUT_BINARY_DIR}\""
                           "-e" "\"${PARAM1}\""
                           "-e" "\"${PARAM2}\""
                           "--serialize-text"
                        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                        "${CPP_OUTPUT_BINARY_DIR}"
                        "${CPP_OUTPUT_SOURCE_DIR}"
                         DEPENDS ${CPP_QUERY} ${SPEC_FILE}
                                 "${H_OUTPUT_BINARY_DIR}" # cpp always depends on .h
                                 "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq"
                       )

     MESSAGE(STATUS "Generating ${H_OUTPUT_BINARY_DIR}")
     ADD_CUSTOM_COMMAND(OUTPUT "${H_OUTPUT_BINARY_DIR}"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-o" "\"${H_OUTPUT_BINARY_DIR}\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                        "${H_OUTPUT_BINARY_DIR}"
                        "${H_OUTPUT_SOURCE_DIR}"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILE}
                                 "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${CPP_OUTPUT_SOURCE_DIR}")
    CHECK_OUTPUT_EXISTS("${H_OUTPUT_SOURCE_DIR}")
  ENDIF (ZORBA_WORKS)
ENDMACRO(CODEGEN_GENERATOR)

MACRO(FUNCTION_ENUM_GENERATOR HEADER_QUERY SPEC_FILES OUTPUT PARAM1 ZORBA_WORKS) 
  SET(OUTPUT_BINARY_DIR   "${CMAKE_BINARY_DIR}/${OUTPUT}")
  SET(OUTPUT_SOURCE_DIR   "${CMAKE_SOURCE_DIR}/${OUTPUT}")
  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Generating ${OUTPUT_BINARY_DIR}")
     ADD_CUSTOM_COMMAND(OUTPUT "${OUTPUT_BINARY_DIR}"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-o" "\"${OUTPUT_BINARY_DIR}\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                        COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
                        "${OUTPUT_BINARY_DIR}"
                        "${OUTPUT_SOURCE_DIR}"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILES}
                                 "${CMAKE_SOURCE_DIR}/src/runtime/spec/utils.xq")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${OUTPUT_SOURCE_DIR}")
  ENDIF (ZORBA_WORKS)
ENDMACRO(FUNCTION_ENUM_GENERATOR)
