#ifndef ZORBA_ITEM_API_H
#define ZORBA_ITEM_API_H

#include <ostream>
#include <zorba/api_shared_types.h>

namespace zorba {

namespace store { class Item; }

class Item
{
public:
  Item();
  Item(const Item& other);
  Item(store::Item *item);
  ~Item();

  // returns QName Item of the type
  Item
  getType() const;

  Item
  getAtomizationValue() const;

  String
  getStringValue() const;

  void
  serialize(std::ostream&) const;

  Item
  getEBV() const;

  bool
  isNode() const;

  bool
  isAtomic() const;

  bool
  isNull() const;

  void
  close();

  const Item& operator =(const Item& rhs);
  const Item& operator =(store::Item *rhs);

  /** functions for QName */
  // prefix for qname items
  String
  getPrefix() const;

  // localname for qname items
  String
  getLocalName() const;

  // namespace for qname items
  String
  getNamespace() const;


  /** functions for numerics */

  //@return true, if containing number is not-a-number (possible for floating-point numbers)
  bool
  isNaN() const;

  // @return true, if containing numbers represents -INF or +INF
  bool
  isPosOrNegInf() const;

  /** functions for boolean */
  bool
  getBooleanValue() const;



private:
  friend class Unmarshaller;
  friend class SAX2_XMLReaderNative;
  store::Item *m_item;

  store::Item * getInternalItem() const { return m_item; }
};

} // namespace zorba

#endif
