// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_xml_sax_ErrorHandler__
#define __org_xml_sax_ErrorHandler__

#pragma interface

#include <java/lang/Object.h>

extern "Java"
{
  namespace org
  {
    namespace xml
    {
      namespace sax
      {
        class ErrorHandler;
        class SAXParseException;
      }
    }
  }
}

class org::xml::sax::ErrorHandler : public ::java::lang::Object
{
public:
  virtual void warning (::org::xml::sax::SAXParseException *) = 0;
  virtual void error (::org::xml::sax::SAXParseException *) = 0;
  virtual void fatalError (::org::xml::sax::SAXParseException *) = 0;

  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif /* __org_xml_sax_ErrorHandler__ */
