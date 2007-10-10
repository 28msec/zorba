SET(FUNCTIONS_SRCS
    Accessors.cpp  Casting.cpp NOTATION.cpp Sequences.cpp Trace.cpp library.cpp
    Binary.cpp  Constructor.cpp Numerics.cpp anyURI.cpp
    Boolean.cpp Context.cpp QNames.cpp  Strings.cpp signature.cpp)

ADD_LIBRARY(functions SHARED ${FUNCTIONS_SRCS})
