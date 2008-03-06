#ifndef ZORBA_STATIC_CONTEXT_H
#define ZORBA_STATIC_CONTEXT_H

#include <zorba/common/libicu.h>
#include <zorba/typeident.h>
#include <zorba/common/api_shared_types.h>
#include <zorba/static_context_consts.h>

namespace zorba {

  // TODO can we hide icu realted stuff from the api
  // otherwise, we cannot change it
  // and the user needs to have icu-devel installed
  typedef struct 
  {
    xqp_string    URI;
    std::string   coll_string;
    ::Collator::ECollationStrength  coll_strength;
    ::Collator    *coll;

  }CollationInfo;

  /// the Static Context
  /// this class represents only the part that is the interface to the user
  class StaticQueryContext : public SimpleRCObject
  {
    public:
      virtual ~StaticQueryContext() { }

      virtual void   
      setXPath1_0CompatibMode( StaticContextConsts::xpath1_0compatib_mode_t mode ) = 0;
      ///true for XPath1.0 only, false for XPath2.0 (default false)
      virtual StaticContextConsts::xpath1_0compatib_mode_t  
      getXPath1_0CompatibMode( ) = 0;
      ///true for XPath1.0 only, false for XPath2.0
      
      virtual bool   
      addNamespace( xqp_string prefix, xqp_string URI ) = 0;
      //override the previous set prefix
      
      virtual xqp_string   
      getNamespaceURIByPrefix( xqp_string prefix ) = 0;
      // virtual xqp_string   
      // getNamespacePrefixByURI( xqp_string URI ) = 0;

      virtual void   
      deleteNamespace( xqp_string prefix ) = 0;

      virtual unsigned int 
      getNamespaceCount() = 0;

      virtual bool   
      getNamespaceByIndex( unsigned int i, xqp_string *prefix, xqp_string *URI ) = 0;

      virtual void   
      deleteAllNamespaces() = 0;

      virtual void   
      setDefaultElementAndTypeNamespace( xqp_string URI ) = 0;
      ///default is none
      
      virtual xqp_string   
      getDefaultElementAndTypeNamespace( ) = 0;

      virtual void   
      setDefaultFunctionNamespace( xqp_string URI ) = 0;
      ///default is none
      
      virtual xqp_string   
      getDefaultFunctionNamespace( ) = 0;

      // TODO ??? here some functions for schema ... not impl yet

      virtual void   
      addExternalVariableType( xqp_string var_name, type_ident_ref_t var_type) = 0;

      virtual type_ident_ref_t 
      getExternalVariableType( xqp_string var_name ) = 0;

      virtual void   
      deleteExternalVariableType( xqp_string var_name ) = 0;

      virtual unsigned int     
      getExternalVariableCount() = 0;

      virtual bool   
      getExternalVariableByIndex( unsigned int i, xqp_string *var_name, type_ident_ref_t *var_type ) = 0;

      virtual void   
      deleteAllVariables() = 0;

      virtual void   
      setContextItemStaticType( type_ident_ref_t    type ) = 0;

      virtual type_ident_ref_t   
      getContextItemStaticType( ) = 0;


      ///here some api for external functions

      virtual void   
      addCollation( xqp_string URI, std::string  coll_string, ::Collator::ECollationStrength coll_strength = ::Collator::TERTIARY) = 0;

      virtual void   
      addCollation( xqp_string URI, ::Collator *user_coll ) = 0;

      virtual CollationInfo*   
      getCollation( xqp_string URI ) = 0;

      virtual void   
      deleteCollation( xqp_string URI) = 0;

      virtual unsigned int     
      getCollationCount() = 0;

      virtual CollationInfo*   
      getCollationInfoByIndex( unsigned int i ) = 0;//std::string *coll_string, ::Collator::ECollationStrength *coll_strength ) = 0;

      virtual void   
      deleteAllCollations() = 0;


      virtual void   
      setDefaultCollation( xqp_string URI ) = 0;//std::string  coll_string, ::Collator::ECollationStrength coll_strength ) = 0;

      virtual xqp_string 
      getDefaultCollation() = 0;


      virtual void   
      setConstructionMode( StaticContextConsts::construction_mode_t ) = 0;

      virtual StaticContextConsts::construction_mode_t  
      getConstructionMode( ) = 0;


      virtual void   
      setOrderingMode( StaticContextConsts::ordering_mode_t ) = 0;

      virtual StaticContextConsts::ordering_mode_t  
      getOrderingMode( ) = 0;


      virtual void   
      setDefaultOrderForEmptySequences( StaticContextConsts::order_empty_mode_t ) = 0;

      virtual StaticContextConsts::order_empty_mode_t   
      getDefaultOrderForEmptySequences( ) = 0;


      virtual void   
      setBoundarySpacePolicy( StaticContextConsts::boundary_space_mode_t ) = 0;

      virtual StaticContextConsts::boundary_space_mode_t  
      getBoundarySpacePolicy( ) = 0;


      virtual void   
      setCopyNamespacesMode( StaticContextConsts::preserve_mode_t preserve, StaticContextConsts::inherit_mode_t inherit ) = 0;

      virtual void   
      getCopyNamespacesMode( StaticContextConsts::preserve_mode_t *preserve, StaticContextConsts::inherit_mode_t *inherit ) = 0;


      virtual bool   
      setBaseURI( xqp_string baseURI ) = 0;

      virtual xqp_string   
      getBaseURI( ) = 0;


      // statically known documents (types)
      virtual void   
      addDocumentType( xqp_string URI, type_ident_ref_t doc_type ) = 0;

      virtual type_ident_ref_t   
      getDocumentType( xqp_string URI) = 0;

      virtual void   
      deleteDocumentType( xqp_string URI) = 0;

      virtual unsigned int     
      getDocumentTypeCount() = 0;

      virtual bool   
      getDocumentByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *doc_type ) = 0;

      virtual void   
      deleteAllDocumentTypes() = 0;

      virtual void   
      addCollectionType( xqp_string URI, type_ident_ref_t   collection_type ) = 0;
      ///if URI is empty then it refers to default collection type
      
      virtual type_ident_ref_t   
      getCollectionType( xqp_string URI ) = 0;
      ///if URI is empty then it refers to default collection type
      
      virtual void   
      deleteCollectionType( xqp_string URI ) = 0;
      ///if URI is empty then it refers to default collection type
      
      virtual unsigned int     
      getCollectionTypeCount() = 0;

      virtual bool   
      getCollectionTypeByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *collection_type ) = 0;

      virtual void   
      deleteAllCollectionTypes() = 0;

      virtual void   
      setDefaultCollectionType( type_ident_ref_t default_collection_type ) = 0;
      ///default node()*
      
      virtual type_ident_ref_t 
      getDefaultCollectionType( ) = 0;

      /**
       * functions that are used for registering external functions
       */
      virtual void 
      registerStatelessExternalFunction(StatelessExternalFunction_t aExternalFunction) = 0;

  };
} /* namespace zorba */
#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
