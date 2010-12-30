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
#include "testdriver_comparator.h"

// used for Canonical XML
#define LIBXML_C14N_ENABLED
#define LIBXML_OUTPUT_ENABLED
#include <libxml/c14n.h>
#include <libxml/tree.h>

#include <sstream>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string.h>


namespace zorba {


/*******************************************************************************

********************************************************************************/
bool compareDOMChildren(xmlNode  *child1, xmlNode  *child2);
bool compareNodeName(xmlNode  *node1, xmlNode  *node2);
bool compareNS(xmlNode  *node1, xmlNode  *node2);
bool compareAttr(xmlAttr *attr1, xmlAttr *attr2);

//recursive DOM comparison of XML
bool compareDOM(xmlNode  *node1, xmlNode  *node2)
{
  if((node1==NULL) || (node2==NULL) || (node1->type != node2->type))
    return false;


  switch(node1->type)
  {
  case XML_DOCUMENT_NODE:
  case XML_DOCUMENT_FRAG_NODE:
    return compareDOMChildren(node1->children, node2->children);
  case XML_TEXT_NODE:
  case XML_CDATA_SECTION_NODE:
  case XML_COMMENT_NODE:
    if(strcmp((const char*)node1->content, (const char*)node2->content))
      return false;
    return true;
  case XML_ELEMENT_NODE:
  {
    //xmlElement *elem1 = static_cast<xmlElement*>(node1);
    // xmlElement *elem2 = static_cast<xmlElement*>(node2);
    if(!compareNodeName(node1, node2))
      return false;
    if(!compareNS(node1, node2))
      return false;
    if(!compareAttr(node1->properties, node2->properties))
      return false;
    return compareDOMChildren(node1->children, node2->children);
  }
  case XML_PI_NODE:
    if(strcmp((const char*)node1->name, (const char*)node2->name))
      return false;
    if(!node1->content && node2->content)
      if(node2->content[0])
        return false;
      else
        return true;
    if(!node2->content && node1->content)
      if(node1->content[0])
        return false;
      else
        return true;
    if(!node1->content && !node2->content)
      return true;
    if(strcmp((const char*)node1->content, (const char*)node2->content))
      return false;
    return true;
  default:
    assert(false);//more to implement here
  }
  return true;
}

bool text_is_whitespace(const char *str)
{
  while(*str && isascii(*str) && isspace(*str))
    str++;
  return str[0] == 0;
}
bool compareDOMChildren(xmlNode  *child1, xmlNode  *child2)
{
  while(child1 && child2)
  {
    if(child1->type == XML_TEXT_NODE && text_is_whitespace((const char*)child1->content))
    {
      child1 = child1->next;
      continue;
    }
    if(child2->type == XML_TEXT_NODE && text_is_whitespace((const char*)child2->content))
    {
      child2 = child2->next;
      continue;
    }
    if(!compareDOM(child1, child2))
      return false;
    child1 = child1->next;
    child2 = child2->next;
  }
  if(child1)
  {
    while(child1 && (child1->type == XML_TEXT_NODE) && text_is_whitespace((const char*)child1->content))
    {
      child1 = child1->next;
      continue;
    }
    if(child1)
      return false;
  }
  if(child2)
  {
    while(child2 && (child2->type == XML_TEXT_NODE) && text_is_whitespace((const char*)child2->content))
    {
      child2 = child2->next;
      continue;
    }
    if(child2)
      return false;
  }
  return true;
}
bool compareNodeName(xmlNode  *node1, xmlNode  *node2)
{
  if(strcmp((const char*)node1->name, (const char*)node2->name))
    return false;
  if(node1->ns && !node2->ns)
    return false;
  if(!node1->ns && node2->ns)
    return false;
  if(node1->ns == node2->ns || !strcmp((const char*)node1->ns->href, (const char*)node2->ns->href))
    return true;
  return false;
}

bool compareAttrName(xmlAttr  *attr1, xmlAttr  *attr2)
{
  if(strcmp((const char*)attr1->name, (const char*)attr2->name))
    return false;
  if(attr1->ns && !attr2->ns)
    return false;
  if(!attr1->ns && attr2->ns)
    return false;
  if(attr1->ns == attr2->ns || !strcmp((const char*)attr1->ns->href, (const char*)attr2->ns->href))
    return true;
  return false;
}

bool compareNS(xmlNode  *node1, xmlNode  *node2)
{
  xmlNs *ns1 = node1->nsDef;
  if(ns1 == NULL && node2->nsDef)
    return false;
  int nr_ns1 = 0;
  int nr_ns2 = 0;
  while(ns1)
  {
    xmlNs *ns2 = node2->nsDef;
    int n = 0;
    while(ns2)
    {
      n++;
      if(!strcmp((const char*)ns1->href, (const char*)ns2->href))
        break;
      ns2 = ns2->next;
    }
    if(!ns2)
      return false;
    if(n > nr_ns2)
      nr_ns2 = n;
    nr_ns1++;
    ns1 = ns1->next;
  }
  if(nr_ns1 != nr_ns2)
    return false;
  return true;
}

bool compareAttr(xmlAttr *attr1, xmlAttr *attr2)
{
  if(!attr1 && attr2)
    return false;
  if(attr1 && !attr2)
    return false;
  int nr_attr1 = 0;
  int nr_attr2 = 0;
  while(attr1)
  {
    xmlAttr *a2 = attr2;
    int n = 0;
    while(a2)
    {
      n++;
      if(compareAttrName(attr1, a2))
      {
        if(strcmp((const char*)attr1->children->content, (const char*)a2->children->content))
          return false;
        break;
      }
      a2 = a2->next;
    }
    if(!a2)
      return false;
    if(n > nr_attr2)
      nr_attr2 = n;
    nr_attr1++;
    attr1 = attr1->next;
  }
  if(nr_attr1 != nr_attr2)
    return false;
  return true;
}

int canonicalizeAndCompare(
    const std::string& aComparisonMethod,
    const char* aRefFile,
    const char* aResultFile,
    const std::string& aRBKTBinDir,
    std::ostream& aOutput)
{
  xmlDocPtr lRefResult_ptr;
  xmlDocPtr lResult_ptr;
  
  LIBXML_TEST_VERSION

  int libxmlFlags = XML_PARSE_NOBLANKS;

  if (aComparisonMethod.compare("XML") == 0) 
  {
    lRefResult_ptr = xmlReadFile(aRefFile, 0, 0);
    lResult_ptr    = xmlReadFile(aResultFile, 0, 0);
  }
  else if (aComparisonMethod.compare("Text") == 0 ||
           aComparisonMethod.compare("Fragment") == 0) 
  {
    // prepend and append an artifical root tag as requested by the guidelines
    std::ostringstream lTmpRefResult;
    lTmpRefResult << "<root>";
    std::ifstream lRefInStream(aRefFile);
    if (!lRefInStream.good())
    {
      aOutput << "Failed to open ref file " << aRefFile << std::endl;
      return 8;
    }

    char buf[2048];
    char buf2[2048];
    char* bufp;
    char* bufp2;
    char* bufend = (buf + 2048);

    while (!lRefInStream.eof()) 
    {
      memset(buf, 0, 2048);
      memset(buf2, 0, 2048);

      lRefInStream.read(buf, 2048);

      bufp = buf;
      bufp2 = buf2;

      // Skip xml declaration, if any
      if (!strncmp(bufp, "<?xml", 5))
      {
        while (*bufp != '\n' && strncmp(bufp, "?>", 2))
        {
          ++bufp;
        }

        if (*bufp == '?')
          bufp += 2;

        if (*bufp == '\r')
          ++bufp;

        if (*bufp == '\n')
          ++bufp;
      }

      // Convert \r\n to \n
      while (bufp != bufend && *bufp != '\0')
      {
        if (*bufp == '\r' && bufp+1 != bufend && *(bufp+1) == '\n')
          ++bufp;

        *bufp2 = *bufp;

        ++bufp;
        ++bufp2;
      }

//       if (*bufp == '\0')
//         *bufp2 = *bufp;

      lTmpRefResult.write(buf2, (std::streamsize)(bufp2 - buf2));
    }

    lTmpRefResult << "</root>";

    lRefResult_ptr = xmlReadMemory(lTmpRefResult.str().c_str(),
                                   (int)lTmpRefResult.str().size(),
                                   "ref_result.xml", 0, libxmlFlags);

    // prepend and append an artifical root tag as requested by the guidelines
    std::ostringstream lTmpResult;
    lTmpResult << "<root>";
    std::ifstream lInStream(aResultFile);
    if (!lInStream.good())
    {
      aOutput << "Failed to open result file " << aResultFile << std::endl;
      return 8;
    }

    while (!lInStream.eof()) 
    {
      memset(buf, 0, 2048);

      lInStream.read(buf, 2048);

      lTmpResult.write(buf, lInStream.gcount());
    }

    lTmpResult << "</root>";

    lResult_ptr = xmlReadMemory(lTmpResult.str().c_str(),
                                (int)lTmpResult.str().size(),
                                "result.xml", 0, libxmlFlags);
    
  }
  else if (aComparisonMethod.compare("Error") == 0 ) 
  {
    aOutput << "an error was expected but we got a result" << std::endl;
    return 8;
  }
  else if (aComparisonMethod.compare("Inspect") == 0 ) 
  {
    aOutput << "result must be inspected by humans." << std::endl;
    return 0;
  }
  else if (aComparisonMethod.compare("Ignore") == 0 ) 
  {
    // safely return no error here
    return 0;
  }
  else 
  {
    aOutput << "comparison method not supported: " << aComparisonMethod << std::endl;
    return 9;
  }

  if (lRefResult_ptr == NULL || lResult_ptr == NULL) 
  {
    std::cerr << "couldn't read reference result or result file" << std::endl;
    return 8;
  }

  if(compareDOMChildren(lRefResult_ptr->children, lResult_ptr->children))
    return 0;

  std::string lCanonicalRefFile = aRBKTBinDir + "/canonical_ref.xml";
  std::string lCanonicalResFile = aRBKTBinDir + "/canonical_res.xml";

  int lRefResultRes = xmlC14NDocSave(lRefResult_ptr, 0, 0, NULL, 0, lCanonicalRefFile.c_str(), 0);
  int lResultRes    = xmlC14NDocSave(lResult_ptr, 0, 0, NULL, 0, lCanonicalResFile.c_str(), 0);

  xmlFreeDoc(lRefResult_ptr);
  xmlFreeDoc(lResult_ptr);

  if (lRefResultRes < 0) 
  {
    std::cerr << "error canonicalizing reference result" << std::endl;
    return 10;
  }
  
  if (lResultRes < 0) 
  {
    std::cerr << "error canonicalizing result" << std::endl;
    return 10;
  }

  // last, we have to diff the result
  int lLine, lCol; // where do the files differ
  std::string lRefLine, lResultLine;
  bool lRes = fileEquals(lCanonicalRefFile.c_str(),
                         lCanonicalResFile.c_str(),
                         lLine, lCol, lRefLine, lResultLine);
  if (!lRes) 
  {
    aOutput << std::endl
              << "Actual and Reference canonical results are not identical"
              << std::endl << std::endl
              << "Actual Canonical Result: "
              << std::endl << std::endl;

    printFile(aOutput, lCanonicalResFile);

    aOutput << std::endl << std::endl;

    aOutput << "Reference Canonical Result: "
              << std::endl << std::endl;

    zorba::printFile(aOutput, lCanonicalRefFile);

    aOutput << std::endl << std::endl;

    aOutput << "See line " << lLine << ", col " << lCol 
              << " of expected result. " << std::endl;
    aOutput << "Actual:   <";
    aOutput << lResultLine;

    aOutput << ">" << std::endl;
    aOutput << "Expected: <";
    aOutput << lRefLine;

    aOutput << ">" << std::endl;

    return 8;
  }
  return 0;

}

/*******************************************************************************
  Return false if the files are not equal.
  aLine contains the line number in which the first difference occurs
  aCol contains the column number in which the first difference occurs
  -1 is returned for aLine and aCol if the files are equal
********************************************************************************/
bool fileEquals(
    const char* aRefFile,
    const char* aResFile,
    int& aLine,
    int& aCol,
    std::string& aRefLine,
    std::string& aResLine,
    std::ostream& aOutput)
{
  std::ifstream refStream(aRefFile);
  std::ifstream resStream(aResFile);
  std::string refLine, resLine;

  if (!refStream.good())
  {
    aOutput << "Failed to open ref file " << aRefFile << std::endl;
    return false;
  }

  if (!resStream.good())
  {
    aOutput << "Failed to open results file " << aResFile << std::endl;
    return false;
  }

  aLine = 1;
  aCol = 0;
  while (! refStream.eof() )
  {
    if ( resStream.eof() ) 
    {
      std::getline(refStream, refLine);
      if (refStream.peek() == -1) // ignore end-of-line in the ref result
        return true;
      else 
        return false;
    }

    std::getline(refStream, refLine);
    std::getline(resStream, resLine);

    while (refLine.compare(resLine) != 0) 
    {
      // Lines did not match, but certain mismatches are overlooked.
      // 1. If the first line of the reference results is an XML
      // declaration, ignore that.
      if (aLine == 1 &&
          refLine == "<?xml version=\"1.0\" encoding=\"UTF-8\"?>")
      {
        ++aLine; 
        std::getline(refStream, refLine);
        continue;
      }
      else
      {
        // Find the column of the mismatch
        for(aCol=0;
            aCol < (int)refLine.length() && aCol < (int)resLine.length();
            aCol++)
        {
          if(refLine.c_str()[aCol] != resLine.c_str()[aCol])
            break;
        }

        // 2. If the lines didn't match only because of an extra \r at
        // the end of the reference results line, ignore that.
        if (aCol == (int)resLine.length() && refLine.c_str()[aCol] == '\r')
        {
          break;
        }

        // Ok, actual mismatch. Send back the reference and result
        // lines and return false.
        aRefLine = refLine;
        aResLine = resLine;
        return false;
      }
    }

    ++aLine;
  }

  if (! resStream.eof() ) 
  {
    std::getline(resStream, resLine);

    if (resStream.peek() == -1) // ignore end-of-line in the actual result
    {
      return true;
    }
    else
    { 
      aResLine = resLine;
      return false;
    }
  }
  return true;

}


/*******************************************************************************
  Print parts of a file starting at aStartPos with the length of aLen
********************************************************************************/
void
printPart(std::ostream& os, const std::string &aInFile, int aStartPos, int aLen)
{
  char* buffer = new char [aLen];
  try {
    std::ifstream lIn(aInFile.c_str());
    lIn.seekg(aStartPos);

    std::streamsize lCharsRead = lIn.readsome (buffer, aLen);
    os.write (buffer, lCharsRead);
    os.flush();
    delete[] buffer;
  } catch (...)
  {
    delete[] buffer;
  }
  return;
}


/*******************************************************************************

********************************************************************************/
void
printFile(std::ostream& os, const std::string &aInFile)
{
  std::ifstream lInFileStream(aInFile.c_str());
  assert(lInFileStream.good());
  if(!lInFileStream.good())
  {
    exit(1);
  }

  char buf[1024];
  while (!lInFileStream.eof()) {
    lInFileStream.read(buf, 1024);
    os.write(buf, lInFileStream.gcount());
  }
  os << std::endl;
}


} /* namespace zorba */
