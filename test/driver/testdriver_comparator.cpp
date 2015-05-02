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

#ifdef _MSC_VER
#pragma warning (disable : 4309 ) //0xEF, 0xBB, 0xBF are out of the value space of 
//char and will be converted to negative values
#endif

namespace zorba {


/*******************************************************************************

********************************************************************************/
int canonicalizeAndCompare(
    const std::string& aComparisonMethod,
    const char* aRefFile,
    const char* aResultFile,
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

  // Form filenames to output canonicalized files based on the *actual* result
  // filename, since that will be in the build dir and unique to this test
  std::string lCanonicalRefFile(aResultFile);
  lCanonicalRefFile.append( ".canonical_ref.xml");
  std::string lCanonicalResFile(aResultFile);
  lCanonicalResFile.append(".canonical_res.xml");

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
#if 0
    aOutput << "See line " << lLine << ", col " << lCol 
              << " of expected result. " << std::endl;
    aOutput << "Actual:   <";
    aOutput << lResultLine;

    aOutput << ">" << std::endl;
    aOutput << "Expected: <";
    aOutput << lRefLine;

    aOutput << ">" << std::endl;
#endif
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

  // Consume a leading byte-order-mark
  char bom[3] = { '\0' };
  refStream.read(bom, 3);
  if (bom[0] != static_cast<char>(0xEF) ||
    bom[1] != static_cast<char>(0xBB) ||
    bom[2] != static_cast<char>(0xBF))
  {
    // Wasn't a BOM; 'unread' it
    refStream.clear();
    refStream.seekg(0, std::ios_base::beg);
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
