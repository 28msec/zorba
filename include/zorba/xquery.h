#ifndef XQP_XQUERY_API_H
#define XQP_XQUERY_API_H

#include <ostream>

#include <zorba/sax2.h>
#include <zorba/api_shared_types.h>


namespace zorba {

  /** \brief This class is the representation of a %XQuery in the %Zorba engine.
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
          O1  /**< Use basic optimizations (e.g.\ removing sorting, removing duplicate elimination, 
                   or constant folding). */
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
       *  @param aErrorHandler ErrorHandler to which errors are reported. The caller retains ownership
       *         over the ErrorHandler passed as parameter.
       *  @throw SystemException if the query has been closed.
       *  @see close()
       */
      virtual void
      registerErrorHandler(ErrorHandler* aErrorHandler) = 0;

      /** \brief Reset the error handling mechanism to throwing exceptions, i.e.\ behave as if no
       *         ErrorHandler had been set.
       *   
       *  @throw SystemException if the query has been closed already.
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

      /** \brief Serialize the result of the query as text to the given output stream.
       *
       * @param aOutStream the output stream on which the result is written.
       * @param aSerOptions an optinal set of serialization options.
       * @throw ZorbaException if an error occurs (e.g. the query is closed or has not been compiled)
       */
      virtual void
      serialize(std::ostream& aOutStream, 
                const SerializerOptions_t& aSerOptions = SerializerOptions()) = 0;

      /** \brief Apply/execute the query if it is an updating query.
       *
       * @throw ZorbaException if an error occured, e.g. if the query has been closed, if the query
       *        has not been compiled, or an error occures during execution.
       */
      virtual void 
      applyUpdates() = 0;

      /** \brief Get an iterator for the result of the query.
        *
        * @return ResultIterator iterator over the result sequence.
        * @throw ZorbaException if an error occurs (e.g. the query is closed or has not been compiled).
        */
      virtual ResultIterator_t
      iterator() = 0;

      /** \brief Get the dynamic context of this query.
       *
       * This function returns the dynamic context that belongs to this query and
       * is used during query execution.
       * The context can be used, for example, to set values of external variables,
       * the default collation, or the current datetime.
       * It is only available if the query has been compiled, otherwise
       * an error is reported. Moreover, the context must not be modified during the
       * execution of a query (i.e. if a ResultIterator is opened).
       * The lifetime of the context returned by this function is restricted
       * by the lifetime of the according query object.
       *
       * @throw SystemException if the query has not been compiled or is closed.
       * @return DynamicContext of this query.
       */
      virtual DynamicContext*
      getDynamicContext() const = 0;

      /** \brief Get the static context of this query.
       *
       * This function returns the static context that belongs to this query.
       * The static context is only available if the query has been compiled, otherwise
       * an error is reported.
       * The context has all the components and values that have been set by the either
       * the static context that was passed when creating the query and and those that
       * were set in the prolog of the query.
       * Note that after compilation of the query the static context is a read only structure.
       * Moreover, the lifetime of the context returned by this function is restricted
       * by the lifetime of the according query object.
       *
       * @throw SystemException if the query has not been compiled or is closed.
       * @return StaticContext of this query.
       */
      virtual const StaticContext*
      getStaticContext() const = 0;

      /** \brief Compile the give query String.
       *
       * @param aQuery the query String to compile.
       * @throw ZorbaException if the query has been closed, is already compiled, or
       *        an error occurs while compiling the query.
       */
      virtual void
      compile(const String& aQuery) = 0;

      /** \brief Compile the give query String with the given compiler hints.
       *
       * @param aQuery the query String to compile.
       * @param aHints hints passed to the query compiler.
       * @throw ZorbaException if the query has been closed, is already compiled, or
       *        an error occurs while compiling the query.
       */
      virtual void 
      compile(const String& aQuery, const XQuery::CompilerHints_t& aHints) = 0;
      
      /** \brief Compile the query given as an input stream with the given compiler hints.
       *
       * @param aQuery the query input stream.
       * @param aHints hints passed to the query compiler.
       * @throw ZorbaException if the query has been closed, is already compiled, or
       *        an error occurs while compiling the query.
       */
      virtual void 
      compile(std::istream& aQuery, const XQuery::CompilerHints_t& aHints) = 0;
      
      /** \brief Compile the give query String with the given static context and the 
       *         given compiler hints.
       *
       * @param aQuery the query String to compile.
       * @param aStaticContext the static context.
       * @param aHints hints passed to the query compiler.
       * @throw ZorbaException if the query has been closed, is already compiled, or
       *        an error occurs while compiling the query.
       */
      virtual void 
      compile(const String& aQuery, const StaticContext_t& aStaticContext, 
              const XQuery::CompilerHints_t& aHints) = 0;
      
      /** \brief Compile the query given as an input stream with the given static context and the 
       *         given compiler hints.
       *
       * @param aQuery the query input stream.
       * @param aStaticContext the static context.
       * @param aHints hints passed to the query compiler.
       * @throw ZorbaException if the query has been closed, is already compiled, or
       *        an error occurs while compiling the query.
       */
      virtual void 
      compile(std::istream& aQuery, const StaticContext_t& aStaticContext, 
              const XQuery::CompilerHints_t& aHints) = 0;

      //Set the fileName
      virtual void
      setFileName( const String& ) = 0;

      //Register a SAX handler
      virtual void
      registerSAXHandler( SAX2_ContentHandler * ) = 0;

      //Execute the query with an handler given
      virtual void
      executeSAX( SAX2_ContentHandler * ) = 0;

      //Execute the query
      virtual void
      executeSAX() = 0;

      /** \brief Close the query and release all aquired ressources.
       *
       * While a query is compiled and/or active, it holds on to a couple of ressources.
       * Before Zorba can be safely shutdown, all ressources must be released.
       * For queries this can be done by calling close. However, if close is not
       * called explicitly, it will be automatically called by the XQuery objects
       * destructor, i.e. if the last boost smart pointer holding on to this XQuery object
       * is destroyed.
       *
       * Note that calling close explicitly is usually not necessary. 
       *
       * @throw SystemException if the XQuery object has already been closed.
       */
      virtual void
      close() = 0;

      /** \brief Clone this query object for executing it in another thread.
       *
       * A query object is not thread safe, i.e. it can't be executed in several threads.
       * In order to execute it in another thread it needs to be cloned with this function.
       * Moreover, this function also clones the StaticContext and DynamicContext of 
       * the XQuery object. In the DynamicContext of the cloned query different variable
       * values can be used, e.g. set different external variable values.
       *
       * For an example of cloning a query and setting different values in the dynamic context
       * see example_10 in file \link simple.cpp \endlink.
       *
       * @return The cloned XQuery object.
       * @throw SystemException if the query has not been compiled or is closed.
       */
      virtual XQuery_t
      clone() const = 0;

  };

  // xml serialization of the query (equiv to calling serialize(os) 
  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery); 

} /* namespace zorba */

#endif
