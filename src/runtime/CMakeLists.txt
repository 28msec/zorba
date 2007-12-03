SET(RUNTIME_SRCS
    accessors/AccessorsImpl.cpp
    core/item_iterator.cpp
    core/flwor_iterator.cpp
    core/constructors.cpp
    core/path_iterators.cpp
    core/nodeid_iterators.cpp
    numerics/NumericsImpl.cpp
    strings/StringsImpl.cpp
    booleans/BooleanImpl.cpp
    dateTime/DurationsDatesTimes.cpp
    base/iterator.cpp
    sequences/SequencesImpl.cpp
    visitors/accept.cpp
    visitors/printervisitor.cpp
    visitors/iterprinter.cpp
)

HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS accessors)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS core)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS numerics)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS strings)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS booleans)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS dateTime)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS base)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS sequences)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS visitors)
