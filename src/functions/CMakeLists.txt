SET(FUNCTIONS_SRCS
    Accessors.cpp Sequences.cpp library.cpp
    Constructor.cpp ContextFunctions.cpp Numerics.cpp 
    Boolean.cpp FnContext.cpp QNames.cpp  Strings.cpp signature.cpp
    DateTime.cpp Misc.cpp function.cpp arithmetic.cpp Nodes.cpp
    external_function_adapters.cpp)

IF (ZORBA_WITH_REST)
  SET(FUNCTIONS_SRCS ${FUNCTIONS_SRCS} Rest.cpp)
ENDIF (ZORBA_WITH_REST)
