
#ifndef DEFAULT_STORE_DEFS
#define DEFAULT_STORE_DEFS
 
#define GET_STORE() \
        (*(static_cast<SimpleStore*>(&Store::getInstance())))

#define GET_FACTORY(store) \
        (*(static_cast<BasicItemFactory*>(&(store).getItemFactory())))


#define BASE_NODE(item) (static_cast<NodeImpl*>((item).get_ptr()))

#define DOC_NODE(item) (static_cast<DocumentNodeImpl*>((item).get_ptr()))

#define ELEM_NODE(item) (static_cast<ElementNodeImpl*>((item).get_ptr()))

#define ATTR_NODE(item) (static_cast<AttributeNodeImpl*>((item).get_ptr()))

#endif
