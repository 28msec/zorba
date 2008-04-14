#include "zorba/sax2.h"
#include "sax2/native/xmlreader_native.h"
#include <iostream>
#include "zorba/error.h"
#include "zorba/xquery.h"
#include "errors/errors.h"
#include "api/zorbaimpl.h"
//#include "system/zorba_engine.h"
#include "api/serialization/serializer.h"

#include "sax2/native/locator_native.h"
#include "sax2/native/attributes_native.h"
#include "sax2/native/namespaces_native.h"
#include "zorba/result_iterator.h"
#include "store/api/iterator.h"


namespace zorba{

#define     STR_CHUNK_SIZE    200

sax2_transcoder::sax2_transcoder() : transcoder(std::cout)
{
  oss = (char*)malloc(STR_CHUNK_SIZE);
  current_size = 0;
  all_size = STR_CHUNK_SIZE;
}

sax2_transcoder::~sax2_transcoder()
{
  ::free(oss);
}

void sax2_transcoder::resize_oss( int ssize )
{
  bool  reallo = false;
  while((current_size + ssize + 1) >= all_size)
  {
    all_size += STR_CHUNK_SIZE;
    reallo = true;
  }
  if(reallo)
    oss = (char*)realloc(oss, all_size);
}

serializer::transcoder& sax2_transcoder::operator<<(const xqpString& s)
{
  xqpString::size_type    ssize;
  ssize = s.bytes();

  resize_oss( ssize );

  memcpy(oss+current_size, s.c_str(), ssize);
  current_size += ssize;

  return *this;
}

serializer::transcoder& sax2_transcoder::operator<<(const char ch)
{
  resize_oss( 1 );
  oss[current_size++] = ch;
//  oss[current_size+1] = 0;
  return *this;
}

void    sax2_transcoder::clear_output()
{
  current_size = 0;
  oss[current_size] = 0;
}

const char*   sax2_transcoder::getbuff()
{
  return oss;
}

int   sax2_transcoder::getsize()
{
  return current_size;
}



SAX2_XMLReaderNative::SAX2_XMLReaderNative(
                      SAX2_ContentHandler *content_handler,
                      SAX2_ErrorHandler *error_handler,
                      SAX2_DTDHandler   *dtd_handler,
                      SAX2_DeclHandler  *decl_handler,
                      SAX2_LexicalHandler* lexical_handler) :
    SAX2_XMLReader(content_handler, error_handler, 
                  dtd_handler, decl_handler, lexical_handler),
    xmlemitter(NULL, oss_transc)

{
}

SAX2_XMLReaderNative::~SAX2_XMLReaderNative()
{
}

bool SAX2_XMLReaderNative::parse(XQuery_t xquery, ErrorHandler* aErrorHandler)
{
  //generate sax event by parsing the item tree
  //use the serializer code to normalize text nodes

/*  //test
  char  strtest[] = "lajsdhgklfkjdhasldkhflkasjhfdlksadjhfdlkjahsdflkjdsahjkfldkdasjhdjkflasdkjhfdjdskaldksjfhdsajkldkfjhdjksladskjfhlajsdhgklfkjdhasldkhflkasjhfdlksadjhfdlkjahsdflkjdsahjkfldkdasjhdjkflasdkjhfdjdskaldksjfhdsajkldkfjhdjksladskjfhlajsdhgklfkjdhasldkhflkasjhfdlksadjhfdlkjahsdflkjdsahjkfldkdasjhdjkflasdkjhfdjdskaldksjfhdsajkldkfjhdjksladskjfhlajsdhgklfkjdhasldkhflkasjhfdlksadjhfdlkjahsdflkjdsahjkfldkdasjhdjkflasdkjhfdjdskaldksjfhdsajkldkfjhdjksladskjfh";
	int		i, j;
	clock_t		c0,c1;
	clock_t		c2,c3;
	c0 = clock();
	for(i=0;i<1000000;i++)
	{
    sax2_transcoder   transc;
    for(j=0;j<sizeof(strtest);j++)
      transc << strtest[j];
	}
	c1=clock();
	std::cout << "using sax2_transcoder 1 milion times "<< (double)(c1-c0)/CLOCKS_PER_SEC << " seconds"  << std::endl;

	c2 = clock();
	for(i=0;i<1000000;i++)
	{
    std::ostringstream   oss;
    for(j=0;j<sizeof(strtest);j++)
      oss << strtest[j];
	}
	c3=clock();
	std::cout << "using ostringstream 1 milion "<< (double)(c3-c2)/CLOCKS_PER_SEC << " seconds" << std::endl;
	std::cout << "ostringstream comparison is  " << (double)(c3-c2)/(c1-c0) << " times slower !!!" << std::endl;
  std::cout << std::endl;
  //end test
*/

  ResultIterator_t    result = xquery->iterator();
  if(result == NULL)
    return false;
  Item    item;
  if(!result->next(item))
    return false;


  try{
  if(content_handler)
    content_handler->setDocumentLocator(&locator_native);
  if(content_handler)
    content_handler->startDocument();

  do
  {
    emit_item(item.getInternalItem());
  }while(result->next(item));

  if(content_handler)
    content_handler->endDocument();

  }
  catch(error::ZorbaError& x)
  {
    if(content_handler)
      content_handler->endDocument();
    SAX2_ParseException   saxx(x.theDescription, &locator_native);
    if(error_handler)
      error_handler->fatalError(saxx);
    throw saxx;
	}
  catch(...)
  {
    if(content_handler)
      content_handler->endDocument();
    throw;
  }

  return true;//return true if all items were processed
}

void SAX2_XMLReaderNative::emit_node_children(store::Item* item)//, bool perform_escaping = true)
{
  store::Iterator_t it;
  store::Item_t child;	
//  int closed_parent_tag = 0;
  
/*  if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    // emit attributes 
    it = item->getAttributes();
    it->open();
    child = it->next();
    while (child!= NULL)
    {		
      emit_node(&*child, depth);
      child = it->next();
    }
  }
  else if (item->getNodeKind() == store::StoreConsts::documentNode)
  {
    closed_parent_tag = 1;
  }
*/	
	// output all the other nodes
	it = item->getChildren();
  it->open();
	child = it->next();
	while (child!= NULL)
	{
    if (child->getNodeKind() != store::StoreConsts::attributeNode)
    {
    //  if (closed_parent_tag == 0)
		//  {
    //    tr << ">";
    //    closed_parent_tag = 1;
    //  }
      emit_node(&*child);
    }
    child = it->next();
  }

  return;
}

void SAX2_XMLReaderNative::emit_startPrefixMapping(store::Item* item, NsBindings &nsBindings)
{
  if(!content_handler)
    return;

  // emit namespace bindings
  NsBindings::size_type   ns_size;

  ns_size = nsBindings.size();
    
  for (unsigned long i = 0; i < ns_size; i++)
  {
    content_handler->startPrefixMapping(nsBindings[i].first, nsBindings[i].second);
  }
}

void SAX2_XMLReaderNative::emit_endPrefixMapping( NsBindings &nsBindings)
{
  if(!content_handler)
    return;
  // emit namespace bindings
  NsBindings::size_type   ns_size;

  ns_size = nsBindings.size();
    
  for (unsigned long i = 0; i < ns_size; i++)
  {
    content_handler->endPrefixMapping(nsBindings[i].first);
  }

}

void SAX2_XMLReaderNative::emit_node(store::Item* item)
{
	if( item->getNodeKind() == store::StoreConsts::documentNode )
	{		
    locator_native.setPublicId(item->getUnparsedEntityPublicId());
    locator_native.setSystemId(item->getUnparsedEntitySystemId());
		emit_node_children(item);    
	}
	else if (item->getNodeKind() == store::StoreConsts::elementNode)
	{
    NsBindings local_nsBindings;
    store::Item_t      item_qname;

    if(content_handler)
    {
      item->getNamespaceBindings(local_nsBindings,
                                 store::StoreConsts::ONLY_LOCAL_NAMESPACES);//only local namespaces

      SAX2_AttributesNative   attrs(item);
      SAX2_NamespacesNative   nss(&local_nsBindings, item);

      emit_startPrefixMapping(item, local_nsBindings);

      item_qname = item->getNodeName();
      content_handler->startElement(item_qname->getNamespace(),
                                    item_qname->getLocalName(),
                                    item_qname->getStringValue().getp(),
                                    attrs, nss);
    }
      
		emit_node_children(item);

    if(content_handler)
    {
      content_handler->endElement(item_qname->getNamespace(),
                                  item_qname->getLocalName(),
                                  item_qname->getStringValue().getp());
      emit_endPrefixMapping(local_nsBindings);
    }
	}
//	else if (item->getNodeKind() == store::StoreConsts::attributeNode )
//	{
//	tr << " " << item->getNodeName()->getStringValue() << "=\"";
//		emit_expanded_string(item->getStringValue(), true);
//		tr << "\"";
//    previous_item = PREVIOUS_ITEM_WAS_NODE;
//	}
	else if (item->getNodeKind() == store::StoreConsts::textNode)
	{		
  //  if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
  //    tr << " ";    
		emit_expanded_string(item->getStringValue().getp());
  //  previous_item = PREVIOUS_ITEM_WAS_TEXT;
	}
	else if (item->getNodeKind() == store::StoreConsts::commentNode)
	{
    if(lexical_handler)
    {
      xqp_string    comment_str = item->getStringValue().getp();
      lexical_handler->comment(comment_str.c_str(), comment_str.bytes());
    }
	}
	else if (item->getNodeKind() == store::StoreConsts::piNode )
	{
  //  tr << "<?" << item->getTarget() << " " << item->getStringValue() << "?>";
  //  previous_item = PREVIOUS_ITEM_WAS_NODE;
    if(content_handler)
      content_handler->processingInstruction(item->getTarget(),
                                             item->getStringValue().getp());
	}
	else 
	{
//		tr << "node of type: " << item->getNodeKind();		
    SAX2_ParseException   saxx("Unknown node type", &locator_native);
    if(error_handler)
      error_handler->fatalError(saxx);
    throw saxx;
	}
}

void SAX2_XMLReaderNative::emit_item(store::Item* item)
{
  if (item->isAtomic())
  {
  //  if (previous_item == PREVIOUS_ITEM_WAS_TEXT )
  //    tr << " ";
    emit_expanded_string(item->getStringValue().getp());
  //  previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else
  {
    if (item->getNodeKind() == store::StoreConsts::attributeNode)
      //||
      //  item->getNodeKind() == namespaceNode)
    {
      SAX2_ParseException   saxx("Node is attribute or namespace", &locator_native);
      if(error_handler)
        error_handler->fatalError(saxx);
      throw saxx;
    }
    else        
      emit_node(item);
  }  
}

void SAX2_XMLReaderNative::emit_expanded_string(xqp_string strtext)
{
  if(content_handler)
  {
    //use xml_emitter to normalize string
    xmlemitter.emit_expanded_string(strtext.getStore(), false);
    content_handler->characters(oss_transc.getbuff(), oss_transc.getsize());
    oss_transc.clear_output();
  }
}

}//end namespace zorba
