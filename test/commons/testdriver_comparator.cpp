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

namespace zorba {

int
canonicalizeAndCompare(const std::string& aComparisonMethod,
                       const char* aRefFile,
                       const char* aResultFile,
                       const std::string& aRBKTBinDir)
{
  xmlDocPtr lRefResult_ptr;
  xmlDocPtr lResult_ptr;
  
  LIBXML_TEST_VERSION

  if (aComparisonMethod.compare("XML") == 0) {
    lRefResult_ptr = xmlReadFile(aRefFile, 0, 0);
    lResult_ptr    = xmlReadFile(aResultFile, 0, 0);
  } else if (aComparisonMethod.compare("Text") == 0 || aComparisonMethod.compare("Fragment") == 0) {
    // prepend and append an artifical root tag as requested by the guidelines
    std::ostringstream lTmpRefResult;
    lTmpRefResult << "<root>" << std::endl;
    std::ifstream lRefInStream(aRefFile);
    char buf[1024];

    while (!lRefInStream.eof()) {
      lRefInStream.read(buf, 1024);
      lTmpRefResult.write(buf, lRefInStream.gcount());
    }
    if (buf[lRefInStream.gcount()-1] != '\n')
      lTmpRefResult << std::endl;
    lTmpRefResult << "</root>";
    lRefResult_ptr = xmlReadMemory(lTmpRefResult.str().c_str(), lTmpRefResult.str().size(), "ref_result.xml", 0, 0);

    // prepend and append an artifical root tag as requested by the guidelines
    std::ostringstream lTmpResult;
    lTmpResult << "<root>" << std::endl;
    std::ifstream lInStream(aResultFile);

    while (!lInStream.eof()) {
      lInStream.read(buf, 1024);
      lTmpResult.write(buf, lInStream.gcount());
    }
    lTmpResult << std::endl << "</root>";
    lResult_ptr = xmlReadMemory(lTmpResult.str().c_str(), lTmpResult.str().size(), "result.xml", 0, 0);
    
  } else if (aComparisonMethod.compare("Error") == 0 ) {
    std::cout << "an error was expected but we got a result" << std::endl;
    return 8;
  } else if (aComparisonMethod.compare("Inspect") == 0 ) {
    std::cout << "result must be inspected by humans." << std::endl;
    return 0;
  } else if (aComparisonMethod.compare("Ignore") == 0 ) {
    // safely return no error here
    return 0;
  } else {
    std::cout << "comparison method not supported: " << aComparisonMethod << std::endl;
    return 9;
  }

  if (lRefResult_ptr == NULL || lResult_ptr == NULL) {
    std::cerr << "couldn't read reference result or result file" << std::endl;
    return 8;
  }

  std::string lCanonicalRefFile = aRBKTBinDir + "/canonical_ref.xml";
  std::string lCanonicalResFile = aRBKTBinDir + "/canonical_res.xml";

  int lRefResultRes = xmlC14NDocSave(lRefResult_ptr, 0, 0, NULL, 0, lCanonicalRefFile.c_str(), 0);
  int lResultRes    = xmlC14NDocSave(lResult_ptr, 0, 0, NULL, 0, lCanonicalResFile.c_str(), 0);

  xmlFreeDoc(lRefResult_ptr);
  xmlFreeDoc(lResult_ptr);

  if (lRefResultRes < 0) {
    std::cerr << "error canonicalizing reference result" << std::endl;
    return 10;
  }
  
  if (lResultRes < 0) {
    std::cerr << "error canonicalizing result" << std::endl;
    return 10;
  }

  // last, we have to diff the result
  int lLine, lCol, lPos; // where do the files differ
  std::string lRefLine, lResultLine;
  bool lRes = fileEquals(lCanonicalRefFile.c_str(), lCanonicalResFile.c_str(), lLine, lCol, lPos, lRefLine, lResultLine);
  if (!lRes) {
    std::cout << std::endl << "Canonical result does not match canonical expected result:" << std::endl;
    printFile(std::cout, aRefFile);
    std::cout << "=== end of expected result ===" << std::endl;

    std::cout << "See line " << lLine << ", col " << lCol << " of expected result. " << std::endl;
    std::cout << "Actual:   <";
    if( -1 != lPos )
      printPart(std::cout, aResultFile, lPos, 15);
    else
      std::cout << lResultLine;
    std::cout << ">" << std::endl;
    std::cout << "Expected: <";
    if( -1 != lPos )
      printPart(std::cout, aRefFile, lPos, 15);
    else
      std::cout << lRefLine;
    std::cout << ">" << std::endl;

    return 8;
  }
  return 0;
} 

// return false if the files are not equal
// aLine contains the line number in which the first difference occurs
// aCol contains the column number in which the first difference occurs
// aPos is the character number off the first difference in the file
// -1 is returned for aLine, aCol, and aPos if the files are equal
bool
fileEquals(const char* aRefFile, const char* aResFile, int& aLine, int& aCol, int& aPos,
        std::string& aRefLine, std::string& aResLine)
{
  std::ifstream li(aRefFile);
  std::ifstream ri(aResFile); 
  std::string lLine, rLine;

  aLine = 1; aCol = 0; aPos = -1;
  while (! li.eof() )
  {
    if ( ri.eof() ) 
    {
      std::getline(li, lLine);
      if (li.peek() == -1) // ignore end-of-line in the ref result
        return true;
      else 
        return false;
    }
    std::getline(li, lLine);
    std::getline(ri, rLine);

    // TODO: should be removed, right?
    trim ( lLine );
    trim ( rLine );
    if ( (aCol = lLine.compare(rLine)) != 0) 
    {
      aRefLine = lLine;
      aResLine = rLine;
      return false;
    }
    ++aLine;
  }

  return true;
}

// print parts of a file
// starting at aStartPos with the length of aLen
void
printPart(std::ostream& os, std::string aInFile, int aStartPos, int aLen)
{
  char* buffer = new char [aLen];
  try {
    std::ifstream lIn(aInFile.c_str());
    lIn.seekg(aStartPos);

#ifdef WIN32
    int lCharsRead = lIn._Readsome_s (buffer, aLen, aLen);
#else
    int lCharsRead = lIn.readsome (buffer, aLen);
#endif
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
printFile(std::ostream& os, std::string aInFile)
{
  std::ifstream lInFileStream(aInFile.c_str());
  assert(lInFileStream.good());

  char buf[1024];
  while (!lInFileStream.eof()) {
    lInFileStream.read(buf, 1024);
    os.write(buf, lInFileStream.gcount());
  }

}

void
trim(std::string& str)
{

  std::string::size_type  notwhite = str.find_first_not_of(" \r\t\n");
  str.erase(0,notwhite);

  notwhite = str.find_last_not_of(" \t\n\r"); 
  str.erase(notwhite+1); 
}



} /* namespace zorba */
