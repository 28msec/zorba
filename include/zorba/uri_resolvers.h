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
#include <zorba/zorba_string.h>

/**
 * @file uri_resolvers.h
 * @brief This header file defines all uri resolvers.
 *
 * %Zorba has a very flexible uri resolver mechanism.
 *
 * QQQ Complete documentation
 * QQQ file should be renamed uri_resolver.h
 */

namespace zorba {
  
class HttpStream;

/**
 * @brief The class representing the result of URL resolution.
 *
 * This class is the final output of the URI resolution process. All
 * URL resolvers return results using subclasses of this class.
 */
class ZORBA_DLL_PUBLIC Resource
{
  public:
  /**
   * @brief enum listing the types of entities that may be represented
   * by URIs, and hence may be looked up via the URI resolution
   * mechanism.
   */
  // QQQ Hmm... having the enum values for Kind and EntityType all end
  // up as Resource::FOO is ugly.
  enum EntityType {
    SCHEMA,
    MODULE,
    THESAURUS,
    STOP_WORDS
  };

  /**
   * @brief enum listing the concrete subclasses of Resource that
   * exist (so far only one).
   */
  enum Kind {
    STREAM
  };

  /**
   * @brief Return the Kind of Resource this is, ie., which concrete
   * subclass this object is actually an instance of.  (This is to
   * avoid the requirement of RTTI.)
   */
  Kind getKind() throw ();

  virtual ~Resource() = 0;

  protected:

  Resource(Kind aKind);

  private:

  Kind theKind;
};

/**
 * @ brief Concrete Resource subclass representing access to an entity
 * via a stream.
 */
class ZORBA_DLL_PUBLIC StreamResource : public Resource
{
public:

  /**
   * @brief Public constructor from istream.
   *
   * Due to the auto_ptr<>, the Resource object will take memory
   * ownership of the istream, and Zorba will free it when it is no
   * longer required.
   *
   * Please note that, while istreams are normally stack objects (ie,
   * local variables, not allocated with "new"), you must not
   * construct a Resource with a pointer to a stack object! Always
   * create your istreams with "new" before passing to this constructor.
   */
  StreamResource(std::auto_ptr<std::istream> aStream);
  
  /**
   * @brief Retrieve the istream associated with this Resource, and
   * take memory ownership of it.
   */
  std::auto_ptr<std::istream> getStream() throw ();

private:

  std::auto_ptr<std::istream> theStream;
};

/**
 * @brief Interface for URL resolving.
 *
 * Subclass this to provide a URL resolver to the method
 * StaticContext::addURLResolver().
 */
class ZORBA_DLL_PUBLIC URLResolver
{
  public:

  URLResolver();
  virtual ~URLResolver();

  /**
   * @brief Transforms an input URL into a Resource.
   *
   * The "aEntityType" parameter informs the URLResolver what type of
   * entity is being referenced by the URL. URLResolvers may choose to
   * make use of this information to alter their behaviour.
   * URLResolvers must ensure that they return a concrete subclass of
   * Resource which is compatible with the entity type being resolved.
   *
   * Implementers of this method should do nothing if they do not know
   * how to resolve the URL.  They should create and return a Resource
   * if they were successfully able to resolve the URL.
   *
   * Implementers may throw any exception if they believe that they
   * are canonical for the URL and yet had some error arise attempting
   * to resolve it.  Note that because there may be several possible
   * URLs attempted, Zorba will catch any exceptions thrown and
   * continue until all all URLs have failed. Zorba will not re-throw
   * any of these exceptions directly. However, if the exception
   * thrown extends std::exception, Zorba will make efforts to ensure
   * that its error message is included in the exception which is
   * ultimately thrown. For any other thrown objects, only the fact
   * that an exception occurred will be remembered; the exception
   * object itself will be discarded.
   *
   * In any case, if they create a Resource, Zorba will take memory
   * ownership of the Resource and delete it when it is no longer
   * needed.
   */
  virtual Resource* resolveURL(const zorba::String& aUrl,
    Resource::EntityType aEntityType) = 0;
};

/**
 * @brief Interface for URI mapping.
 *
 * Subclass this to provide a URI mapper to the method
 * StaticContext::addURIMapper().
 */
class ZORBA_DLL_PUBLIC URIMapper
{
  public:

  URIMapper();
  virtual ~URIMapper();

  /**
   * @brief Transform an input URI into a set of output URIs.
   *
   * The "aEntityType" parameter informs the URIMapper what type of
   * entity is being referenced by URI. URIMappers may choose to make
   * use of this information to alter their behaviour.
   *
   * Implementers of this method should provide output URIs by adding
   * them to the oUris output parameter, using the push_back()
   * method. They should not otherwise view or manipulate this vector.
   *
   * If a URIMapper does not wish to provide any output URIs for the
   * given input URI, they should simply do nothing and return. In
   * this case, Zorba will continue with the original, unmapped URI.
   */
  virtual void mapURI(const zorba::String aUri,
    Resource::EntityType aEntityType, std::vector<zorba::String>& oUris) 
    throw () = 0;

  /**
   * @brief enum defining legal return values for mapperKind().
   */
  enum Kind {
    COMPONENT,
    CANDIDATE
  };

  /**
   * @brief Declare whether this is a "component" or "candidate" URI
   * mapper.
   *
   * Zorba supports two different kinds of URI mapping. The first,
   * "component URI mapping", is to allow mapping from an input URI to
   * a set of URIs which, taken together, comprise the entire entity
   * to be resolved. This is currently only supported for module
   * import, where it can be used to load a module which is physically
   * stored in multiple library module files.
   *
   * "Candidate URI mapping" is to allow mapping from an input URI to
   * a set or URIs which are *potential* identifiers of the entity
   * being resolved. Each of these URIs will be treated to any
   * subsequent URI mappers, and then treated as URLs and passed in
   * turn to all registered URLResolvers. This type of URI mapping is
   * supported for all uses of URIs in Zorba. It can be used for
   * example to redirect http: URIs to locally-cached file: URLs, or
   * to provide several alternative locations for a given resource.
   *
   * If you do not override this method, the default is "candidate".
   */
  virtual Kind mapperKind() throw () { return CANDIDATE; }

  /**
   * @brief Constant indicating that Zorba should deny access to the
   * given URI.
   *
   * If any kind of URIMapper returns this value at any point in the
   * vector of URIs, Zorba will cause the resolution of this URI to be
   * denied with an error.  This can be used, for example, to suppress
   * importing particular modules by URI.
   */
  const zorba::String DENY_ACCESS;
};


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

#ifndef ZORBA_NO_FULL_TEXT
/**
  * @brief The result of a FullTextURIResolver.
  *
  */
class ZORBA_DLL_PUBLIC FullTextURIResolverResult : public URIResolverResult 
{
 public:

  /**
    */
  virtual String
  getResolvedFullText() const = 0;
};
  
/**
  * @brief A thesaurus uri resolver.
  *
  * Maps an arbitrary thesaurus ID (i.e. a URI) to some string that may be
  * either a URI or a special string like "##default".
  */
class ZORBA_DLL_PUBLIC FullTextURIResolver
{
 public:
  virtual ~FullTextURIResolver() {}

  /**
    * @brief Resolves a thesaurus uri.
    *
    */
  virtual std::auto_ptr<FullTextURIResolverResult>
  resolve(const Item& aURI, StaticContext* aStaticContext) = 0;
};
#endif /* ZORBA_NO_FULL_TEXT */

} /* namespace zorba */

#endif
/* vim:set et sw=2 ts=2: */
