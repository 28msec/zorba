#ifndef ZORBA_SHARED_TYPES_INCL_H
#define ZORBA_SHARED_TYPES_INCL_H

#include <memory>

#include <boost/smart_ptr.hpp>

namespace zorba {

  class XQuery;
  class StaticContext;
  class DynamicContext;
  class XmlDataManager;
  class ResultIterator;
  class StatelessExternalFunction;
  class TypeIdentifier;
  class ItemSequence;

  class ErrorHandler;

  // smart pointers
  typedef boost::shared_ptr<XQuery>                     XQuery_t;
  typedef boost::shared_ptr<StaticContext>              StaticContext_t;
  typedef boost::shared_ptr<DynamicContext>             DynamicContext_t;
  typedef boost::shared_ptr<ResultIterator>             ResultIterator_t;
  typedef boost::shared_ptr<TypeIdentifier>             TypeIdentifier_t;

  // auto pointer
  typedef std::auto_ptr<ItemSequence>                   ItemSequence_t;

  // data handlers 
  class Item;
  class String;

} /* namespace zorba */
#endif
