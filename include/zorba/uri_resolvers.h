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
#ifndef ZORBA_URI_RESOLVERS_API_H
#define ZORBA_URI_RESOLVERS_API_H

#include <istream>
#include <vector>
#include <memory>

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>
#include <zorba/zorbastring.h>

/**
  * @file uri_resolvers.h
  * @brief This header file defines all uri resolvers.
  *
  * %Zorba has a very flexible uri resolver mechanism. %Zorba has three ways to
  * map a namespace to its physical location:
  *
  * 1. The system uri resolvers tries to resolves the physical location of a
  *  library module according to its namespace URI. This approach is equivalent
  *  to the one used in Java with CLASSPATH.
  *
  * 2. User-defined URI Resolvers: %Zorba has hooks to allow user-defined URI
  *  resolvers to be used for resolving the module source. This process of
  *  declaring and registering new URI resolvers to the static context is done
  *  using %Zorba C++ API. User-defined URI resolvers are similar to user-defined
  *  class loaders in the Java platform.
  *
  * 3. Literal URI resolving: %Zorba treats the module namespace URI has a
  *  literal URL of the module physical location.
  *
  * To implement the second possibility, a user has to implement uri resolvers.
  * The user can subclass as many uri resolvers as she wants to and she can
  * also register as many uri resolvers in the static context as she wants to.
  * If she registeres more than one uri resolver, %Zorba will try to resolve a
  * namespace with the one resolver after the other in the order the user
  * registered them. But there can be at most one DocumentURIResolver and also
  * most one CollectionURIResolver.
  *
  * To add a uri resolver, the corresponding methods in the static context.
  * Please see the documentation of the corresponding class or the StaticContext
  * to know which method you have to use, to register or remove a uri resolver.
  */

namespace zorba {

/**
  * @brief The base class for results of the URI resolvers.
  *
  * This class is the base class for all classes representing a result from
  * a uri resolver. The user should not subclass this class herself, but use
  * a subclass for the specific uri resolver she wants to implement.
  *
  * This class is used for both: to return a result of a successful resolve
  * call and to report errors to %Zorba.
  */
class ZORBA_DLL_PUBLIC URIResolverResult
{
 public:
  /**
    * @brief Erros a uri resolver can return.
    *
    * These are the available error codes a uri resolver can return.
    */
  enum ErrorCode
  {
    UR_NOERROR,
    /**
      * documents and collections errors
      */
    UR_FODC0002,
    UR_FODC0003,
    UR_FODC0004,
    UR_FODC0005,
    /**
      * module errors
      */
    UR_XQST0088,
    UR_XQST0046,
    UR_XQST0059,
    /**
      * schemas errors
      */
    UR_XQST0057
  };

  /**
    * @brief Default constructor.
    *
    * The default constructor initializes the error code of the result to
    * UR_NOERROR.
    */
  URIResolverResult() : theErrorCode(UR_NOERROR) {}

  virtual ~URIResolverResult() {}

  /**
    * @brief Get the error from this result.
    *
    * Whenever %Zorba resolves a namespace, it will first consult this function
    * for errors.
    *
    * @return The error code of ths result.
    */
  ErrorCode
  getError() const { return theErrorCode; }

  /**
    * @brief Sets the error code of the result.
    *
    * Sets the error code for this result. By default, the error code will be
    * UR_NOERROR. If the namespace could not be resolved, the code has to be
    * set to something else.
    *
    * @param aErrorCode The error code which should been set for this result.
    */
  void
  setError(const ErrorCode& aErrorCode) { theErrorCode = aErrorCode; }

  /**
    * @brief Sets the error description for the result.
    *
    * In case, the namespace resolving went wrong, an error description can be
    * set as a hint to the user. If URIResolverResult::getError returns
    * UR_NOERROR, setting the description will have no effect.
    *
    * @param aDescription The error description for this result.
    */
  void
  setErrorDescription(const String& aDescription) { theDescription = aDescription; }

  /**
    * @brief Gets the error description.
    *
    * This method will return the error description of this result.
    */
  String
  getErrorDescription() { return theDescription; }

