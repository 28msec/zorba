#ifndef ZORBA_SIMPLE_STORE_ITEM_FACTORY
#define ZORBA_SIMPLE_STORE_ITEM_FACTORY

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"


#include "common/shared_types.h"

#include "store/api/item_factory.h"


namespace zorba { namespace store {

class CopyMode;
class PUL;

typedef StringPool UriPool;


class BasicItemFactory : public ItemFactory
{
protected:
  UriPool    * theUriPool;
  QNamePool  * theQNamePool;

public:
  BasicItemFactory(UriPool* uriPool, QNamePool* qnPool);

  virtual ~BasicItemFactory();

  Item_t createQName(
        xqpStringStore* ns,
        xqpStringStore* pre,
        xqpStringStore* local,
        bool*           inserted = 0);

  Item_t createQName(
        const char* ns,
        const char* pre,
        const char* ln);

  Item_t createNCName(xqpStringStore* value);

  Item_t createAnyURI(xqpStringStore* value);
  Item_t createAnyURI(const char* value);

  Item_t createUntypedAtomic(xqpStringStore* value);

  Item_t createString(xqpStringStore* value);

  Item_t createBase64Binary(xqp_base64Binary value);

  Item_t createBoolean(xqp_boolean value);

  Item_t createDecimal(xqp_decimal value);

  Item_t createInteger(xqp_integer value);

  Item_t createLong(xqp_long value);

  Item_t createInt(xqp_int value);

  Item_t createShort(xqp_short value);

  Item_t createByte(xqp_byte value);

  Item_t createDate(xqp_date& value);
  
  Item_t createDate(short year, short month, short day);

  Item_t createDate(const xqp_string& value);

  Item_t createDateTime(xqp_dateTime& value);
 
  Item_t createDateTime(short year, short month, short day, short hour, short minute, short second);

  Item_t createDateTime(short year , short month, short day, short hour, short minute, short second, short timeZone);

  Item_t createDateTime(const xqp_string& value);
  
  Item_t createDateTime(const Item_t&, const Item_t&);

  Item_t createDouble(xqp_double value);

  Item_t createDuration(xqp_duration& value);
  
  Item_t createDuration(const xqp_string& value);

  Item_t createDuration(short years, short months, short days, short hours, short minutes, short seconds, short frac_seconds);

  Item_t createENTITIES ( const xqp_string& value );

  Item_t createENTITY ( const xqp_string& value );

  Item_t createFloat ( xqp_float value );

  Item_t createGDay (xqp_gDay& value );

  Item_t createGDay ( const xqp_string& value );

  Item_t createGDay ( short day );

  Item_t createGMonth (xqp_gMonth& value);

  Item_t createGMonth ( const xqp_string& value );

  Item_t createGMonth ( short month );

  Item_t createGMonthDay (xqp_gMonthDay& value);

  Item_t createGMonthDay ( const xqp_string& value );

  Item_t createGMonthDay ( short month, short day );

  Item_t createGYear (xqp_gYear& value);
  
  Item_t createGYear ( const xqp_string& value );

  Item_t createGYear ( short year );

  Item_t createGYearMonth (xqp_gYearMonth& value);

  Item_t createGYearMonth ( const xqp_string& value );

  Item_t createGYearMonth ( short year, short month );

  Item_t createHexBinary ( xqp_hexBinary value );

  Item_t createID ( const xqp_string& value );

  Item_t createIDREF ( const xqp_string& value );

  Item_t createIDREFS ( const xqp_string& value );

  Item_t createLanguage ( const xqp_string& value );

  Item_t createNMTOKEN ( const xqp_string& value );

  Item_t createNMTOKENS ( const xqp_string& value );

  Item_t createNOTATION ( const xqp_string& value );

  Item_t createName ( const xqp_string& value );

  Item_t createNegativeInteger ( xqp_integer value );

  Item_t createNonNegativeInteger(xqp_uinteger value );

  Item_t createNonPositiveInteger(xqp_integer value );

  Item_t createNormalizedString(const xqp_string& value );

  Item_t createPositiveInteger( xqp_uinteger value );

  Item_t createTime(xqp_time& value);
  
  Item_t createTime(const xqp_string& value );

  Item_t createTime(short hour, short minute, short second );

  Item_t createTime(short hour, short minute, short second, short timeZone);

  Item_t createToken(const xqp_string& value);

  Item_t createUnsignedByte(xqp_ubyte value);

  Item_t createUnsignedInt(xqp_uint value);

  Item_t createUnsignedLong(xqp_ulong value);

  Item_t createUnsignedShort(xqp_ushort value);



  Item_t createDocumentNode(
        ulong             qid,
        xqpStringStore_t& baseURI,
        Iterator*         children,
        bool              isRoot,
        bool              assignIds,
        bool              copy,
        const CopyMode&   copymode);

  Item_t createElementNode(
        ulong             qid,
        Item_t&           name,
        Item_t&           type,
        Iterator*         childrenIte,
        Iterator*         attributesIte,
        Iterator*         namespacesIte,
        const NsBindings& localBindings,
        xqpStringStore_t& baseURI,
        bool              isRoot,
        bool              assignIds,
        bool              copy,
        const CopyMode&   copymode);

  Item_t createAttributeNode(
        ulong     qid,
        Iterator* nameIter,
        Item_t&   typeName,
        Iterator* valueIter,
        bool      isRoot,
        bool      assignIds);

  Item_t createTextNode(
        ulong           qid,
        Iterator*       valueIter,
        bool            isRoot,
        bool            assignIds);

  Item_t createTextNode(
        ulong             qid,
        xqpStringStore_t& content,
        bool              isRoot,
        bool              assignIds);

  Item_t createPiNode (
        ulong             qid,
        xqpStringStore_t& target,
        xqpStringStore_t& content,
        bool              isRoot,
        bool              assignIds);

  Item_t createCommentNode (
        ulong             qid,
        xqpStringStore_t& content,
        bool              isRoot,
        bool              assignIds);

  PUL* createPendingUpdateList();
};

} // namespace store
} // namespace zorba

#endif
