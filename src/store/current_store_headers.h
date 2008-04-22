
#ifndef ZORBA_STORE_HEADERS_FOR_CURRENT_STORE
#define ZORBA_STORE_HEADERS_FOR_CURRENT_STORE

#include "common/common.h"

#ifndef ZORBA_MINIMAL_STORE
#include "store/naive/atomic_items.h"
#include "store/naive/simple_store.h"
#include "store/naive/node_items.h"
#else
#include "store/minimal/min_atomic_items.h"
#include "store/minimal/min_store.h"
#include "store/minimal/min_node_items.h"
#endif


#endif
