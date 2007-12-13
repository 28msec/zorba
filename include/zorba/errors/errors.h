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

#ifndef XQP_ERRORS_H
#define XQP_ERRORS_H

#include <string>

#include "util/rchandle.h"

namespace xqp {

class error_messages : public rcobject
{
public:
	enum errcode {
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

    MAX_ZORBA_ERROR_CODE
	};

	enum error_type
	{
		STATIC_ERROR,
		RUNTIME_ERROR,
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

	virtual std::string err_decode(enum errcode) = 0;
	virtual std::string warning_decode(enum warning_code) = 0;
	virtual std::string notify_event_decode(enum NotifyEvent_code) = 0;
	virtual std::string ask_user_decode(enum AskUserString_code) = 0;
	virtual std::string ask_user_options_decode(enum AskUserStringOptions_code) = 0;
//	static void err(enum errcode);

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

//typedef rchandle<error_messages>		error_messages_t;

class errors_english : public error_messages
{
public:
	virtual std::string err_decode(enum errcode);
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
class errors_string_table : public error_messages
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
