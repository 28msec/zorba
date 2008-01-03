/**
 * @file errors.h
 * @author Paul Pedersen
 * @copyright 2006-2007 FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef XQP_ALERT_CODES
#define XQP_ALERT_CODES

#include <string>

namespace xqp {

class AlertCodes
{
public:
	enum error_code
  {
    // XPath dynamic error
    XPDY0002 = 1,  // evaluation of an expression relies on some part of the dynamic context that has not been assigned a value.
    XPDY0021,  // (Not currently used.)
    XPDY0050,  // the dynamic type of the operand of a treat expression does not match the sequence type specified by the treat expression. This error might also be raised by a path expression beginning with "/" or "// " if the context node is not in a tree that is rooted at a document node. This is because a leading "/" or "// " in a path expression is an abbreviation for an initial step that includes the clause treat as document-node().

    // XPath static error
    XPST0001,  // analysis of an expression relies on some component of the static context that has not been assigned a value.
    XPST0003,  // an expression is not a valid instance of the grammar.
    XPST0005,  // During the analysis phase, it is a static error if the static type assigned to an expression other than the expression () or data(()) is empty-sequence().
    XPST0008,  // an expression refers to an element name, attribute name, schema type name, namespace prefix, or variable name that is not defined in the static context, except for an ElementName in an ElementTest or an AttributeName in an AttributeTest.
    XPST0010,  // An implementation must raise a static error if it encounters a reference to an axis that it does not support.
    XPST0017,  // the expanded QName and number of arguments in a function call do not match the name and arity of a function signature in the static context.
    XPST0051,  // a QName that is used as an AtomicType in a SequenceType is not defined in the in-scope schema types as an atomic type.
    XPST0080,  // the target type of a cast or castable expression is xs:NOTATION or xs:anyAtomicType.
    XPST0081,  // a QName used in a query contains a namespace prefix that cannot be expanded into a namespace URI by using the statically known namespaces.
    XPST0083,  // (Not currently used.)

    // XPath type error
    XPTY0004,  // during the static analysis phase, an expression is found to have a static type that is not appropriate for the context in which the expression occurs, or during the dynamic evaluation phase, the dynamic type of a value does not match a required type as specified by the matching rules in 2.5.4,  // SequenceType Matching.
    XPTY0006,  // (Not currently used.)
    XPTY0007,  // (Not currently used.)
    XPTY0018,  // the result of the last step in a path expression contains both nodes and atomic values.
    XPTY0019,  // the result of a step (other than the last step) in a path expression contains an atomic value.
    XPTY0020,  // in an axis step, the context item is not a node.

    // XQuery dynamic error
    XQDY0025,  // any attribute of a constructed element does not have a name that is distinct from the names of all other attributes of the constructed element.
    XQDY0026,  // the result of the content expression of a computed processing instruction constructor contains the string "?>".
    XQDY0027,  // In a validate expression, it is a dynamic error if the root element information item in the PSVI resulting from validation does not have the expected validity property: valid if validation mode is strict, or either valid or notKnown if validation mode is lax.
    XQDY0029,  // (Not currently used.)
    XQDY0041,  // the value of the name expression in a computed processing instruction constructor cannot be cast to the type xs:NCName.
    XQDY0044,  // the node-name property of the node constructed by a computed attribute constructor is in the namespace http:// www.w3.org/2000/xmlns/ (corresponding to namespace prefix xmlns), or is in no namespace and has local name xmlns.
    XQDY0052,  // (Not currently used.)
    XQDY0061,  // the operand of a validate expression is a document node whose children do not consist of exactly one element node and zero or more comment and processing instruction nodes, in any order.
    XQDY0062,  // (Not currently used.)
    XQDY0064,  // the value of the name expression in a computed processing instruction constructor is equal to "XML" (in any combination of upper and lower case).
    XQDY0072,  // the result of the content expression of a computed comment constructor contains two adjacent hyphens or ends with a hyphen.
    XQDY0074,  // the value of the name expression in a computed element or attribute constructor cannot be converted to an expanded QName (for example, because it contains a namespace prefix not found in statically known namespaces.) 
    XQDY0084,  // the element validated by a validate statement does not have a top-level element declaration in the in-scope element declarations, if validation mode is strict.
    XQDY0091,  // An implementation MAY raise a dynamic error if an xml:id error, as defined in [XML ID], is encountered during construction of an attribute named xml:id.
    XQDY0092,  // An implementation MAY raise a dynamic error if a constructed attribute named xml:space has a value other than preserve or default.

    // XQuery static error
    XQST0009,  // An implementation that does not support the Schema Import Feature must raise a static error if a Prolog contains a schema import.
    XQST0012,  // the set of definitions contained in all schemas imported by a Prolog do not satisfy the conditions for schema validity specified in Sections 3,  // and 5,  // of [XML Schema] Part 1--i.e., each definition must be valid, complete, and unique.
    XQST0013,  // an implementation recognizes a pragma but determines that its content is invalid.
    XQST0014,  // (Not currently used.)
    XQST0015,  // (Not currently used.)
    XQST0016,  // An implementation that does not support the Module Feature raises a static error if it encounters a module declaration or a module import.
    XQST0022,  // the value of a namespace declaration attribute is not a URILiteral.
    XQST0031,  // the version number specified in a version declaration is not supported by the implementation.
    XQST0032,  // A static error is raised if a Prolog contains more than one base URI declaration.
    XQST0033,  // a module contains multiple bindings for the same namespace prefix.
    XQST0034,  // multiple functions declared or imported by a module have the number of arguments and their expanded QNames are equal (as defined by the eq operator).
    XQST0035,  // It is a static error to import two schema components that both define the same name in the same symbol space and in the same scope.
    XQST0036,  // It is a static error to import a module if the importing module's in-scope schema types do not include definitions for the schema type names that appear in the declarations of variables and functions (whether in an argument type or return type) that are present in the imported module and are referenced in the importing module.
    XQST0037,  // (Not currently used.)
    XQST0038,  // a Prolog contains more than one default collation declaration, or the value specified by a default collation declaration is not present in statically known collations.
    XQST0039,  // It is a static error for a function declaration to have more than one parameter with the same name.
    XQST0040,  // the attributes specified by a direct element constructor do not have distinct expanded QNames.
    XQST0042,  // (Not currently used.)
    XQST0043,  // (Not currently used.)
    XQST0045,  // the function name in a function declaration is in one of the following namespaces: http:// www.w3.org/XML/1998/namespace, http:// www.w3.org/2001/XMLSchema, http:// www.w3.org/2001/XMLSchema-instance, http:// www.w3.org/2005/xpath-functions.
    XQST0046,  // An implementation MAY raise a static error if the value of a URILiteral is of nonzero length and is not in the lexical space of xs:anyURI.
    XQST0047,  // multiple module imports in the same Prolog specify the same target namespace.
    XQST0048,  // a function or variable declared in a library module is not in the target namespace of the library module.
    XQST0049,  // two or more variables declared or imported by a module have equal expanded QNames (as defined by the eq operator.)
    XQST0053,  // (Not currently used.)
    XQST0054,  // a variable depends on itself.
    XQST0055,  // a Prolog contains more than one copy-namespaces declaration.
    XQST0056,  // (Not currently used.)
    XQST0057,  // a schema import binds a namespace prefix but does not specify a target namespace other than a zero-length string.
    XQST0058,  // multiple schema imports specify the same target namespace.
    XQST0059,  // an implementation is unable to process a schema or module import by finding a schema or module with the specified target namespace.
    XQST0060,  // the name of a function in a function declaration is not in a namespace (expanded QName has a null namespace URI).
    XQST0063,  // (Not currently used.)
    XQST0065,  // A static error is raised if a Prolog contains more than one ordering mode declaration.
    XQST0066,  // A static error is raised if a Prolog contains more than one default element/type namespace declaration, or more than one default function namespace declaration.
    XQST0067,  // A static error is raised if a Prolog contains more than one construction declaration.
    XQST0068,  // A static error is raised if a Prolog contains more than one boundary-space declaration.
    XQST0069,  // A static error is raised if a Prolog contains more than one empty order declaration.
    XQST0070,  // A static error is raised if a namespace URI is bound to the predefined prefix xmlns, or if a namespace URI other than http:// www.w3.org/XML/1998/namespace is bound to the prefix xml, or if the prefix xml is bound to a namespace URI other than http:// www.w3.org/XML/1998/namespace.
    XQST0071,  // A static error is raised if the namespace declaration attributes of a direct element constructor do not have distinct names.
    XQST0073,  // the graph of module imports contains a cycle (that is, if there exists a sequence of modules M1,  // ... Mn such that each Mi imports Mi+1,  // and Mn imports M1), unless all the modules in the cycle share a common namespace.
    XQST0075,  // An implementation that does not support the Validation Feature must raise a static error if it encounters a validate expression.
    XQST0076,  // a collation subclause in an order by clause of a FLWOR expression does not identify a collation that is present in statically known collations.
    XQST0077,  // (Not currently used.)
    XQST0078,  // (Not currently used.)
    XQST0079,  // an extension expression contains neither a pragma that is recognized by the implementation nor an expression enclosed in curly braces.
    XQST0082,  // (Not currently used.)
    XQST0085,  // the namespace URI in a namespace declaration attribute is a zero-length string, and the implementation does not support [XML Names 1.1].
    XQST0087,  // the encoding specified in a Version Declaration does not conform to the definition of EncName specified in [XML 1.0].
    XQST0088,  // the literal that specifies the target namespace in a module import or a module declaration is of zero length.
    XQST0089,  // a variable bound in a for clause of a FLWOR expression, and its associated positional variable, do not have distinct names (expanded QNames).
    XQST0090,  // a character reference does not identify a valid character in the version of XML that is in use.
    XQST0093,  // It is a static error to import a module M1,  // if there exists a sequence of modules M1,  // ... Mi ... M1,  // such that each module directly depends on the next module in the sequence (informally, if M1,  // depends on itself through some chain of module dependencies.)

    // XQuery Type erros
    XQTY0023,  // (Not currently used.)
    XQTY0024,  // the content sequence in an element constructor contains an attribute node following a node that is not an attribute node.
    XQTY0028,  // (Not currently used.)
    XQTY0030,  // the argument of a validate expression does not evaluate to exactly one document or element node.
    XQTY0086,  // the typed value of a copied element or attribute node is namespace-sensitive when construction mode is preserve and copy-namespaces mode is no-preserve.

    // XQuery 1.0 and XPath 2.0 Functions and Operators
    FOER0000, //Unidentified error.
    FOAR0001, //Division by zero.  This error is raised whenever an attempt is made to divide by zero.
    FOAR0002, //Numeric operation overflow/underflow.  This error is raised whenever numeric operations result in an overflow or underflow.
    FOCA0001, //Input value too large for decimal.
    FOCA0002, //Invalid lexical value.
    FOCA0003, //Input value too large for integer.
    FOCA0005, //NaN supplied as float/double value.
    FOCA0006, //String to be cast to decimal has too many digits of precision.
    FOCH0001, //Code point not valid.
    FOCH0002, //Unsupported collation.
    FOCH0003, //Unsupported normalization form.
    FOCH0004, //Collation does not support collation units.
    FODC0001, //No context document.
    FODC0002, //Error retrieving resource.
    FODC0003, //Function stability not defined.
    FODC0004, //Invalid argument to fn:collection.
    FODC0005, //Invalid argument to fn:doc or fn:doc-available.
    FODT0001, //Overflow/underflow in date/time operation.
    FODT0002, //Overflow/underflow in duration operation.
    FODT0003, //Invalid timezone value.
    FONS0004, //No namespace found for prefix.
    FONS0005, //Base-uri not defined in the static context.
    FORG0001, //Invalid value for cast/constructor.
    FORG0002, //Invalid argument to fn:resolve-uri().
    FORG0003, //fn:zero-or-one called with a sequence containing more than one item.
    FORG0004, //fn:one-or-more called with a sequence containing no items.
    FORG0005, //fn:exactly-one called with a sequence containing zero or more than one item.
    FORG0006, //Invalid argument type.
    FORG0008, //Both arguments to fn:dateTime have a specified timezone.
    FORG0009, //Error in resolving a relative URI against a base URI in fn:resolve-uri.
    FORX0001, //Invalid regular expression. flags
    FORX0002, //Invalid regular expression.
    FORX0003, //Regular expression matches zero-length string.
    FORX0004, //Invalid replacement string.
    FOTY0012, //Argument node does not have a typed value.

#if 0
		// XQuery errors
		XPST0001_STATIC_CONTEXT_COMPONENT_MISSING						= 1,
		XPDY0002_DYNAMIC_CONTEXT_COMPONENT_MISSING					= 2,
		XPST0003_STATIC_GRAMMAR_ERROR												= 3,
		XPTY0004_STATIC_TYPE_ERROR													= 4,
		XPST0005_STATIC_ILLEGAL_EMPTY_SEQUENCE							= 5,
		FORG0006_INVALID_ARGUMENT_TYPE											= 6,
		XPST0008_STATIC_ILLEGAL_REFERENCE										= 8,
		XQST0009_STATIC_SCHEMA_IMPORT_NOT_SUPPORTED					= 9,
		XPST0010_STATIC_AXIS_NOT_SUPPORTED									= 10,
		XQST0012_STATIC_SCHEMA_NOT_VALID										= 12,
		XQST0013_STATIC_PRAGMA_NOT_VALID										= 13,
		XQST0016_STATIC_MODULE_IMPORT_NOT_SUPPORTED					= 16,
		XPST0017_STATIC_FUNCTION_NOT_FOUND									= 17,
		XPTY0018_TYPE_MIXED_PATHEXPR												= 18,
		XPTY0019_TYPE_STEP_IS_ATOMIC												= 19,
		XPTY0020_TYPE_CONTEXT_NOT_A_NODE										= 20,
		XQST0022_STATIC_NAMESPACE_DECL_NOT_A_URI						= 22,
		XQTY0024_TYPE_ATTRIBUTE_NODE_OUT_OF_ORDER						= 24,
		XQDY0025_DYNAMIC_DUPLICATE_ATTRIBUTE_NAME						= 25,
		XQDY0026_DYNAMIC_ILLEGAL_CONTENT										= 26,
		XQDY0027_DYNAMIC_VALIDATION_FAILED									= 27,
		XQTY0030_TYPE_VALIDATION_BAD_ARG										= 30,
		XQST0031_STATIC_BAD_VERSION													= 31,
		XQST0032_STATIC_DUPLICATE_BASE_URI									= 32,
		XQST0033_STATIC_DUPLICATE_NAMESPACE_PREFIX					= 33,
		XQST0034_STATIC_DUPLICATE_FUNCTIONS									= 34,
		XQST0035_STATIC_DUPLICATE_SCHEMAS										= 35,
		XQST0036_STATIC_MISSSING_IMPORTED_SCHEMA_TYPES			= 36,
		XQST0038_STATIC_DUPLICATE_DEFAULT_COLLATION					= 38,
		XQST0039_STATIC_DUPLICATE_FUNARG_NAME								= 39,
		XQST0040_STATIC_DUPLICATE_ATTRIBUTE_NAME						= 40,
		XQDY0041_DYNAMIC_PI_NON_NCNAME											= 41,
		XQDY0044_DYNAMIC_ILLEGAL_ATTRIBUTE_NAME							= 44,
		XQST0045_STATIC_ILLEGAL_FUNCTION_NAME								= 45,
		XQST0046_STATIC_ILLEGAL_URI_LITERAL									= 46,
		XQST0047_STATIC_DUPLICATE_IMPORTED_TARGET_NS				= 47,
		XQST0048_STATIC_MISSING_TARGET_NAMESPACE						= 48,
		XQST0049_STATIC_DUPLICATE_IMPORTED_VARIABLES				= 49,
		XPDY0050_DYNAMIC_TREAT_FAILED												= 50,
		XPST0051_STATIC_MISSING_SCHEMA_TYPE									= 51,
		XQST0054_STATIC_CIRCULAR_INITIALIZATION							= 54,
		XQST0055_STATIC_DUPLICATE_COPY_NAMESPACE						= 55,
		XQST0057_STATIC_MISSING_TARGET_NAMESPACE						= 57,
		XQST0058_STATIC_DUPLICATE_TARGET_NAMESPACE					= 58,
		XQST0059_STATIC_TARGET_NAMESPACE_NOT_FOUND					= 59,
		XQST0060_STATIC_FUNCTION_MISSING_NAMESPACE					= 60,
		XQDY0061_DYNAMIC_VALIDATE_BAD_DOCUMENT							= 61,
		XQDY0064_DYNAMIC_ILLEGAL_PI_NAME										= 64,
		XQST0065_STATIC_DUPLICATE_ORDERING_MODE_DECL				= 65,
		XQST0066_STATIC_DUPLICATE_DEFAULT_NAMESPACE_DECL		= 66,
		XQST0067_STATIC_DUPLICATE_CONSTRUCTION_DECL					= 67,
		XQST0068_STATIC_DUPLICATE_BOUNDARY_SPACE_DECL				= 68,
		XQST0069_STATIC_DUPLICATE_EMPTY_ORDER_DECL					= 69,
		XQST0070_STATIC_RESERVED_PREFIX											= 70,
		XQST0071_STATIC_DUPLICATE_NS_ATTRIBUTES							= 71,
		XQDY0072_DYNAMIC_ILLEGAL_HYPHENS										= 72,
		XQST0073_STATIC_CYCLIC_MODULE_IMPORT								= 73,
		XQDY0074_DYNAMIC_BAD_ELEM_ATTR_QNAME								= 74,
		XQST0075_STATIC_VALIDATION_NOT_SUPPORTED						= 75,
		XQST0076_STATIC_UNRECOGNIZED_COLLATION							= 76,
		XQST0079_STATIC_UNRECOGNIZE_EXTENSION_EXPR					= 79,
		XPST0080_STATIC_BAD_CAST_EXPR												= 80,
		XPST0081_STATIC_BAD_QNAME_PREFIX										= 81,
		XQDY0084_DYNAMIC_UNKNOWN_VALIDATED_ELEMENT					= 84,
		XQST0085_STATIC_EMPTY_NAMESPACE_URI									= 85,
		XQTY0086_TYPE_NODE_COPY_LOOSES_NAMESPACES						= 86,
		XQST0087_STATIC_ILLEGAL_ENCODING										= 87,
		XQST0088_STATIC_EMPTY_IMPORT_TARGET_NAMESPACE				= 88,
		XQST0089_STATIC_POSVAR_SHADOW												= 89,
		XQST0090_STATIC_ILLEGAL_CHARREF											= 90,

		//XPATH errors
		FOER0000_Unidentified_error,
		FOAR0001_Division_by_zero,
		FOAR0002_Numeric_operation_overflow_underflow,
		FOCA0001_Input_value_too_large_for_decimal,
		FOCA0002_Invalid_lexical_value,
		FOCA0003_Input_value_too_large_for_integer,
		FOCA0005_NaN_supplied_as_float_double_value,
		FOCA0006_String_to_be_cast_to_decimal_has_too_many_digits_of_precision,
		FOCH0001_Code_point_not_valid,
		FOCH0002_Unsupported_collation,
		FOCH0003_Unsupported_normalization_form,
		FOCH0004_Collation_does_not_support_collation_units,
		FODC0001_No_context_document,
		FODC0002_Error_retrieving_resource,
		FODC0003_Function_stability_not_defined,
		FODC0004_Invalid_argument_to_fn_collection,
		FODC0005_Invalid_argument_to_fn_doc_or_fn_doc_available,
		FODT0001_Overflow_underflow_in_date_time_operation,
		FODT0002_Overflow_underflow_in_duration_operation,
		FODT0003_Invalid_timezone_value,
		FONS0004_No_namespace_found_for_prefix,
		FONS0005_Base_uri_not_defined_in_the_static_context,
		FORG0001_Invalid_value_for_cast_constructor,
		FORG0002_Invalid_argument_to_fn_resolve_uri,
		FORG0003_fn_zero_or_one_called_with_a_sequence_containing_more_than_one_item,
		FORG0004_fn_one_or_more_called_with_a_sequence_containing_no_items,
		FORG0005_fn_exactly_one_called_with_a_sequence_containing_zero_or_more_than_one_item,
		FORG0006_Invalid_argument_type,
		FORG0008_Both_arguments_to_fn_dateTime_have_a_specified_timezone,
		FORG0009_Error_in_resolving_a_relative_URI_against_a_base_URI_in_fn_resolve_uri,
		FORX0001_Invalid_regular_expression_flags,
		FORX0002_Invalid_regular_expression,
		FORX0003_Regular_expression_matches_zero_length_string,
		FORX0004_Invalid_replacement_string,
		FOTY0012_Argument_node_does_not_have_a_typed_value,
#endif
		// Serialization errors
		SENR0001_Item_is_attribute_or_namespace_node,
  		SEPM0016_Invalid_parameter_value,
 

		// ZORBA errors
		XQP0000_DYNAMIC_RUNTIME_ERROR,
		XQP0001_DYNAMIC_ITERATOR_OVERRUN,
		XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD,
		XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND,
		XQP0004_SYSTEM_NOT_SUPPORTED,
		XQP0005_SYSTEM_ASSERT_FAILED,
		XQP0006_SYSTEM_HASH_ERROR_KEYLEN_EXCEEDS_MAXKEYLEN,
		XQP0007_SYSTEM_VECTOR_OUT_OF_RANGE,
		XQP0008_SYSTEM_READ_LOCK_FAILED,
		XQP0009_SYSTEM_WRITE_LOCK_FAILED,
		XQP0010_SYSTEM_POP_FROM_EMPTY_LIST,
		XQP0011_SYSTEM_FILE_ERROR_IN_FUNCTION,
		XQP0012_SYSTEM_FXCHARHEAP_IOEXCEPTION,
		XQP0013_SYSTEM_MMFILE_IOEXCEPTION,
		XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
		XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
		XQP0016_LOADER_IO_ERROR,
    XQP0017_LOADER_NOT_WELL_FORMED_XML,
    XQP0018_NODEID_OUT_OF_RANGE,

		//Zorba API errors
		API0001_XQUERY_STRING_IS_EMPTY,
		API0002_COMPILE_FAILED,
		API0003_XQUERY_NOT_COMPILED,
		API0004_XQUERY_ALREADY_COMPILED,
    API0005_COLLECTION_ALREADY_EXISTS,
    API0006_COLLECTION_NOT_FOUND,
    API0007_COLLECTION_ITEM_MUST_BE_A_NODE,
    API0008,

    MAX_ZORBA_ERROR_CODE
	};

	enum error_type
	{
		STATIC_ERROR,
		RUNTIME_ERROR,
    TYPE_ERROR,
		SYSTEM_ERROR,
		USER_ERROR
	};

  enum warning_code
  {
  };

  enum NotifyEvent_code
  {
		NOTIF_EXECUTION_STEP
  };

  enum AskUserString_code
  {
  };

  enum AskUserStringOptions_code
  {
    YES_NO,  //"Yes/NO"
    OK_CANCEL, //"OK/Cancel"
  };

//?	enum alert_initiator
//	{
//		USER_INITIATED_ALERT,
//		SYSTEM_INITIATED_ALERT
//	};

  virtual ~AlertCodes();

	virtual std::string err_decode(enum error_code) = 0;
	virtual std::string warning_decode(enum warning_code) = 0;
	virtual std::string notify_event_decode(enum NotifyEvent_code) = 0;
	virtual std::string ask_user_decode(enum AskUserString_code) = 0;
	virtual std::string ask_user_options_decode(enum AskUserStringOptions_code) = 0;

	virtual std::string errtype_decode(enum error_type errtype) = 0;

  std::string::size_type ApplyParam(
        std::string *err_decoded,
        const std::string *param1,
        std::string::size_type);

	void ApplyParams(
        std::string *err_decoded,
        const std::string *param1,
        const std::string *param2);

	/*
	bool is_static_err(enum errcode);
	bool is_dynamic_err(enum errcode);
	bool is_type_err(enum errcode);
	*/
};



class errors_english : public AlertCodes
{
public:
	virtual std::string err_decode(enum error_code);
	virtual std::string errtype_decode(enum error_type errtype);
	virtual std::string warning_decode(enum warning_code);
	virtual std::string notify_event_decode(enum NotifyEvent_code);
	virtual std::string ask_user_decode(enum AskUserString_code);
	virtual std::string ask_user_options_decode(enum AskUserStringOptions_code);
};

/*
	This class reads the error messages from a string table file.
	No need to recompile the code to use international languages.
*/
class errors_string_table : public AlertCodes
{
public:
	errors_string_table( std::string file_name );

//+	virtual std::string err_decode(enum errcode);
//+	virtual std::string warning_decode(enum warning_code);
//+	virtual std::string notify_event_decode(enum NotifyEvent_code);
//+	virtual std::string ask_user_decode(enum AskUserString_code);
//+	virtual std::string ask_user_options_decode(enum AskUserStringOptions_code);
};


#ifndef NDEBUG
extern const char*		g_error_in_file;
extern int						g_error_at_line;
extern bool						g_abort_when_fatal_error;
#endif


} /* namespace xqp */
#endif /* XQP_ERRORS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
