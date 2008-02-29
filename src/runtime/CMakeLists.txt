SET(RUNTIME_SRCS
    accessors/AccessorsImpl.cpp
    context/ContextImpl.cpp
    core/item_iterator.cpp
    core/var_iterators.cpp
    core/flwor_iterator.cpp
    core/constructors.cpp
    core/path_iterators.cpp
    core/nodeid_iterators.cpp
    core/sequencetypes.cpp
    core/fncall_iterator.cpp
    core/arithmetic_impl.cpp
    core/trycatch.cpp
    numerics/NumericsImpl.cpp
    qnames/QNamesImpl.cpp
    strings/StringsImpl.cpp
    booleans/BooleanImpl.cpp
    dateTime/DurationsDatesTimes.cpp
    base/plan_iterator.cpp
    base/plan_wrapper.cpp
    base/plan_iterator_wrapper.cpp
    sequences/SequencesImpl.cpp
    visitors/accept.cpp
    visitors/printervisitor.cpp
    visitors/iterprinter.cpp
    fncontext/FnContextImpl.cpp
    debug/debug_iterators.cpp
)

HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS accessors)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS context)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS core)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS numerics)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS strings)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS booleans)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS dateTime)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS base)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS sequences)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS visitors)
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS fncontext)