 protected:
  /**
    * @brief The error code for this result.
    *
    * This variable saves the error code of this result. By default (after
    * initialization with the default constructor), the value of this variable
    * will be UR_NOERROR. If the uri resolver could not find a result, the user
    * has to change this value (either in the subclass or with
    * URIResolverResult::setError).
    */
  ErrorCode theErrorCode;
  /**
    * @brief The error description.
    *
    * The result also can set a description for the error. This description will
    * be shown to the user. Set this value either in a subclass or with
    * URIResolverResult::setErrorDescription.
    */
  String    theDescription;
};

/**
  * @brief The result from a DocumentURIResolver.
  *
  * This class has to be subclassed by an implementer of DocumentURIResolver.
  * The instance of this class serves as a container for either an error code
  * or desciption, or the resolved document.
  *
  * @sa URIResolverResult
  */
class ZORBA_DLL_PUBLIC DocumentURIResolverResult : public URIResolverResult
{
public:
  virtual ~DocumentURIResolverResult() {}

  /**
    * @brief Returns an item to the document.
    *
    * This method has to be implemented by the user and should return a
    * document as an Item if there was no error.
    *
    * @sa Item
    */
  virtual Item
  getDocument() const = 0;
};

/**
  * @brief A document uri resolver.
  *
  * If you want to give %Zorba hints, where to resolve documents by uri, this
  * class can be subclassed. Before subclassing this class, one should make sure
  * that she understands the resolving mechanisms from %Zorba, since in most
  * cases the default behaviour should be sufficient.
  *
  * To set the document uri resolver in the static context, use
  * StaticContext::setDocumentURIResolver. There can only be one document uri
  * resolver in the static context.
  */
class ZORBA_DLL_PUBLIC DocumentURIResolver 
{
 public:
  virtual ~DocumentURIResolver() {}

  /**
    * @brief Method which gets called to resolve a document uri.
    *
    * This method gets called, whenever %Zorba tries to resolve a document uri.
    *
    * @param aUri The URI which should be resolved.
    * @param aStaticContext The static context, the query runs with.
    * @param aXmlDataManager An XmlDataManager, which can be used to load
    *  documents.
    * @param validateUri Tells the resolver, if it should validate the uri.
    * @param tidying If this is set to true, the document could be HTML and
    *  should be tidied up before loaded. If tidy is not supported, the module
    *  should return an error code.
    * @param replaceDoc Inicates, wheter the document should replace the
    *   document with the same namespace, if it was loaded before.
    * @param aTidyUserOpt If tidying is set to true, this contains the tidy
    *   options (or NULL, if some default options should be used).
    *
    * @returns An instance of DocumentURIResolverResult, which contains either
    *  the document or an error code and an optional error description.
    */
  virtual std::auto_ptr<DocumentURIResolverResult>
  resolve(const Item& aURI,
          StaticContext* aStaticContext,
          XmlDataManager* aXmlDataManager,
          bool validateUri,
          bool tidying,
          bool replaceDoc = false,
          const Item& aTidyUserOpt = NULL) = 0;
};

/**
  * @brief The result from a CollectionURIResolver.
  *
  * This class has to be subclassed by an implementer of CollectionURIResolver.
  * The instance of this class serves as a container for either an error code
  * and desciption, or the resolved collection.
  *
  * @sa URIResolverResult
  */
class ZORBA_DLL_PUBLIC CollectionURIResolverResult : public URIResolverResult
{
 public:
  virtual ~CollectionURIResolverResult() {}

  /**
    * @brief Returns an item to the collection.
    *
    * This method has to be implemented by the user and should return a
    * collection if there was no error.
    *
    * @sa Collection
    */
  virtual Collection_t
  getCollection() const = 0;
};

/**
  * @brief A document uri resolver.
  *
  * If you want to give %Zorba hints, where to resolve collections by uri, this
  * class can be subclassed. Before subclassing this class, one should make sure
  * that she understands the resolving mechanisms from %Zorba, since in most
  * cases the default behaviour should be sufficient.
  *
  * To set the collections uri resolver in the static context, use
  * StaticContext::setCollectionURIResolver. There can only be one collection
  * uri resolver in the static context.
  */
class ZORBA_DLL_PUBLIC CollectionURIResolver
{
 public:
  virtual ~CollectionURIResolver() {}

