/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "store/naive/query_context.h"
#include "store/naive/node_items.h"


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
