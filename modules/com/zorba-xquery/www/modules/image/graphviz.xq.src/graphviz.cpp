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

#include "graphviz.h"

#include <cassert>
#include <fstream>
#include <sstream>
#ifdef WIN32
#  include <io.h>
#endif

#include <stdio.h>
#ifdef WIN32
  #include <direct.h>
  #define GetCurrentDir _getcwd
#else
  #include <unistd.h>
  #define GetCurrentDir getcwd
#endif

#include <graphviz/types.h>
#include <graphviz/graph.h>
#include <graphviz/gvc.h>

#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>

namespace zorba
{
  namespace graphvizmodule
  {

/******************************************************************************
 *****************************************************************************/
String
GraphvizFunction::getURI() const
{
  return theModule->getURI();
}

/******************************************************************************
 *****************************************************************************/
std::string
GraphvizFunction::getGraphvizTmpFileName() {
  char lTmpDir[FILENAME_MAX];

  if (!GetCurrentDir(lTmpDir, sizeof(lTmpDir)))
  {
    throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
    "Test",
    __FILE__, __LINE__
    );
  }
  zorba::String test(lTmpDir);
  std::ostringstream  lTmpFileNameTemplate;
  lTmpFileNameTemplate << test << "/zorba.XXXXXX";

  char* lTemporaryString = (char*) malloc(lTmpFileNameTemplate.str().size()+1);
  strcpy(lTemporaryString, lTmpFileNameTemplate.str().c_str());
  std::string lRes = mktemp(lTemporaryString); // the replaced string is copied by assigning it to the string
  free(lTemporaryString);
  return lRes;
}

/******************************************************************************
 *****************************************************************************/
bool
GraphvizFunction::getAttribute(zorba::ItemFactory* aFactory,
    const char* attrname,
    const Item& elem,
    Item& attr)
{
  Item lIdQName = aFactory->createQName("", "", attrname);

  Iterator_t lAttributes = elem.getAttributes();
  lAttributes->open();
  while (lAttributes->next(attr)) {
    Item lNodeName;
    attr.getNodeName(lNodeName);
    if (lNodeName.getLocalName().equals(lIdQName.getLocalName())) {
      return true;
    }
  }
  attr = NULL;
  return false;
}

/******************************************************************************
 *****************************************************************************/
void
GraphvizFunction::printTypeAndAttr(ItemFactory* aFactory,
    const Item& in,
    std::fstream& os)
{
  Item lItem;
  Item lTypeQName = aFactory->createQName("", "", "type");
  Item lAttrQName = aFactory->createQName("", "", "attr");

  Iterator_t lChildren = in.getChildren();

  lChildren->open();
  while (lChildren->next(lItem)) {

    // needed?
    if (!lItem.isNode())
      continue;

    Item lNodeName;
    lItem.getNodeName(lNodeName);
    
    if (lNodeName.getLocalName().equals(lAttrQName.getLocalName())) {
      Item lNameAttr;
      if (!getAttribute(aFactory, "name", lItem, lNameAttr)) {
        throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
          "GXL parse error: attr node does not have a name attribute",
          __FILE__, __LINE__
        );
      }

      os << "    \"" << lNameAttr.getStringValue() << "\"=\"";

      // get the values of all bool, string, float, and int elements
      Iterator_t lAttrChildren = lItem.getChildren();
      Item lChild;
      lAttrChildren->open();
      while (lAttrChildren->next(lChild)) {
        if (!lChild.isNode())
          continue;

        Item lNodeName;
        lChild.getNodeName(lNodeName);
        String lChildName = lNodeName.getLocalName();
        if ( (lChildName == "bool") || (lChildName == "string")
             || (lChildName == "float") || (lChildName == "int")) {
          os << lChild.getStringValue();
        }
      }

      os << "\"" << std::endl;
      
    } else if (lNodeName.getStringValue().equals(lTypeQName.getStringValue())) {
      Item lHRefAttr;
      if (!getAttribute(aFactory, "href", lItem, lHRefAttr)) {
        throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
          "GXL parse error: type node does not have a href attribute",
          __FILE__, __LINE__
        );
      }

      os << "    _gxl_type=\"" << lHRefAttr.getStringValue() << "\"" << std::endl;
    }
  }
}

/******************************************************************************
 *****************************************************************************/
