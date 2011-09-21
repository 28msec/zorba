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
#include "stdafx.h"

#include "common/common.h"

#ifndef ZORBA_NO_XMLSCHEMA

#include "PrintSchema.h"
#include "xercesIncludes.h"
#include "StrX.h"
#include "schema.h"
#include <iostream>
#include "types/typeimpl.h"

XERCES_CPP_NAMESPACE_USE
using namespace std;

namespace zorba
{

void PrintSchema::printInfo(bool excludeBuiltIn, XMLGrammarPool* grammarPool)
{
  std::cout << "********** Printing out information from Schema **********" <<
      "\n\n";

  bool modelHasChanged;
  XSModel *xsModel = grammarPool->getXSModel(modelHasChanged);
  if (xsModel)
  {
    StringList *namespaces = xsModel->getNamespaces();
    for (unsigned i = 0; i < namespaces->size(); i++)
    {

      std::cout << "Processing Namespace:   ";
      const XMLCh *nameSpace = namespaces->elementAt(i);

      if (nameSpace && (XMLString::stringLen(nameSpace)>0))
      {
        std::cout << StrX(nameSpace);
        char * nsCh = XMLString::transcode(nameSpace);
	    if ( XMLString::equals(Schema::XSD_NAMESPACE, nsCh ) )
        {
          std::cout << std::endl;
          XMLString::release(&nsCh);
          break;
        }
        else
          XMLString::release(&nsCh);
      }

      std::cout << "\n============================================"
                                << std::endl
                                << std::endl;

      processElements(excludeBuiltIn,
          xsModel->getComponentsByNamespace(XSConstants::ELEMENT_DECLARATION,
                                            nameSpace));
      processTypeDefinitions(excludeBuiltIn,
          xsModel->getComponentsByNamespace(XSConstants::TYPE_DEFINITION,
                                            nameSpace));

      processTypeDefinitions(excludeBuiltIn,
          xsModel->getComponentsByNamespace(XSConstants::MODEL_GROUP_DEFINITION,
                                 nameSpace));

      processTypeDefinitions(excludeBuiltIn,
          xsModel->getComponentsByNamespace(XSConstants::ATTRIBUTE_GROUP_DEFINITION,
                                 nameSpace));
    }
  }
  else
  {
    std::cout << "No XSModel to print" << "\n\n";
  }
}


void PrintSchema::printBasic(std::string pre, bool excludeBuiltIn,
    XSObject *xsObject, const char *type)
{
    std::cout << pre << type << std::endl;
    std::cout << pre << "Name:           ";
    const XMLCh *nameSpace = xsObject->getNamespace();
    std::cout << StrX(xsObject->getName()) << " @ ";
    if (nameSpace && (XMLString::stringLen(nameSpace)>0))
    {
        std::cout << StrX(nameSpace);
    }
    std::cout << std::endl;
}


void PrintSchema::processElements(bool excludeBuiltIn,
    XSNamedMap<XSObject> *xsElements)
{
  if (!xsElements || xsElements->getLength() == 0)
  {
    std::cout << "no elements\n\n" << std::endl;
    return;
  }

  for (unsigned i=0; i < xsElements->getLength(); i++)
  {
    XSElementDeclaration *xsElement =
        (XSElementDeclaration *)xsElements->item(i);
    printBasic("", excludeBuiltIn, xsElement, "Element");

    // Content Model
    XSTypeDefinition *xsTypeDef = xsElement->getTypeDefinition();

    printTypeRef("", excludeBuiltIn, xsTypeDef);

    if (xsTypeDef->getAnonymous())
        processTypeDefinition("  ", excludeBuiltIn, xsTypeDef);

    std::cout << "--------------------------------------------" << std::endl;
  }
}


void PrintSchema::processSimpleTypeDefinition(std::string pre,
    bool excludeBuiltIn, XSSimpleTypeDefinition * xsSimpleTypeDef)
{
  XSTypeDefinition *xsBaseTypeDef = xsSimpleTypeDef->getBaseType();
  std::cout << pre << "Base:\t\t\t";
  std::cout << StrX(xsBaseTypeDef->getName()) << std::endl;

  int facets = xsSimpleTypeDef->getDefinedFacets();
  if (facets)
  {
    std::cout << pre << "Facets:\n";

    if (facets & XSSimpleTypeDefinition::FACET_LENGTH)
      std::cout << pre << "\tLength:\t\t" << StrX(xsSimpleTypeDef->
          getLexicalFacetValue(XSSimpleTypeDefinition::FACET_LENGTH)) <<
          std::endl;
    if (facets & XSSimpleTypeDefinition::FACET_MINLENGTH)
      std::cout << pre << "\tMinLength:\t" << StrX(xsSimpleTypeDef->
          getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MINLENGTH)) <<
          std::endl;
    if (facets & XSSimpleTypeDefinition::FACET_MAXLENGTH)
      std::cout << pre << "\tMaxLength:\t" << StrX(xsSimpleTypeDef->
          getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MAXLENGTH)) <<
          std::endl;

