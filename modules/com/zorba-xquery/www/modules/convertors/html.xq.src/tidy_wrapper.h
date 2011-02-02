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

#ifndef ZORBA_HTMLMODULE_TIDY_WRAPPER_H
#define ZORBA_HTMLMODULE_TIDY_WRAPPER_H

#include <iostream>
#include <sstream>

#include <tidy.h>
#include <buffio.h>

#include <zorba/item_factory.h>
#include <zorba/item.h>
#include <zorba/iterator.h>
#include <zorba/store_consts.h>
#include <zorba/xmldatamanager.h>
#include <zorba/error.h>
#include <zorba/exception.h>
#include <zorba/external_function_data.h>
#include <zorba/zorba.h>

namespace zorba
{
  namespace htmlmodule
  {
    class TidyReader {
    private:
      std::istream* theStream;
      // We need a buffer to support the unget function
      std::vector<unsigned int> theBuffer;
    public:
      TidyReader(std::istream* aStream) : theStream(aStream) {}
      TidyInputSource getInputSource()
      {
        TidyInputSource lResult;
        lResult.sourceData = this;
        lResult.getByte = &getByte;
        lResult.ungetByte = &ungetByte;
        lResult.eof = &isEof;
        return lResult;
      }
      
      public: // callback functions
      static int TIDY_CALL getByte(void* aData)
      {
        TidyReader* lReader = static_cast<TidyReader*>(aData);
        if (lReader->theBuffer.empty())
          return lReader->theStream->get();
        else
        {
          int lResult = lReader->theBuffer.back();
          lReader->theBuffer.pop_back();
          return lResult;
        }
      }
      
      static void TIDY_CALL ungetByte(void* aData, byte aByte)
      {
        TidyReader* lReader = static_cast<TidyReader*>(aData);
        lReader->theBuffer.push_back(aByte);
      }
      
      static Bool TIDY_CALL isEof(void* aData)
      {
        TidyReader* lReader = static_cast<TidyReader*>(aData);
        return lReader->theStream->eof() ? yes : no;
      }
    };
    
    static void checkOption(Bool ok)
    {
      if (ok != yes)
      {
        ZorbaException e = ExternalFunctionData::createZorbaException(XQP0019_INTERNAL_ERROR,
                                                                      "Could not set Tidy option",
                                                                      __FILE__,
                                                                      __LINE__);
        throw e;
      }
    }
    
    static void checkRC(int rc, const char* errMsg)
    {
      if (rc > 1)
      {
        ZorbaException e = ExternalFunctionData::createZorbaException(XQP0019_INTERNAL_ERROR,
                                                                      errMsg,
                                                                      __FILE__,
                                                                      __LINE__);
        throw e;
      }
    }
    
    static Bool setTidyOption(TidyDoc doc, const char* option, const char* value)
    {
      Bool ok = yes;
      TidyOptionId toID = tidyOptGetIdForName(option);
      if(toID < N_TIDY_OPTIONS)
      {
        ok = tidyOptSetValue(doc, toID, value);
        checkOption(ok);
      }
      else
        return no;
      return ok;
    }

    static Bool applyOptions(TidyDoc aDoc, zorba::Item &aOptions)
    {
      zorba::Iterator_t lAttributes, lElements;
      zorba::Item lAttr, lElementItem, lAttrName;
      zorba::String lStrName, lStrValue;
      Bool lRet = yes;

      if(!aOptions.isNull())
      {
        lElements = aOptions.getChildren();
        lElements->open();
        while (lElements->next(lElementItem)
          && lElementItem.getNodeKind () == store::StoreConsts::elementNode)
        {
          lAttributes = lElementItem.getAttributes();
          lAttributes->open();
          while (lAttributes->next(lAttr))
          {
            lAttr.getNodeName(lAttrName);
            if(lAttrName.getLocalName().byteEqual("name",4))
              lStrName = lAttr.getStringValue();
            else if(lAttrName.getLocalName().byteEqual("value",5))
              lStrValue = lAttr.getStringValue();
          }
          setTidyOption(aDoc, lStrName.c_str(), lStrValue.c_str());
          lAttributes->close();
        }
        lElements->close();
      }
      return lRet;
    }

    static zorba::Item createHtmlItem( std::istream& aStream , zorba::Item &aOptions)
    {
      TidyReader lReader(&aStream);
      TidyInputSource lInputSource = lReader.getInputSource();
      
      TidyBuffer output;
      tidyBufInit(&output);
      TidyBuffer errbuf;
      tidyBufInit(&errbuf);
      TidyDoc tDoc = tidyCreate();

      applyOptions(tDoc, aOptions);

      int rc = -1;
      rc = tidySetErrorBuffer(tDoc, &errbuf);
      checkRC(rc, "Could not set error buffer");
      rc = tidyParseSource(tDoc, &lInputSource);
      checkRC(rc, "Could not parse the source");
      rc = tidyCleanAndRepair(tDoc);
      checkRC(rc, "Could not clean and repair");
      rc = tidyRunDiagnostics(tDoc);
      if ( rc > 1 )
        rc = ( tidyOptSetBool(tDoc, TidyForceOutput, yes) ? rc : -1 );

      // Tidy does not support streaming for output, it only supports
      // something they call a "sink". Therefore we buffer it in a string.
      rc = tidySaveBuffer(tDoc, &output);
      checkRC(rc, "Could not save the buffer");
      std::string lResult((char*) output.bp, output.size);
      std::istringstream lStream(lResult);

      tidyBufFree(&output);
      tidyBufFree(&errbuf);
      tidyRelease(tDoc);
      XmlDataManager* lDM = Zorba::getInstance(0)->getXmlDataManager();
      try
      {
        return lDM->parseDocument(lStream);
      } catch (ZorbaException&)
      {
        return NULL;//Zorba::getInstance(0)->getItemFactory()->createString(lResult);
      }
    }
  } /* namespace htmlmodule */
} /* namespace zorba */

#endif //ZORBA_HTMLMODULE_TIDY_WRAPPER_H