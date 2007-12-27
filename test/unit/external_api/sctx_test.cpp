
#include "zorba/zorba_api.h"
#include <fstream>
#include <assert.h>

//#include "../error_display.h"

using namespace std;
using namespace xqp;

string make_absolute_file_name(const char *result_file_name, const char *this_file_name)
{
	string		str_result;
	string::size_type		pos;

	str_result = this_file_name;
	pos = str_result.rfind('/');
	if(pos == string::npos)
		pos = str_result.rfind('\\');
	if(pos == string::npos)
		return result_file_name;
	str_result.erase(pos+1);
	str_result += result_file_name;
//	cout << "make_absolute_file_name -> " << str_result << endl;
	return str_result;
}

bool verify_expected_result(string result_file_name, string expected_file)
{
	FILE			*ftest, *fexpected;
	char			c1,c2;
	size_t		nr_read1, nr_read2;

  // warning: this method of reading a file might trim the 
  // whitespace at the end of lines
	ftest = fopen(result_file_name.c_str(), "r");
	if(!ftest)
		return false;
	fexpected = fopen(expected_file.c_str(), "r");
	if(!fexpected)
	{
		fclose(ftest);
		return false;
	}
  while (1)
	{
		do{
			nr_read1 = fread(&c1, sizeof(c1), 1, ftest);
			if((c1 != '\r') && (c1 != '\n'))
				break;
		}while(nr_read1 > 0);
		do{
			nr_read2 = fread(&c2, sizeof(c2), 1, fexpected);
			if((c2 != '\r') && (c2 != '\n'))
				break;
		}while(nr_read2 > 0);
		if(nr_read1 < 1)
		{
			if(nr_read2 < 1)
			{ fclose(ftest);fclose(fexpected);return true;}
			else
				break;
		}
		else if(nr_read2 < 1)
			break;
		else if(c1 != c2)
			break;
  }     
	fclose(ftest);fclose(fexpected);return false;
}

