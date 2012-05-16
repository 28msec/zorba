/*
 * Copyright 2006-2011 The FLWOR Foundation.
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
#include <map>

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>
#include <zorba/zorba_string.h>
#include <zorba/streams.h>
#include <zorba/locale.h>
#include <zorba/internal/unique_ptr.h>
#include <zorba/internal/ztd.h>

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

/**
 * @brief The class representing the result of URL resolution.
 *
 * This class is the final output of the URI resolution process. All
 * URL resolvers return results using subclasses of this class.
 */
class ZORBA_DLL_PUBLIC Resource
{
public:
  typedef std::unique_ptr<Resource,internal::ztd::destroy_delete<Resource> >
          ptr;

  virtual ~Resource() = 0;

  /**
   * @brief Destroy/clean up this Resource.
   *
   * Zorba will call this method when it no longer needs the Resource. It
   * is the responsibility of subclasses to clean up appropriate when
   * this method is called, including calling "delete this" if the Resource
   * was allocated with "new".
   */
  virtual void destroy() const = 0;
};

/**
 * @brief Concrete Resource subclass representing access to an entity
 * via a stream.
 */
class ZORBA_DLL_PUBLIC StreamResource : public Resource
{
public:

  /**
   * @brief Public factory method from istream.
   *
   * The Resource object will take memory ownership of the istream. Zorba will
   * pass it to aStreamReleaser when it is no longer needed, so that the
   * original client may delete it.
   * @param aStream An istream whence to read the string's content.
   * @param aStreamReleaser A function pointer which is invoked once
   *        the StreamResource is destroyed. Normally this function will delete
   *        the std::istream object passed to it.
   * @param aIsStreamSeekable Determines whether the given stream is arbitrarily
   *   seekable without throwing errors.
   */
  static StreamResource* create(std::istream* aStream,
                                StreamReleaser aStreamReleaser,
                                bool aIsStreamSeekable = false);
  
  /**
   * @brief Retrieve the istream associated with this Resource.
   */
  virtual std::istream* getStream() = 0;

  /**
   * @brief Retrieve the stream-releaser function.
   */
  virtual StreamReleaser getStreamReleaser() = 0;

  virtual ~StreamResource() = 0;

  virtual bool isStreamSeekable() const = 0;
};

/**
 * @brief The class containing data which may be of use to URIMappers
 * and URLResolvers when mapping/resolving a URI.
 *
 * This base class specifies the kind of entity for which this URI is being
 * resolved - for instance, a schema URI or a module URI. Subclasses of
 * this class will provide additional data for specific kinds of entities.
 */
class ZORBA_DLL_PUBLIC EntityData
{
public:
  /**
   * @brief enum listing the kinds of entities that may be represented
   * by URIs, and hence may be looked up via the URI resolution
   * mechanism.
   */
  enum Kind {
    SCHEMA,
    MODULE,
    THESAURUS,
    STOP_WORDS,
    COLLECTION,
    DOCUMENT,
    SOME_CONTENT
  };

  /**
   * @brief Return the Kind of Entity for which this URI is being resolved.
   */
  virtual Kind getKind() const = 0;

  virtual ~EntityData() = 0;
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
   * The "aEntityData" parameter informs the URLResolver what kind of
   * entity is being referenced by the URL. URLResolvers may choose to
   * make use of this information to alter their behaviour.
   * URLResolvers must ensure that they return a concrete subclass of
   * Resource which is compatible with the entity kind being resolved.
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
   * ownership of the Resource and delete it (by calling destroy() on it)
   * when it is no longer needed.
   */
  virtual Resource* resolveURL(const zorba::String& aUrl,
    EntityData const* aEntityData) = 0;
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
   * The "aEntityData" parameter informs the URIMapper what kind of
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
    EntityData const* aEntityData, std::vector<zorba::String>& oUris)
    = 0;

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
  virtual Kind mapperKind();

  /**
   * @brief Constant indicating that Zorba should deny access to the
   * given URI.
   *
   * If any kind of URIMapper returns this value at any point in the
   * vector of URIs, Zorba will cause the resolution of this URI to be
   * denied with an error.  This can be used, for example, to suppress
   * importing particular modules by URI.
   */
  const static zorba::String DENY_ACCESS;
};


/**
 * Convenience implementation of a mapper that maps URIs to other
 * single URIs. Will only map for one specific Entity Kind.
 */
class ZORBA_DLL_PUBLIC OneToOneURIMapper : public URIMapper {

public:

  /**
   * Constructor. Specify the Entity Kind you wish to map. Optionally,
   * specify whether this should be a CANDIDATE or COMPONENT mapper;
   * default is CANDIDATE.
   */
  OneToOneURIMapper(EntityData::Kind aEntityKind,
                    URIMapper::Kind aMapperKind = URIMapper::CANDIDATE);

  /**
   * Add a mapping from a given URI to another URI.
   */
  void
  addMapping(const String& aUri, const String& aMappedUri);

  virtual Kind mapperKind();

  virtual void mapURI(const zorba::String aUri,
    EntityData const* aEntityData, std::vector<zorba::String>& oUris);

private:

  EntityData::Kind const theEntityKind;
  URIMapper::Kind const theMapperKind;
  typedef std::map<String, String> Mapping_t;
  typedef Mapping_t::const_iterator          MappingIter_t;
  Mapping_t theMappings;
};

} /* namespace zorba */

#endif
/* vim:set et sw=2 ts=2: */
