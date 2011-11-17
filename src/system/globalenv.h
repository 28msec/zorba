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
#pragma once
#ifndef ZORBA_GLOBALENV_H
#define ZORBA_GLOBALENV_H

#include <memory>
#include <zorba/config.h>
#include "common/common.h"
#include "common/shared_types.h"

namespace zorba {

class RootTypeManager;
class root_static_context;
class XQueryXConvertor;

namespace internal {
class HTTPURLResolver;
class FileURLResolver;
class AutoFSURIMapper;
#ifndef ZORBA_NO_FULL_TEXT
class ThesaurusURLResolver;
#endif /* ZORBA_NO_FULL_TEXT */
}

namespace store {
class Store;
}


// exported for unit testing only
class ZORBA_DLL_PUBLIC GlobalEnvironment 
{
private:

  static GlobalEnvironment    * m_globalEnv;

private:
  store::Store                * m_store;

  root_static_context         * m_rootStaticContext;

  XQueryCompilerSubsystem     * m_compilerSubSys;

#ifdef ZORBA_XQUERYX
  XQueryXConvertor            * xqueryx_convertor;
#endif

  internal::HTTPURLResolver       * m_http_resolver;
  internal::FileURLResolver       * m_file_resolver;
  internal::AutoFSURIMapper       * m_autofs_mapper;
#ifndef ZORBA_NO_FULL_TEXT
  internal::ThesaurusURLResolver  * m_thesaurus_resolver;
#endif /* ZORBA_NO_FULL_TEXT */

public:

  static void init(store::Store* store);

  static void destroy();

  static void destroyStatics();

  static GlobalEnvironment& getInstance()
  {
    assert(m_globalEnv);
    return *m_globalEnv;
  }

public:
  ~GlobalEnvironment();

  RootTypeManager& getRootTypeManager();

  static_context& getRootStaticContext();

  bool isRootStaticContextInitialized();

  XQueryCompilerSubsystem& getCompilerSubsystem();

  store::Store& getStore();

  store::ItemFactory* getItemFactory();

  store::IteratorFactory* getIteratorFactory();

  internal::HTTPURLResolver* getHTTPURLResolver() const { return m_http_resolver; }

  internal::FileURLResolver* getFileURLResolver() const { return m_file_resolver; }

  internal::AutoFSURIMapper* getAutoFSURIMapper() const { return m_autofs_mapper; }

#ifndef ZORBA_NO_FULL_TEXT
  internal::ThesaurusURLResolver* getThesaurusURLResolver() const { return m_thesaurus_resolver; }
#endif /* ZORBA_NO_FULL_TEXT */

#ifdef ZORBA_XQUERYX
  XQueryXConvertor* getXQueryXConvertor();
#endif

private:
  GlobalEnvironment();

  void init_icu();

  void cleanup_icu();

};

#define GENV GlobalEnvironment::getInstance()

#define GENV_TYPESYSTEM GlobalEnvironment::getInstance().getRootTypeManager()

#define GENV_COMPILERSUBSYS GlobalEnvironment::getInstance().getCompilerSubsystem()

#define GENV_STORE GlobalEnvironment::getInstance().getStore()

#define GENV_ITEMFACTORY GlobalEnvironment::getInstance().getItemFactory()

#define GENV_ITERATOR_FACTORY GlobalEnvironment::getInstance().getIteratorFactory()

#define GENV_ROOT_STATIC_CONTEXT GlobalEnvironment::getInstance().getRootStaticContext()

}

#endif /* ZORBA_GLOBALENV_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
