MACRO(CHECK_OUTPUT_EXISTS OUTPUT)
  IF (EXISTS "${OUTPUT}")
    MESSAGE(STATUS "The Zorba Command Line Utility is not available to generate ${OUTPUT}. "
                   "The files from the repository are there and will be used.")
  ELSE (EXISTS "${OUTPUT}")
    MESSAGE(FATAL_ERROR "Neither the Zorba Command Line Utility nor the files ${OUTPUT} are available. "
                        "Can't proceed building Zorba.")
  ENDIF (EXISTS "${OUTPUT}")
ENDMACRO(CHECK_OUTPUT_EXISTS)

# macro used for generating the runtime's header and cpp files out of the xml specifications
MACRO(RUNTIME_GENERATOR CPP_QUERY HEADER_QUERY SPEC_FILE OUTPUT PARAM1 PARAM2 ZORBA_WORKS) 
  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     ADD_CUSTOM_COMMAND(OUTPUT "${OUTPUT}.cpp"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${CPP_QUERY}\"" "-f" 
                           "-e" "\"${PARAM1}\"" "-e" "\"${PARAM2}\""
                           "-o" "\"${OUTPUT}.cpp\""
                           "--serialize-text"
                         DEPENDS ${CPP_QUERY} ${SPEC_FILE}
                                 "${OUTPUT}.h") # cpp always depends on .h

     ADD_CUSTOM_COMMAND(OUTPUT "${OUTPUT}.h"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-e" "\"${PARAM1}\"" "-e" "\"${PARAM2}\""
                           "-o" "\"${OUTPUT}.h\""
                           "--serialize-text"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILE})
    MESSAGE(STATUS "added command for generating ${OUTPUT}")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${OUTPUT}.cpp")
    CHECK_OUTPUT_EXISTS("${OUTPUT}.h")
  ENDIF (ZORBA_WORKS)
ENDMACRO(RUNTIME_GENERATOR)

MACRO(PRINTER_VISITOR_GENERATOR CPP_QUERY HEADER_QUERY SPEC_FILES OUTPUT PARAM1 ZORBA_WORKS) 
  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     ADD_CUSTOM_COMMAND(OUTPUT "${OUTPUT}.cpp"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${CPP_QUERY}\"" "-f" 
                           "-o" "\"${OUTPUT}.cpp\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                         DEPENDS ${CPP_QUERY} ${SPEC_FILES}
                                 "${OUTPUT}.h" # cpp always depends on .h
                                 "${CMAKE_SOURCE_DIR}/src/runtime/visitors/planiter_visitor.h")

     MESSAGE(STATUS "Generating ${OUTPUT}.h")
     ADD_CUSTOM_COMMAND(OUTPUT "${OUTPUT}.h"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-o" "\"${OUTPUT}.h\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILES})
    MESSAGE(STATUS "added command for generating ${OUTPUT}")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${OUTPUT}.cpp")
    CHECK_OUTPUT_EXISTS("${OUTPUT}.h")
  ENDIF (ZORBA_WORKS)
ENDMACRO(PRINTER_VISITOR_GENERATOR)

MACRO(PLANINTER_VISITOR_GENERATOR HEADER_QUERY SPEC_FILES OUTPUT PARAM1 ZORBA_WORKS) 
  IF (ZORBA_WORKS) # only try to generate if zorbacmd is working 
     MESSAGE(STATUS "Generating planvisitor ${OUTPUT}.h")
     ADD_CUSTOM_COMMAND(OUTPUT "${OUTPUT}.h"
                        COMMAND ${ZORBA_RUNTIME_GENERATOR} 
                           "-q" "\"${HEADER_QUERY}\"" "-f" 
                           "-o" "\"${OUTPUT}.h\""
                           "-e" "\"${PARAM1}\""
                           "--serialize-text"
                         DEPENDS ${HEADER_QUERY} ${SPEC_FILES})
    MESSAGE(STATUS "added command for generating ${OUTPUT}")
  ELSE (ZORBA_WORKS)
    CHECK_OUTPUT_EXISTS("${OUTPUT}.h")
  ENDIF (ZORBA_WORKS)
ENDMACRO(PLANINTER_VISITOR_GENERATOR)