int test_api_static_context(const char *result_file_name)
{
	ofstream		result_file(make_absolute_file_name(result_file_name, __FILE__).c_str());
	unsigned int		i;
	unsigned int	max;
	ostringstream		oss2;

	///now start the zorba engine
	ZorbaEngine& zorba_factory = ZorbaEngine::getInstance();

	///thread specific
	zorba_factory.initThread();

	//do the test
	ZorbaAlertsManager&		errmanager = zorba_factory.getAlertsManagerForCurrentThread();

	///testing the static context!
	StaticQueryContext_t		sctx1;

	for(i=0;i<100;i++)
	{
		sctx1 = zorba_factory.createStaticContext();
	}

	sctx1->SetXPath1_0CompatibMode(StaticQueryContext::xpath2_0);
	StaticQueryContext::xpath1_0compatib_mode_t		xp_compatib_mode;
	xp_compatib_mode = sctx1->GetXPath1_0CompatibMode();
	result_file << "GetXPath1_0CompatibMode " << xp_compatib_mode << endl;

	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		ostringstream		oss2;
		oss1 << "ulu" << i;
		oss2 << "http://www.flworfound.org/apitest/test_ns" << i;
		sctx1->AddNamespace(oss1.str(), oss2.str());
	}
	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "ulu" << i;
		xqp_string		ns_uri = sctx1->GetNamespaceURIByPrefix(oss1.str());
		result_file << "ns uri " << i << ":" << (std::string)ns_uri << endl;
	}
	result_file << "delete some namespaces..." << endl;
	for(i=0;i<100;i+=2)
	{
		ostringstream		oss1;
		oss1 << "ulu" << i;
		sctx1->DeleteNamespace(oss1.str());
	}
	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "ulu" << i;
		xqp_string		ns_uri = sctx1->GetNamespaceURIByPrefix(oss1.str());
		result_file << "ns uri " << i << ":" << (std::string)ns_uri << endl;
	}
	max = sctx1->GetNamespaceCount();
	result_file << "there are " << max << " namespaces:" << endl;
	for(i=0;i<max;i++)
	{
		xqp_string	prefix;
		xqp_string	uri;
		if(sctx1->GetNamespaceByIndex(i, &prefix, &uri))
		{
			result_file << "ns uri " << i << ":" << (std::string)prefix << "->" << (std::string)uri << endl;
		}
		else
		{
			result_file << "error on GetNamespaceByIndex(" << i << ")" << endl;
			break;
		}
	}
	result_file << "delete all namespaces" << endl;
	sctx1->DeleteAllNamespaces();
	sctx1->AddNamespace((xqp_string)"ulu1", (xqp_string)"http://www.flworfound.org/apitest/test_ns1");
	result_file << "now there are " << sctx1->GetNamespaceCount() << "namespaces" << endl;

	sctx1->SetDefaultElementAndTypeNamespace("http://www.flworfound.org/apitest/default_elem_type_ns1");
	result_file << "1my default elem & type ns " << (std::string)sctx1->GetDefaultElementAndTypeNamespace() << endl;
	sctx1->SetDefaultElementAndTypeNamespace("http://www.flworfound.org/apitest/default_elem_type_ns1");
	result_file << "2my default elem & type ns " << (std::string)sctx1->GetDefaultElementAndTypeNamespace() << endl;

	sctx1->SetDefaultFunctionNamespace("http://www.flworfound.org/apitest/default_function_ns1");
	result_file << "1my default function ns " << (std::string)sctx1->GetDefaultFunctionNamespace() << endl;
	sctx1->SetDefaultFunctionNamespace("http://www.flworfound.org/apitest/default_function_ns1");
	result_file << "2my default function ns " << (std::string)sctx1->GetDefaultFunctionNamespace() << endl;


	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "ulu1:var" << i;
		sctx1->AddExternalVariableType(oss1.str(), new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	}
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		vartype;
		ostringstream		oss1;
		oss1 << "ulu1:var" << i;
		vartype = sctx1->GetExternalVariableType(oss1.str());
		result_file << "variable " << i << " has type (" << vartype->get_kind() << "," << vartype->get_quantifier() << ")" << endl;
	}
	for(i=0;i<100;i+=2)
	{
		ostringstream		oss1;
		oss1 << "ulu1:var" << i;
		sctx1->DeleteExternalVariableType(oss1.str());
	}
	max = sctx1->GetExternalVariableCount();
	result_file << "vars remaining after delete " << max << endl;
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		vartype;
		ostringstream		oss1;
		oss1 << "ulu1:var" << i;
		vartype = sctx1->GetExternalVariableType(oss1.str());
		if(!vartype.isNull())
			result_file << "variable " << i << " has type (" << vartype->get_kind() << "," << vartype->get_quantifier() << ")" << endl;
		else
			result_file << "variable " << i << "does not exist" << endl;
	}

	for(i=0;i<max;i++)
	{
		xqp_string		var_name;
		type_ident_ref_t		vartype;
		if(sctx1->GetExternalVariableByIndex(i, &var_name, &vartype))
		{
			result_file << "variable " << i << " " << (std::string)var_name << " has type (" << vartype->get_kind() << "," << vartype->get_quantifier() << ")" << endl;
		}
		else
		{
			result_file << "error on GetExternalVariableByIndex " << i << endl;
			break;
		}
	}
	sctx1->DeleteAllVariables();
	sctx1->AddExternalVariableType("ulu1:var1", new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	result_file << "vars remaining " << sctx1->GetExternalVariableCount() << endl;

	sctx1->SetContextItemStaticType(new EmptyTypeIdentifier);
	type_ident_ref_t		context_item_type;
	context_item_type = sctx1->GetContextItemStaticType();
	result_file << "1my context item static type " << context_item_type->get_kind() << "," << context_item_type->get_quantifier() << ")" << endl;

	sctx1->SetContextItemStaticType(new EmptyTypeIdentifier);
	context_item_type = sctx1->GetContextItemStaticType();
	result_file << "2my context item static type " << context_item_type->get_kind() << "," << context_item_type->get_quantifier() << ")" << endl;


	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/coll" << i;
		sctx1->AddCollation(oss1.str(), "en");
	}
	for(i=0;i<100;i++)
	{
		CollationInfo	*colinfo;
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/coll" << i;
		colinfo = sctx1->GetCollation(oss1.str());
		if(colinfo)
		{
			result_file << "collation " << i << " " << (std::string)colinfo->URI << " " << colinfo->coll_string << " " << colinfo->coll_strength << " " << (unsigned int)colinfo->coll << endl;
		}
	}
	for(i=0;i<100;i+=2)
	{
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/coll" << i;
		sctx1->DeleteCollation(oss1.str());
	}
	max = sctx1->GetCollationCount();
	result_file << "remaining collations " << max << endl;
	for(i=0;i<100;i++)
	{
		CollationInfo	*colinfo;
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/coll" << i;
		colinfo = sctx1->GetCollation(oss1.str());
		if(colinfo)
		{
			result_file << "collation " << i << " " << (std::string)colinfo->URI << " " << colinfo->coll_string << " " << colinfo->coll_strength << " " << (unsigned int)colinfo->coll << endl;
		}
	}
	for(i=0;i<max;i++)
	{
		CollationInfo	*colinfo;
		colinfo = sctx1->GetCollationInfoByIndex(i);
		if(colinfo)
		{
			result_file << "collation " << i << " " << (std::string)colinfo->URI << " " << colinfo->coll_string << " " << colinfo->coll_strength << " " << (unsigned int)colinfo->coll << endl;
		}
	}
	sctx1->DeleteAllCollations();
	sctx1->AddCollation((xqp_string)"http://www.flworfound.org/apitest/coll1", "en");
	result_file << "remaining collations " << sctx1->GetCollationCount() << endl;

	sctx1->SetDefaultCollation((xqp_string)"http://www.flworfound.org/apitest/coll1");
	result_file << "my default collation " << (std::string)sctx1->GetDefaultCollation() << endl;

	sctx1->SetConstructionMode(StaticQueryContext::cons_strip);
	result_file << "1my construction mode " << sctx1->GetConstructionMode() << endl;
	sctx1->SetConstructionMode(StaticQueryContext::cons_preserve);
	result_file << "2my construction mode " << sctx1->GetConstructionMode() << endl;

	sctx1->SetOrderingMode(StaticQueryContext::ordered);
	result_file << "1my ordering mode " << sctx1->GetOrderingMode() << endl;
	sctx1->SetOrderingMode(StaticQueryContext::unordered);
	result_file << "2my ordering mode " << sctx1->GetOrderingMode() << endl;

	sctx1->SetDefaultOrderForEmptySequences(StaticQueryContext::empty_greatest);
	result_file << "1my DefaultOrderForEmptySequences" << sctx1->GetDefaultOrderForEmptySequences() << endl;
	sctx1->SetDefaultOrderForEmptySequences(StaticQueryContext::empty_least);
	result_file << "2my DefaultOrderForEmptySequences" << sctx1->GetDefaultOrderForEmptySequences() << endl;

	sctx1->SetBoundarySpacePolicy(StaticQueryContext::preserve_space);
	result_file << "1my BoundarySpacePolicy" << sctx1->GetBoundarySpacePolicy() << endl;
	sctx1->SetBoundarySpacePolicy(StaticQueryContext::strip_space);
	result_file << "2my BoundarySpacePolicy" << sctx1->GetBoundarySpacePolicy() << endl;

	StaticQueryContext::preserve_mode_t preserve_mode;
	StaticQueryContext::inherit_mode_t inherit_mode;
	sctx1->SetCopyNamespacesMode(StaticQueryContext::preserve_ns, StaticQueryContext::inherit_ns);
	sctx1->GetCopyNamespacesMode(&preserve_mode, &inherit_mode);
	result_file << "1my CopyNamespacesMode" << preserve_mode << "," << inherit_mode << endl;
	sctx1->SetCopyNamespacesMode(StaticQueryContext::no_preserve_ns, StaticQueryContext::no_inherit_ns);
	sctx1->GetCopyNamespacesMode(&preserve_mode, &inherit_mode);
	result_file << "2my CopyNamespacesMode" << preserve_mode << "," << inherit_mode << endl;

	sctx1->SetBaseURI("http://www.flworfound.orj");
	result_file << "1my base URI " << (std::string)sctx1->GetBaseURI() << endl;
	sctx1->SetBaseURI("http://www.flworfound.org");
	result_file << "2my base URI " << (std::string)sctx1->GetBaseURI() << endl;


	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "ulu1:doc" << i;
		sctx1->AddDocumentType(oss1.str(), new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	}
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		doctype;
		ostringstream		oss1;
		oss1 << "ulu1:doc" << i;
		doctype = sctx1->GetDocumentType(oss1.str());
		result_file << "doc " << i << " has type (" << doctype->get_kind() << "," << doctype->get_quantifier() << ")" << endl;
	}
	for(i=0;i<100;i+=2)
	{
		ostringstream		oss1;
		oss1 << "ulu1:doc" << i;
		sctx1->DeleteDocumentType(oss1.str());
	}
	max = sctx1->GetDocumentTypeCount();
	result_file << "docs remaining after delete " << max << endl;
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		doctype;
		ostringstream		oss1;
		oss1 << "ulu1:doc" << i;
		doctype = sctx1->GetDocumentType(oss1.str());
		if(!doctype.isNull())
			result_file << "doc " << i << " has type (" << doctype->get_kind() << "," << doctype->get_quantifier() << ")" << endl;
	}

	for(i=0;i<max;i++)
	{
		xqp_string		doc_name;
		type_ident_ref_t		doctype;
		if(sctx1->GetDocumentByIndex(i, &doc_name, &doctype))
		{
			result_file << "doc " << i << " " << (std::string)doc_name << " has type (" << doctype->get_kind() << "," << doctype->get_quantifier() << ")" << endl;
		}
		else
		{
			result_file << "error on GetDocumentByIndex " << i << endl;
			break;
		}
	}
	sctx1->DeleteAllDocumentTypes();
	sctx1->AddDocumentType("ulu1:doc1", new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	result_file << "docs remaining " << sctx1->GetDocumentTypeCount() << endl;



	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "ulu1:colec" << i;
		sctx1->AddCollectionType(oss1.str(), new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	}
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		colectype;
		ostringstream		oss1;
		oss1 << "ulu1:colec" << i;
		colectype = sctx1->GetCollectionType(oss1.str());
		result_file << "colec " << i << " has type (" << colectype->get_kind() << "," << colectype->get_quantifier() << ")" << endl;
	}
	for(i=0;i<100;i+=2)
	{
		ostringstream		oss1;
		oss1 << "ulu1:colec" << i;
		sctx1->DeleteCollectionType(oss1.str());
	}
	max = sctx1->GetCollectionTypeCount();
	result_file << "colecs remaining after delete " << max << endl;
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		colectype;
		ostringstream		oss1;
		oss1 << "ulu1:colec" << i;
		colectype = sctx1->GetCollectionType(oss1.str());
		if(!colectype.isNull())
			result_file << "colec " << i << " has type (" << colectype->get_kind() << "," << colectype->get_quantifier() << ")" << endl;
	}

	for(i=0;i<max;i++)
	{
		xqp_string		colec_name;
		type_ident_ref_t		colectype;
		if(sctx1->GetCollectionTypeByIndex(i, &colec_name, &colectype))
		{
			result_file << "colec " << i << " " << (std::string)colec_name << " has type (" << colectype->get_kind() << "," << colectype->get_quantifier() << ")" << endl;
		}
		else
		{
			result_file << "error on GetCollectionByIndex " << i << endl;
			break;
		}
	}
	sctx1->DeleteAllCollectionTypes();
	sctx1->AddCollectionType("ulu1:colec1", new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	result_file << "colecs remaining " << sctx1->GetCollectionTypeCount() << endl;

	type_ident_ref_t		def_colectype;
	sctx1->SetDefaultCollectionType(new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	def_colectype = sctx1->GetDefaultCollectionType();
	result_file << "1my def colec (" << def_colectype->get_kind() << "," << def_colectype->get_quantifier() << ")" << endl;
	sctx1->SetDefaultCollectionType(new EmptyTypeIdentifier());
	def_colectype = sctx1->GetDefaultCollectionType();
	result_file << "2my def colec (" << def_colectype->get_kind() << "," << def_colectype->get_quantifier() << ")" << endl;

	sctx1 = NULL;//free now the static context

	zorba_factory.uninitThread();

	//compare the results with expected result
	oss2 << "expected_";
	oss2 << result_file_name;
	assert(verify_expected_result(make_absolute_file_name(result_file_name, __FILE__),
																make_absolute_file_name(oss2.str().c_str(), __FILE__)));
	return 0;

DisplayErrorsAndExit:
	cerr << endl << "Display all error list now:" << endl;

	//DisplayErrorListForCurrentThread();

	zorba_factory.uninitThread();

	assert(false);
	return -1; 
}

//for CTEST
int sctx_test(int argc, char* argv[])
{
  ZorbaEngine& engine = ZorbaEngine::getInstance();
	test_api_static_context("sctx_test.txt");
	engine.shutdown();
	return 0;
}
