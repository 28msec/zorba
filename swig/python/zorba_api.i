/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


%{

#include <zorba/sax2.h>
#include <zorba/zorbastring.h>

#include <iostream>

class SAX2Attributes
{
protected:
  const zorba::SAX2_Attributes* attr;

public:
  SAX2Attributes() : attr(NULL) { };
  SAX2Attributes(const zorba::SAX2_Attributes* the_attr) : attr(the_attr) { };
  
  virtual ~SAX2Attributes() {};
  unsigned int getLength() const
  {
    if (attr == NULL)
      return 0;
    else
      return attr->getLength();
  }
  
  const char* getURI( const unsigned int index) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getURI(index).c_str();
  }
  
  const char* getLocalName( const unsigned int index) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getLocalName(index).c_str();
  };
  
  const char* getQName( const unsigned int index) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getQName(index).c_str();
  };
  
  const char* getType( const unsigned int index) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getType(index).c_str();
  };
  
  const char* getValue( const unsigned int index) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getValue(index).c_str();
  };
  
  int getIndex( const char* uri, const char* localPart ) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getIndex(uri, localPart);
  };
  
  int getIndex(const char* qName ) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getIndex(qName);
  };
  
  const char* getType(const char* uri, const char* localPart ) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getType(uri, localPart).c_str();
  };
  
  const char* getType( const char* qName ) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getType(qName).c_str();
  };
  
  const char* getValue( const char* uri, const char* localPart ) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getValue(uri, localPart).c_str();
  };
  
  const char* getValue( const char* qName ) const
  {
    if (attr == NULL)
      return NULL;
    else
      return attr->getValue(qName).c_str();
  };
};


// class SAX2ContentHandlerProxy
class SAX2ContentHandlerProxy : public zorba::SAX2_ContentHandler
{
protected:
  void* startDocumentCallback;
  void* endDocumentCallback;
  void* startElementCallback;
  void* endElementCallback;
  void* charactersCallback;
  void* processingInstructionCallback;
  void* ignorableWhitespaceCallback;
  void* startPrefixMappingCallback;
  void* endPrefixMappingCallback;
  void* skippedEntityCallback;

public:
  SAX2ContentHandlerProxy() :
    startDocumentCallback(NULL), endDocumentCallback(NULL), startElementCallback(NULL),
    endElementCallback(NULL), charactersCallback(NULL), processingInstructionCallback(NULL),
    ignorableWhitespaceCallback(NULL), startPrefixMappingCallback(NULL), endPrefixMappingCallback(NULL),
    skippedEntityCallback(NULL)
  {  }
  
protected:
  void startDocument()
  {
    if (startDocumentCallback == NULL)
      return;
    
    PyObject *func, *arglist, *result;
    func = (PyObject*)startDocumentCallback;
    arglist = NULL;
    result = PyEval_CallObject(func, arglist);
    Py_XDECREF(result);
  };
  
  void endDocument()
  {
    if (endDocumentCallback == NULL)
      return;
    
    PyObject *func, *arglist, *result;
    func = (PyObject*)endDocumentCallback;
    arglist = NULL;
    result = PyEval_CallObject(func, arglist);
    Py_XDECREF(result);
  };

  void startElement( const zorba::String& aURI, const zorba::String& aLocalname,
                             const zorba::String& aQName, const zorba::SAX2_Attributes& aAttrs )
  {
    if (startElementCallback == NULL)
      return;

    SAX2Attributes* attributes = new SAX2Attributes(&aAttrs);
    PyObject *func, *arglist, *result, *obj;
    func = (PyObject*)startElementCallback;
    obj = SWIG_NewPointerObj(SWIG_as_voidptr(attributes), SWIGTYPE_p_SAX2Attributes, 0);
    arglist = Py_BuildValue("(sssO)", aURI.c_str(), aLocalname.c_str(), aQName.c_str(), obj);
    // arglist = Py_BuildValue("(O)", obj);

    result = PyEval_CallObject(func, arglist);
    
    Py_DECREF(arglist);
    Py_XDECREF(result);
  };

  void endElement( const zorba::String& aURI, const zorba::String& aLocalname, const zorba::String& aQName )
  {
    if (endElementCallback == NULL)
      return;

    PyObject *func, *arglist, *result;
    func = (PyObject*)endElementCallback;
    arglist = Py_BuildValue("(sss)", aURI.c_str(), aLocalname.c_str(), aQName.c_str());
    
    result = PyEval_CallObject(func, arglist);
    
    Py_DECREF(arglist);
    Py_XDECREF(result);
  };