void
GraphvizFunction::visitNode(ItemFactory* aFactory,
    const Item& in, std::fstream& os)
{
  Item lItem;
  if (!getAttribute(aFactory, "id", in, lItem)) {
    throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
      "GXL parse error: node does not have an id attribute",
       __FILE__, __LINE__
    );
  }

  // start node with id attribute as name
  os << "  \"" << lItem.getStringValue() << "\" [ " << std::endl;

  printTypeAndAttr(aFactory, in, os);

  // end of node
  os << "  ]" << std::endl;
  
} /* GraphvizFunction::visitNode */

/******************************************************************************
 *****************************************************************************/
void
GraphvizFunction::visitEdge(ItemFactory* aFactory,
    const Item& in, std::fstream& os)
{
  Item lIdAttr;
  Item lFromAttr;
  Item lToAttr;

  if (!getAttribute(aFactory, "id", in, lIdAttr)) {
    throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
      "GXL parse error: edge does not have an id attribute",
       __FILE__, __LINE__
     );
  }
  if (!getAttribute(aFactory, "to", in, lToAttr)) {
    throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
      "GXL parse error: edge does not have an id attribute",
       __FILE__, __LINE__
    );
  }
  if (!getAttribute(aFactory, "from", in, lFromAttr)) {
    throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
      "GXL parse error: edge does not have an id attribute",
      __FILE__, __LINE__
    );
  }

  os << "  \"" << lFromAttr.getStringValue() << "\" -> \"" << lToAttr.getStringValue() << "\" [ " << std::endl
     << "    _gxl_id=\"" << lIdAttr.getStringValue() << "\"" << std::endl;
  
  printTypeAndAttr(aFactory, in, os);

  os << "  ]" << std::endl;
} /* GraphvizFunction::visitEdge */

/******************************************************************************
 *****************************************************************************/
void
GraphvizFunction::printGraph(ItemFactory* aFactory,
    const Item& in, std::fstream& os)
{
  // create helper qnames for comparison
  Item lNodeQName = aFactory->createQName("", "", "node");
  Item lEdgeQName = aFactory->createQName("", "", "edge");
  Item lRelQName  = aFactory->createQName("", "", "rel");

  // print the graph with all its children
  Item lGraphId;
  if (!getAttribute(aFactory, "id", in, lGraphId)) {
    throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
      "GXL parse error: graph does not have an id attribute.",
      __FILE__, __LINE__
    );
  }

  os << "digraph \"" << lGraphId.getStringValue() << "\" {" << std::endl;

  // visit nodes and edges (TODO add rel elements)
  Iterator_t lChildren = in.getChildren();
  lChildren->open();
  Item item;
  while (lChildren->next(item)) {
    Item lNodeName;
    item.getNodeName(lNodeName);
    if (lNodeName.getLocalName().equals(lNodeQName.getLocalName())) {
      visitNode(aFactory, item, os);
    } else if (lNodeName.getLocalName().equals(lEdgeQName.getLocalName())) {
      visitEdge(aFactory, item, os);
    } 
  }

  os << "}" << std::endl;
} /* GraphvizFunction::printGraph */

/******************************************************************************
 *****************************************************************************/
void
GraphvizFunction::gxl2dot(ItemFactory* aFactory,
    const Item& in, std::fstream& os)
{
  Item lGXLQName   = aFactory->createQName("", "", "gxl");
  Item lGraphQName = aFactory->createQName("", "", "graph");

  if (!in.isNode()) {
    throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
      "GXL parse error: item is not a node",
      __FILE__, __LINE__
    );
  }

  Item lNodeName;
  in.getNodeName(lNodeName);
  if (!lNodeName.getLocalName().equals(lGXLQName.getLocalName())) {
    Item lNodeName;
    in.getNodeName(lNodeName);

    std::ostringstream lErrorMsg;
    lErrorMsg << "GXL parse error: only element with name "
              << lGXLQName.getStringValue() << " allowed (got " << lNodeName.getStringValue()
              << ").";

    throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
      lErrorMsg.str(),
      __FILE__, __LINE__
    );
  }

  Iterator_t lGraphs = in.getChildren();
  lGraphs->open();

  Item lGraph;
  while(lGraphs->next(lGraph)) {
    if (!lGraph.isNode()) {
      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
        "GXL parse error: item is not a node",
        __FILE__, __LINE__
      );
    }

    lGraph.getNodeName(lNodeName);
    if (!lNodeName.getLocalName().equals(lGraphQName.getLocalName())) {
      std::ostringstream lErrorMsg;
      Item lNodeName;
      lGraph.getNodeName(lNodeName);

      lErrorMsg << "GXL parse error: only elements with name "
                << lGraphQName.getStringValue() << " allowed (got "
                << lNodeName.getLocalName() << ").";
      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
        lErrorMsg.str(),
        __FILE__, __LINE__
      );
    }

    printGraph(aFactory, lGraph, os);

  }

} /* GraphvizFunction::gxl2dot */

