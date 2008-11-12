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
#include "common/common.h"

#ifndef ZORBA_NO_XMLSCHEMA

#include "PrintSchema.h"
#include "StrX.h"
#include "schema.h"
#include <iostream>

using namespace std;

namespace zorba
{

void PrintSchema::printInfo(bool excludeBuiltIn, XMLGrammarPool* grammarPool)
{
    XERCES_STD_QUALIFIER cout << "********** Printing out information from Schema **********" << "\n\n";

    XSModel *xsModel = grammarPool->getXSModel();
    if (xsModel)
    {
        StringList *namespaces = xsModel->getNamespaces();
        for (unsigned i = 0; i < namespaces->size(); i++)
        {

            XERCES_STD_QUALIFIER cout << "Processing Namespace:   ";
            const XMLCh *nameSpace = namespaces->elementAt(i);
            
            if (nameSpace && (XMLString::stringLen(nameSpace)>0))
            {
                XERCES_STD_QUALIFIER cout << StrX(nameSpace);
//              const XMLCh* ns1 = XMLString::transcode(XSD_NAMESPACE); 
                const char* ns2 = XMLString::transcode(nameSpace);
				if ( XMLString::equals(Schema::XSD_NAMESPACE, ns2 /*ns1, nameSpace*/) )
                {
                    XERCES_STD_QUALIFIER cout << XERCES_STD_QUALIFIER endl;
                    break;
                }
            }
            XERCES_STD_QUALIFIER cout << "\n============================================" << XERCES_STD_QUALIFIER endl << XERCES_STD_QUALIFIER endl;

            processElements(excludeBuiltIn, xsModel->getComponentsByNamespace(
                    XSConstants::ELEMENT_DECLARATION, nameSpace));
            processTypeDefinitions(excludeBuiltIn, 
                    xsModel->getComponentsByNamespace( XSConstants::TYPE_DEFINITION, nameSpace));
        }
    }
    else
    {
        XERCES_STD_QUALIFIER cout << "No XSModel to print" << "\n\n";
    }
}

void PrintSchema::printBasic(bool excludeBuiltIn, XSObject *xsObject, const char *type)
{
    XERCES_STD_QUALIFIER cout << "Name:\t\t\t";
    const XMLCh *nameSpace = xsObject->getNamespace();
    XERCES_STD_QUALIFIER cout << StrX(xsObject->getName()) << " @ ";
    if (nameSpace && (XMLString::stringLen(nameSpace)>0))
    {
        XERCES_STD_QUALIFIER cout << StrX(nameSpace) << "\n";
    }
    XERCES_STD_QUALIFIER cout << "Component Type:\t" << type << XERCES_STD_QUALIFIER endl;
}

void PrintSchema::processElements(bool excludeBuiltIn, XSNamedMap<XSObject> *xsElements)
{
    if (!xsElements || xsElements->getLength() == 0)
    {
        XERCES_STD_QUALIFIER cout << "no elements\n\n" << XERCES_STD_QUALIFIER endl;
        return;
    }
    for (unsigned i=0; i < xsElements->getLength(); i++)
    {
        XSElementDeclaration *xsElement =
                (XSElementDeclaration *)xsElements->item(i);
        printBasic(excludeBuiltIn, xsElement, "Element");

        // Content Model
        XSTypeDefinition *xsTypeDef = xsElement->getTypeDefinition();
        XERCES_STD_QUALIFIER cout << "Content Model" << "\n";
        XERCES_STD_QUALIFIER cout << "\tType:\t";
        if (xsTypeDef->getTypeCategory() == XSTypeDefinition::SIMPLE_TYPE)
        {
            XERCES_STD_QUALIFIER cout << "Simple\n";
        }
        else
        {
            XERCES_STD_QUALIFIER cout << "Complex\n";
        }
        XERCES_STD_QUALIFIER cout << "\tName:\t"
        << StrX(xsTypeDef->getName()) << "\n";

        XERCES_STD_QUALIFIER cout << "\n--------------------------------------------" << XERCES_STD_QUALIFIER endl;
    }
}

void PrintSchema::processSimpleTypeDefinition(bool excludeBuiltIn,
        XSSimpleTypeDefinition * xsSimpleTypeDef)
{
    XSTypeDefinition *xsBaseTypeDef = xsSimpleTypeDef->getBaseType();
    XERCES_STD_QUALIFIER cout << "Base:\t\t\t";
    XERCES_STD_QUALIFIER cout << StrX(xsBaseTypeDef->getName()) << XERCES_STD_QUALIFIER endl;

    int facets = xsSimpleTypeDef->getDefinedFacets();
    if (facets)
    {
        XERCES_STD_QUALIFIER cout << "Facets:\n";

        if (facets & XSSimpleTypeDefinition::FACET_LENGTH)
            XERCES_STD_QUALIFIER cout << "\tLength:\t\t" << StrX(xsSimpleTypeDef->getLexicalFacetValue(XSSimpleTypeDefinition::FACET_LENGTH)) << XERCES_STD_QUALIFIER endl;
        if (facets & XSSimpleTypeDefinition::FACET_MINLENGTH)
            XERCES_STD_QUALIFIER cout << "\tMinLength:\t" << StrX(xsSimpleTypeDef->getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MINLENGTH)) << XERCES_STD_QUALIFIER endl;
        if (facets & XSSimpleTypeDefinition::FACET_MAXLENGTH)
            XERCES_STD_QUALIFIER cout << "\tMaxLength:\t" << StrX(xsSimpleTypeDef->getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MAXLENGTH)) << XERCES_STD_QUALIFIER endl;
        if (facets & XSSimpleTypeDefinition::FACET_PATTERN)
        {
            StringList *lexicalPatterns = xsSimpleTypeDef->getLexicalPattern();
            if (lexicalPatterns && lexicalPatterns->size())
            {
                XERCES_STD_QUALIFIER cout << "\tPattern:\t\t";
                for (unsigned i = 0; i < lexicalPatterns->size(); i++)
                {
                    XERCES_STD_QUALIFIER cout << StrX(lexicalPatterns->elementAt(i));
                }
                XERCES_STD_QUALIFIER cout << XERCES_STD_QUALIFIER endl;
            }
        }
        if (facets & XSSimpleTypeDefinition::FACET_WHITESPACE)
            XERCES_STD_QUALIFIER cout << "\tWhitespace:\t\t" << StrX(xsSimpleTypeDef->getLexicalFacetValue(XSSimpleTypeDefinition::FACET_WHITESPACE)) << XERCES_STD_QUALIFIER endl;
        if (facets & XSSimpleTypeDefinition::FACET_MAXINCLUSIVE)
            XERCES_STD_QUALIFIER cout << "\tMaxInclusive:\t" << StrX(xsSimpleTypeDef->getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MAXINCLUSIVE)) << XERCES_STD_QUALIFIER endl;
        if (facets & XSSimpleTypeDefinition::FACET_MAXEXCLUSIVE)
            XERCES_STD_QUALIFIER cout << "\tMaxExclusive:\t" << StrX(xsSimpleTypeDef->getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MAXEXCLUSIVE)) << XERCES_STD_QUALIFIER endl;
        if (facets & XSSimpleTypeDefinition::FACET_MINEXCLUSIVE)
            XERCES_STD_QUALIFIER cout << "\tMinExclusive:\t" << StrX(xsSimpleTypeDef->getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MINEXCLUSIVE)) << XERCES_STD_QUALIFIER endl;
        if (facets & XSSimpleTypeDefinition::FACET_MININCLUSIVE)
            XERCES_STD_QUALIFIER cout << "\tMinInclusive:\t" << StrX(xsSimpleTypeDef->getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MININCLUSIVE)) << XERCES_STD_QUALIFIER endl;
        if (facets & XSSimpleTypeDefinition::FACET_TOTALDIGITS)
            XERCES_STD_QUALIFIER cout << "\tTotalDigits:\t" << StrX(xsSimpleTypeDef->getLexicalFacetValue(XSSimpleTypeDefinition::FACET_TOTALDIGITS)) << XERCES_STD_QUALIFIER endl;
        if (facets & XSSimpleTypeDefinition::FACET_FRACTIONDIGITS)
            XERCES_STD_QUALIFIER cout << "\tFractionDigits:\t" << StrX(xsSimpleTypeDef->getLexicalFacetValue(XSSimpleTypeDefinition::FACET_FRACTIONDIGITS)) << XERCES_STD_QUALIFIER endl;
        if (facets & XSSimpleTypeDefinition::FACET_ENUMERATION)
        {
            StringList *lexicalEnums = xsSimpleTypeDef->getLexicalEnumeration();
            if (lexicalEnums && lexicalEnums->size())
            {
                XERCES_STD_QUALIFIER cout << "\tEnumeration:\n";
                for (unsigned i = 0; i < lexicalEnums->size(); i++)
                {
                    XERCES_STD_QUALIFIER cout << "\t\t\t" << StrX(lexicalEnums->elementAt(i)) << "\n";
                }
                XERCES_STD_QUALIFIER cout << XERCES_STD_QUALIFIER endl;
            }
        }
    }
}

