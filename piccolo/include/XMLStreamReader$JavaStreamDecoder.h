// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __com_bluecast_xml_XMLStreamReader$JavaStreamDecoder__
#define __com_bluecast_xml_XMLStreamReader$JavaStreamDecoder__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace com
  {
    namespace bluecast
    {
      namespace xml
      {
        class XMLStreamReader$JavaStreamDecoder;
        class XMLStreamReader;
      }
    }
  }
}

class com::bluecast::xml::XMLStreamReader$JavaStreamDecoder : public ::java::lang::Object
{
public:
  XMLStreamReader$JavaStreamDecoder (::com::bluecast::xml::XMLStreamReader *);
  virtual void reset ();
  virtual jint read ();
  virtual jint read (jcharArray, jint, jint);
  virtual jboolean ready ();
  virtual jlong skip (jlong);
private:
  ::java::io::Reader * __attribute__((aligned(__alignof__( ::java::lang::Object )))) reader;
public: // actually package-private
  jcharArray oneCharBuffer;
  jboolean sawCR;
  ::com::bluecast::xml::XMLStreamReader *this$0;

  friend class com_bluecast_xml_XMLStreamReader$JavaStreamDecoder;
  friend class com_bluecast_xml_XMLStreamReader$XMLStreamDecoder;
public:

  static ::java::lang::Class class$;
};

#endif /* __com_bluecast_xml_XMLStreamReader$JavaStreamDecoder__ */
