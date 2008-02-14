
#ifndef STATIC_CONTEXT_API_12_DEC_2007
#define STATIC_CONTEXT_API_12_DEC_2007

///from ICU
#include <unicode/coll.h>
#include "types/typeident.h"

#include "zorba/common/shared_types_incl.h"


namespace xqp {

/*
class CollationInfo : public rcobject
{
  std::string  coll_string;
  ::Collator::ECollationStrength coll_strength;

  ::Collator *coll;
public:
  CollationInfo();
  CollationInfo( ::Collator *coll );
  CollationInfo( std::string  coll_string, ::Collator::ECollationStrength coll_strength);
  ~CollationInfo();

  ::Collator  *getCollator();
  std::string getLocaleString();
  ::Collator::ECollationStrength getCollatorStrength();
};

typedef rchandle<CollationInfo>   CollationInfo_t;
*/
typedef struct 
{
  xqp_string    URI;
  std::string   coll_string;
  ::Collator::ECollationStrength  coll_strength;
  ::Collator    *coll;

}CollationInfo;
/// the Static Context
/// this class represents only the part that is the interface to the user
class StaticQueryContext : public rcobject
{
public:
  typedef enum { xpath2_0, xpath1_0_only }    xpath1_0compatib_mode_t;
  typedef enum { cons_preserve, cons_strip }  construction_mode_t;
  typedef enum { ordered, unordered }         ordering_mode_t;
  typedef enum { empty_greatest, empty_least } order_empty_mode_t;
  typedef enum { preserve_space, strip_space } boundary_space_mode_t;
  typedef enum { inherit_ns, no_inherit_ns }  inherit_mode_t;
  typedef enum { preserve_ns, no_preserve_ns } preserve_mode_t;


public:
  virtual ~StaticQueryContext() { }

  virtual void    setXPath1_0CompatibMode( xpath1_0compatib_mode_t mode ) = 0;///true for XPath1.0 only, false for XPath2.0 (default false)
  virtual xpath1_0compatib_mode_t   getXPath1_0CompatibMode( ) = 0;///true for XPath1.0 only, false for XPath2.0

  virtual bool    addNamespace( xqp_string prefix, xqp_string URI ) = 0;//override the previous set prefix
  virtual xqp_string    getNamespaceURIByPrefix( xqp_string prefix ) = 0;
  // virtual xqp_string    getNamespacePrefixByURI( xqp_string URI ) = 0;
  virtual void    deleteNamespace( xqp_string prefix ) = 0;
  virtual unsigned int  getNamespaceCount() = 0;
  virtual bool    getNamespaceByIndex( unsigned int i, xqp_string *prefix, xqp_string *URI ) = 0;
  virtual void    deleteAllNamespaces() = 0;

  virtual void    setDefaultElementAndTypeNamespace( xqp_string URI ) = 0;///default is none
  virtual xqp_string    getDefaultElementAndTypeNamespace( ) = 0;

  virtual void    setDefaultFunctionNamespace( xqp_string URI ) = 0;///default is none
  virtual xqp_string    getDefaultFunctionNamespace( ) = 0;

  // here some functions for schema ... not impl yet

  virtual void    addExternalVariableType( xqp_string var_name, type_ident_ref_t var_type) = 0;
  virtual type_ident_ref_t  getExternalVariableType( xqp_string var_name ) = 0;
  virtual void    deleteExternalVariableType( xqp_string var_name ) = 0;
  virtual unsigned int      getExternalVariableCount() = 0;
  virtual bool    getExternalVariableByIndex( unsigned int i, xqp_string *var_name, type_ident_ref_t *var_type ) = 0;
  virtual void    deleteAllVariables() = 0;

  virtual void    setContextItemStaticType( type_ident_ref_t    type ) = 0;
  virtual type_ident_ref_t    getContextItemStaticType( ) = 0;

  ///here some api for external functions
  // virtual void AddExternalFunction( xqp_string func_name, extern_func *cpp_func, TypeIdentifier *type_of_result, ...);//and the types of parameters
  // virtual void DeleteAllExternalFunctions();

  virtual void    addCollation( xqp_string URI, std::string  coll_string, ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY) = 0;
  virtual void    addCollation( xqp_string URI, ::Collator *user_coll ) = 0;
  virtual CollationInfo*    getCollation( xqp_string URI ) = 0;
  virtual void    deleteCollation( xqp_string URI) = 0;
  virtual unsigned int      getCollationCount() = 0;
  virtual CollationInfo*    getCollationInfoByIndex( unsigned int i ) = 0;//std::string *coll_string, ::Collator::ECollationStrength *coll_strength ) = 0;
  virtual void    deleteAllCollations() = 0;

  virtual void    setDefaultCollation( xqp_string URI ) = 0;//std::string  coll_string, ::Collator::ECollationStrength coll_strength ) = 0;
  virtual xqp_string  getDefaultCollation() = 0;

  virtual void    setConstructionMode( construction_mode_t ) = 0;
  virtual construction_mode_t   getConstructionMode( ) = 0;

  virtual void    setOrderingMode( ordering_mode_t ) = 0;
  virtual ordering_mode_t   getOrderingMode( ) = 0;

  virtual void    setDefaultOrderForEmptySequences( order_empty_mode_t ) = 0;
  virtual order_empty_mode_t    getDefaultOrderForEmptySequences( ) = 0;

  virtual void    setBoundarySpacePolicy( boundary_space_mode_t ) = 0;
  virtual boundary_space_mode_t   getBoundarySpacePolicy( ) = 0;

  virtual void    setCopyNamespacesMode( preserve_mode_t preserve, inherit_mode_t inherit ) = 0;
  virtual void    getCopyNamespacesMode( preserve_mode_t *preserve, inherit_mode_t *inherit ) = 0;

  virtual bool    setBaseURI( xqp_string baseURI ) = 0;
  virtual xqp_string    getBaseURI( ) = 0;

  // statically known documents (types)
  virtual void    addDocumentType( xqp_string URI, type_ident_ref_t doc_type ) = 0;
  virtual type_ident_ref_t    getDocumentType( xqp_string URI) = 0;
  virtual void    deleteDocumentType( xqp_string URI) = 0;
  virtual unsigned int      getDocumentTypeCount() = 0;
  virtual bool    getDocumentByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *doc_type ) = 0;
  virtual void    deleteAllDocumentTypes() = 0;

  virtual void    addCollectionType( xqp_string URI, type_ident_ref_t   collection_type ) = 0;///if URI is empty then it refers to default collection type
  virtual type_ident_ref_t    getCollectionType( xqp_string URI ) = 0;///if URI is empty then it refers to default collection type
  virtual void    deleteCollectionType( xqp_string URI ) = 0;///if URI is empty then it refers to default collection type
  virtual unsigned int      getCollectionTypeCount() = 0;
  virtual bool    getCollectionTypeByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *collection_type ) = 0;
  virtual void    deleteAllCollectionTypes() = 0;

  virtual void    setDefaultCollectionType( type_ident_ref_t default_collection_type ) = 0;///default node()*
  virtual type_ident_ref_t  getDefaultCollectionType( ) = 0;

  /**
   * functions that are used for registering external functions
   */
  virtual void registerStatelessExternalFunction(StatelessExternalFunction_t aExternalFunction) = 0;

};

typedef rchandle<StaticQueryContext>  StaticQueryContext_t;



} // end namespace xqp

#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
