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
#ifndef XQP_ZORBATYPES_COLLATION_MANAGER_H
#define XQP_ZORBATYPES_COLLATION_MANAGER_H

#include <zorba/config.h>
#include "common/common.h"
#include <string>
#include <map>

namespace zorba
{

#ifdef ZORBA_NO_UNICODE

class   Collator
{
};

#endif /* ZORBA_NO_UNICODE */

class XQPCollator
{
  friend class CollationFactory;

 protected:
  void             * theCollator;
  const std::string  uri;
  bool               theDoMemCmp;

 private:
  XQPCollator(void* Collator, const std::string& aCollationURI, bool doMemCmp = false);

 public:
  virtual ~XQPCollator();

  bool doMemCmp() const { return theDoMemCmp; }

  const std::string& getURI();

  void* getCollator() const { return theCollator; }
};


class CollationFactory
{
 protected:
  XQPCollator * theRootCollator;

 public:
  CollationFactory();

  virtual ~CollationFactory();

  /**
   * Creates a collator.
   * The URI specifies the locale and collation strengh that is used.
   *
   * The uri must begin with
   * http://www.zorba-xquery.com/collations/.
   * Then a collation strengh (PRIMARY, SECONDARY, TERTIARY, QUATTERNARY,
   * or IDENTICAL followed by a '/'.
   * Then a lowercase two-letter or three-letter ISO-639 code
   * followed by '/' and an optional uppercase two-letter ISO-3166 code.
   * For example, http://www.zorba-xquery.com/collations/PRIMARY/en/US
   * specifies an english language with US begin the country..
   *
   * For a detailed description see
   * http://www.icu-project.org/apiref/icu4c/classCollator.html
   * and http://www.icu-project.org/apiref/icu4c/classLocale.html
   *
   * @returns 0 if no collator could be found.
   */
  static XQPCollator* createCollator(const std::string& aCollationURI);

  /**
   * Creates a collator for the english language, US country and
   * a PRIMARY collation strength.
   */
  static XQPCollator* createCollator();
};


} /* namespace xqp */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

/* vim:set et sw=2 ts=2: */
