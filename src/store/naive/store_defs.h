#ifndef ZORBA_STORE_STORE_DEFS_H
#define ZORBA_STORE_STORE_DEFS_H
 
#define GET_STORE() \
        (*(static_cast<SimpleStore*>(&GENV.getStore())))

#define GET_FACTORY() \
        (*(reinterpret_cast<BasicItemFactory*>(GET_STORE().getItemFactory())))


#define BASE_NODE(item) (static_cast<XmlNode*>((item).getp()))

#define DOC_NODE(item) (reinterpret_cast<DocumentNode*>((item).getp()))

#define ATTR_NODE(item) (reinterpret_cast<AttributeNode*>((item).getp()))

#define ELEM_NODE(item) (reinterpret_cast<ElementNode*>((item).getp()))

#define TEXT_NODE(item) (reinterpret_cast<TextNode*>((item).getp()))

#define PI_NODE(item) (reinterpret_cast<PiNode*>((item).getp()))

#define COMMENT_NODE(item) (reinterpret_cast<CommentNode*>((item).getp()))

#endif
