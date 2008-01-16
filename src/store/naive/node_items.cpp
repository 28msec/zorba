/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#include <algorithm>

#include "system/zorba.h"
#include "system/zorba_engine.h"

#include "errors/error_factory.h"

#include "runtime/core/item_iterator.h"

#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"
#include "store/naive/nsbindings.h"
#include "store/api/temp_seq.h"


#ifndef NDEBUG

int traceLevel = 0;

#define NODE_TRACE(level, msg)               \
{                                            \
  if (level <= traceLevel)                   \
    std::cout << msg << std::endl;           \
}

#define NODE_TRACE1(msg) NODE_TRACE(1, msg);

#else

#define NODE_TRACE(msg)
#define NODE_TRACE1(msg)

#endif


namespace xqp
{

#define GET_CURRENT_LOCATION() \
        ZORBA_FOR_CURRENT_THREAD()->GetCurrentLocation()


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class NodeVector                                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


NodeVector::NodeVector(unsigned long size)
{
  theNodes = new Item_t[size+1];
  *(unsigned long*)(theNodes) = size;
}


NodeVector::~NodeVector()
{
  clear();
}


void NodeVector::clear()
{
  if (theNodes != 0)
  {
    *((void**)theNodes) = 0;
    delete [] theNodes;
    theNodes = 0;
  }
}


NodeVector& NodeVector::operator=(const NodeVector& v)
{
  clear();

  unsigned long size = v.size();

  if (size == 0)
    return *this;

  resize(size);

  for (unsigned long i = 1; i <= size; i++)
    theNodes[i] = v.theNodes[i];

  return *this;
}


unsigned long NodeVector::size() const
{
  if (theNodes == 0)
    return 0;

  return *(unsigned long*)(theNodes);
}


void NodeVector::resize(unsigned long newSize)
{
  if (newSize == 0)
  {
    clear();
    return;
  }

  if (newSize == size())
    return;

  if (theNodes != 0)
  {
    Item_t* nodes = new Item_t[newSize + 1];
    memset(nodes, 0, (newSize + 1) * sizeof(Item_t));
 
    unsigned long copySize = (newSize > size() ? size() : newSize) + 1;

    for (unsigned long i = 1; i < copySize; i++)
      nodes[i] = theNodes[i];

    *(unsigned long*)(nodes) = newSize;
   
    clear();
    theNodes = nodes;
  }
  else
  {
    theNodes = new Item_t[newSize + 1];
    memset(theNodes, 0, (newSize + 1) * sizeof(Item_t));
    *(unsigned long*)(theNodes) = newSize;
  }
}


void NodeVector::truncate()
{
  if (theNodes == 0)
    return;

  unsigned long i;

  for (i = size(); i > 0 && theNodes[i] == 0; i--) ;

  resize(i);
}


void NodeVector::push_back(const Item_t& item, unsigned long index)
{
  Assert(index <= size());

  if (index == size())
    resize(size() + 100);

  theNodes[index+1] = item;
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class Node                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


NodeImpl::NodeImpl(bool assignId)
  :
  theTreeId(0),
  theParent(NULL)
{
  if (assignId)
    initId();
}


xqp_string NodeImpl::getBaseURI() const
{
  return theParent ? theParent->getBaseURI() : "";
}


xqp_string NodeImpl::getDocumentURI() const
{
  return theParent ? theParent->getDocumentURI() : "";
}


bool NodeImpl::equals(Item_t item) const
{
  ZORBA_ASSERT (false && "Equal function for node items not implemented");
  return false;
}


Item_t NodeImpl::getEBV() const
{
  return GET_FACTORY().createBoolean(true);
}


void NodeImpl::initId()
{
  theTreeId = GET_STORE().getTreeId();
  theOrdPath.init();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class DocumentNode                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Constructor used by the xml SAX loader.
********************************************************************************/
DocumentNodeImpl::DocumentNodeImpl(
    const xqpStringStore_t& baseURI,
    const xqpStringStore_t& docURI)
  :
  NodeImpl(false),
  theBaseURI(baseURI),
  theDocURI(docURI),
  theFlags(0)
{
  NODE_TRACE1("Loaded doc node " << this);
}


/*******************************************************************************
  Constructor used by the zorba runtime (during node construction).
********************************************************************************/
DocumentNodeImpl::DocumentNodeImpl(
    const xqpStringStore_t& baseURI,
    const xqpStringStore_t& docURI,
    const Iterator_t&       childrenIte,
    bool                    assignId)
  :
  NodeImpl(assignId),
  theBaseURI(baseURI),
  theDocURI(docURI),
  theFlags(NodeImpl::IsConstructed)
{
  unsigned long numChildren = 0;

  Item_t item = childrenIte->next();
  while (item != NULL)
  {
    Assert(item->isNode() && item->getNodeKind() != StoreConsts::attributeNode);

    theChildren.push_back(item, numChildren++);

    item = childrenIte->next();
  }

  if (numChildren > 0)
    theChildren.truncate();

  NODE_TRACE1("Constructed doc node " << this << " nid = " << theOrdPath.show());
}
 

/*******************************************************************************
  Copy constructor used during the evaluation of an enclosed expression inside
  a node construction expression.
********************************************************************************/
DocumentNodeImpl::DocumentNodeImpl(
    const DocumentNodeImpl* src,
    bool                    typePreserve,
    bool                    nsPreserve)
  :
  NodeImpl(false),
  theBaseURI(src->theBaseURI),
  theDocURI(src->theDocURI),
  theFlags(NodeImpl::IsConstructed | NodeImpl::IsCopy)
{
  if (typePreserve)
    theFlags |= NodeImpl::TypePreserve;

  if (nsPreserve)
    theFlags |= NodeImpl::NsPreserve;

  theChildren = src->theChildren;

  NODE_TRACE1("Copied doc node " << src << " to doc node " << this
             << " typePreserve = " << typePreserve
             << " nsPreserve = " << nsPreserve);
}


/*******************************************************************************

********************************************************************************/
DocumentNodeImpl::~DocumentNodeImpl()
{
  unsigned long numChildren = theChildren.size();
  unsigned long i;
  for (i = 0; i < numChildren; i++)
  {
    NodeImpl* child = BASE_NODE(theChildren[i]);

    if (!child->hasId())
    {
      child->initId();
    }

    child->theParent = NULL;
  }

  NODE_TRACE1("Deleted doc node " << this);
}


Item_t DocumentNodeImpl::getType() const
{
  return GET_STORE().theAnyType;
}


Iterator_t DocumentNodeImpl::getChildren() const
{
  return (new ChildrenIterator((NodeImpl*)this, 0));
}


Iterator_t DocumentNodeImpl::getTypedValue() const
{
  Item_t item = GET_FACTORY().createUntypedAtomic(getStringProperty());
  PlanIter_t ret(new SingletonIterator(GET_CURRENT_LOCATION(), item));
  return new PlanWrapper(ret);
}


Item_t DocumentNodeImpl::getAtomizationValue() const
{
  return GET_FACTORY().createUntypedAtomic(getStringProperty());
}


xqp_string DocumentNodeImpl::getStringProperty() const
{
  ostringstream oss;
  Iterator_t it = getChildren();
  Item_t item = it->next();
  while (item != NULL)
  {
    oss << item->getStringProperty();
    item = it->next();
  }
  return oss.str();
}


xqp_string DocumentNodeImpl::show() const
{
  std::stringstream strStream;

  strStream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl
            << "<document baseUri = \"" << *theBaseURI << "\" docUri = \""
            << *theDocURI << "\">" << std::endl;

  Iterator_t iter = getChildren();
  Item_t item = iter->next();
  while (item != NULL)
  {
    strStream << item->show();
    item = iter->next();
  }
  
  strStream << std::endl << "</document>";

  return strStream.str().c_str();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ElementNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Constructor used by the xml SAX loader.
********************************************************************************/
ElementNodeImpl::ElementNodeImpl(
    Item*         name,
    Item*         type,
    unsigned long numBindings,
    unsigned long numAttributes)
  :
  NodeImpl(false),
  theName(name),
  theTypeName(type),
  theFlags(0)
{
  if (numBindings > 0)
  {
    theNsContext = new NsBindingsContext(numBindings);
    theFlags |= NodeImpl::HaveLocalBindings;
  }

  if (numAttributes > 0)
    theAttributes.resize(numAttributes);

  NODE_TRACE1("Loaded elem node " << this << " name = " << theName->show()
              <<" num bindings = " << numBindings);
}


/*******************************************************************************
  Constructor used by the zorba runtime to create a new node as specified by
  a direct or computed element construction expression.
********************************************************************************/
ElementNodeImpl::ElementNodeImpl(
    const Item_t&            name,
    const Item_t&            type,
    Iterator_t&              childrenIte,
    Iterator_t&              attributesIte,
    Iterator_t&              namespacesIte,
    const NamespaceBindings& nsBindings,
    bool                     nsInherit,
    bool                     assignId)
  :
  NodeImpl(assignId),
  theName(name),
  theTypeName(type),
  theFlags(NodeImpl::IsConstructed)
{
  Assert(namespacesIte == NULL);

  unsigned long numAttrs = 0;
  Item_t item;

  if (nsInherit)
    theFlags |= NodeImpl::NsInherit;

  if (attributesIte != 0)
  {
    item = attributesIte->next();
    while (item != 0)
    {
      Assert(item->isNode() && item->getNodeKind() == StoreConsts::attributeNode);
      theAttributes.push_back(item, numAttrs++);
      item = attributesIte->next();
    }
  }
  
  if (childrenIte != 0)
  {
    unsigned long numChildren = 0;

    item = childrenIte->next();
    while (item != 0)
    {
      Assert(item->isNode());

      if (item->getNodeKind() == StoreConsts::attributeNode)
      {
        theAttributes.push_back(item, numAttrs++);
      }
      else
      {
        theChildren.push_back(item, numChildren++);
      }

      item = childrenIte->next();
    }

    if (numChildren > 0)
      theChildren.truncate();
  }

  if (numAttrs > 0)
    theAttributes.truncate();

  if (!nsBindings.empty())
  {
    theNsContext = new NsBindingsContext(nsBindings);
    theFlags |= NodeImpl::HaveLocalBindings;
  }

  NODE_TRACE1("Constructed elem node " << this << " nid = " << theOrdPath.show()
              << " nsInherit = " << nsInherit);
}


/*******************************************************************************
  Copy constructor used during the evaluation of an enclosed expression inside
  a node construction expression.

  Note: "parent" will be NULL iff we are copying a node N that is returned by
  the enclosed expr. If we are copying a node in the subtree of N, "parent" will
  be non-NULL. 
********************************************************************************/
ElementNodeImpl::ElementNodeImpl(
    const NodeImpl*        parent,
    const ElementNodeImpl* src,
    bool                   typePreserve,
    bool                   nsPreserve)
  :
  NodeImpl(false),
  theName(src->getNodeName()),
  theFlags(NodeImpl::IsConstructed | NodeImpl::IsCopy)
{
  theParent = const_cast<NodeImpl*>(parent);

  assert(parent == NULL ||
         parent->getNodeKind() == StoreConsts::elementNode ||
         parent->getNodeKind() == StoreConsts::documentNode);

  if (typePreserve)
  {
    theFlags |= NodeImpl::TypePreserve;
    theTypeName = src->getType();
  }
  else
  {
    theTypeName = GET_STORE().theUntypedType;
  }

  theAttributes = src->theAttributes;
  theChildren = src->theChildren;

  if (nsPreserve)
  {
    theFlags |= NodeImpl::NsPreserve;

    if (parent == NULL)
    {
      if (src->haveLocalBindings())
      {
        theNsContext = new NsBindingsContext(src->getNamespaceBindings());
        theFlags |= NodeImpl::HaveLocalBindings;
      }
    }
    else if (src->haveLocalBindings())
    {
      theNsContext = new NsBindingsContext(src->getNsContext()->getBindings());
      theNsContext->setParent(parent->getNsContext());
      theFlags |= NodeImpl::HaveLocalBindings;
    }
    else
    {
      theNsContext = parent->getNsContext();
    }
  }
  else
  {
    xqpString prefix;
    xqpStringStore_t ns;
    std::auto_ptr<NsBindingsContext> nsContext(new NsBindingsContext);

    prefix = theName->getPrefix();

    ns = (parent != NULL && parent->getNodeKind() == StoreConsts::elementNode ?
          parent->getNsContext()->findBinding(prefix) :
          NULL);

    if (ns == NULL)
      ns = src->getNsContext()->findBinding(prefix);

    // ns may be null only if the prefix was empty and there was no default
    // namespace declaration in scope.
    ZORBA_ASSERT(prefix == "" || ns != NULL);

    if (ns != NULL)
    {
      nsContext->addBinding(prefix, ns);
      theFlags |= NodeImpl::HaveLocalBindings;
    }

    unsigned long numAttrs = numAttributes();

    for (unsigned long i = 0; i < numAttrs; i++)
    {
      prefix = theAttributes[i]->getNodeName()->getPrefix();

      ns = (parent != NULL && parent->getNodeKind() == StoreConsts::elementNode ?
            parent->getNsContext()->findBinding(prefix) :
            NULL);

      if (ns == NULL)
        ns = src->getNsContext()->findBinding(prefix);


      ZORBA_ASSERT(prefix == "" || ns != NULL);

      if (ns != NULL)
      {
        nsContext->addBinding(prefix, ns);
        theFlags |= NodeImpl::HaveLocalBindings;
      }
    }

    if (haveLocalBindings())
    {
      theNsContext = nsContext.release();
    }
    else if (parent != NULL)
    {
      theNsContext = parent->getNsContext();
    }
  }

  NODE_TRACE1("Copied elem node " << src << " to elem node " << this
              << " parent = " << parent
              << " typePreserve = " << typePreserve
              << " nsPreserve = " << nsPreserve);
}


/*******************************************************************************

********************************************************************************/
ElementNodeImpl::~ElementNodeImpl()
{
  Assert(getRefCount() == 0);

  unsigned long i;
  unsigned long numNodes = theChildren.size();

  for (i = 0; i < numNodes; i++)
  {
    NodeImpl* child = BASE_NODE(theChildren[i]);

    if (!child->hasId())
    {
      child->initId();
    }

    if (child->theParent == this)
      child->theParent = NULL;
  }

  numNodes = theAttributes.size();

  for (i = 0; i < numNodes; i++)
  {
    NodeImpl* attr = BASE_NODE(theAttributes[i]);

    if (!attr->hasId())
    {
      attr->initId();
    }

    if (attr->theParent == this)
      attr->theParent = NULL;
  }

  NODE_TRACE1("Deleted elem node " << this << ", nscontext "
              << theNsContext.get_ptr() << ", "
              << (theNsContext != NULL ? theNsContext->getRefCount() : -1));
}


/*******************************************************************************

********************************************************************************/
unsigned long ElementNodeImpl::numAttributes() const
{
  return theAttributes.size();
}


/*******************************************************************************

********************************************************************************/
Iterator_t ElementNodeImpl::getAttributes() const
{
  return (new AttributesIterator((ElementNodeImpl*)this));
}


/*******************************************************************************

********************************************************************************/
Iterator_t ElementNodeImpl::getChildren() const
{
  return (new ChildrenIterator((NodeImpl*)this, numAttributes() * 2));
}


/*******************************************************************************

********************************************************************************/
Iterator_t ElementNodeImpl::getTypedValue() const
{
  Item_t retItem = getAtomizationValue();
  PlanIter_t ret(new SingletonIterator(GET_CURRENT_LOCATION(), retItem));
  return new PlanWrapper(ret);
}


/*******************************************************************************

********************************************************************************/
Item_t ElementNodeImpl::getAtomizationValue() const
{
  ostringstream oss;
  Iterator_t it = getChildren();
  Item_t lItem = it->next();
  while ( lItem != 0) {
    if (!(lItem->isNode() && lItem->getNodeKind() == StoreConsts::commentNode)) {
      Item_t lAtomicItem = lItem->getAtomizationValue(); 
      oss << lAtomicItem->getStringProperty();
    }
    lItem = it->next();
  }
  Item_t retItem = GET_FACTORY().createUntypedAtomic(oss.str());
  return retItem;
  //return GET_FACTORY().createUntypedAtomic(getStringProperty());
}


/*******************************************************************************

********************************************************************************/
xqp_string ElementNodeImpl::getStringProperty() const
{
  ostringstream oss;
  Iterator_t it = getChildren();
  Item_t item = it->next();
  while ( item != NULL )
  {
    oss << item->getStringProperty();
    item = it->next();
  }  return oss.str();
}


/*******************************************************************************

********************************************************************************/
void ElementNodeImpl::setNsContext(NsBindingsContext* ctx)
{
  if (theNsContext == NULL)
    theNsContext = ctx;
  else
    theNsContext->setParent(ctx);
}


/*******************************************************************************

********************************************************************************/
NamespaceBindings ElementNodeImpl::getNamespaceBindings() const
{
  NamespaceBindings bindings;

  if (theNsContext != NULL)
  {
    bindings = theNsContext->getBindings();

    NsBindingsContext* parentContext = theNsContext->getParent();

    while (parentContext != NULL)
    {
      const NamespaceBindings& parentBindings = parentContext->getBindings();
      unsigned long parentSize = parentBindings.size();
      unsigned long currSize = bindings.size();

      for (unsigned long i = 0; i < parentSize; i++)
      {
        unsigned long j;
        for (j = 0; j < currSize; j++)
        {
          if (bindings[j].first.byteEqual(parentBindings[i].first))
            break;
        }

        if (j == currSize)
          bindings.push_back(parentBindings[i]);
      }

      parentContext = parentContext->getParent();
    }
  }

  return bindings;
}


/*******************************************************************************

********************************************************************************/
bool ElementNodeImpl::getNilled() const
{
  Iterator_t iter = getChildren();
  Item_t item = iter->next();
  while (item != NULL)
  {
    if (item->isNode() && 
        (item->getNodeKind() == StoreConsts::elementNode ||
         item->getNodeKind() == StoreConsts::textNode))
      return false;

    item = iter->next();
  }
  return true;
}


/*******************************************************************************

********************************************************************************/
xqp_string ElementNodeImpl::show() const
{
  std::stringstream str;

  str <<  "<" << theName->getStringProperty();

  str << " nid=\"" << theOrdPath.show() << "\"";

  NamespaceBindings nsBindings = getNamespaceBindings();

  for (unsigned long i = 0; i < nsBindings.size(); i++)
  {
    str << " xmlns:" <<  nsBindings[i].first << "=\""
        << nsBindings[i].second << "\"";
  }

  Iterator_t iter = getAttributes();
  Item_t item = iter->next();
  while (item != NULL)
  {
    str << " " << item->show();
    item = iter->next();
  }

  str << ">";

  iter = getChildren();
  item = iter->next();
  while (item != NULL)
  {
    str << item->show();
    item = iter->next();
  }

  str << "</" << theName->getStringProperty() << ">";
  return str.str().c_str();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class AttributeNode                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
AttributeNodeImpl::AttributeNodeImpl(
    const Item_t& name,
    const Item_t& type,
    const Item_t& lexicalValue,
    const Item_t& typedValue,
    bool isId,
    bool isIdrefs,
    bool assignId)
  :
  NodeImpl(assignId),
  theName(name),
  theTypeName(type),
  theLexicalValue(lexicalValue),
  theTypedValue(typedValue),
  theIsId(isId),
  theIsIdrefs(isIdrefs)
{
}


/*******************************************************************************
  Copy constructor used during the evaluation of an enclosed expression inside
  a node construction expression.
********************************************************************************/
AttributeNodeImpl::AttributeNodeImpl(
    const NodeImpl*          parent,
    const AttributeNodeImpl* src,
    bool                     typePreserve)
  :
  NodeImpl(false),
  theName(src->getNodeName()),
  theLexicalValue(src->theLexicalValue),
  theTypedValue(src->theTypedValue),
  theIsId(src->isId()),
  theIsIdrefs(src->isIdrefs())
{
  theParent = const_cast<NodeImpl*>(parent);

  theTypeName = (typePreserve ? src->getType() : GET_STORE().theUntypedType);
}


Iterator_t AttributeNodeImpl::getTypedValue() const
{
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), theTypedValue);
  return new PlanWrapper(planIter);
}


Item_t AttributeNodeImpl::getAtomizationValue() const
{
  return theLexicalValue;
}

xqp_string AttributeNodeImpl::getStringProperty() const
{
  if (theLexicalValue != 0)
    return theLexicalValue->getStringProperty();
  else
    return "";
}


xqp_string AttributeNodeImpl::getStringValue() const
{
  return getStringProperty();
}


xqp_string AttributeNodeImpl::show() const
{
  return theName->getStringProperty() + "=\"" +
         (theLexicalValue != NULL ? theLexicalValue->show() : "") + "\"";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class TextNode                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


TextNodeImpl::TextNodeImpl(const xqpStringStore_t& content, bool assignId) 
  :
  NodeImpl(assignId),
  theContent(content)
{
}


TextNodeImpl::TextNodeImpl(const NodeImpl* parent, const TextNodeImpl* src) 
  :
  NodeImpl(false),
  theContent(src->theContent)
{
  theParent = const_cast<NodeImpl*>(parent);;
}


Item_t TextNodeImpl::getType() const
{
  return GET_STORE().theUntypedAtomicType;
}


Iterator_t TextNodeImpl::getTypedValue() const
{
  const Item_t& item = Store::getInstance().getItemFactory().
                              createUntypedAtomic(theContent);

  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  return new PlanWrapper(planIter);
}


Item_t TextNodeImpl::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().createUntypedAtomic(theContent);
}


xqp_string TextNodeImpl::show() const
{
  return theContent;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class PiNode                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

 
PiNodeImpl::PiNodeImpl(
    const xqpStringStore_t& target,
    const xqpStringStore_t& data,
    bool assignId)
  :
  NodeImpl(assignId),
  theTarget(target),
  theData(data)
{
}


PiNodeImpl::PiNodeImpl(const NodeImpl* parent, const PiNodeImpl* src) 
  :
  NodeImpl(false),
  theTarget(src->theTarget),
  theData(src->theData)
{
  theParent = const_cast<NodeImpl*>(parent);
}


Item_t PiNodeImpl::getType() const
{
  return GET_STORE().theUntypedAtomicType;
}


Iterator_t PiNodeImpl::getTypedValue() const
{
  const Item_t& item = GET_FACTORY().createString(theData);
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  return new PlanWrapper(planIter);
}


Item_t PiNodeImpl::getAtomizationValue() const
{
  return GET_FACTORY().createUntypedAtomic(theData);
}


xqp_string PiNodeImpl::show() const
{
  return "<?" + *theTarget + " " + *theData + "?>";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class CommentNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


CommentNodeImpl::CommentNodeImpl(
    const xqpStringStore_t& content,
    bool assignId)
  :
  NodeImpl(assignId),
  theContent(content)
{
}


CommentNodeImpl::CommentNodeImpl(const NodeImpl* parent, const CommentNodeImpl* src) 
  :
  NodeImpl(false),
  theContent(src->theContent)
{
  theParent = const_cast<NodeImpl*>(parent);
}


Item_t CommentNodeImpl::getType() const
{
  return static_cast<SimpleStore*>(&Store::getInstance())->theUntypedAtomicType;
}


Iterator_t CommentNodeImpl::getTypedValue() const
{
  const Item_t& item = GET_FACTORY().createString(theContent);
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  return new PlanWrapper(planIter);
}


Item_t CommentNodeImpl::getAtomizationValue() const
{
  return GET_FACTORY().createUntypedAtomic(theContent);
}


xqp_string CommentNodeImpl::show() const
{
  return "<!--" + *theContent + "-->";
}


} /* namespace xqp */
