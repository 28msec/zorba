
#ifndef ZORBA_STORE_NODE_UPDATES_H
#define ZORBA_STORE_NODE_UPDATES_H

namespace zorba { namespace store {


struct NodeTypeInfo
{
  NodeTypeInfo(Item* tname, bool isId, bool isIdRefs) 
    :
    theTypeName(tname),
    theIsId(isId),
    theIsIdRefs(isIdRefs),
    theIsNillable(false)
  {
  }

  Item    * theTypeName;
  bool      theIsId;
  bool      theIsIdRefs;
  bool      theIsNillable;
};


typedef std::vector<std::pair<XmlNode*, NodeTypeInfo> > TypeUndoList;

}
}
#endif

