#ifndef XQP_XQUERY_API_H
#define XQP_XQUERY_API_H

#include <ostream>

#include <zorba/api_shared_types.h>


namespace zorba {


  /** \brief This class is the representation for an %XQuery in the %Zorba
   *         engine.
   *
   * It is used for compiling and executing a query. An instance of
   * this class is not thread safe, i.e.\ on object can not be executed/serialized
   * in multiple threads. To execute on query in several threads
   * the function clone() creates a clone of the same query that
   * can be executed in another thread.
   *
   * An instance of this class can only be created using either the createQuery
   * or compileQuery functions of the Zorba class. Objects are returned as
   * a boost smart pointer (see http://www.boost.org/doc/libs/1_35_0/libs/smart_ptr/smart_ptr.htm),
   * i.e. objects of type XQuery_t are reference counted boost smart pointers to an dynamically
   * allocated XQuery object. Hence, each object can have multiple owners. The object is deleted
   * if nobody holds on to an XQuery_t object anymore.
   *
   * The file \link simple.cpp \endlink contains some basic examples the demonstrate
   * the use of this class.
   */
  class XQuery 
  {
    public:

      /** \brief Set of hints that can be passed to the query compiler.
       *
       * An instance of this class can be passed to the compileQuery function
       * of the Zorba class or the compile function of this class.
       * The members of this class represent hints that are passed to the
       * query compiler. For example, whether optimization of the query
       * should be done (O1) or not (O0).
       *
       * example_6 in file \link simple.cpp \endlink shows an example
       * how CompilerHints can be used.
       */
      typedef struct CompilerHints {

        /** \brief The optimization level used for optimizing the query. */
        typedef enum {
          O0, /**< Don't use any optimization. */
          O1  /**< Use basic optimizations (e.g.\ removing sorting, removing duplicate elimination, or constant folding). */
        } opt_level_t;

        /** \brief The optimization level that is used */
        opt_level_t opt_level;

        /** \brief Default constructor for CompilerHints which assigns default values to all hints.
         *
         * Default values:
         *   - optimization level: O1 
         */
        CompilerHints() { opt_level = O1; }
      } CompilerHints_t;

      /** \brief Options that configure the serialization process of a query result.
       *         See http://www.w3.org/TR/2005/CR-xslt-xquery-serialization-20051103/.
       *
       * This struct defines options that can be passed to the serialization process of a query
       * result. An instance of this class can be passed to the serialize function.
       *
       * File \link serialization.cpp \endlink contains examples that show how to use
       * the SerializerOptions.
       */
      typedef struct SerializerOptions {

        typedef struct serialization_method {
          typedef enum {
            XML, 
            HTML
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

        /** \brief Default constructor for SerializerOptions which assigns default values to all 
         *         options.
         *
         * Default values:
         *   - serialization method: XML
         *   - byte-order-mark: NO
         *   - esacpe-uri-attributes: NO
         *   - include-content-type: NO
         *   - indent: NO
         *   - normalization-form: none
         *   - omit-xml-declaration: NO
         *   - standalone: omit
         *   - undeclare-prefixes: NO
         */
        SerializerOptions() 
          : ser_method(serialization_method::XML),
            byte_order_mark(byte_order_mark::NO),
            escape_uri_attributes(escape_uri_attributes::NO),
            include_content_type(include_content_type::NO),
            indent(indent::NO),
            normalization_form(normalization_form::none),
            omit_xml_declaration(omit_xml_declaration::NO),
            standalone(standalone::OMIT),
            undeclare_prefixes(undeclare_prefixes::NO) {}
      } SerializerOptions_t;

    public:
      /** \brief Destructor that destroys this XQuery object. 
       * 
       * The destructor is called if there are no references to an 
       * XQuery_t object hold anymore.
       */
      virtual ~XQuery() {}

      /** \brief Register an ErrorHandler to which errors during compilation or
       *         execution/serialization are reported.
       *
       *  If not ErrorHandler has been set using this function or when creating/compiling
       *  the query using the Zorba object (i.e.\ createQuery or compileQuery), then subclasses 
       *  of the ZorbaException class are thrown to report errors.
       *
       *  @param ErrorHandler to which errors are reported. The caller retains ownership
       *         over the ErrorHandler passed as parameter.
       *  @throw SystemException if the query has been closed.
       *  @see close()
       */
      virtual void
      registerErrorHandler(ErrorHandler*) = 0;

      /** \brief Reset the error handling mechanism to throwing exceptions, i.e.\ behave as if no
       *         ErrorHandler had been set.
       *   
       *  @throw SystemException if the query has been closed.
       *  @see close()
       *  @see registerErrorHandler(ErrorHandler*)
       */
      virtual void
      resetErrorHandler() = 0;

      /** \brief Check if this query is an updating query.
       *
       * @return true if the query is an updating query, false otherwise.
       * @throw SystemException if the query is not compiled or has been closed.
       * @see close()
       * @see compile(...)
       */
      virtual bool
      isUpdateQuery() const = 0;

      // xml serialization
      // prepares the query with the default dynamic that belongs to this query
      // it can be retrieved using getDynamicContext. 
      virtual void
      serialize(std::ostream&, const SerializerOptions_t& = SerializerOptions()) = 0;

      virtual void 
      applyUpdates(std::ostream& os) = 0;

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
      virtual const StaticContext_t
      getStaticContext() const = 0;

      virtual void
      compile(const String&) = 0;

      virtual void 
      compile(const String&, const XQuery::CompilerHints_t& aHints) = 0;
      
      virtual void 
      compile(std::istream&, const XQuery::CompilerHints_t& aHints) = 0;
      
      virtual void 
      compile(const String&, const StaticContext_t&, const XQuery::CompilerHints_t& aHints) = 0;
      
      virtual void 
      compile(std::istream&, const StaticContext_t&, const XQuery::CompilerHints_t& aHints) = 0;

      //Set the fileName
      virtual void
      setFileName( const String& ) = 0;

      virtual void
      close() = 0;

      virtual XQuery_t
      clone() const = 0;

  };

  // xml serialization of the query (equiv to calling serialize(os) 
  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery); 

} /* namespace zorba */

/** \example simple.cpp
 *  This is a simple example that demonstrate how to use the Zorba XQuery Engine to
 *  compile and execute queries.
 *
 */

#endif
