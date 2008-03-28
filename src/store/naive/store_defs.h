#ifndef ZORBA_STORE_STORE_DEFS_H
#define ZORBA_STORE_STORE_DEFS_H
 
#define GET_STORE() \
        (*(static_cast<SimpleStore*>(&GENV.getStore())))

#define GET_FACTORY() \
        (*(reinterpret_cast<BasicItemFactory*>(GET_STORE().getItemFactory())))


#define BASE_NODE(item) (static_cast<XmlNode*>((item).getp()))

#endif
