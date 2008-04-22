
#include "store/minimal/min_query_context.h"
#include "store/minimal/min_node_items.h"


namespace zorba { namespace store {


QueryContext& QueryContextContainer::getContext(ulong queryId)
{
  SYNC_CODE(AutoMutex lock(theMutex);)
    
  std::map<ulong, QueryContext>::iterator ctxi;

  ctxi = theContainer.find(queryId);

  if (ctxi != theContainer.end())
    return ctxi->second;

  std::pair<std::map<ulong, QueryContext>::iterator, bool> res =
    theContainer.insert(std::pair<ulong, QueryContext>(queryId, QueryContext()));

  ctxi = res.first;
  return ctxi->second;
}


void QueryContextContainer::removeContext(ulong queryId)
{
  SYNC_CODE(AutoMutex lock(theMutex);)

  std::map<ulong, QueryContext>::iterator ctxi;

  ctxi = theContainer.find(queryId);

  ZORBA_FATAL(ctxi != theContainer.end(), "");
  ZORBA_FATAL(ctxi->second.empty(), "");

  theContainer.erase(queryId);
}


}
}
