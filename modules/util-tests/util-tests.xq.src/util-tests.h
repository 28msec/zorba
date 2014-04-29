/*
 * Copyright 2014 The FLWOR Foundation.
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

#ifndef EXTERNAL_MODULE_UTIL_TESTS_H
#define EXTERNAL_MODULE_UTIL_TESTS_H

#include <zorba/zorba.h>
#include <zorba/item_factory.h>
#include <zorba/external_module.h>
#include <zorba/function.h>

namespace zorba {

namespace tests {

/******************************************************************************
 *****************************************************************************/
class UtilTestsModule : public ExternalModule
{
  typedef std::vector<ItemSequence*> Arguments_t;

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
  virtual zorba::String
  getURI() const { return "http://zorba.io/modules/util-tests"; }

  virtual zorba::ExternalFunction*
  getExternalFunction(const zorba::String& aLocalname);

  zorba::ItemSequence_t
  test01(const Arguments_t& aArgs,
          const zorba::StaticContext* aSctx,
          const zorba::DynamicContext* aDctx) const;

  zorba::ItemSequence_t
  test02(const Arguments_t& aArgs,
          const zorba::StaticContext* aSctx,
          const zorba::DynamicContext* aDctx) const;

  zorba::ItemSequence_t
  test03(const Arguments_t& aArgs,
          const zorba::StaticContext* aSctx,
          const zorba::DynamicContext* aDctx) const;

  zorba::ItemSequence_t
  test04(const Arguments_t& aArgs,
          const zorba::StaticContext* aSctx,
          const zorba::DynamicContext* aDctx) const;

  zorba::ItemSequence_t
  test05(const Arguments_t& aArgs,
          const zorba::StaticContext* aSctx,
          const zorba::DynamicContext* aDctx) const;

  zorba::ItemSequence_t
  test06(const Arguments_t& aArgs,
          const zorba::StaticContext* aSctx,
          const zorba::DynamicContext* aDctx) const;

  zorba::ItemSequence_t
  test07(const Arguments_t& aArgs,
          const zorba::StaticContext* aSctx,
          const zorba::DynamicContext* aDctx) const;

  static zorba::Item
  getOneItemArgument(const Arguments_t& aArgs, int aIndex);
};


/*******************************************************************************
 ******************************************************************************/
class TestFunction : public ContextualExternalFunction
{
protected:
  const UtilTestsModule* theModule;

public:
  static zorba::Item
  getOneItemArgument(const Arguments_t& aArgs, int aIndex);

public:
  TestFunction(const UtilTestsModule* aModule) : theModule(aModule) {};

  String getURI() const;

};

/******************************************************************************
 *****************************************************************************/
class Test01CacheFunction : public TestFunction
{
public:
  Test01CacheFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test01CacheFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-01-cache"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test01(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test01SDFunction : public TestFunction
{
public:
  Test01SDFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test01SDFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-01-sd"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test01(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test02CacheFunction : public TestFunction
{
public:
  Test02CacheFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test02CacheFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-02-cache"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test02(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test02SDFunction : public TestFunction
{
public:
  Test02SDFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test02SDFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-02-sd"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test02(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test03CacheFunction : public TestFunction
{
public:
  Test03CacheFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test03CacheFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-03-cache"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test03(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test03SDFunction : public TestFunction
{
public:
  Test03SDFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test03SDFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-03-sd"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test03(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test04CacheFunction : public TestFunction
{
public:
  Test04CacheFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test04CacheFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-04-cache"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test04(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test04SDFunction : public TestFunction
{
public:
  Test04SDFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test04SDFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-04-sd"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test04(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test05CacheFunction : public TestFunction
{
public:
  Test05CacheFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test05CacheFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-05-cache"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test05(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test05SDFunction : public TestFunction
{
public:
  Test05SDFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test05SDFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-05-sd"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test05(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test06CacheFunction : public TestFunction
{
public:
  Test06CacheFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test06CacheFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-06-cache"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test06(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test06SDFunction : public TestFunction
{
public:
  Test06SDFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test06SDFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-06-sd"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test06(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test07CacheFunction : public TestFunction
{
public:
  Test07CacheFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test07CacheFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-07-cache"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test07(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class Test07SDFunction : public TestFunction
{
public:
  Test07SDFunction(const UtilTestsModule* aModule) :
    TestFunction(aModule) {};

  virtual ~Test07SDFunction() {}

  virtual zorba::String
  getLocalName() const { return "test-07-sd"; }

  zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const
  {
    return theModule->test07(aArgs, aSctx, aDctx);
  }
};

/******************************************************************************
 *****************************************************************************/
class NonSeeakableStreamableStringFunction : public TestFunction
{
public:
  NonSeeakableStreamableStringFunction(const UtilTestsModule* aModule)
: TestFunction(aModule) {};

  virtual ~NonSeeakableStreamableStringFunction() {}

  virtual zorba::String
  getLocalName() const { return "non-seeakable-streamable-string"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
      const zorba::StaticContext*,
      const zorba::DynamicContext*) const;

  static void streamReleaser(std::istream* stream) {delete stream;};
};

/******************************************************************************
 *****************************************************************************/
class UUIDFunction : public TestFunction
{
public:
  UUIDFunction(const UtilTestsModule* aModule)
: TestFunction(aModule) {};

  virtual ~UUIDFunction() {}

  virtual zorba::String
  getLocalName() const { return "uuid"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
      const zorba::StaticContext*,
      const zorba::DynamicContext*) const;
};

} /* namespace tests */ } /* namespace zorba */

#endif