  /**
    * @brief Resolves a collection by uri.
    *
    * This method gets called, when %Zorba tries to resolve a collection uri.
    * It should return either a collection or an error.
    *
    * @param aURI The URI to resolve.
    * @param aStaticContext The StaticContext the query runs in.
    * @param aXmlDataManager An instance of XmlDataManager which can be used
    *  to load collections.
    *
    * @returns The CollectionURIResolverResult, which contains either the found
    *  collection or an error code (with optional error description).
    */
  virtual std::auto_ptr<CollectionURIResolverResult>
  resolve(const Item& aURI,
          StaticContext* aStaticContext,
          XmlDataManager* aXmlDataManager) = 0;
};
  
/**
  * @brief The result from a SchemaURIResolver.
  *
  * This class has to be subclassed by an implementer of SchemaURIResolver.
  * The instance of this class serves as a container for either an error code
  * and desciption, or the resolved schema.
  *
  * @sa URIResolverResult
  */
class ZORBA_DLL_PUBLIC SchemaURIResolverResult : public URIResolverResult 
{
 public:
  virtual ~SchemaURIResolverResult() {}

  /**
    * @brief Returns the schema.
    *
    * This method has to be implemented by the user and should return a
    * schema if there was no error.
    */
  virtual String
  getSchema() const = 0;
};

/**
  * @brief A schema uri resolver.
  *
  * If you want to give %Zorba hints, where to resolve schemas by uri, this
  * class can be subclassed. Before subclassing this class, one should make sure
  * that she understands the resolving mechanisms from %Zorba, since in most
  * cases the default behaviour should be sufficient.
  *
  * To add a schema uri resolver to the static context, use
  * StaticContext::addSchemaURIResolver. There can only be as many schema uri
  * resolvers as desired in the static context and %Zorba will try to resolve
  * schemas with all of them in the order they were added to the static context.
  */
class ZORBA_DLL_PUBLIC SchemaURIResolver
{
 public:
  virtual ~SchemaURIResolver() {}

  /**
    * @brief Resolves a schema uri.
    *
    * This method gets called, when %Zorba tries to resolve a schema uri.
    *
    * @param aUri The uri of the schema which should be resolved.
    * @param aStaticContext The current static context.
    * @param aAtList The location hints given in the query.
    * @param aFileUri The file uri, if the resolve was successful. The user can
    *  set this either to the URI or return a string with the whole schema in
    *  the SchemaURIResolverResult. If the user provides a url, %Zorba will
    *  be able to stream the result.
    *
    * @returns A SchemaURIResolverResult with an error code or (if aFileUri is
    *  not set and the resolving was successful) a string with the schema.
    */
  virtual std::auto_ptr<SchemaURIResolverResult>
  resolve(const Item& aURI,
          StaticContext* aStaticContext,
          std::vector<Item>& aAtList,
          String* aFileUri = 0) = 0;
};

#ifndef ZORBA_NO_FULL_TEXT
/**
  * @brief The result of a ThesaurusURIResolver.
  *
  */
class ZORBA_DLL_PUBLIC ThesaurusURIResolverResult : public URIResolverResult 
{
 public:
  virtual ~ThesaurusURIResolverResult() {}

  /**
    */
  virtual String
  getResolvedThesaurus() const = 0;
};
  
/**
  * @brief A thesaurus uri resolver.
  *
  * Maps an arbitrary thesaurus ID (i.e. a URI) to some string that may be either a
  * URI or a special string like "##default".
  */
class ZORBA_DLL_PUBLIC ThesaurusURIResolver
{
 public:
  virtual ~ThesaurusURIResolver() {}

  /**
    * @brief Resolves a thesaurus uri.
    *
    */
  virtual std::auto_ptr<ThesaurusURIResolverResult>
  resolve(const Item& aURI, StaticContext* aStaticContext) = 0;
};
#endif

class ZORBA_DLL_PUBLIC ModuleURIResolverResult : public URIResolverResult
{
 public:
  virtual ~ModuleURIResolverResult() {}
  
  virtual std::istream* getModuleStream() const = 0;

  virtual void getModuleURL(std::string&) const = 0;

  virtual void getComponentURIs(std::vector<std::string>&) const = 0;
};


class ZORBA_DLL_PUBLIC ModuleURIResolver
{
 public:
  virtual ~ModuleURIResolver() {}

  virtual std::auto_ptr<ModuleURIResolverResult> resolveTargetNamespace(
        const String& aTargetNamespaceURI,
        const StaticContext& aStaticContext) = 0;

  virtual std::auto_ptr<ModuleURIResolverResult> resolve(
        const String& aURI,
        const StaticContext& aStaticContext) = 0;
};


} /* namespace zorba */

#endif
