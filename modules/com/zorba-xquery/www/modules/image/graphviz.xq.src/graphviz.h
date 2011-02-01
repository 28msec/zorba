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

#ifndef ZORBA_GRAPHVIZMODULE_GRAPHVIZ_H
#define ZORBA_GRAPHVIZMODULE_GRAPHVIZ_H

#include <map>

#include <zorba/zorba.h>
#include <zorba/external_function.h>
#include <zorba/external_module.h>

namespace zorba
{
  namespace graphvizmodule
  {
    class GraphvizModule;
/******************************************************************************
 *****************************************************************************/
class GraphvizFunction : public NonePureStatelessExternalFunction
{
  protected:
    const GraphvizModule* theModule;

    GraphvizFunction(const GraphvizModule* aModule)
    : theModule(aModule) {}

    static std::string
    getGraphvizTmpFileName();

    static bool
    getAttribute(zorba::ItemFactory* aFactory,
        const char* attrname,
        const zorba::Item& elem,
        zorba::Item& attr);

    static void
    printTypeAndAttr(zorba::ItemFactory* aFactory,
        const zorba::Item& in, std::fstream& os);

    static void
    visitNode(zorba::ItemFactory* aFactory,
        const zorba::Item& in, std::fstream& os);

    static void
    visitEdge(zorba::ItemFactory* aFactory,
        const zorba::Item& in, std::fstream& os);

    static void
    printGraph(zorba::ItemFactory* aFactory,
        const zorba::Item& in, std::fstream& os);

    static void
    gxl2dot(zorba::ItemFactory* aFactory,
        const zorba::Item& in, std::fstream& os);

  public:

    virtual String
    getURI() const;
};

/******************************************************************************
 *****************************************************************************/
class DotFunction : public GraphvizFunction
{
public:
  DotFunction(const GraphvizModule* aModule)
    : GraphvizFunction(aModule) {}

  virtual ~DotFunction() {}

  virtual String
  getLocalName() const { return "dot"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;

protected:
  class LazyDotSequence : public zorba::ItemSequence
  {
    class InternalIterator : public Iterator
    {
    private:
      LazyDotSequence   *theItemSequence;
      Iterator_t        arg_iter;
      bool is_open;
    public:
      InternalIterator(LazyDotSequence *item_sequence);

      virtual void open();
      virtual bool next(Item& aItem);
      virtual void close();
      virtual bool isOpen() const;
    };
    public:
      LazyDotSequence(const DotFunction*,
                      ItemSequence* aArg);

      virtual Iterator_t    getIterator();

    protected:
      const DotFunction* theFunc;
      ItemSequence*      theArg;
  };
};

/******************************************************************************
 *****************************************************************************/
class GxlFunction : public GraphvizFunction
{
public:
  GxlFunction(const GraphvizModule* aModule)
    : GraphvizFunction(aModule) {}

  virtual ~GxlFunction() {}

  virtual String
  getLocalName() const { return "gxl"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;

protected:
  class LazyGxlSequence : public zorba::ItemSequence
  {
    class InternalIterator : public Iterator
    {
    private:
      LazyGxlSequence   *theItemSequence;
      Iterator_t        arg_iter;
      bool is_open;
    public:
      InternalIterator(LazyGxlSequence *item_sequence);

      virtual void open();
      virtual bool next(Item& aItem);
      virtual void close();
      virtual bool isOpen() const;
    };
    public:
      LazyGxlSequence(const GxlFunction*,
                      ItemSequence* aArg);

      Iterator_t  getIterator();

    protected:
      const GxlFunction* theFunc;
      ItemSequence*      theArg;
  };
};

/******************************************************************************
 ******************************************************************************/
class GraphvizModule : public ExternalModule
{
private:
  static ItemFactory* theFactory;

protected:
  class ltstr
  {
  public:
    bool operator()(const String& s1, const String& s2) const
    {
      return s1.compare(s2) < 0;
    }
  };

  typedef std::map<String, StatelessExternalFunction*, ltstr> FuncMap_t;

  FuncMap_t theFunctions;

public:
  virtual ~GraphvizModule();

  virtual String
  getURI() const
  {
    return "http://www.zorba-xquery.com/modules/image/graphviz";
  }

  virtual StatelessExternalFunction*
  getExternalFunction(const String& aLocalname);

  virtual void
  destroy();

  static ItemFactory*
  getItemFactory()
  {
    if(!theFactory)
    {
      theFactory = Zorba::getInstance(0)->getItemFactory();
    }
    return theFactory;
  }
};

  } /* namespace zorba */
} /* namespace graphvizmodule */

#endif