/******************************************************************************
 *****************************************************************************/
DotFunction::LazyDotSequence::LazyDotSequence(const DotFunction* aFunc,
    ItemSequence* aArg)
  : theFunc(aFunc),
    theArg(aArg)
{
}

/******************************************************************************
 *****************************************************************************/
Iterator_t DotFunction::LazyDotSequence::getIterator()
{
  return new DotFunction::LazyDotSequence::InternalIterator(this);
}

DotFunction::LazyDotSequence::InternalIterator::InternalIterator(LazyDotSequence *item_sequence) :
  theItemSequence(item_sequence), is_open(false)
{
  arg_iter = item_sequence->theArg->getIterator();
}

void DotFunction::LazyDotSequence::InternalIterator::open()
{
  is_open = true;
  arg_iter->open();
}

void DotFunction::LazyDotSequence::InternalIterator::close()
{
  is_open = false;
  arg_iter->close();
}

bool DotFunction::LazyDotSequence::InternalIterator::isOpen() const
{
  return is_open;
}

bool
DotFunction::LazyDotSequence::InternalIterator::next(Item& aItem)
{
  if(!is_open)
  {
    throw zorba::ExternalFunctionData::createZorbaException(XQP0019_INTERNAL_ERROR,
      "DotFunction::LazyDotSequence Iterator consumed without open", __FILE__, __LINE__);  
  }
  Item          lItem;
  Agraph_t      *lGraph = 0;
  String        lGraphInput;
  GVC_t         *lGvc = 0;
  std::ifstream lSVGFile;

  if (!arg_iter->next(lItem)) // exhausted
    return false;

  lGvc = gvContext();

  try {
    lGraphInput = lItem.getStringValue();

    lGraph = agmemread(const_cast<char*>(lGraphInput.c_str()));
    if (!lGraph) {
      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
        "could not read input", __FILE__, __LINE__);
    }

    if ( gvLayout(lGvc, lGraph, const_cast<char*>("dot")) != 0 ) {
      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
        "could not generate layout", __FILE__, __LINE__);
    }

    std::string lTmpFile = theItemSequence->theFunc->getGraphvizTmpFileName();

    if ( gvRenderFilename(lGvc, lGraph, const_cast<char*>("svg"),
                          const_cast<char*>(lTmpFile.c_str())) != 0 )  {
      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
        "could not render graph", __FILE__, __LINE__);
    }

    lSVGFile.open(lTmpFile.c_str());
    if (lSVGFile.bad()) {
      std::ostringstream lErrorMsg;
      lErrorMsg << "could not read from file "
                << lTmpFile.c_str();

      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
          lErrorMsg.str(), __FILE__, __LINE__);
    }

    aItem = Zorba::getInstance(0)->getXmlDataManager()->parseDocument(lSVGFile);

    gvFreeLayout(lGvc, lGraph);
    agclose(lGraph);
    gvFreeContext(lGvc);

    remove(lTmpFile.c_str());
  } catch (...) {
    aItem = NULL;
    if (lGraph) {
      gvFreeLayout(lGvc, lGraph);
      agclose(lGraph);
    }
    gvFreeContext(lGvc);
    throw;
  }

  return true;

} /* DotFunction::LazyDotSequence::next */

/******************************************************************************
 *****************************************************************************/
Iterator_t GxlFunction::LazyGxlSequence::getIterator()
{
  return new GxlFunction::LazyGxlSequence::InternalIterator(this);
}

GxlFunction::LazyGxlSequence::InternalIterator::InternalIterator(LazyGxlSequence *item_sequence) :
  theItemSequence(item_sequence), is_open(false)
{
  arg_iter = item_sequence->theArg->getIterator();
}

void GxlFunction::LazyGxlSequence::InternalIterator::open()
{
  is_open = true;
  arg_iter->open();
}

void GxlFunction::LazyGxlSequence::InternalIterator::close()
{
  is_open = false;
  arg_iter->close();
}

bool GxlFunction::LazyGxlSequence::InternalIterator::isOpen() const
{
  return is_open;
}

