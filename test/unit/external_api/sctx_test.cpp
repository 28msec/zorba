
#include "zorba/zorba_api.h"
#include <fstream>
#include <assert.h>

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
using namespace zorba;

//#include "../error_display.h"

using namespace std;
using namespace zorba;

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
	ofstream		result_file(result_file_name);
	unsigned int		i;
	unsigned int	max;
	ostringstream		oss2;

	///now start the zorba engine
	ZorbaEngine_t zorba_factory = ZorbaEngine::getInstance();

	///thread specific
	zorba_factory->initThread();

	//do the test
	ZorbaAlertsManager_t		errmanager = zorba_factory->getAlertsManagerForCurrentThread();

	///testing the static context!
	StaticQueryContext_t		sctx1;

	for(i=0;i<100;i++)
	{
		sctx1 = zorba_factory->createStaticContext();
	}

	sctx1->setXPath1_0CompatibMode(StaticContextConsts::xpath2_0);
	StaticContextConsts::xpath1_0compatib_mode_t		xp_compatib_mode;
	xp_compatib_mode = sctx1->getXPath1_0CompatibMode();
	result_file << "GetXPath1_0CompatibMode " << xp_compatib_mode << endl;

	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		ostringstream		oss2;
		oss1 << "ulu" << i;
		oss2 << "http://www.flworfound.org/apitest/test_ns" << i;
		sctx1->addNamespace(oss1.str(), oss2.str());
	}
	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "ulu" << i;
		xqp_string		ns_uri = sctx1->getNamespaceURIByPrefix(oss1.str());
		result_file << "ns uri " << i << ":" << ns_uri << endl;
	}
	result_file << "delete some namespaces..." << endl;
	for(i=0;i<100;i+=2)
	{
		ostringstream		oss1;
		oss1 << "ulu" << i;
		sctx1->deleteNamespace(oss1.str());
	}
	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "ulu" << i;
		xqp_string		ns_uri = sctx1->getNamespaceURIByPrefix(oss1.str());
		result_file << "ns uri " << i << ":" << ns_uri << endl;
	}
	max = sctx1->getNamespaceCount();
	result_file << "there are " << max << " namespaces:" << endl;
	for(i=0;i<max;i++)
	{
		xqp_string	prefix;
		xqp_string	uri;
		if(sctx1->getNamespaceByIndex(i, &prefix, &uri))
		{
			result_file << "ns uri " << i << ":" << prefix << "->" << uri << endl;
		}
		else
		{
			result_file << "error on getNamespaceByIndex(" << i << ")" << endl;
			break;
		}
	}
	result_file << "delete all namespaces" << endl;
	sctx1->deleteAllNamespaces();
	sctx1->addNamespace((xqp_string)"ulu1", (xqp_string)"http://www.flworfound.org/apitest/test_ns1");
	result_file << "now there are " << sctx1->getNamespaceCount() << "namespaces" << endl;

	sctx1->setDefaultElementAndTypeNamespace("http://www.flworfound.org/apitest/default_elem_type_ns1");
	result_file << "1my default elem & type ns " << sctx1->getDefaultElementAndTypeNamespace() << endl;
	sctx1->setDefaultElementAndTypeNamespace("http://www.flworfound.org/apitest/default_elem_type_ns1");
	result_file << "2my default elem & type ns " << sctx1->getDefaultElementAndTypeNamespace() << endl;

	sctx1->setDefaultFunctionNamespace("http://www.flworfound.org/apitest/default_function_ns1");
	result_file << "1my default function ns " << sctx1->getDefaultFunctionNamespace() << endl;
	sctx1->setDefaultFunctionNamespace("http://www.flworfound.org/apitest/default_function_ns1");
	result_file << "2my default function ns " << sctx1->getDefaultFunctionNamespace() << endl;


	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "ulu1:var" << i;
		sctx1->addExternalVariableType(oss1.str(), new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	}
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		vartype;
		ostringstream		oss1;
		oss1 << "ulu1:var" << i;
		vartype = sctx1->getExternalVariableType(oss1.str());
		result_file << "variable " << i << " has type (" << vartype->get_kind() << "," << vartype->get_quantifier() << ")" << endl;
	}
	for(i=0;i<100;i+=2)
	{
		ostringstream		oss1;
		oss1 << "ulu1:var" << i;
		sctx1->deleteExternalVariableType(oss1.str());
	}
	max = sctx1->getExternalVariableCount();
	result_file << "vars remaining after delete " << max << endl;
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		vartype;
		ostringstream		oss1;
		oss1 << "ulu1:var" << i;
		vartype = sctx1->getExternalVariableType(oss1.str());
		if(vartype != NULL)
			result_file << "variable " << i << " has type (" << vartype->get_kind() << "," << vartype->get_quantifier() << ")" << endl;
		else
			result_file << "variable " << i << "does not exist" << endl;
	}

	for(i=0;i<max;i++)
	{
		xqp_string		var_name;
		type_ident_ref_t		vartype;
		if(sctx1->getExternalVariableByIndex(i, &var_name, &vartype))
		{
			result_file << "variable " << i << " " << var_name << " has type (" << vartype->get_kind() << "," << vartype->get_quantifier() << ")" << endl;
		}
		else
		{
			result_file << "error on GetExternalVariableByIndex " << i << endl;
			break;
		}
	}
	sctx1->deleteAllVariables();
	sctx1->addExternalVariableType("ulu1:var1", new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	result_file << "vars remaining " << sctx1->getExternalVariableCount() << endl;

	sctx1->setContextItemStaticType(new EmptyTypeIdentifier);
	type_ident_ref_t		context_item_type;
	context_item_type = sctx1->getContextItemStaticType();
	result_file << "1my context item static type " << context_item_type->get_kind() << "," << context_item_type->get_quantifier() << ")" << endl;

	sctx1->setContextItemStaticType(new EmptyTypeIdentifier);
	context_item_type = sctx1->getContextItemStaticType();
	result_file << "2my context item static type " << context_item_type->get_kind() << "," << context_item_type->get_quantifier() << ")" << endl;


	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/coll" << i;
		sctx1->addCollation(oss1.str(), "en");
	}
	for(i=0;i<100;i++)
	{
		CollationInfo	*colinfo;
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/coll" << i;
		colinfo = sctx1->getCollation(oss1.str());
		if(colinfo)
		{
			result_file << "collation " << i << " " << colinfo->URI << " " << colinfo->coll_string << " " << colinfo->coll_strength << " " << (uint32_t)colinfo->coll << endl;
		}
	}
	for(i=0;i<100;i+=2)
	{
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/coll" << i;
		sctx1->deleteCollation(oss1.str());
	}
	max = sctx1->getCollationCount();
	result_file << "remaining collations " << max << endl;
	for(i=0;i<100;i++)
	{
		CollationInfo	*colinfo;
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/coll" << i;
		colinfo = sctx1->getCollation(oss1.str());
		if(colinfo)
		{
			result_file << "collation " << i << " " << colinfo->URI << " " << colinfo->coll_string << " " << colinfo->coll_strength << " " << (uint32_t)colinfo->coll << endl;
		}
	}
	for(i=0;i<max;i++)
	{
		CollationInfo	*colinfo;
		colinfo = sctx1->getCollationInfoByIndex(i);
		if(colinfo)
		{
			result_file << "collation " << i << " " << colinfo->URI << " " << colinfo->coll_string << " " << colinfo->coll_strength << " " << (uint32_t)colinfo->coll << endl;
		}
	}
	sctx1->deleteAllCollations();
	sctx1->addCollation((xqp_string)"http://www.flworfound.org/apitest/coll1", "en");
	result_file << "remaining collations " << sctx1->getCollationCount() << endl;

	sctx1->setDefaultCollation((xqp_string)"http://www.flworfound.org/apitest/coll1");
	result_file << "my default collation " << sctx1->getDefaultCollation() << endl;

	sctx1->setConstructionMode(StaticContextConsts::cons_strip);
	result_file << "1my construction mode " << sctx1->getConstructionMode() << endl;
	sctx1->setConstructionMode(StaticContextConsts::cons_preserve);
	result_file << "2my construction mode " << sctx1->getConstructionMode() << endl;

	sctx1->setOrderingMode(StaticContextConsts::ordered);
	result_file << "1my ordering mode " << sctx1->getOrderingMode() << endl;
	sctx1->setOrderingMode(StaticContextConsts::unordered);
	result_file << "2my ordering mode " << sctx1->getOrderingMode() << endl;

	sctx1->setDefaultOrderForEmptySequences(StaticContextConsts::empty_greatest);
	result_file << "1my DefaultOrderForEmptySequences" << sctx1->getDefaultOrderForEmptySequences() << endl;
	sctx1->setDefaultOrderForEmptySequences(StaticContextConsts::empty_least);
	result_file << "2my DefaultOrderForEmptySequences" << sctx1->getDefaultOrderForEmptySequences() << endl;

	sctx1->setBoundarySpacePolicy(StaticContextConsts::preserve_space);
	result_file << "1my BoundarySpacePolicy" << sctx1->getBoundarySpacePolicy() << endl;
	sctx1->setBoundarySpacePolicy(StaticContextConsts::strip_space);
	result_file << "2my BoundarySpacePolicy" << sctx1->getBoundarySpacePolicy() << endl;

	StaticContextConsts::preserve_mode_t preserve_mode;
	StaticContextConsts::inherit_mode_t inherit_mode;
	sctx1->setCopyNamespacesMode(StaticContextConsts::preserve_ns, StaticContextConsts::inherit_ns);
	sctx1->getCopyNamespacesMode(&preserve_mode, &inherit_mode);
	result_file << "1my CopyNamespacesMode" << preserve_mode << "," << inherit_mode << endl;
	sctx1->setCopyNamespacesMode(StaticContextConsts::no_preserve_ns, StaticContextConsts::no_inherit_ns);
	sctx1->getCopyNamespacesMode(&preserve_mode, &inherit_mode);
	result_file << "2my CopyNamespacesMode" << preserve_mode << "," << inherit_mode << endl;

	sctx1->setBaseURI("http://www.flworfound.orj");
	result_file << "1my base URI " << sctx1->getBaseURI() << endl;
	sctx1->setBaseURI("http://www.flworfound.org");
	result_file << "2my base URI " << sctx1->getBaseURI() << endl;


	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/doc" << i;
		sctx1->addDocumentType(oss1.str(), new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	}
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		doctype;
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/doc" << i;
		doctype = sctx1->getDocumentType(oss1.str());
		result_file << "doc " << i << " has type (" << doctype->get_kind() << "," << doctype->get_quantifier() << ")" << endl;
	}
	for(i=0;i<100;i+=2)
	{
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/doc" << i;
		sctx1->deleteDocumentType(oss1.str());
	}
	max = sctx1->getDocumentTypeCount();
	result_file << "docs remaining after delete " << max << endl;
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		doctype;
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/doc" << i;
		doctype = sctx1->getDocumentType(oss1.str());
		if(doctype != NULL)
			result_file << "doc " << i << " has type (" << doctype->get_kind() << "," << doctype->get_quantifier() << ")" << endl;
	}

	for(i=0;i<max;i++)
	{
		xqp_string		doc_name;
		type_ident_ref_t		doctype;
		if(sctx1->getDocumentByIndex(i, &doc_name, &doctype))
		{
			result_file << "doc " << i << " " << doc_name << " has type (" << doctype->get_kind() << "," << doctype->get_quantifier() << ")" << endl;
		}
		else
		{
			result_file << "error on GetDocumentByIndex " << i << endl;
			break;
		}
	}
	sctx1->deleteAllDocumentTypes();
	sctx1->addDocumentType("http://www.flworfound.org/apitest/doc1", new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	result_file << "docs remaining " << sctx1->getDocumentTypeCount() << endl;



	for(i=0;i<100;i++)
	{
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/collection" << i;
		sctx1->addCollectionType(oss1.str(), new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	}
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		colectype;
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/collection" << i;
		colectype = sctx1->getCollectionType(oss1.str());
		result_file << "colec " << i << " has type (" << colectype->get_kind() << "," << colectype->get_quantifier() << ")" << endl;
	}
	for(i=0;i<100;i+=2)
	{
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/collection" << i;
		sctx1->deleteCollectionType(oss1.str());
	}
	max = sctx1->getCollectionTypeCount();
	result_file << "colecs remaining after delete " << max << endl;
	for(i=0;i<100;i++)
	{
		type_ident_ref_t		colectype;
		ostringstream		oss1;
		oss1 << "http://www.flworfound.org/apitest/collection" << i;
		colectype = sctx1->getCollectionType(oss1.str());
		if(colectype != NULL)
			result_file << "colec " << i << " has type (" << colectype->get_kind() << "," << colectype->get_quantifier() << ")" << endl;
	}

	for(i=0;i<max;i++)
	{
		xqp_string		colec_name;
		type_ident_ref_t		colectype;
		if(sctx1->getCollectionTypeByIndex(i, &colec_name, &colectype))
		{
			result_file << "colec " << i << " " << colec_name << " has type (" << colectype->get_kind() << "," << colectype->get_quantifier() << ")" << endl;
		}
		else
		{
			result_file << "error on GetCollectionByIndex " << i << endl;
			break;
		}
	}
	sctx1->deleteAllCollectionTypes();
	sctx1->addCollectionType("http://www.flworfound.org/apitest/collection1", new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	result_file << "colecs remaining " << sctx1->getCollectionTypeCount() << endl;

	type_ident_ref_t		def_colectype;
	sctx1->setDefaultCollectionType(new ItemTypeIdentifier(TypeIdentifier::QUANT_ONE));
	def_colectype = sctx1->getDefaultCollectionType();
	result_file << "1my def colec (" << def_colectype->get_kind() << "," << def_colectype->get_quantifier() << ")" << endl;
	sctx1->setDefaultCollectionType(new EmptyTypeIdentifier());
	def_colectype = sctx1->getDefaultCollectionType();
	result_file << "2my def colec (" << def_colectype->get_kind() << "," << def_colectype->get_quantifier() << ")" << endl;

	sctx1 = NULL;//free now the static context

	zorba_factory->uninitThread();
	zorba_factory->shutdown();

	//compare the results with expected result
	oss2 << "expected_";
	oss2 << result_file_name;
	assert(verify_expected_result(result_file_name,
																make_absolute_file_name(oss2.str().c_str(), __FILE__)));
	return 0;

DisplayErrorsAndExit:
	result_file << endl << "Display all error list now:" << endl;

	errmanager->dumpAlerts(result_file);

	zorba_factory->uninitThread();
	zorba_factory->shutdown();

	exit(1);
	return -1; 
}

//for CTEST
int sctx_test(int argc, char* argv[])
{
//  ZorbaEngine_t engine = ZorbaEngine::getInstance();
	test_api_static_context("sctx_test.txt");
//	engine.shutdown();
	return 0;
}
