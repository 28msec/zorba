SET(RUNTIME_SRCS
    accessors/AccessorsImpl.cpp
    core/item_iterator.cpp
    core/constructors.cpp
    numerics/NumericsImpl.cpp
    strings/StringsImpl.cpp
    booleans/BooleanImpl.cpp
    dateTime/DurationsDatesTimes.cpp
    paths/path_iterators.cpp
    base/iterator.cpp
    sequences/SequencesImpl.cpp)

HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS accessors)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS core)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS numerics)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS strings)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS booleans)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS dateTime)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS paths)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS base)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS sequences)
