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
#include <libxml/parser.h>
#include "common/common.h"

#include "zorbatypes/icu_init.h"

#ifdef ZORBA_WITH_REST
#include <curl/curl.h>
#endif

#ifndef ZORBA_NO_BIGNUMBERS
#include "zorbatypes/m_apm.h"
#endif

#include "globalenv.h"
#include "types/root_typemanager.h"
#include "context/root_static_context.h"
#include "functions/library.h"
#include "store/current_store_headers.h"
#include "compiler/api/compiler_api.h"
#include "types/schema/schema.h"

#include "store/api/collection.h"

#ifdef ZORBA_XBROWSER
#include "DOMStoreSingelton.h"
#endif

using namespace zorba;

GlobalEnvironment * GlobalEnvironment::m_globalEnv = 0;

void GlobalEnvironment::init()
{
  // initialize Xerces-C lib
  Schema::initialize();

  m_globalEnv = new GlobalEnvironment();

  m_globalEnv->m_icu->zorbatypes_global_init();

#ifdef ZORBA_XBROWSER
  m_globalEnv->m_store.reset(xqp::DOMStoreSingelton::getInstance()->getStore());
  //static_cast<store::SimpleStore *>(m_globalEnv->m_store.get())->init();
#else
  m_globalEnv->m_store.reset(new store::SimpleStore());
  static_cast<store::SimpleStore *>(m_globalEnv->m_store.get())->init();
#endif

  root_static_context *rctx = new root_static_context();
  m_globalEnv->m_rootStaticContext.reset(rctx);
  rctx->init();
  BuiltinFunctionLibrary::populateContext(m_globalEnv->m_rootStaticContext.get());

#ifdef ZORBA_MINIMAL_STORE
  //for minimal store init types is based on root type manager
#ifndef ZORBA_XBROWSER
  static_cast<store::SimpleStore *>(m_globalEnv->m_store.get())->init();
#endif // ifndef ZORBA_XBROWSER
#endif

#ifndef ZORBA_NO_BIGNUMBERS
  // initialize mapm for bignum handling
  m_globalEnv->m_mapm = m_apm_init();
#endif
  // This initializes the libxml2 library and checks potential ABI mismatches
  // between the version it was compiled for and the actual  shared library used.
  // Calling its init is done here because we also want to free it at the end,
  // i.e. when zorba is shutdown
#ifndef ZORBA_MINIMAL_STORE
  LIBXML_TEST_VERSION
#endif

#ifdef ZORBA_WITH_REST
  curl_global_init(CURL_GLOBAL_ALL);
#endif

  m_globalEnv->m_compilerSubSys = XQueryCompilerSubsystem::create();
}


void GlobalEnvironment::destroy()
{
  // terminate Xerces-C lib
  Schema::terminate();

  // do cleanup of the libxml2 library
  // however, after that, a user will have to call 
  // LIBXML_TEST_VERSION if he wants to use libxml2
  // beyond the lifecycle of zorba
#ifndef ZORBA_MINIMAL_STORE
  xmlCleanupParser(); 
#endif

#ifdef ZORBA_WITH_REST
  curl_global_cleanup();
#endif

#ifndef ZORBA_NO_BIGNUMBERS
  // release resources aquired by the mapm library
  // this will force zorba users to reinit mapm
  // if they shutdown zorba but want to use mapm beyond
  m_apm_free(m_globalEnv->m_mapm);
  m_apm_free_all_mem();
  m_globalEnv->m_mapm = 0;
#endif

  m_globalEnv->m_rootStaticContext.reset(NULL);

  m_globalEnv->m_store.reset(NULL);

  // we shutdown icu
  // again it is important to mention this in the documentation
  // we might disable this call because it only
  // releases statically initialized memory and prevents
  // valgrind from reporting those problems at the end
  // see http://www.icu-project.org/apiref/icu4c/uclean_8h.html#93f27d0ddc7c196a1da864763f2d8920
  m_globalEnv->m_icu->zorbatypes_global_cleanup();

  delete m_globalEnv;
	m_globalEnv = NULL;
}

GlobalEnvironment::GlobalEnvironment()
{
}


static_context& GlobalEnvironment::getRootStaticContext()
{
  return *m_rootStaticContext;
}

RootTypeManager& GlobalEnvironment::getRootTypeManager()
{
  return *(static_cast<RootTypeManager *>(m_rootStaticContext->get_typemanager()));
}


store::Store& GlobalEnvironment::getStore()
{
  return *m_store;
}


store::ItemFactory* GlobalEnvironment::getItemFactory()
{
  return m_store->getItemFactory();
}


XQueryCompilerSubsystem& GlobalEnvironment::getCompilerSubsystem()
{
  return *m_compilerSubSys;
}

/* vim:set ts=2 sw=2: */