    if (facets & XSSimpleTypeDefinition::FACET_PATTERN)
    {
      StringList *lexicalPatterns = xsSimpleTypeDef->getLexicalPattern();
      if (lexicalPatterns && lexicalPatterns->size())
      {
        std::cout << pre << "\tPattern:\t\t";
        for (unsigned i = 0; i < lexicalPatterns->size(); i++)
        {
          std::cout << StrX(lexicalPatterns->elementAt(i));
        }
        std::cout << std::endl;
      }
    }
    if (facets & XSSimpleTypeDefinition::FACET_WHITESPACE)
      std::cout << pre << "\tWhitespace:\t\t" << StrX(xsSimpleTypeDef->
          getLexicalFacetValue(XSSimpleTypeDefinition::FACET_WHITESPACE)) <<
          std::endl;
    if (facets & XSSimpleTypeDefinition::FACET_MAXINCLUSIVE)
      std::cout << pre << "\tMaxInclusive:\t" << StrX(xsSimpleTypeDef->
          getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MAXINCLUSIVE)) <<
          std::endl;
    if (facets & XSSimpleTypeDefinition::FACET_MAXEXCLUSIVE)
      std::cout << pre << "\tMaxExclusive:\t" << StrX(xsSimpleTypeDef->
          getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MAXEXCLUSIVE)) <<
          std::endl;
    if (facets & XSSimpleTypeDefinition::FACET_MINEXCLUSIVE)
      std::cout << pre << "\tMinExclusive:\t" << StrX(xsSimpleTypeDef->
          getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MINEXCLUSIVE)) <<
          std::endl;
    if (facets & XSSimpleTypeDefinition::FACET_MININCLUSIVE)
      std::cout << pre << "\tMinInclusive:\t" << StrX(xsSimpleTypeDef->
          getLexicalFacetValue(XSSimpleTypeDefinition::FACET_MININCLUSIVE)) <<
          std::endl;
    if (facets & XSSimpleTypeDefinition::FACET_TOTALDIGITS)
      std::cout << pre << "\tTotalDigits:\t" << StrX(xsSimpleTypeDef->
          getLexicalFacetValue(XSSimpleTypeDefinition::FACET_TOTALDIGITS)) <<
          std::endl;
    if (facets & XSSimpleTypeDefinition::FACET_FRACTIONDIGITS)
      std::cout << pre << "\tFractionDigits:\t" << StrX(xsSimpleTypeDef->
          getLexicalFacetValue(XSSimpleTypeDefinition::FACET_FRACTIONDIGITS)) <<
          std::endl;

    if (facets & XSSimpleTypeDefinition::FACET_ENUMERATION)
    {
      StringList *lexicalEnums = xsSimpleTypeDef->getLexicalEnumeration();
      if (lexicalEnums && lexicalEnums->size())
      {
        std::cout << pre << "\tEnumeration:\n";
        for (unsigned i = 0; i < lexicalEnums->size(); i++)
        {
          std::cout << "\t\t\t" << StrX(lexicalEnums->elementAt(i)) << "\n";
        }
        std::cout << std::endl;
      }
    }
  }
}


void PrintSchema::printCompositorTypeConnector(XSModelGroup::COMPOSITOR_TYPE type)
{
  switch (type)
  {
  case XSModelGroup::COMPOSITOR_SEQUENCE:
    std::cout << ",";
    break;
  case XSModelGroup::COMPOSITOR_CHOICE:
    std::cout << "|";
    break;
  case XSModelGroup::COMPOSITOR_ALL:
    std::cout << "*";
    break;
  }
}

std::string PrintSchema::getCompositorTypeConnector(XSModelGroup::COMPOSITOR_TYPE type)
{
  switch (type)
  {
  case XSModelGroup::COMPOSITOR_SEQUENCE:
    return ",";
  case XSModelGroup::COMPOSITOR_CHOICE:
    return "|";
  case XSModelGroup::COMPOSITOR_ALL:
    return "*";
  default:
    return "";
  }
}