  void characters( const zorba::String& aText )
  {
    if (charactersCallback == NULL)
      return;

    PyObject *func, *arglist, *result;
    func = (PyObject*)charactersCallback;
    arglist = Py_BuildValue("(s)", aText.c_str());
    
    result = PyEval_CallObject(func, arglist);
    
    Py_DECREF(arglist);
    Py_XDECREF(result);
  };

  void processingInstruction( const zorba::String& aTarget, const zorba::String& aData )
  {
    if (processingInstructionCallback == NULL)
      return;

    PyObject *func, *arglist, *result;
    func = (PyObject*)processingInstructionCallback;
    arglist = Py_BuildValue("(ss)", aTarget.c_str(), aData.c_str());
    
    result = PyEval_CallObject(func, arglist);
    
    Py_DECREF(arglist);
    Py_XDECREF(result);
  };

  void ignorableWhitespace( const zorba::String& aText )
  {
    if (ignorableWhitespaceCallback == NULL)
      return;

    PyObject *func, *arglist, *result;
    func = (PyObject*)ignorableWhitespaceCallback;
    arglist = Py_BuildValue("(s)", aText.c_str());
    
    result = PyEval_CallObject(func, arglist);
    
    Py_DECREF(arglist);
    Py_XDECREF(result);
  };

  void startPrefixMapping( const zorba::String& aPrefix, const zorba::String& aURI )
  {
  };

  void endPrefixMapping( const zorba::String& aPrefix )
  {
  };

  void skippedEntity( const  zorba::String& aName )
  {
  };
  
public:
  void setStartDocumentHandler(PyObject* pyfunc)
  {
    startDocumentCallback = pyfunc;
    Py_INCREF(pyfunc);
  };
  
  void setEndDocumentHandler(PyObject* pyfunc)
  {
    endDocumentCallback = pyfunc;
    Py_INCREF(pyfunc);
  };

  void setStartElementHandler(PyObject* pyfunc)
  {
    startElementCallback = pyfunc;
    Py_INCREF(pyfunc);
  };

  void setEndElementHandler(PyObject* pyfunc)
  {
    endElementCallback = pyfunc;
    Py_INCREF(pyfunc);
  };

  void setCharactersHandler(PyObject* pyfunc)
  {
    charactersCallback = pyfunc;
    Py_INCREF(pyfunc);
  };

  void setProcessingInstructionHandler(PyObject* pyfunc)
  {
    processingInstructionCallback = pyfunc;
    Py_INCREF(pyfunc);
  };

  void setIgnorableWhitespaceHandler(PyObject* pyfunc)
  {
    ignorableWhitespaceCallback = pyfunc;
    Py_INCREF(pyfunc);
  };

  void setStartPrefixMappingHandler(PyObject* pyfunc)
  {
    startPrefixMappingCallback = pyfunc;
    Py_INCREF(pyfunc);
  };

  void setEndPrefixMappingHandler(PyObject* pyfunc)
  {
    endPrefixMappingCallback = pyfunc;
    Py_INCREF(pyfunc);
  };

  void setSkippedEntityHandler(PyObject* pyfunc)
  {
    skippedEntityCallback = pyfunc;
    Py_INCREF(pyfunc);
  };
};

%}

class SAX2Attributes
{
public:
  SAX2Attributes();
  
  ~SAX2Attributes();
  unsigned int getLength() const;
  const char* getURI( const unsigned int index) const;
  const char* getLocalName( const unsigned int index) const;
  const char* getQName( const unsigned int index) const;
  const char* getType( const unsigned int index) const;
  const char* getValue( const unsigned int index) const;
  int getIndex( const char* uri, const char* localPart ) const;
  int getIndex(const char* qName ) const;
  const char* getType(const char* uri, const char* localPart ) const;
  const char* getType( const char* qName ) const;
  const char* getValue( const char* uri, const char* localPart ) const;
  const char* getValue( const char* qName ) const;
};


class SAX2ContentHandlerProxy
{
public:
  void setStartDocumentHandler(PyObject *pyfunc);
  void setEndDocumentHandler(PyObject *pyfunc);
  void setStartElementHandler(PyObject* pyfunc);
  void setEndElementHandler(PyObject* pyfunc);
  void setCharactersHandler(PyObject* pyfunc);
  void setProcessingInstructionHandler(PyObject* pyfunc);
  void setIgnorableWhitespaceHandler(PyObject* pyfunc);
  void setStartPrefixMappingHandler(PyObject* pyfunc);
  void setEndPrefixMappingHandler(PyObject* pyfunc);
  void setSkippedEntityHandler(PyObject* pyfunc);
};

%include ../zorba_api.i
