// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __com_bluecast_xml_FastNamespaceSupport__
#define __com_bluecast_xml_FastNamespaceSupport__

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
        class FastNamespaceSupport;
      }
      namespace util
      {
        class IntStack;
        class StringStack;
      }
    }
  }
}

class com::bluecast::xml::FastNamespaceSupport : public ::java::lang::Object
{
public:
  FastNamespaceSupport ();
  virtual void reset ();
  virtual void pushContext ();
  virtual void popContext ();
  virtual void declarePrefix (::java::lang::String *, ::java::lang::String *);
  virtual JArray< ::java::lang::String *> *processName (::java::lang::String *, JArray< ::java::lang::String *> *, jboolean);
  virtual ::java::lang::String *getDefaultURI () { return defaultURI; }
  virtual ::java::lang::String *getURI (::java::lang::String *);
  virtual jint getContextSize ();
  virtual ::java::lang::String *getContextPrefix (jint);
  virtual ::java::lang::String *getContextURI (jint);
  static ::java::lang::String *XMLNS;
private:
  JArray< ::java::lang::String *> * __attribute__((aligned(__alignof__( ::java::lang::Object )))) prefixes;
  JArray< ::java::lang::String *> *uris;
  jint prefixPos;
  ::java::lang::String *defaultURI;
  ::com::bluecast::util::StringStack *defaultURIs;
  jint prefixCount;
  ::com::bluecast::util::IntStack *contextPrefixCounts;
  jint defaultURIContexts;
  ::com::bluecast::util::IntStack *defaultURIContextCounts;
public:

  static ::java::lang::Class class$;
};

#endif /* __com_bluecast_xml_FastNamespaceSupport__ */
