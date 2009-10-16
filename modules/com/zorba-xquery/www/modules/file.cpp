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

#include <map>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/singleton_item_sequence.h>

#include <zorba/util/file.h>

namespace zorba { namespace filemodule {

  class ExistsFunction : public PureStatelessExternalFunction
  {
    protected:
      ItemFactory*              theFactory;
      const ExternalModule*     theModule;

      static String
      getOneStringArg(const StatelessExternalFunction::Arguments_t& aArgs,
                      int aPos) {
        Item        lItem;
        if (!aArgs[0]->next(lItem)) {
          std::stringstream lErrorMessage;
          lErrorMessage << "An empty-sequence is not allowed as " 
                        << aPos << ". parameter.";
          throw zorba::ExternalFunctionData::createZorbaException(XPTY0004,
                  lErrorMessage.str().c_str(), __FILE__, __LINE__);
        } 
        zorba::String lTmpString = lItem.getStringValue();
        if (aArgs[aPos]->next(lItem)) {
          std::stringstream lErrorMessage;
          lErrorMessage << "A sequence of more then one item is not allowed as "
                        << aPos << ". parameter.";
          throw zorba::ExternalFunctionData::createZorbaException(XPTY0004,
                  lErrorMessage.str().c_str(), __FILE__, __LINE__);
        }
        return lTmpString;
      }

    public:
      ExistsFunction(const ExternalModule* aModule)
        : theFactory(Zorba::getInstance(0)->getItemFactory()),
          theModule(aModule)
      {}
  
      virtual String
      getURI() const { return theModule->getURI(); }
  
      virtual String
      getLocalName() const { return "exists"; }
  
      virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args) const
      {
        bool        lFileExists = false;
        String      lFile = getOneStringArg(args, 0);
        std::string lFileName = lFile.c_str();
        zorba::file lTest(lFileName);
        if (lTest.exists()) {
          lFileExists = true;
        }

        return ItemSequence_t(new SingletonItemSequence(
                theFactory->createBoolean(lFileExists)));
      }
  };

  class FileModule : public ExternalModule
  {
    protected:
      class ltstr
      {
        public:
          bool
          operator()(const String& s1, const String& s2) const
          {
            return s1.compare(s2) < 0;
          }
      };

      typedef std::map<String, StatelessExternalFunction*, ltstr> FuncMap_t;
      mutable FuncMap_t theFunctions;
  
    public:
      virtual ~FileModule()
      {
        for (FuncMap_t::const_iterator lIter = theFunctions.begin();
             lIter != theFunctions.end(); ++lIter) {
          delete lIter->second;
        }
        theFunctions.clear();
      }
  
      virtual String
      getURI() const { return "http://www.zorba-xquery.com/modules/file"; }
  
      virtual StatelessExternalFunction*
      getExternalFunction(String aLocalname) const
      {
        StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
        if (!lFunc) {
          if (aLocalname.equals("exists")) {
            lFunc = new ExistsFunction(this);
          } 
        }
        return lFunc;
      }

      virtual void
      destroy()
      {
        if (!dynamic_cast<FileModule*>(this)) {
          return;
        }
        delete this;
      }

  };

} /* namespace filemodule */ } /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::filemodule::FileModule();
}
