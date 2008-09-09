
#include <atlconv.h>
#include <atlbase.h>

#include "store/naive/msdom_addon/import_msdom.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"

#include "zorbaerrors/Assert.h"

namespace zorba {
namespace simplestore 
{

ImportMSDOM::ImportMSDOM(store::ItemFactory *factory)
{
  this->theFactory = factory;
  rootNode = NULL;
  xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
  xmlTree->during_import_DOM = true;
}

ImportMSDOM::~ImportMSDOM()
{
  xmlTree->during_import_DOM = false;
}

char *ImportMSDOM::fromBSTR(BSTR inbstr)
{
  int   len;
  char  *outstr;

  len = WideCharToMultiByte(CP_UTF8, 0, inbstr, -1, NULL, 0, NULL, NULL);
  outstr = (char*)malloc(len+1);
  WideCharToMultiByte(CP_UTF8, 0, inbstr, -1, outstr, len, NULL, NULL);
  outstr[len] = 0;
  return outstr;
}

rchandle<XmlNode>   ImportMSDOM::importMSDOM(IXMLDOMNode* domNode,
                              xqpStringStore_t docUri,
                              xqpStringStore_t baseUri)
{
  theDocUri = docUri;
  theBaseUri = baseUri;

  HRESULT      hr;
  DOMNodeType  node_type;

  IXMLDOMDocument *owner_document;
  domNode->get_ownerDocument(&owner_document);
  xmlTree->setDOMcreator(owner_document);

  hr = domNode->get_nodeType(&node_type);
  if(FAILED(hr))
    return NULL;

  if(node_type == NODE_INVALID)
    return NULL;

  if((node_type != NODE_DOCUMENT) && (node_type != NODE_DOCUMENT_FRAGMENT))
  {
    import_document(NULL, NULL);
  }
  
  if(!import_node(domNode))
    return false;

  if((node_type != NODE_DOCUMENT) && (node_type != NODE_DOCUMENT_FRAGMENT))
  {
    end_document();
  }
  return rootNode;
}

bool ImportMSDOM::import_node(IXMLDOMNode *domNode)
{
  HRESULT      hr;
  DOMNodeType  node_type;

  hr = domNode->get_nodeType(&node_type);
  if(FAILED(hr))
    return false;

  if(node_type == NODE_INVALID)
    return false;


  //start import node
  switch(node_type)
  {
	case NODE_ELEMENT:
  {
    IXMLDOMElement  *dom_element;
    hr = domNode->QueryInterface(IID_IXMLDOMElement, (void**)&dom_element);
    if(FAILED(hr))
      return false;
    if(!import_element(dom_element))
      return false;
    dom_element->Release();
  }break;
	case NODE_ATTRIBUTE: return false;//unreachable
	case NODE_TEXT:
	case NODE_CDATA_SECTION:
  {
    IXMLDOMText  *dom_text;
    hr = domNode->QueryInterface(IID_IXMLDOMText, (void**)&dom_text);
    if(FAILED(hr))
      return false;
    if(!import_characters(dom_text))
      return false;
    dom_text->Release();
  }break;
	case NODE_ENTITY_REFERENCE: return true;//ignore
	case NODE_ENTITY: return true;//ignore
	case NODE_PROCESSING_INSTRUCTION:
  {
    IXMLDOMProcessingInstruction  *dom_pi;
    hr = domNode->QueryInterface(IID_IXMLDOMProcessingInstruction, (void**)&dom_pi);
    if(FAILED(hr))
      return false;
    if(!import_pi(dom_pi))
      return false;
    dom_pi->Release();
  }break;
	case NODE_COMMENT:
  {
    IXMLDOMComment  *dom_comment;
    hr = domNode->QueryInterface(IID_IXMLDOMComment, (void**)&dom_comment);
    if(FAILED(hr))
      return false;
    if(!import_comment(dom_comment))
      return false;
    dom_comment->Release();
  }break;
	case NODE_DOCUMENT:
  {
    IXMLDOMDocument  *dom_doc;
    hr = domNode->QueryInterface(IID_IXMLDOMDocument, (void**)&dom_doc);
    if(FAILED(hr))
      return false;
    import_document(dom_doc, NULL);
    dom_doc->Release();
  }break;
	case NODE_DOCUMENT_TYPE: return true;//ignore
	case NODE_DOCUMENT_FRAGMENT:
  {
    IXMLDOMDocumentFragment  *dom_docfrag;
    hr = domNode->QueryInterface(IID_IXMLDOMDocumentFragment, (void**)&dom_docfrag);
    if(FAILED(hr))
      return false;
    import_document(NULL, dom_docfrag);
    dom_docfrag->Release();
  }break;
	case NODE_NOTATION: return true;//ignore
  default: return true;//ignore
  }

  //import kids
  switch(node_type)
  {
	case NODE_ELEMENT:
	case NODE_DOCUMENT:
	case NODE_DOCUMENT_FRAGMENT:
    {
      IXMLDOMNodeList *childList;
      IXMLDOMNode     *child_node;
      hr = domNode->get_childNodes(&childList);
      while(childList->nextNode(&child_node) == S_OK)
      {
        if(!import_node(child_node))
          return false;
      }
    }break;
  }

  //end import node
  switch(node_type)
  {
	case NODE_ELEMENT:
    end_element();
    break;
	case NODE_DOCUMENT:
	case NODE_DOCUMENT_FRAGMENT:
    end_document();
    break;
  }

  return true;
}

void ImportMSDOM::import_document(IXMLDOMDocument *dom_doc, IXMLDOMDocumentFragment *dom_frag)
{
  DocumentNode* n = NULL;

  n = new DocumentTreeNode(xmlTree, theBaseUri, theDocUri, dom_doc, dom_frag);

  if(!rootNode)
    rootNode = n;

  elem_stack.push(n);
}

void ImportMSDOM::end_document()
{
  if (elem_stack.size() == 0 )
    return;

  XmlNode* docNode = elem_stack.top();
  elem_stack.pop();

  ZORBA_ASSERT(docNode != NULL);

  docNode->finalizeNode();
}

bool ImportMSDOM::import_element(IXMLDOMElement *dom_elem)
{
  BSTR  elem_basename;
  char  *char_basename;
  BSTR  elem_prefix;
  char  *char_prefix;
  BSTR  elem_namespace;
  char  *char_namespace;
  HRESULT hr;

  hr = dom_elem->get_baseName(&elem_basename);
  if(FAILED(hr))
    return false;
  
  hr = dom_elem->get_prefix(&elem_prefix);
  if(FAILED(hr))
    return false;

  hr = dom_elem->get_namespaceURI(&elem_namespace);
  if(FAILED(hr))
    return false;

  char_basename = fromBSTR(elem_basename);
  char_prefix = fromBSTR(elem_prefix);
  char_namespace = fromBSTR(elem_namespace);
  
  


  {
    ulong numAttributes = 0;//(ulong)numAttrs;
    ulong numBindings = 0;//(ulong)numNamespaces;

    XmlNode* parent = NULL;
    store::Item_t qname;
    store::Item_t tname;
    store::Item_t nullValue;
    xqpStringStore_t baseUri;

    // Get the parent node from the node stack
    if (!elem_stack.empty())
      parent = elem_stack.top();

    // Construct node name and type
    theFactory->createQName(qname,
                             char_namespace,
                             char_prefix,
                             char_basename);
    theFactory->createQName(tname,
                             "http://www.w3.org/2001/XMLSchema",
                             "xs",
                             "untyped");

    // If this is going to be the root of the xml tree, give it the input base uri
    if (parent == NULL)
      baseUri = theBaseUri;

    // Process namespace bindings (they are kept as attributes in MS DOM)
    store::NsBindings bindings;//(numBindings);
    IXMLDOMNamedNodeMap   *attr_nodes;
    dom_elem->get_attributes(&attr_nodes);
    long i;
    long  attr_count;
    attr_nodes->get_length(&attr_count);
    for (i = 0; i < attr_count; ++i)
    {
    //  const char* prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
    //  const char* nsuri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);
      IXMLDOMNode   *attr;
      std::pair<xqpString, xqpString>     nsb;
      BSTR  attr_basename;
      BSTR  attr_prefix;
      bool  is_ns = false;
      BSTR  ns_bstr_prefix;

      attr_nodes->get_item(i, &attr);

      attr->get_baseName(&attr_basename);
      attr->get_prefix(&attr_prefix);
      CComBSTR  bstr_prefix(attr_prefix);
      CComBSTR  bstr_basename(attr_basename);
      if(bstr_prefix == "xmlns")
      {
        is_ns = true;
        ns_bstr_prefix = attr_basename;
      }
      else if(bstr_prefix == "")
      {
        if(bstr_basename == "xmlns")
        {
          is_ns = true;
          CComBSTR  empty_prefix("");
          ns_bstr_prefix = empty_prefix.Detach();
        }
      }

      if(is_ns)
      {
        VARIANT attr_value;
        attr->get_nodeValue(&attr_value);
        
        char  *char_prefix;
        char  *char_uri;

        char_prefix = fromBSTR(ns_bstr_prefix);
        char_uri = fromBSTR(attr_value.bstrVal);

        nsb.first = char_prefix;
        nsb.second = char_uri;
        bindings.push_back(nsb);

        free(char_prefix);
        free(char_uri);

        numBindings++;
      }
      else
      {
        numAttributes++;
      }
    }

    // Create the element node and push it to the node stack
    ElementNode *n;
    n = new ElementTreeNode(xmlTree, parent, -1, qname,
                            tname, 
                            true,//haveTypedValue, 
                            false,//haveEmptyValue,
                            false,//isId, 
                            false,//isIdRefs,
                            &bindings, 
                            baseUri,
                            dom_elem);
    if (!rootNode)
      rootNode = n;

    elem_stack.push(n);

    // Process attributes

    theFactory->createQName(tname,
                             "http://www.w3.org/2001/XMLSchema",
                             "xs",
                             "untypedAtomic");
    for (i = 0; i < attr_count; ++i)
    {
      //const char* lname = reinterpret_cast<const char*>(attributes[index]);
      //const char* prefix = reinterpret_cast<const char*>(attributes[index+1]);
      //const char* uri = reinterpret_cast<const char*>(attributes[index+2]);
      //const char* valueBegin = reinterpret_cast<const char*>(attributes[index+3]);
      //const char* valueEnd = reinterpret_cast<const char*>(attributes[index+4]);
      IXMLDOMNode   *attr;
      BSTR  attr_basename;
      BSTR  attr_prefix;
      //BSTR  ns_bstr_prefix;

      attr_nodes->get_item(i, &attr);

      attr->get_baseName(&attr_basename);
      attr->get_prefix(&attr_prefix);
      CComBSTR  bstr_prefix(attr_prefix);
      CComBSTR  bstr_basename(attr_basename);
      if((bstr_prefix != "xmlns") && ((bstr_prefix != "") || (bstr_basename != "xmlns")))
      {
        char  *char_uri;
        char  *char_prefix;
        char  *char_lname;
        BSTR  attr_uri;
        attr->get_namespaceURI(&attr_uri);
        char_uri = fromBSTR(attr_uri);
        char_prefix = fromBSTR(attr_prefix);
        char_lname = fromBSTR(attr_basename);
        theFactory->createQName(qname, char_uri, char_prefix, char_lname);

        free(char_uri);
        free(char_prefix);
        free(char_lname);

        VARIANT  attr_value;
        attr->get_nodeValue(&attr_value);
        char  *char_value = fromBSTR(attr_value.bstrVal);
        xqpStringStore_t  stringValue = new xqpStringStore(char_value);
        free(char_value);
        store::Item_t typedValue;
        theFactory->createUntypedAtomic(typedValue, stringValue);

        store::Item_t tnameCopy = tname;
        //store::Item_t attr_item;
        IXMLDOMAttribute  *dom_attr;
        attr->QueryInterface(IID_IXMLDOMAttribute, (void**)&dom_attr);
        new AttributeNode(xmlTree, n, -1,
                          qname, tnameCopy, typedValue, 
                          false,//isId, 
                          false,//isIdRefs, 
                          false,//isIdRefs
                          false,//hidden
                          dom_attr);
        dom_attr->Release();

      }
    }
  }


  ::free(char_basename);
  ::free(char_prefix);
  ::free(char_namespace);
  return true;
}

bool ImportMSDOM::end_element()
{
  {
    store::Item* node = elem_stack.top();
    ZORBA_ASSERT(node != NULL);
    elem_stack.pop();

    node->finalizeNode();

  }
  return true;
}

bool ImportMSDOM::import_characters(IXMLDOMText *dom_text)
{
  {
    XmlNode* parent = NULL;

    // Get the parent node from the node stack
    if (!elem_stack.empty())
      parent = elem_stack.top();

    // Get the text content
    VARIANT  var_text;
    dom_text->get_nodeValue(&var_text);
    char* charp = fromBSTR(var_text.bstrVal);
    xqpStringStore_t content(new xqpStringStore(charp));
    ::free(charp);

    // Create the text node
    TextNode *node;
    node = new TextNode(xmlTree, parent, -1, content, dom_text);

    if (elem_stack.empty())
      rootNode = node;

  }

  return true;
}

bool ImportMSDOM::import_pi(IXMLDOMProcessingInstruction *dom_pi)
{
  {
    XmlNode* parent = NULL;

    // Get the parent node from the node stack
    if (!elem_stack.empty())
      parent = elem_stack.top();

    BSTR  bstr_data;
    BSTR  bstr_target;
    char  *data;
    char  *targetp;

    dom_pi->get_data(&bstr_data);
    dom_pi->get_target(&bstr_target);
    data = fromBSTR(bstr_data);
    targetp = fromBSTR(bstr_target);

    xqpStringStore_t content = new xqpStringStore(reinterpret_cast<const char*>(data));
    xqpStringStore_t target = new xqpStringStore(reinterpret_cast<const char*>(targetp));

    ::free(data);
    ::free(targetp);

    PiNode  *node;
    node = new PiNode(xmlTree, parent, -1, target, content, dom_pi);

    if (elem_stack.empty())
      rootNode = node;
  }

  return true;
}

bool ImportMSDOM::import_comment(IXMLDOMComment *dom_comment)
{
  {
    XmlNode* parent = NULL;

    // Get the parent node from the node stack
    if (!elem_stack.empty())
      parent = elem_stack.top();

    char* charp;
    VARIANT  var_comment;

    dom_comment->get_nodeValue(&var_comment);
    charp = fromBSTR(var_comment.bstrVal);
    xqpStringStore_t content(new xqpStringStore(charp));
    ::free(charp);

    CommentNode *n;
    n = new CommentNode(xmlTree, parent, -1, content, dom_comment);

    if (elem_stack.empty())
      rootNode = n;

  }
  return true;
}




////////////////////////////////////////
CMyBSTR::CMyBSTR(const char* str)
{
  int   len;
  LPWSTR  outstr;

  len = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
  outstr = (wchar_t*)malloc(sizeof(wchar_t)*(len+1));
  MultiByteToWideChar(CP_UTF8, 0, str, -1, outstr, len);
  outstr[len] = 0;

  internal_bstr = SysAllocString(outstr);
  free(outstr);
}

CMyBSTR::~CMyBSTR()
{
  ::SysFreeString(internal_bstr);
}

CMyBSTR::operator BSTR()
{
  return internal_bstr;
}



} // namespace simplestore
} // namespace zorba
