SET(RUNTIME_SRCS
    accessors/AccessorsImpl.cpp
    core/item_iterator.cpp
    numerics/NumericsImpl.cpp
    strings/StringsImpl.cpp
    booleans/BooleanImpl.cpp
    dateTime/DurationsDatesTimes.cpp
    paths/path_iterators.cpp
    core/batching.cpp
    iterators.cpp
    sequences/SequencesImpl.cpp)

ADD_LIBRARY(runtime SHARED ${RUNTIME_SRCS})
