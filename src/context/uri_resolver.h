/*
 * Copyright 2006-2010 The FLWOR Foundation.
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
#pragma once
#ifndef ZORBA_URI_RESOLVER_H
#define ZORBA_URI_RESOLVER_H


/**
 * This file contains the implementation of the Zorba URI resolver.
 * This comprises the URLResolver and URIMapper interfaces, and the
 * Resource class hierarchy.
 *
 * Zorba has two built-in URLResolver implementations and two built-in
 * URIResolver implementations; those are implemented in
 * default_url_resolvers.h/cpp and default_uri_mappers.h/cpp.
 */

#include <memory>
#include <istream>
#include <zorbatypes/zstring.h>
#include <util/auto_vector.h>
#include <util/http_util.h>
#include <store/api/shared_types.h>

namespace zorba {

// Forward declaration
class static_context;

namespace impl {

/**
 * @brief The class representing the result of URL resolution.
 *
 * This class is the final output of the URI resolution process. All
 * URL resolvers return results using subclasses of this class.
 */
class Resource
{
  public:
  /**
   * @brief enum listing the types of entities that may be represented
   * by URIs, and hence may be looked up via the URI resolution
   * mechanism.
   */
  enum EntityType {
    SCHEMA,
    MODULE,
    THESAURUS,
    STOP_WORDS,
    COLLECTION,
    DOCUMENT,
    SOME_CONTENT
  };

  /**
   * @brief enum listing the concrete subclasses of Resource that
   * exist.
   */
  enum Kind {
    STREAM,
    COLLECTION_T
  };

  /**
   * @brief Return the Kind of Resource this is, ie., which concrete
   * subclass this object is actually an instance of.  (This is to
   * avoid the requirement of RTTI.)
   */
  Kind getKind() throw ();

  /**
   * @brief Return the URL used to load this Resource.
   */
  zstring getUrl() throw () { return theUrl; }

  virtual ~Resource() = 0;

  protected:

  Resource(Kind aKind);

  private:

  /**
   * Used by static_context to populate the URL.
   */
  friend class zorba::static_context;
  void setUrl(zstring aUrl) { theUrl = aUrl; }

  Kind theKind;
  zstring theUrl;
};

/**
 * @ brief Concrete Resource subclass representing access to an entity
 * via a stream.
 */
class StreamResource : public Resource
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
   *
   * @param aStreamUrl Normally this StreamResource represents the
   * contents of the URL which was used to resolve it. However, there
   * are certain unusual circumstances where a URLResolver may wish to
   * return a stream over some other URL than the one passed to it. In
   * that case, the URLResolver may pass the true URL here.
   */
  StreamResource(std::auto_ptr<std::istream> aStream, zstring aStreamUrl = "");
  
  StreamResource(HttpStream* aHttpStream, const zstring& aUrl = "");
  
  virtual ~StreamResource();

  /**
   * @brief Retrieve the istream associated with this Resource.
   */
  std::auto_ptr<std::istream> getStream() throw ();

  /**
   * @brief Retrieve the URL that the stream was actually loaded from.
   * By default this will be the same as getUrl().
   */
  zstring getStreamUrl() throw ();

private:

  std::auto_ptr<std::istream> theStream;
  zstring theStreamUrl;
  HttpStream* theHttpStream;
};

/**
 */
class CollectionResource : public Resource
{
  public:
  /**
   */
  CollectionResource(const store::Collection_t& aCollection);

  /**
   */
  store::Collection_t
  getCollection() throw ();

  private:
  store::Collection_t theCollection;
};

/**
 * @brief Interface for URL resolving.
 *
 * Subclass this to provide a URL resolver to the method
 * StaticContext::addURLResolver().
 */
class URLResolver
{
  public:

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
  virtual Resource* resolveURL(zstring const& aUrl,
    Resource::EntityType aEntityType) = 0;
};

/**
 * @brief Interface for URI mapping.
 */
class URIMapper
{
  public:

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
   * given input URI, they should simply do nothing and return.
   */
  virtual void mapURI(zstring const& aUri,
    Resource::EntityType aEntityType, static_context const& aSctx,
    std::vector<zstring>& oUris)
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
  static const zstring DENY_ACCESS;
};

} /* namespace zorba::impl */

} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
