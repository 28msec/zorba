#ifndef XQP_XQUERY_API_H
#define XQP_XQUERY_API_H

#include <ostream>

#include <zorba/api_shared_types.h>


namespace zorba {


  class XQuery 
  {
    public:
      typedef struct CompilerHints {

        // optimization level
        typedef enum {
          O0, // no optimization
          O1  // basic optimization
        } opt_level_t;

        opt_level_t opt_level;

        CompilerHints() { opt_level = O1; }
      } CompilerHints_t;

      typedef struct SerializerOptions {

        typedef struct serialization_method {
          typedef enum {
            XML, 
            HTML, 
            TEXT
          } serialization_method_t;
        };

        typedef struct byte_order_mark {
          typedef enum {
            YES, 
            NO
          } byte_order_mark_t;
        };

        typedef struct escape_uri_attributes {
          typedef enum {
            YES, NO
          } escape_uri_attributes_t;
        };

        typedef struct include_content_type {
          typedef enum {
            YES, NO
          } include_content_type_t;
        };

        typedef struct indent  {
          typedef enum {
            YES, NO
          } indent_t;
        }; 

        typedef struct normalization_form {
          typedef enum {
            NFC, NFD, NFKC, NFKD, fully_normalized, none
          } normalization_form_t;
        };

        typedef struct omit_xml_declaration {
          typedef enum {
            YES, NO
          } omit_xml_declaration_t;
        };

        typedef struct standalone {
          typedef enum {
            YES, NO, OMIT
          } standalone_t;
        };

        typedef struct undeclare_prefixes {
          typedef enum {
            YES, NO
          } undeclare_prefixes_t;
        };

        serialization_method::serialization_method_t    ser_method;
        byte_order_mark::byte_order_mark_t              byte_order_mark;
        escape_uri_attributes::escape_uri_attributes_t  escape_uri_attributes;
        include_content_type::include_content_type_t    include_content_type;
        indent::indent_t                                indent;
        normalization_form::normalization_form_t        normalization_form;
        omit_xml_declaration::omit_xml_declaration_t    omit_xml_declaration;
        standalone::standalone_t                        standalone; 
        undeclare_prefixes::undeclare_prefixes_t        undeclare_prefixes;

        SerializerOptions() 
          : ser_method(serialization_method::XML),
            byte_order_mark(byte_order_mark::NO),
            indent(indent::NO),
            normalization_form(normalization_form::none),
            omit_xml_declaration(omit_xml_declaration::YES),
            standalone(standalone::OMIT),
            undeclare_prefixes(undeclare_prefixes::NO) {}
      } SerializerOptions_t;

    public:
      virtual ~XQuery() {}

      // register an error handler
      // if no error handler has already been set when creating the query
      // the default error handler (i.e. throwing exceptions) is used
      virtual void
      registerErrorHandler(ErrorHandler*) = 0;

      virtual void
      resetErrorHandler() = 0;

      // xml serialization
      // prepares the query with the default dynamic that belongs to this query
      // it can be retrieved using getDynamicContext. 
      virtual void
      serialize(std::ostream&, SerializerOptions_t = SerializerOptions()) = 0;

      // get an result iterator
      // prepares the query with the default dynamic context if non is set using prepare
      virtual ResultIterator_t
      iterator() = 0;

      // get the static context of this query
      // you can modify it and afterwards execute the query with the changes that were applied
      virtual DynamicContext_t
      getDynamicContext() = 0;

      // get the static context that belongs to this query
      // the static context has all the components and values that have been
      // set before (by supplying a static context) compiling the query and
      // those that have been changed while compiling the query (e.g. in the query prolog)
      virtual StaticContext_t
      getStaticContext() = 0;

  };

  // xml serialization of the query (equiv to calling serialize(os) 
  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery); 

} /* namespace zorba */

#endif