void PrintSchema::printCompositorTypeConnector(bool excludeBuiltIn, XSModelGroup::COMPOSITOR_TYPE type)
{
    switch (type)
    {
    case XSModelGroup::COMPOSITOR_SEQUENCE:
        XERCES_STD_QUALIFIER cout << ",";
        break;
    case XSModelGroup::COMPOSITOR_CHOICE:
        XERCES_STD_QUALIFIER cout << "|";
        break;
    case XSModelGroup::COMPOSITOR_ALL:
        XERCES_STD_QUALIFIER cout << "*";
        break;
    }
}

void PrintSchema::processParticle(bool excludeBuiltIn, XSParticle *xsParticle)
{
    if (!xsParticle)
    {
        XERCES_STD_QUALIFIER cout << "xsParticle is NULL";
        return;
    }
    XSParticle::TERM_TYPE termType = xsParticle->getTermType();
    if (termType == XSParticle::TERM_ELEMENT)
    {
        XSElementDeclaration *xsElement = xsParticle->getElementTerm();
        XERCES_STD_QUALIFIER cout << StrX(xsElement->getName());
    }
    else if (termType == XSParticle::TERM_MODELGROUP)
    {
        XERCES_STD_QUALIFIER cout << "(";

        XSModelGroup *xsModelGroup = xsParticle->getModelGroupTerm();
        XSModelGroup::COMPOSITOR_TYPE compositorType =
                xsModelGroup->getCompositor();
        XSParticleList *xsParticleList = xsModelGroup->getParticles();
        for (unsigned i = 0; i < xsParticleList->size()-1; i++)
        {
            processParticle(excludeBuiltIn, xsParticleList->elementAt(i));
            printCompositorTypeConnector(excludeBuiltIn, compositorType);
        }
        processParticle(excludeBuiltIn, xsParticleList->elementAt(xsParticleList->size()-1));

        XERCES_STD_QUALIFIER cout << ")";
    }
    else if (termType == XSParticle::TERM_WILDCARD)
    {
        XERCES_STD_QUALIFIER cout << "* (wildcard)";
    }
}

