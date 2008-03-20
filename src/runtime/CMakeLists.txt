SET(RUNTIME_SRCS
    accessors/AccessorsImpl.cpp
    api/plan_iterator_wrapper.cpp
    api/plan_wrapper.cpp
    base/plan_iterator.cpp
    booleans/BooleanImpl.cpp
    context/ContextImpl.cpp
    core/arithmetic_impl.cpp
    core/constructors.cpp
    core/flwor_iterator.cpp
    core/fncall_iterator.cpp
    core/item_iterator.cpp
    core/nodeid_iterators.cpp
    core/path_iterators.cpp
    core/sequencetypes.cpp
    core/trycatch.cpp
    core/var_iterators.cpp
    dateTime/DurationsDatesTimes.cpp
    debug/debug_iterators.cpp
    fncontext/FnContextImpl.cpp
    numerics/NumericsImpl.cpp
    qnames/QNamesImpl.cpp
    sequences/SequencesImpl.cpp
    strings/StringsImpl.cpp
    visitors/accept.cpp
    visitors/iterprinter.cpp
    visitors/printervisitor.cpp
    update/update.cpp
    misc/MiscImpl.cpp
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
HEADER_GROUP_SUBFOLDER(RUNTIME_SRCS misc)
