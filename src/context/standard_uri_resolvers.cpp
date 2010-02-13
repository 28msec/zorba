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
#include "context/standard_uri_resolvers.h"

#include <istream>
#include <fstream>
#include <sstream>

#include <zorba/util/file.h>
#include <zorba/external_module.h>

#include "util/web/web.h"

#include "store/api/item.h"
#include "store/api/collection.h"

#include "store/api/store.h"
#include "system/globalenv.h"
#include "zorbatypes/URI.h"
#include "zorbaerrors/error_manager.h"
#include "context/static_context.h"
#include "context/dynamic_loader.h"
#include "context/get_current_lib_suffix.h"

namespace zorba 
{

/*******************************************************************************

********************************************************************************/
store::Item_t
StandardDocumentURIResolver::resolve(
    const store::Item_t& aURI,
    static_context* aStaticContext,
    bool validate,
    bool tidying,
    const store::Item_t& tidyUserOpt)
{
  store::Item_t lResultDoc;

  if (aURI == NULL)
    return NULL;

  xqpStringStore_t lUriString = aURI->getStringValue();

  store::Store& lStore = GENV.getStore();

  xqpString lURIString = xqpString(&*aURI->getStringValue());
  URI lURI(lURIString.getStore(), validate);

  lResultDoc = lStore.getDocument(lURI.toString().getp());
  if (lResultDoc != NULL)
    return lResultDoc;

  if (lURI.get_scheme()->byteEqual("file", 4)) 
  {
#ifdef ZORBA_WITH_FILE_ACCESS // maybe we don't want to allow file access for security reasons (e.g. in a webapp)
    std::ifstream lInStream;
    xqpStringStore_t decodedURI;
    URI::decode_file_URI(lURI.toString().getp(), decodedURI);

    lInStream.open(decodedURI->c_str(), std::ios::in);
    if (lInStream.is_open() == false) 
    {
      ZORBA_ERROR_DESC_OSS(FODC0002, "File not found or accessible " << decodedURI);
    }

    if (tidying) 
    {
#ifdef ZORBA_WITH_TIDY
      std::stringstream out;
      xqp_string        diag;
      int res = tidy(lInStream, out, diag, (NULL != tidyUserOpt? tidyUserOpt->getStringValue()->c_str(): NULL));
      if( res < 0){
        ZORBA_ERROR_DESC_OSS(API0036_TIDY_ERROR, diag.c_str());
      }
      /*
        else if(res > 0){
        //raise a warning
      }*/

      lResultDoc = lStore.loadDocument(lURI.toString(), out);
#else
      ZORBA_ASSERT(!tidying);
#endif
    }
    else 
    {
      // parse exception must be caught by the caller
      lResultDoc = lStore.loadDocument(lURI.toString(), lInStream);
    }
    
    // result can't be null, because we already asked the store if he has it
    ZORBA_ASSERT(lResultDoc != NULL);
#else
    ZORBA_ERROR_DESC_OSS(FODC0002, "Unable to retrieve " << lURI.toString());
#endif
  } 
  else if (lURI.get_scheme()->byteEqual("http", 4) ||
           lURI.get_scheme()->byteEqual("https", 5)) 
  {
#ifdef ZORBA_WITH_REST
    // retrieve web file
    std::stringstream iss;
    int result = http_get(lURI.toString()->c_str(), iss);
    
    if (result != 0) 
      ZORBA_ERROR_DESC_OSS(FODC0002, "File not found or accessible. Could not make HTTP call");

    if (tidying)
    {
#ifdef ZORBA_WITH_TIDY
      std::stringstream out;
      xqp_string        diag;
      int res = tidy(iss, out, diag, (NULL != tidyUserOpt? tidyUserOpt->getStringValue()->c_str(): NULL));

      if( res < 0)
      {
        ZORBA_ERROR_DESC_OSS(API0036_TIDY_ERROR, diag.c_str());
      }
      /*
        else if(res > 0){
        //raise a warning
      }*/

      lResultDoc = lStore.loadDocument(lURI.toString(), out);
#else
      ZORBA_ASSERT(!tidying);
#endif
    }
    else 
    {
      // parse exception must be caught by the caller
      lResultDoc = lStore.loadDocument(lURI.toString(), iss);
    }

    // result can't be null, because we already asked the store if he has it
    ZORBA_ASSERT(lResultDoc != NULL);
#else
    ZORBA_ERROR_DESC_OSS(FODC0002,
                         "Can't retrieve the http:// or https:// URI "
                         << lURI.toString());
#endif
    } 
  else
  {
    xqpString   q;
#ifdef WIN32
    if(lURI.get_scheme().size() == 1)
    {
      q = "Did you miss the \"file:///\" ahead of the absolute path?";
    }
#endif
    ZORBA_ERROR_DESC_OSS(FODC0002,
                         "Unknown URI scheme \"" << lURI.get_scheme() << "\" in URI "
                         << lURI.toString()
                         << " . " << q);
  }
  if (lResultDoc == NULL) 
  {
    ZORBA_ERROR_DESC_OSS(FODC0002,
                         "Couldn't retrieve document with URI "
                         << lURI.toString());
  }

  return lResultDoc;
}


/*******************************************************************************

********************************************************************************/
store::Collection_t 
StandardCollectionURIResolver::resolve(
    const store::Item_t& aURI,
    static_context* aStaticContext)
{
  store::Collection_t lResultCol;

  xqpStringStore_t lUriString = aURI->getStringValue();

  store::Store& lStore = GENV.getStore();

  // check and eventually resolve URI
  // throw FODC0004 if the URI is not valid
  URI lURI;

  try 
  {
    lURI = URI(&*lUriString);
    if (!lURI.is_absolute()) 
    {
      URI lBaseURI(aStaticContext->final_baseuri().getStore());
      lURI = URI(lBaseURI, &*lUriString); 
    }
  }
  catch (error::ZorbaError& e) 
  {
    ZORBA_ERROR_DESC_OSS(FODC0004,
                         "URI " << lUriString
                         << " is not valid or could not be resolved. Reason: " 
                         << e.theDescription);
  }

  // try to get it from the store again
  lResultCol = lStore.getUriCollection(lURI.toString());
  return lResultCol;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  StandardSchemaURIResolver                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
std::string
StandardSchemaURIResolver::resolve(
    const store::Item_t& aURI,
    static_context* aStaticContext,
    std::vector<store::Item_t>& aAtList,
    xqpStringStore* aFileUri)
{
  // 1. check using module paths => return if good stream is found
  std::vector<std::string> lModulePaths;
  aStaticContext->get_full_module_paths(lModulePaths);

  if (lModulePaths.size() != 0) 
  {
    std::string filepath;
    filepath = checkSchemaPath(lModulePaths, aURI, 0);
    if (filepath != "") 
    {
      xqpStringStore_t filepath2 = new xqpStringStore(filepath);
      xqpStringStore_t url;
      URI::encode_file_URI(filepath2, url);
      return url->str();
    }
  }

  // 2. check the user's resolvers
  std::vector<InternalSchemaURIResolver*> lResolvers;
  aStaticContext->get_schema_uri_resolvers(lResolvers);
  for (std::vector<InternalSchemaURIResolver*>::const_iterator lIter =
      lResolvers.begin(); lIter != lResolvers.end(); ++lIter) 
  {
    std::string lResult = (*lIter)->resolve(aURI,
                                            aStaticContext,
                                            aAtList,
                                            aFileUri);
    if (lResult != "") 
    {
      return lResult;
    }
  }

  // 3. treat the URI as URL and check if a file is in the
  // filesystem or on the web
  // TODO register other interal resolvers for each of the tasks
  xqpStringStore_t  lResolvedURI;
  if (aAtList.size() > 0) 
  {
    lResolvedURI = aAtList[0]->getStringValue();
  }
  else 
  {
    lResolvedURI = aURI->getStringValue();
  }

  if (lResolvedURI->byteStartsWith("file://", 7)) 
  {
    // maybe we don't want to allow file access for security reasons (e.g. in a webapp)
#ifdef ZORBA_WITH_FILE_ACCESS
    xqpStringStore_t filepath;
    URI::decode_file_URI(lResolvedURI, filepath);

    std::auto_ptr<std::ifstream> lSchemaFile(new std::ifstream(filepath->c_str()));
 
    if (lSchemaFile->good()) 
    {
      return lResolvedURI->c_str();
    }
    else
    {
      ZORBA_ERROR_PARAM(XQST0059, lResolvedURI, aURI->getStringValue());
    }
#endif
  }
  return aURI->getStringValue()->c_str();
}


/*******************************************************************************

********************************************************************************/
std::string StandardSchemaURIResolver::checkSchemaPath(
    const std::vector<std::string>& aSchemaPath,
    const store::Item_t& aUri,
    xqpStringStore* aResultFile)
{
  URI lURI(aUri->getStringValueP());
  // compute path notation of the uri with a .xq at the end
  // TODO: we might extend that to other file exentsions
  xqpStringStore_t lPathNotation = lURI.toPathNotation();
  if (!lPathNotation->byteEndsWith(".xsd", 4)) 
  {
    lPathNotation = lPathNotation->append(".xsd");
  }

  // check all module path in the according order
  // the higher in the hirarchy the static context is
  // the higher the priority of its module paths
  for (std::vector<std::string>::const_iterator lIter = aSchemaPath.begin();
       lIter != aSchemaPath.end(); ++lIter) 
  {
    xqpString lPotentialModuleFile = (*lIter) + lPathNotation->str();
    std::auto_ptr<std::istream> modfile(
                                        new std::ifstream(lPotentialModuleFile.c_str()));
    if (modfile->good())
    {
      if (aResultFile)
      {
        *aResultFile = *(lPotentialModuleFile.getStore());
      }
      return lPotentialModuleFile.c_str();
    } 
  }
  return "";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  StandardModuleURIResolver                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void StandardModuleURIResolver::resolveTargetNamespace(
    const std::string& nsURI,
    static_context& sctx,
    std::vector<std::string>& compURIs)
{
  // check the user's resolvers
  std::vector<InternalModuleURIResolver*> resolvers;
  sctx.get_module_uri_resolvers(resolvers);

  std::vector<InternalModuleURIResolver*>::const_iterator ite;
  for (ite = resolvers.begin(); ite != resolvers.end(); ++ite)
  {
    (*ite)->resolveTargetNamespace(nsURI, sctx, compURIs);

    if (!compURIs.empty())
      return;
  }

  // If there were no user resolvers, or if none of them new anuthing about the
  // given target namespace, assume that the module consists of a single component
  // whose URI is the same as the target namespace.
  compURIs.push_back(nsURI);
}


/*******************************************************************************
  Resolve a logical URI (i.e. target ns or location hint) to an input stream.
  Resolving is done according to the following rules:

  (1) all module paths are searched for a file with path and name of the path
      notation of the uri
  (2) a (potential) user's resolver is asked
  (3) the URI is treated as an URL

  Besides returning an input stream, the function also returns the URL of the
  file that the given URI was resolved to.
********************************************************************************/
std::istream* StandardModuleURIResolver::resolve(
    const std::string& uri,
    static_context& sctx,
    std::string& url)
{
  // 1. check using module paths => return if good stream is found
  std::vector<std::string> lModulePaths;
  sctx.get_full_module_paths(lModulePaths);

  std::auto_ptr<std::istream> modfile(0); // result file

  if (lModulePaths.size() != 0) 
  {
    modfile.reset(checkModulePath(lModulePaths, uri, url));
    if (modfile.get() != 0)  
    {
      assert(modfile->good());
      return modfile.release();
    }
  }

  // 2. check the user's resolvers
  std::vector<InternalModuleURIResolver*> lResolvers;
  sctx.get_module_uri_resolvers(lResolvers);

  if (modfile.get() == 0) 
  {
    std::vector<InternalModuleURIResolver*>::const_iterator ite;
    for (ite = lResolvers.begin(); ite != lResolvers.end(); ++ite)
    {
      modfile.reset((*ite)->resolve(uri, sctx, url));
      if (modfile.get()) 
      {
        assert(modfile->good());
        return modfile.release();
      }
    }
  }

  // 3. treat the URI as URL and check if a file is in the filesystem or on the web
  // TODO register other interal resolvers for each of the tasks
  url = uri;

  if (url.compare(0, 7, "file://") == 0) 
  {
    // maybe we don't want to allow file access for security reasons (e.g. in a webapp)
#ifdef ZORBA_WITH_FILE_ACCESS
    xqpStringStore_t tmp(new xqpStringStore(uri));
    xqpStringStore_t filepath;
    URI::decode_file_URI(tmp, filepath);
    modfile.reset(new std::ifstream(filepath->c_str()));
#endif
  }
  else
  {
    std::auto_ptr<std::stringstream> code(new std::stringstream());
    if (http_get(url.c_str(), *code) != 0) 
    {
      return NULL;
    }
    modfile.reset(code.release());
  }

  // we transfer ownership to the caller
  return modfile.release();
}


/*******************************************************************************

********************************************************************************/
std::istream* StandardModuleURIResolver::checkModulePath(
    const std::vector<std::string>& modulePaths,
    const std::string& uri,
    std::string& fileURL)
{
  xqpStringStore_t tmp = new xqpStringStore(uri);
  URI lURI(tmp.getp());

  // compute path notation of the uri with a .xq at the end
  // TODO: we might extend that to other file exentsions
  xqpStringStore_t lPathNotation = lURI.toPathNotation();
  if (!lPathNotation->byteEndsWith(".xq", 3)) 
  {
    lPathNotation = lPathNotation->append(".xq");
  }

  // check all module path in the according order
  // the higher in the hirarchy the static context is
  // the higher the priority of its module paths
  for (std::vector<std::string>::const_iterator ite = modulePaths.begin();
      ite != modulePaths.end(); ++ite)
  {
    fileURL = (*ite) + lPathNotation->c_str();
    std::auto_ptr<std::istream> modfile(new std::ifstream(fileURL.c_str()));
    if (modfile->good())
    {
      return modfile.release();
    } 
  }
  return 0;
}


/*******************************************************************************

********************************************************************************/
ExternalModule* StandardModuleURIResolver::getExternalModule(
    const std::string& fileURL,
    static_context& sctx)
{
  std::vector<std::string> lModulePaths;
  sctx.get_full_module_paths(lModulePaths);

  std::auto_ptr<std::istream> modfile(0); // result file

  if (lModulePaths.size() != 0) 
  {
    xqpStringStore_t tmp = new xqpStringStore(fileURL);
    URI lURI(tmp);

    std::string lLibraryName = computeLibraryName(lURI);

    // check all module path in the according order
    // the higher in the hirarchy the static context is
    // the higher the priority of its module paths
    for (std::vector<std::string>::const_iterator ite = lModulePaths.begin();
        ite != lModulePaths.end(); ++ite) 
    {
      std::string potentialModuleFile = (*ite);
      potentialModuleFile += lLibraryName;
      std::auto_ptr<std::istream> modfile(new std::ifstream(potentialModuleFile.c_str()));
      if (modfile->good()) 
      {
        ExternalModule* lModule = DynamicLoader::getInstance()->
                                  getModule(potentialModuleFile);
        if (lModule) 
        {
          if (!lModule->getURI().equals(fileURL.c_str())) 
          {
            ZORBA_ERROR_DESC_OSS(XQP0028_FUNCTION_IMPL_NOT_FOUND,
                                 "The module loaded from " << potentialModuleFile
                                 << "doesn't provide the required target namespace "
                                 << "(" << lURI.toString() << ").");
          }
        }
        return lModule;
      } 
    }
  }
  return 0;
}


/*******************************************************************************

********************************************************************************/
std::string StandardModuleURIResolver::computeLibraryName(const URI& aURI)
{
  xqpStringStore_t lPathNotation = aURI.toPathNotation();

  // get the module file name
  std::string lRelativePath(lPathNotation->c_str());
  size_t lIndexOfLastSlash = lRelativePath.find_last_of("/");

  std::string lFileName = "";
  std::string lBranchPath = "";
  
  // is the URI ends in '/'
  if (lIndexOfLastSlash == lRelativePath.length()) 
  {
    lBranchPath = lRelativePath;
  } 
  else 
  {
    // is '/' is not found
    if (lIndexOfLastSlash == std::string::npos)
    {
      lFileName = lRelativePath;
    }
    else
    {
      lFileName = lRelativePath.substr(lIndexOfLastSlash + 1);
      lBranchPath = lRelativePath.substr(0, lIndexOfLastSlash + 1);
    }

    // remove .xq from the end of the file if present
    // bugfix: find_last_of didn't do the right thing
    size_t lIndexOfXQ = lFileName.find(".xq");
    if (lIndexOfXQ == lFileName.size() - 3) 
    {
      lFileName.erase(lIndexOfXQ );
    }
  }

  // create the name of the file
  // win32: module.dll
  // apple: libmodule.dylib
  // other unix: libmodule.so
  std::ostringstream lLibraryName;
  lLibraryName << lBranchPath
#ifdef WIN32
      << lFileName << get_current_lib_suffix() << ".dll";
#else
#ifdef APPLE
      << "lib" << lFileName << get_current_lib_suffix() << ".dylib";
#else 
      << "lib" << lFileName << get_current_lib_suffix() << ".so";
#endif
#endif

  return lLibraryName.str();
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  StandardLibraryModuleURIResolver                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void StandardLibraryModuleURIResolver::resolveTargetNamespace(
    const std::string& nsURI,
    static_context& sctx,
    std::vector<std::string>& compURIs)
{
  compURIs.push_back(nsURI);
}


/*******************************************************************************

********************************************************************************/
std::istream* 
StandardLibraryModuleURIResolver::resolve(
    const std::string& uri,
    static_context& sctx,
    std::string& url)
{
  assert(uri == theLibraryModuleNamespace);
  assert(theStream.good());

  url = theFileName;

  std::auto_ptr<std::istream> modfile(new std::istream(theStream.rdbuf()));

  // we transfer ownership to the caller
  return modfile.release();
}

} /* namespace zorba */
