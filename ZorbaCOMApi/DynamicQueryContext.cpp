// DynamicQueryContext.cpp : Implementation of CDynamicQueryContext

#include "stdafx.h"
#include "DynamicQueryContext.h"
#include "zorba/dynamic_context.h"
#include "utils.h"

// CDynamicQueryContext

/* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CDynamicQueryContext::getInternalDynamicQueryContextPtr( 
    /* [retval][out] */ VARIANT *internal_ptr)
{
  internal_ptr->pintVal = (int*)&*wrapped_interface;
  internal_ptr->vt = VT_INT | VT_BYREF;

  return S_OK;
}


 /* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CDynamicQueryContext::setVariableAsInt( 
    /* [in] */ BSTR varname,
    /* [in] */ int int_value)
{
  char  *utf8varname;
  utf8varname = getUtf8String(varname);
  if(!utf8varname)
  {
    return E_INVALIDARG;
  }
  
  bool retbool = wrapped_interface->setVariableAsInt(utf8varname, int_value);
  delete[] utf8varname;

  return retbool ? S_OK : E_FAIL;
}

HRESULT STDMETHODCALLTYPE CDynamicQueryContext::setVariableAsString( BSTR varname, BSTR str_value)
{
  char  *utf8varname;
  utf8varname = getUtf8String(varname);
  if(!utf8varname)
  {
    return E_INVALIDARG;
  }
  char  *utf8str_value;
  utf8str_value = getUtf8String(str_value);
  if(!utf8str_value)
  {
    delete[] utf8varname;
    return E_INVALIDARG;
  }

  bool retbool = wrapped_interface->setVariableAsString(utf8varname, utf8str_value);
  delete[] utf8varname;
  delete[] utf8str_value;

  return retbool ? S_OK : E_FAIL;
}

 /* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CDynamicQueryContext::setVariableAsDocumentFromFile( 
    /* [in] */ BSTR varname,
    /* [in] */ BSTR file_path,
    /* [in] */ BSTR storeUri)
{
  char  *utf8varname;
  utf8varname = getUtf8String(varname);
  if(!utf8varname)
  {
    return E_INVALIDARG;
  }
  char  *utf8file_path;
  utf8file_path = getUtf8String(file_path);
  if(!utf8file_path)
  {
    delete[] utf8varname;
    return E_INVALIDARG;
  }
  char  *utf8storeUri;
  utf8storeUri = getUtf8String(storeUri);
  if(!utf8storeUri)
  {
    delete[] utf8varname;
    delete[] utf8file_path;
    return E_INVALIDARG;
  }
  
  bool retbool = wrapped_interface->setVariableAsDocumentFromFile(utf8varname, 
                                                                  utf8file_path,
                                                                  utf8storeUri);
  delete[] utf8varname;
  delete[] utf8file_path;
  delete[] utf8storeUri;

  return retbool ? S_OK : E_FAIL;
}

 /* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CDynamicQueryContext::deleteVariable( 
    /* [in] */ BSTR varname)
{
  char  *utf8varname;
  utf8varname = getUtf8String(varname);
  if(!utf8varname)
  {
    return E_INVALIDARG;
  }

  bool retbool = wrapped_interface->deleteVariable(utf8varname);

  return retbool ? S_OK : E_FAIL;
}

 /* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CDynamicQueryContext::deleteAllVariables( void)
{
  wrapped_interface->deleteAllVariables();

  return S_OK;
}

 /* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CDynamicQueryContext::setContextItemAsDocumentFromFile( 
    /* [in] */ BSTR file_path,
    /* [in] */ BSTR storeUri)
{
  char  *utf8file_path;
  utf8file_path = getUtf8String(file_path);
  if(!utf8file_path)
  {
    return E_INVALIDARG;
  }
  char  *utf8storeUri;
  utf8storeUri = getUtf8String(storeUri);
  if(!utf8storeUri)
  {
    delete[] utf8file_path;
    return E_INVALIDARG;
  }
  
  bool retbool = wrapped_interface->setContextItemAsDocumentFromFile(
                                                                  utf8file_path,
                                                                  utf8storeUri);
  delete[] utf8file_path;
  delete[] utf8storeUri;

  return retbool ? S_OK : E_FAIL;
}
