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

#include "zorbatypes/icu_init.h"

#include "common/common.h"

#ifndef ZORBA_NO_BIGNUMBERS
#include "zorbatypes/m_apm.h"
#endif

#include "zorbautils/fatal.h"

#include "globalenv.h"
#include "types/root_typemanager.h"
#include "types/schema/schema.h"
#include "context/root_static_context.h"
#include "functions/library.h"
#include "compiler/api/compiler_api.h"

#include "types/schema/schema.h"

#include "store/api/collection.h"

#include "store/api/store.h"

#ifdef ZORBA_WITH_REST
#include <curl/curl.h>
#endif


using namespace zorba;

GlobalEnvironment * GlobalEnvironment::m_globalEnv = 0;


void GlobalEnvironment::init(store::Store* store)
{
  // initialize Xerces-C lib
  Schema::initialize();

  m_globalEnv = new GlobalEnvironment();

  m_globalEnv->m_icu->zorbatypes_global_init();

  ZORBA_FATAL(store != NULL, "Must provide store during zorba initialization");

  m_globalEnv->m_store = store;

  root_static_context* rctx = new root_static_context();
  m_globalEnv->m_rootStaticContext.reset(rctx);
  rctx->init();
  BuiltinFunctionLibrary::populateContext(m_globalEnv->m_rootStaticContext.get());

#ifndef ZORBA_NO_BIGNUMBERS
  // initialize mapm for bignum handling
  m_globalEnv->m_mapm = m_apm_init();
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

  m_globalEnv->m_store = NULL;

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

