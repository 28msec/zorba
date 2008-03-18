
#ifndef ZORBA_SAX2_XML_READER_NATIVE_IMPLEMENTATION_12_MAR_2008
#define ZORBA_SAX2_XML_READER_NATIVE_IMPLEMENTATION_12_MAR_2008

#include <list>
#include <utility>

#include <zorba/common/common.h>
#include <zorbatypes/representations.h>
#include "sax2/xmlreader.h"
#include "api/serialization/serializer.h"
#include "sax2/native/locator_native.h"

namespace zorba{

class SAX2_Locator;
class SAX2_ContentHandler;
class SAX2_ErrorHandler;
class SAX2_DTDHandler;
class SAX2_DeclHandler;
class SAX2_LexicalHandler;

class sax2_transcoder : public serializer::transcoder
{
public:
  sax2_transcoder();
  virtual ~sax2_transcoder();
  
  virtual serializer::transcoder& operator<<(const xqpString& s);
  virtual serializer::transcoder& operator<<(const char ch);
  
  void    clear_output();
  const char*   getbuff();
  int     getsize();
protected:
  void resize_oss( int ssize );
protected:
  //std::string os;
  char  *oss;
  int   all_size;
  int   current_size;
};


class SAX2_XMLReaderNative : public SAX2_XMLReader
{
public:
  SAX2_XMLReaderNative(
                        SAX2_ContentHandler *content_handler = NULL,
                        SAX2_ErrorHandler *error_handler = NULL,
                        SAX2_DTDHandler   *dtd_handler = NULL,
                        SAX2_DeclHandler  *decl_handler = NULL,
                        SAX2_LexicalHandler *lexical_handler = NULL);
  virtual ~SAX2_XMLReaderNative();

  virtual bool parse(XQuery_t xquery);

protected:
  sax2_transcoder   oss_transc;
  serializer::xml_emitter   xmlemitter;

  SAX2_LocatorNative    locator_native;

protected:
  void emit_node_children(store::Item* item);
  void emit_startPrefixMapping(store::Item* item, NsBindings &nsBindings);
  void emit_endPrefixMapping( NsBindings &nsBindings);
  void emit_node(store::Item* item);
  void emit_item(store::Item* item);
  void emit_expanded_string(xqp_string strtext);
};

}//end namespace zorba

#endif
