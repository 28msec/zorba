// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __com_bluecast_xml_JAXPSAXParserFactory__
#define __com_bluecast_xml_JAXPSAXParserFactory__

#pragma interface

#include <javax/xml/parsers/SAXParserFactory.h>

extern "Java"
{
  namespace javax
  {
    namespace xml
    {
      namespace parsers
      {
        class SAXParser;
        class ParserConfigurationException;
        class SAXParserFactory;
      }
    }
  }
  namespace com
  {
    namespace bluecast
    {
      namespace xml
      {
        class JAXPSAXParserFactory;
        class Piccolo;
      }
    }
  }
}

class com::bluecast::xml::JAXPSAXParserFactory : public ::javax::xml::parsers::SAXParserFactory
{
public:
  static ::javax::xml::parsers::SAXParserFactory *newInstance ();
  JAXPSAXParserFactory ();
  virtual jboolean getFeature (::java::lang::String *);
  virtual ::javax::xml::parsers::SAXParser *newSAXParser ();
  virtual void setFeature (::java::lang::String *, jboolean);
  virtual void setNamespaceAware (jboolean);
  virtual void setValidating (jboolean);
private:
  static ::java::lang::Class *findValidatingFactory ();
  void reconfigureValidating ();
  void reconfigureNonvalidating ();
  ::java::util::Map * __attribute__((aligned(__alignof__( ::javax::xml::parsers::SAXParserFactory )))) featureMap;
  static ::java::lang::Boolean *TRUE;
  static ::java::lang::Boolean *FALSE;
  ::com::bluecast::xml::Piccolo *nvParser;
  ::javax::xml::parsers::SAXParserFactory *validatingFactory;
  static ::java::lang::String *VALIDATING_PROPERTY;
  static ::java::lang::Class *validatingFactoryClass;
  ::javax::xml::parsers::ParserConfigurationException *pendingValidatingException;
  ::javax::xml::parsers::ParserConfigurationException *pendingNonvalidatingException;
  jboolean validating;
  jboolean namespaceAware;

  friend class com_bluecast_xml_JAXPSAXParserFactory$JAXPSAXParser;
  friend class java_util_Map$Entry;
public:

  static ::java::lang::Class class$;
};

#endif /* __com_bluecast_xml_JAXPSAXParserFactory__ */
