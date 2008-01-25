
#ifndef DEFAULT_STORE_DEFS
#define DEFAULT_STORE_DEFS
 
#define GET_STORE() \
        (*(static_cast<SimpleStore*>(&Store::getInstance())))

#define GET_FACTORY() \
        (*(static_cast<BasicItemFactory*>(& GET_STORE().getItemFactory())))


#define BASE_NODE(item) (static_cast<XmlNode*>((item).get_ptr()))

#define DOC_NODE(item) (static_cast<DocumentNode*>((item).get_ptr()))

#define ELEM_NODE(item) (static_cast<ElementNode*>((item).get_ptr()))

#define ATTR_NODE(item) (static_cast<AttributeNode*>((item).get_ptr()))

#define TEXT_NODE(item) (static_cast<TextNode*>((item).get_ptr()))

#define PI_NODE(item) (static_cast<PiNode*>((item).get_ptr()))

#define COMMENT_NODE(item) (static_cast<CommentNode*>((item).get_ptr()))

#endif
