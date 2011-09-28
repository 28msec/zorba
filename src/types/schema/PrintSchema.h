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
#ifndef PRINTSCHEMA_H_
#define PRINTSCHEMA_H_

#include "common/common.h"
#ifndef ZORBA_NO_XMLSCHEMA

#ifdef __GNUC__
  // disable a warning in xerces 
#  pragma GCC diagnostic ignored "-Wparentheses"
#  pragma GCC diagnostic ignored "-Wctor-dtor-privacy"
#endif

#include <xercesc/framework/psvi/XSNamedMap.hpp>
#include <xercesc/framework/psvi/XSModelGroup.hpp>
#include <xercesc/framework/psvi/XSObject.hpp>

#ifdef __GNUC__
#  pragma GCC diagnostic warning "-Wctor-dtor-privacy"
#  pragma GCC diagnostic warning "-Wparentheses"
#endif

#ifdef CYGWIN
#  undef WIN32
#endif

#include <string>


namespace XERCES_CPP_NAMESPACE
{
  class XMLGrammarPool;
  class XSObject;
  class XSTypeDefinition;
  class XSComplexTypeDefinition;
}

namespace zorba
{

class PrintSchema;


class PrintSchema
{
public:
    static void printInfo(bool excludeBuiltIn,
                          XERCES_CPP_NAMESPACE::XMLGrammarPool* grammarPool);
private:
    static void printBasic(std::string pre,
                           bool excludeBuiltIn,
                           XERCES_CPP_NAMESPACE::XSObject *xsObject,
                           const char *type);

    static void processElements(bool excludeBuiltIn,
                                XERCES_CPP_NAMESPACE::XSNamedMap<XERCES_CPP_NAMESPACE::XSObject> *xsElements);

    static void printCompositorTypeConnector(XERCES_CPP_NAMESPACE::XSModelGroup::COMPOSITOR_TYPE type);

    static std::string getCompositorTypeConnector(XERCES_CPP_NAMESPACE::XSModelGroup::COMPOSITOR_TYPE type);

    static void processParticle(std::string pre,
                                bool excludeBuiltIn,
                                XERCES_CPP_NAMESPACE::XSParticle *xsParticle);

    static void processTypeDefinitions(bool excludeBuiltIn,
                                       XERCES_CPP_NAMESPACE::XSNamedMap<XERCES_CPP_NAMESPACE::XSObject> *xsTypeDefs);

    static void printTypeRef(std::string pre,
                             bool excludeBuiltIn,
                             XERCES_CPP_NAMESPACE::XSTypeDefinition *xsTypeDef);

    static void processTypeDefinition(std::string pre,
                                      bool excludeBuiltIn,
                                      XERCES_CPP_NAMESPACE::XSTypeDefinition *xsTypeDef);

    static void processSimpleTypeDefinition(std::string pre,
                                            bool excludeBuiltIn,
                                            XERCES_CPP_NAMESPACE::XSSimpleTypeDefinition * xsSimpleTypeDef);

    static void processComplexTypeDefinition(std::string pre,
                                             bool excludeBuiltIn,
                                             XERCES_CPP_NAMESPACE::XSComplexTypeDefinition *xsComplexTypeDef);
};

} // namespace xqp

#endif // ifndef ZORBA_NO_XMLSCHEMA
#endif /*PRINTSCHEMA_H_*/
/* vim:set et sw=2 ts=2: */