void PrintSchema::processComplexTypeDefinition(bool excludeBuiltIn,
        XSComplexTypeDefinition *xsComplexTypeDef)
{
    XSTypeDefinition *xsBaseTypeDef = xsComplexTypeDef->getBaseType();
    if (xsBaseTypeDef)
    {
        XERCES_STD_QUALIFIER cout << "Base:\t\t\t";
        XERCES_STD_QUALIFIER cout << StrX(xsBaseTypeDef->getName()) << "\n";
    }

    XERCES_STD_QUALIFIER cout << "Content Model:\t";
    XSComplexTypeDefinition::CONTENT_TYPE contentType =
            xsComplexTypeDef->getContentType();
    if (contentType == XSComplexTypeDefinition::CONTENTTYPE_ELEMENT
            || contentType == XSComplexTypeDefinition::CONTENTTYPE_MIXED)
    {
        processParticle(excludeBuiltIn, xsComplexTypeDef->getParticle());
        XERCES_STD_QUALIFIER cout << XERCES_STD_QUALIFIER endl;
    }
}

void PrintSchema::processTypeDefinitions(bool excludeBuiltIn,
        XSNamedMap<XSObject> *xsTypeDefs)
{
    if (!xsTypeDefs)
        return;

    for (unsigned i=0; i < xsTypeDefs->getLength(); i++)
    {
        XSTypeDefinition *xsTypeDef = (XSTypeDefinition *)xsTypeDefs->item(i);

        printBasic(excludeBuiltIn, xsTypeDef, "Type Definition");

        // Content Model
        XERCES_STD_QUALIFIER cout << "Category:\t";
        if (xsTypeDef->getTypeCategory() == XSTypeDefinition::SIMPLE_TYPE)
        {
            XERCES_STD_QUALIFIER cout << "\tSimple\n";
            processSimpleTypeDefinition(excludeBuiltIn,
                    (XSSimpleTypeDefinition *)xsTypeDef);
        }
        else
        {
            XERCES_STD_QUALIFIER cout << "\tComplex\n";
            processComplexTypeDefinition(excludeBuiltIn,
                    (XSComplexTypeDefinition *)xsTypeDef);
        }

        XERCES_STD_QUALIFIER cout << "\n--------------------------------------------" << XERCES_STD_QUALIFIER endl;
    }
}

} // namespace xqp

#endif //#ifndef ZORBA_NO_XMLSCHEMA
