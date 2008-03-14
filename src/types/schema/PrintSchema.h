#ifndef PRINTSCHEMA_H_
#define PRINTSCHEMA_H_

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

#endif /*PRINTSCHEMA_H_*/
