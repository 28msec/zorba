#ifndef XQP_ERRORS_H
#define XQP_ERRORS_H

#include "common/shared_types.h"
#include <string>
#include <vector>

#include <zorba/error.h>
#include "compiler/parser/query_loc.h"

namespace zorba { namespace error {

  class ZorbaError
  {
  public:
    ZorbaError(
        ::zorba::ZorbaError::ErrorCode aErrorCode,
        const xqpString& aDescription,
        const QueryLoc& aLocation,
        const std::string& aFileName,
        int aLineNumber);

    ZorbaError(
        const ::zorba::store::Item_t& aErrorQName,
        const xqpString& aDescription,
        const QueryLoc& aLocation,
        const std::string& aFileName,
        int aLineNumber);

    ZorbaError(const ZorbaError& other);

    virtual ~ZorbaError();

    virtual bool 
    isXPathStaticError() const
    {
      return (::zorba::ZorbaError::XPST0001 <= theErrorCode && 
              theErrorCode <= ::zorba::ZorbaError::XPST0083);
    }
      
    virtual bool 
    isXPathDynamicError() const
    {
      return (::zorba::ZorbaError::XPDY0002 <= theErrorCode && 
              theErrorCode <= ::zorba::ZorbaError::XPDY0050);
    }
      
    virtual bool 
    isXPathTypeError() const 
    {
      return ::zorba::ZorbaError::XPTY0004 <= theErrorCode && 
              theErrorCode <= ::zorba::ZorbaError::XPTY0020;
    }
      
    virtual bool
    isXQueryDynamicError() const
    {
      return ((::zorba::ZorbaError::XQDY0025 <= theErrorCode && 
               theErrorCode <= ::zorba::ZorbaError::XQDY0092) ||
              ::zorba::ZorbaError::XUDY0009 == theErrorCode ||
              (::zorba::ZorbaError::XUDY0014 <= theErrorCode && 
               theErrorCode <= ::zorba::ZorbaError::XUDY0021) ||
              (::zorba::ZorbaError::XUDY0023 <= theErrorCode && 
               theErrorCode <= ::zorba::ZorbaError::XUDY0025) ||
              theErrorCode == ::zorba::ZorbaError::XUDY0027 ||
              theErrorCode == ::zorba::ZorbaError::XUDY0029 ||
              theErrorCode == ::zorba::ZorbaError::XUDY0030);
    }
      
    virtual bool 
    isXQueryStaticError() const
    {
      return ((::zorba::ZorbaError::XQST0009 <= theErrorCode && 
               theErrorCode <= ::zorba::ZorbaError::XQST0093) ||
              (::zorba::ZorbaError::XUST0001 <= theErrorCode && 
               theErrorCode <= ::zorba::ZorbaError::XUST0003) ||
              theErrorCode == ::zorba::ZorbaError::XUST0028);
    }
      
    virtual bool 
    isXQueryTypeError() const
    {
      return ((::zorba::ZorbaError::XQTY0023 <= theErrorCode && 
               theErrorCode <= ::zorba::ZorbaError::XQTY0086) ||
              (::zorba::ZorbaError::XUTY0004 <= theErrorCode && 
               theErrorCode <= ::zorba::ZorbaError::XUTY0008) ||
              (::zorba::ZorbaError::XUTY0010 <= theErrorCode && 
               theErrorCode <= ::zorba::ZorbaError::XUTY0013) ||
              theErrorCode == ::zorba::ZorbaError::XUTY0022);
    }
      
    virtual bool 
    isFunctionError() const
    {
      return ::zorba::ZorbaError::FOER0000 <= theErrorCode && 
             theErrorCode <= ::zorba::ZorbaError::FOTY0012;
    }
      
    virtual bool
    isSerializationError() const
    {
      return ::zorba::ZorbaError::SENR0001 <= theErrorCode && 
             theErrorCode <= ::zorba::ZorbaError::SEPM0016;
    }

    virtual bool 
    isInternalError() const
    {
      return ::zorba::ZorbaError::XQP0000_DYNAMIC_RUNTIME_ERROR <= theErrorCode && 
             theErrorCode <= ::zorba::ZorbaError::API0021_ITEM_TO_LOAD_IS_NOT_NODE; 
    }

    virtual bool
    isStaticError() const
    {
      return isXPathStaticError() || isXQueryStaticError();
    }

    virtual bool
    isDynamicError() const
    {
      return isXPathDynamicError() || isXQueryDynamicError() || isFunctionError();
    }

    virtual bool
    isTypeError() const
    {
      return isXPathTypeError() || isXQueryTypeError();
    }

    virtual bool
    isUserError() const          { return false; }

    static std::string
    toString(::zorba::ZorbaError::ErrorCode& code);

    static std::string
    error_decode(::zorba::ZorbaError::ErrorCode& code);

    static ::zorba::ZorbaError::ErrorCode
    err_name_to_code (std::string name);

    public:
      store::Item_t theQName;
      ::zorba::ZorbaError::ErrorCode   theErrorCode;
      xqpString     theDescription;
      QueryLoc      theQueryLocation;
      std::string   theFileName; // source file
      int           theLineNumber; // line number in the source file

  }; /* class ZorbaError */


  class ZorbaUserError : public ZorbaError
  {
  public:
    ZorbaUserError(
        ::zorba::ZorbaError::ErrorCode aErrorCode,
        const xqpString& aDescription,
        const QueryLoc& aLocation,
        const std::string& aFileName,
        int aLineNumber,
        std::vector< ::zorba::store::Item_t> aErrorObject);

    ZorbaUserError(
        const ::zorba::store::Item_t& aErrorQName,
        const xqpString& aDescription,
        const QueryLoc& aLocation,
        const std::string& aFileName,
        int aLineNumber,
        std::vector< ::zorba::store::Item_t> aErrorObject);

    virtual ~ZorbaUserError();

    virtual bool
    isUserError() const          { return true; }

    std::vector< ::zorba::store::Item_t> theErrorObject;
  }; /* class ZorbaUserError */


  class ZorbaWarning
  {
  public:
    // move to the outside if we ever have warnings
    enum WarningCode
    {
    };

    ZorbaWarning(WarningCode aWarningCode, const xqpString& aDescription,
                 const QueryLoc& aLocation, const std::string& aFileName,
                 int aLineNumber);

  protected:
    WarningCode  theCode;          
    xqpString    theDescription;   
    QueryLoc     theQueryLocation; 
    std::string  theFileName;      
    int          theLineNumber;    
  };
    

} /* namespace error */
} /* namespace zorba */
#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