bool
GxlFunction::LazyGxlSequence::InternalIterator::next(Item& aItem)
{
  if(!is_open)
  {
    throw zorba::ExternalFunctionData::createZorbaException(XQP0019_INTERNAL_ERROR,
      "GxlFunction::LazyGxlSequence Iterator consumed without open", __FILE__, __LINE__);  
  }
  Item              lItem;
  Agraph_t          *lGraph = 0;
  GVC_t             *lGvc = 0;
  std::fstream       lSVGFile;
  FILE              *lFile = 0;

  if (!arg_iter->next(lItem)) // exhausted
    return false;

  lGvc = gvContext();

  try {

    std::string lTmpFile = theItemSequence->theFunc->getGraphvizTmpFileName();
    lSVGFile.open(lTmpFile.c_str(),
        std::fstream::in | std::fstream::out | std::fstream::trunc);

    gxl2dot(theItemSequence->theFunc->theModule->getItemFactory(), lItem, lSVGFile);
    lSVGFile.close();

    lFile = fopen(lTmpFile.c_str(), "r");
    if (!lFile) {
      std::ostringstream lErrorMsg;
      lErrorMsg << "could not read from file " << lTmpFile.c_str();
      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
          lErrorMsg.str(), __FILE__, __LINE__);
    }

    lGraph = agread(lFile);
    fclose(lFile);

    if (!lGraph) {
      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
          "could not read input", __FILE__, __LINE__);
    }

    int blub =  gvLayout(lGvc, lGraph, const_cast<char*>("dot"));
    if ( blub != 0 ) {
      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
          "could not generate layout", __FILE__, __LINE__);
    }

    if ( gvRenderFilename(lGvc, lGraph, const_cast<char*>("svg"),
                          const_cast<char*>(lTmpFile.c_str())) != 0 )  {
      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
          "could not render graph", __FILE__, __LINE__);
    }

    lSVGFile.open(lTmpFile.c_str(), std::ifstream::in);
    if (lSVGFile.bad()) {
      std::ostringstream lErrorMsg;
      lErrorMsg << "could not read from file " << lTmpFile.c_str();
      throw ExternalFunctionData::createZorbaException(XQP0000_DYNAMIC_RUNTIME_ERROR,
          lErrorMsg.str(), __FILE__, __LINE__);
    }

    aItem = Zorba::getInstance(0)->getXmlDataManager()->parseDocument(lSVGFile);

    gvFreeLayout(lGvc, lGraph);
    agclose(lGraph);
    gvFreeContext(lGvc);

    remove(lTmpFile.c_str());
  } catch (...) {
    if (lGraph) {
      gvFreeLayout(lGvc, lGraph);
      agclose(lGraph);
    }
    gvFreeContext(lGvc);
    throw;
  }

  return true;

} /* GxlFunction::LazyGxlSequence::next */

/******************************************************************************
 *****************************************************************************/
GxlFunction::LazyGxlSequence::LazyGxlSequence(const GxlFunction* aFunc,
    ItemSequence* aArg)
  : theFunc(aFunc),
    theArg(aArg)
{
}

/******************************************************************************
 *****************************************************************************/
zorba::ItemSequence_t
DotFunction::evaluate(
  const Arguments_t& aArgs,
  const zorba::StaticContext* aSctx,
  const zorba::DynamicContext* aDctx) const
{
  return ItemSequence_t(new LazyDotSequence(this, aArgs[0]));
} /* DotFunction::evaluate */

/******************************************************************************
 *****************************************************************************/
zorba::ItemSequence_t
GxlFunction::evaluate(
  const Arguments_t& aArgs,
  const zorba::StaticContext* aSctx,
  const zorba::DynamicContext* aDctx) const
{
  return ItemSequence_t(new LazyGxlSequence(this, aArgs[0]));
} /* GxlFunction::evaluate */

/******************************************************************************
 *****************************************************************************/
ItemFactory* GraphvizModule::theFactory = 0;


GraphvizModule::~GraphvizModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) {
    delete lIter->second;
       }
       theFunctions.clear();
}

zorba::StatelessExternalFunction*
GraphvizModule::getExternalFunction(const String& aLocalname)
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (1 == 0) {}
    else if (aLocalname.equals("dot"))
    {
      lFunc = new DotFunction(this);
    } else if (aLocalname.equals("gxl"))
    {
      lFunc = new GxlFunction(this);
    }
    }
  return lFunc;
}

void
GraphvizModule::destroy()
{
  if (!dynamic_cast<GraphvizModule*>(this)) {
    return;
  }
  delete this;
}

  } /* namespace zorba */
} /* namespace graphvizmodule */

/******************************************************************************
 *****************************************************************************/
#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::graphvizmodule::GraphvizModule();
}