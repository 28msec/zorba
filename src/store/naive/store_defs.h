
#ifndef DEFAULT_STORE_DEFS
#define DEFAULT_STORE_DEFS
 
#define GET_STORE() \
        (*(static_cast<SimpleStore*>(&Store::getInstance())))

#define GET_FACTORY() \
        (*(static_cast<BasicItemFactory*>(& GET_STORE().getItemFactory())))


#define BASE_NODE(item) (static_cast<NodeImpl*>((item).get_ptr()))

#define DOC_NODE(item) (static_cast<DocumentNodeImpl*>((item).get_ptr()))

#define ELEM_NODE(item) (static_cast<ElementNodeImpl*>((item).get_ptr()))

#define ATTR_NODE(item) (static_cast<AttributeNodeImpl*>((item).get_ptr()))

#define TEXT_NODE(item) (static_cast<TextNodeImpl*>((item).get_ptr()))

#define PI_NODE(item) (static_cast<PiNodeImpl*>((item).get_ptr()))

#define COMMENT_NODE(item) (static_cast<CommentNodeImpl*>((item).get_ptr()))

#endif
