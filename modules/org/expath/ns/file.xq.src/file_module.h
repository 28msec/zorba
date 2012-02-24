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

#ifndef ZORBA_FILEMODULE_FILEMODULE_H
#define ZORBA_FILEMODULE_FILEMODULE_H

#include <map>

#include <zorba/zorba.h>
#include <zorba/external_module.h>

namespace zorba { namespace filemodule {

class FileModule : public ExternalModule
{
private:
  mutable ItemFactory* theFactory;

public:
  static const char* theNamespace;

protected:
  class ltstr
  {
  public:
    bool operator()(const String& s1, const String& s2) const
    {
      return s1.compare(s2) < 0;
    }
  };
  
  typedef std::map<String, ExternalFunction*, ltstr> FuncMap_t;
  FuncMap_t theFunctions;

public:
  static void
  streamReleaser(std::istream* stream)
  {
    delete stream;
  }

  FileModule() : theFactory(0) {}

  virtual ~FileModule();
  
  virtual String
  getURI() const { return theNamespace; }
  
  virtual ExternalFunction*
  getExternalFunction(const String& aLocalname);

  virtual void
  destroy();

  ItemFactory*
  getItemFactory() const
  {
    if (!theFactory)
    {
      theFactory = Zorba::getInstance(0)->getItemFactory();
    }
    
    return theFactory;
  }
};


} /* namespace filemodule */ 
} /* namespace zorba */

#endif /* ZORBA_FILEMODULE_FILEMODULE_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
