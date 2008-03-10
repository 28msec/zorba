
#ifndef ZORBA_STORE_NODE_UPDATES_H
#define ZORBA_STORE_NODE_UPDATES_H

namespace zorba { namespace store {


struct NodeTypeInfo
{
  NodeTypeInfo(Item_t& tname, bool isId, bool isIdRefs) 
    :
    theTypeName(tname),
    theIsId(isId),
    theIsIdRefs(isIdRefs)
  {
  }

  Item_t  theTypeName;
  bool    theIsId;
  bool    theIsIdRefs;
  bool    theIsNillable;
};


typedef std::vector<std::pair<XmlNode*, NodeTypeInfo> > TypeUndoList;

}
}
#endif

