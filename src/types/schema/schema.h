/*
 *	Copyright 2006-2008 FLWOR Foundation.
 *  Author: Cezar Andrei (cezar dot andrei at gmail dot com)
 *
 */
#ifndef ZORBA_SCHEMA_H_
#define ZORBA_SCHEMA_H_

#include "xercesIncludes.h"

#include <zorba/api_shared_types.h>

#include "common/shared_types.h"
#include "types/typeconstants.h"
#include "store/api/item.h"
#include "zorbatypes/xqpstring.h"


namespace zorba
{

class Schema;


class Schema
{
public:
	static const char* XSD_NAMESPACE;
	
	/* before first use init must be called */
  static void initialize();
  /* before finishing up terminate must be called */
  static void terminate();
    
  Schema();
  virtual ~Schema();
    
  void registerXSD(const char* xsdFileName);
  void printXSDInfo(bool excludeBuiltIn = true);
    
  /*
   * Checks if the Type with the qname exists in the schema as a user-defined type
   * if it does than return an XQType for it, if not return NULL
   */
  xqtref_t createIfExists(
        const TypeManager *manager,
        const store::Item* qname,
        TypeConstants::quantifier_t quantifier);

  store::Item_t parseAtomicValue(xqtref_t type, xqpString textValue);    
    
  // Validator getValidator();
  //void getValidatingItemIterator();
    
private:
  static bool _isInitialized;
  XERCES_CPP_NAMESPACE::XMLGrammarPool *_grammarPool;
};

} // namespace zorba
#endif /*ZORBA_SCHEMA_H_*/
