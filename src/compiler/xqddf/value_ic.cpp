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
#include "stdafx.h"

#include "store/api/iterator.h"

#include "compiler/xqddf/value_ic.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "runtime/api/plan_wrapper.h"
#include "compiler/api/compilercb.h"


#include "zorbaserialization/class_serializer.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(ValueIC)
END_SERIALIZABLE_CLASS_VERSIONS(ValueIC)


/*******************************************************************************

*******************************************************************************/
void ValueIC::serialize(::zorba::serialization::Archiver& ar)
{
  //ZORBA_SER_ERROR_DESC_OSS(ZCSE0009_CLASS_NOT_SERIALIZABLE, "ValueIC");

  ar & theSctx;
  ar & theName;
  SERIALIZE_ENUM(store::IC::ICKind, theICKind);
  ar & theCollectionName;
  ar & theFromCollectionName;
  ar & theToCollectionName;
  ar & thePlan;
  ar & theCcb;
}


/*******************************************************************************
  Check that the pathexpr 
  (a) is deterministic,
  (b) does not have any free variables,
  (c) does not reference any input functions other than dc:collection()
  (d) the arg to each dc:collection is a const qname 
*******************************************************************************/
//void ValueIC::analyze()
//{
//}

store::Iterator_t ValueIC::getIterator() const
{
  return new PlanWrapper(thePlan.getp(), theCcb, NULL /*dctx*/, NULL);;
}


std::string ValueIC::toString()
{
  std::ostringstream os;

  os << "IC : " << theName->getStringValue() << " " << 
    (theICKind==store::IC::ic_collection) << " ";
  
  switch( theICKind )
  {
  case store::IC::ic_collection:
    os << "Coll: " << theCollectionName->getStringValue();
    break;
  
  case store::IC::ic_foreignkey:
    os << "ToColl: " << theToCollectionName->getStringValue() << 
      " FromColl: " << theFromCollectionName->getStringValue();
  }

  os << std::endl;
  
  return os.str();
}


/*******************************************************************************
*******************************************************************************/
void ICCheckerImpl::check(const store::Item* collName)
{
  store::Iterator_t activeICNames = theDctx->listActiveICNames();

  store::Item_t activeICName;
  activeICNames->open();

  while ( activeICNames->next(activeICName) )
  {
    store::IC* ic = theDctx->getIC(activeICName);
  
    if ( ic == NULL ) 
    {
      // if icname in activelist but not available something went wrong
      ZORBA_ASSERT(false);
    }

    store::Item_t icCollName;
    switch ( ic->getICKind() )
    {
    case store::IC::ic_collection:
      actualCheck( collName, ic->getCollectionName(), ic->getICName() );
      break;

    case store::IC::ic_foreignkey:
      actualCheck( collName, ic->getFromCollectionName(), ic->getICName() );
      actualCheck( collName, ic->getToCollectionName(), ic->getICName() );
      break;

    default:
      ZORBA_ASSERT(false);
    }
  }

  activeICNames->close();
}

void ICCheckerImpl::actualCheck(const store::Item* collName, 
                                const store::Item* icCollName,
                                const store::Item* icName)
{
  if ( collName->equals(icCollName) )
  {
    // if this ic has a dependency on current collection
    
    //std::cout << "ic check : " << icName->getStringValue() <<
    //"  coll: " << collName->getStringValue() << std::endl; std::cout.flush(); 
    
    ValueIC* vic = theSctx->lookup_ic(icName);
    
    store::Item_t partialRes;
    store::Iterator_t iter = vic->getIterator();
    
    iter->open();

    try
    {
      iter->next(partialRes);
    }
    catch(...)
    {
      iter->close();
      throw;
    }
    
    iter->close();

    bool icConditionHolds = partialRes->getBooleanValue();
    //std::cout << "ic check : result = " 
    //          << (icConditionHolds ? "true" : "false")
    //          << std::endl; std::cout.flush(); 
    
    if ( !icConditionHolds )
    {
			throw ZORBA_EXCEPTION(
				zerr::ZDDY0033_IC_NOT_MET, 
				ERROR_PARAMS( icName->getStringValue(), collName->getStringValue() )
			);
    }
  }
} 

} // namespace zorba
/* vim:set et sw=2 ts=2: */
