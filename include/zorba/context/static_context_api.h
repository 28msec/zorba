
#ifndef STATIC_CONTEXT_API_12_DEC_2007
#define STATIC_CONTEXT_API_12_DEC_2007

///from ICU
#include <unicode/coll.h>
#include "types/typeident.h"


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

  virtual void    SetXPath1_0CompatibMode( xpath1_0compatib_mode_t mode ) = 0;///true for XPath1.0 only, false for XPath2.0 (default false)
  virtual xpath1_0compatib_mode_t   GetXPath1_0CompatibMode( ) = 0;///true for XPath1.0 only, false for XPath2.0

  virtual bool    AddNamespace( xqp_string prefix, xqp_string URI ) = 0;//override the previous set prefix
  virtual xqp_string    GetNamespaceURIByPrefix( xqp_string prefix ) = 0;
  // virtual xqp_string    GetNamespacePrefixByURI( xqp_string URI ) = 0;
  virtual void    DeleteNamespace( xqp_string prefix ) = 0;
  virtual unsigned int  GetNamespaceCount() = 0;
  virtual bool    GetNamespaceByIndex( unsigned int i, xqp_string *prefix, xqp_string *URI ) = 0;
  virtual void    DeleteAllNamespaces() = 0;

  virtual void    SetDefaultElementAndTypeNamespace( xqp_string URI ) = 0;///default is none
  virtual xqp_string    GetDefaultElementAndTypeNamespace( ) = 0;

  virtual void    SetDefaultFunctionNamespace( xqp_string URI ) = 0;///default is none
  virtual xqp_string    GetDefaultFunctionNamespace( ) = 0;

  // here some functions for schema ... not impl yet

  virtual void    AddExternalVariableType( xqp_string var_name, type_ident_ref_t var_type) = 0;
  virtual type_ident_ref_t  GetExternalVariableType( xqp_string var_name ) = 0;
  virtual void    DeleteExternalVariableType( xqp_string var_name ) = 0;
  virtual unsigned int      GetExternalVariableCount() = 0;
  virtual bool    GetExternalVariableByIndex( unsigned int i, xqp_string *var_name, type_ident_ref_t *var_type ) = 0;
  virtual void    DeleteAllVariables() = 0;

  virtual void    SetContextItemStaticType( type_ident_ref_t    type ) = 0;
  virtual type_ident_ref_t    GetContextItemStaticType( ) = 0;

  ///here some api for external functions
  // virtual void AddExternalFunction( xqp_string func_name, extern_func *cpp_func, TypeIdentifier *type_of_result, ...);//and the types of parameters
  // virtual void DeleteAllExternalFunctions();

  virtual void    AddCollation( xqp_string URI, std::string  coll_string, ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY) = 0;
  virtual void    AddCollation( xqp_string URI, ::Collator *user_coll ) = 0;
  virtual CollationInfo*    GetCollation( xqp_string URI ) = 0;
  virtual void    DeleteCollation( xqp_string URI) = 0;
  virtual unsigned int      GetCollationCount() = 0;
  virtual CollationInfo*    GetCollationInfoByIndex( unsigned int i ) = 0;//std::string *coll_string, ::Collator::ECollationStrength *coll_strength ) = 0;
  virtual void    DeleteAllCollations() = 0;

  virtual void    SetDefaultCollation( xqp_string URI ) = 0;//std::string  coll_string, ::Collator::ECollationStrength coll_strength ) = 0;
  virtual xqp_string  GetDefaultCollation() = 0;

  virtual void    SetConstructionMode( construction_mode_t ) = 0;
  virtual construction_mode_t   GetConstructionMode( ) = 0;

  virtual void    SetOrderingMode( ordering_mode_t ) = 0;
  virtual ordering_mode_t   GetOrderingMode( ) = 0;

  virtual void    SetDefaultOrderForEmptySequences( order_empty_mode_t ) = 0;
  virtual order_empty_mode_t    GetDefaultOrderForEmptySequences( ) = 0;

  virtual void    SetBoundarySpacePolicy( boundary_space_mode_t ) = 0;
  virtual boundary_space_mode_t   GetBoundarySpacePolicy( ) = 0;

  virtual void    SetCopyNamespacesMode( preserve_mode_t preserve, inherit_mode_t inherit ) = 0;
  virtual void    GetCopyNamespacesMode( preserve_mode_t *preserve, inherit_mode_t *inherit ) = 0;

  virtual void    SetBaseURI( xqp_string baseURI ) = 0;
  virtual xqp_string    GetBaseURI( ) = 0;

  // statically known documents (types)
  virtual void    AddDocumentType( xqp_string URI, type_ident_ref_t doc_type ) = 0;
  virtual type_ident_ref_t    GetDocumentType( xqp_string URI) = 0;
  virtual void    DeleteDocumentType( xqp_string URI) = 0;
  virtual unsigned int      GetDocumentTypeCount() = 0;
  virtual bool    GetDocumentByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *doc_type ) = 0;
  virtual void    DeleteAllDocumentTypes() = 0;

  virtual void    AddCollectionType( xqp_string URI, type_ident_ref_t   collection_type ) = 0;///if URI is empty then it refers to default collection type
  virtual type_ident_ref_t    GetCollectionType( xqp_string URI ) = 0;///if URI is empty then it refers to default collection type
  virtual void    DeleteCollectionType( xqp_string URI ) = 0;///if URI is empty then it refers to default collection type
  virtual unsigned int      GetCollectionTypeCount() = 0;
  virtual bool    GetCollectionTypeByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *collection_type ) = 0;
  virtual void    DeleteAllCollectionTypes() = 0;

  virtual void    SetDefaultCollectionType( type_ident_ref_t default_collection_type ) = 0;///default node()*
  virtual type_ident_ref_t  GetDefaultCollectionType( ) = 0;

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