void PrintSchema::processParticle(std::string pre, bool excludeBuiltIn,
    XSParticle *xsParticle)
{
  if (!xsParticle)
  {
    std::cout << pre << "- xsParticle is NULL\n";
    return;
  }

  XSParticle::TERM_TYPE termType = xsParticle->getTermType();
  if (termType == XSParticle::TERM_ELEMENT)
  {
    XSElementDeclaration *xsElement = xsParticle->getElementTerm();
    std::cout << pre << "- " << StrX(xsElement->getName());

    if ( xsElement->getScope() != XSConstants::SCOPE_GLOBAL )
    {
      XSTypeDefinition* xsTypeDef = xsElement->getTypeDefinition();
      if ( xsTypeDef->getAnonymous() )
      {
          std::cout << "  Type anonymous:\n";
          processTypeDefinition(pre + "    ", excludeBuiltIn, xsTypeDef);
      }
      else
        std::cout << "\n";
    }
    else
      std::cout << "  ref to global\n";

  }
  else if (termType == XSParticle::TERM_MODELGROUP)
  {
    XSModelGroup *xsModelGroup = xsParticle->getModelGroupTerm();
    XSModelGroup::COMPOSITOR_TYPE compositorType =
      xsModelGroup->getCompositor();
    std::string compositor = getCompositorTypeConnector(compositorType);

    std::cout << pre << "- ModelGroup w/ compositor: " << compositor << "\n";

    XSParticleList *xsParticleList = xsModelGroup->getParticles();
    for (unsigned i = 0; i < xsParticleList->size(); i++)
    {
      processParticle(pre + "  ", excludeBuiltIn, xsParticleList->elementAt(i));
    }
  }
  else if (termType == XSParticle::TERM_WILDCARD)
  {
    std::cout << pre << "- * (wildcard)\n";
  }
}


void PrintSchema::processComplexTypeDefinition(std::string pre,
    bool excludeBuiltIn, XSComplexTypeDefinition *xsComplexTypeDef)
{
  XSTypeDefinition *xsBaseTypeDef = xsComplexTypeDef->getBaseType();
  if (xsBaseTypeDef)
  {
    std::cout << pre << "Base:           ";
    std::cout << StrX(xsBaseTypeDef->getName()) << "\n";
  }

  XSComplexTypeDefinition::CONTENT_TYPE contentType =
    xsComplexTypeDef->getContentType();

  std::string contentModelType;
  switch (contentType)
  {
  case XSComplexTypeDefinition::CONTENTTYPE_ELEMENT:
    contentModelType = "elements";
    break;

  case XSComplexTypeDefinition::CONTENTTYPE_MIXED:
    contentModelType = "mixed";
    break;

  case XSComplexTypeDefinition::CONTENTTYPE_SIMPLE:
    contentModelType = "simple";
    break;

  case XSComplexTypeDefinition::CONTENTTYPE_EMPTY:
    contentModelType = "empty";
    break;

  default:
    contentModelType = "unknown";
  }

  std::cout << pre << "Content Model: " << contentModelType << "\n";

  if (contentType == XSComplexTypeDefinition::CONTENTTYPE_ELEMENT
      || contentType == XSComplexTypeDefinition::CONTENTTYPE_MIXED)
  {
    processParticle(pre + "  ", excludeBuiltIn, xsComplexTypeDef->getParticle());
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
    processTypeDefinition("", excludeBuiltIn, xsTypeDef);

    std::cout << "--------------------------------------------" << std::endl;
  }
}

void PrintSchema::printTypeRef(std::string pre, bool excludeBuiltIn,
    XSTypeDefinition *xsTypeDef)
{
    if ( xsTypeDef->getAnonymous() )
    {
        std::cout << pre << "Type anonymous: ";
    }
    else
    {
        std::cout << pre << "Type:           ";
    }

    const XMLCh *nameSpace = xsTypeDef->getNamespace();
    std::cout << StrX(xsTypeDef->getName()) << " @ ";
    if (nameSpace && (XMLString::stringLen(nameSpace)>0))
    {
        std::cout << StrX(nameSpace);
    }

    std::cout << std::endl;
}

void PrintSchema::processTypeDefinition(std::string pre, bool excludeBuiltIn,
    XSTypeDefinition *xsTypeDef)
{
    printBasic(pre, excludeBuiltIn, xsTypeDef, "Type Definition");

    // Content Model
    std::cout << pre << "Category:       ";
    if (xsTypeDef->getTypeCategory() == XSTypeDefinition::SIMPLE_TYPE)
    {
      std::cout << "Simple\n";
      processSimpleTypeDefinition(pre, excludeBuiltIn,
                                  (XSSimpleTypeDefinition *)xsTypeDef);
    }
    else if (xsTypeDef->getTypeCategory() == XSTypeDefinition::COMPLEX_TYPE)
    {
      std::cout << "Complex\n";
      processComplexTypeDefinition(pre, excludeBuiltIn,
                                   (XSComplexTypeDefinition *)xsTypeDef);
    }
    else
      std::cout << std::endl;
}

} // namespace xqp

#endif //#ifndef ZORBA_NO_XMLSCHEMA
/* vim:set et sw=2 ts=2: */
