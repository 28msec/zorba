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
#ifndef PRINTSCHEMA_H_
#define PRINTSCHEMA_H_

#include "common/common.h"
#ifndef ZORBA_NO_XMLSCHEMA

#include "xercesIncludes.h"


XERCES_CPP_NAMESPACE_USE

namespace zorba
{

class PrintSchema;


class PrintSchema
{
public:
    static void printInfo(bool excludeBuiltIn, XMLGrammarPool* grammarPool);
private:
    static void printBasic(bool excludeBuiltIn, XSObject *xsObject, const char *type);
    static void processElements(bool excludeBuiltIn, XSNamedMap<XSObject> *xsElements);
    static void processSimpleTypeDefinition(bool excludeBuiltIn, XSSimpleTypeDefinition * xsSimpleTypeDef);
    static void printCompositorTypeConnector(bool excludeBuiltIn, XSModelGroup::COMPOSITOR_TYPE type);
    static void processParticle(bool excludeBuiltIn, XSParticle *xsParticle);
    static void processComplexTypeDefinition(bool excludeBuiltIn, XSComplexTypeDefinition *xsComplexTypeDef);
    static void processTypeDefinitions(bool excludeBuiltIn, XSNamedMap<XSObject> *xsTypeDefs);
};

} // namespace xqp

#endif // ifndef ZORBA_NO_XMLSCHEMA
#endif /*PRINTSCHEMA_H_*/
