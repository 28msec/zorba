/**
 * 
 */
#include <iostream>

#include <zorba/zorba.h>

using namespace zorba;

bool
serialization_example_1(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
serialization_example_2(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    lQuery->serialize(std::cout);
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
serialization_example_3(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    XQuery::SerializerOptions lSerOptions;
    lSerOptions.ser_method = XQuery::SerializerOptions::serialization_method::HTML;

    lQuery->serialize(std::cout, lSerOptions);
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
serialization_example_4(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    XQuery::SerializerOptions lSerOptions;
    lSerOptions.indent = XQuery::SerializerOptions::indent::YES;

    lQuery->serialize(std::cout, lSerOptions);
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
serialization_example_5(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    XQuery::SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = XQuery::SerializerOptions::omit_xml_declaration::YES;

    lQuery->serialize(std::cout, lSerOptions);
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
serialization_example_6(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    XQuery::SerializerOptions lSerOptions;
    lSerOptions.byte_order_mark = XQuery::SerializerOptions::byte_order_mark::YES;

    lQuery->serialize(std::cout, lSerOptions);
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
serialization_example_7(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

  ResultIterator_t lIterator = lQuery->iterator();

  try {
    lIterator->open();

    Item lItem;
    while ( lIterator->next(lItem) ) {
      lItem.serialize(std::cout);
    }

    lIterator->close();

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    lIterator->close();
    return false;
  }
	return true;
}

int 
serialization(int argc, char* argv[])
{
  Zorba* lZorba = Zorba::getInstance();

  std::cout << "executing serialization example 1" << std::endl;
	assert(serialization_example_1(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing serialization example 2" << std::endl;
	assert(serialization_example_2(lZorba)); 
  std::cout << std::endl;

//std::cout << "executing serialization example 3" << std::endl;
//assert(serialization_example_3(lZorba)); 
//std::cout << std::endl;

  std::cout << "executing serialization example 4" << std::endl;
	assert(serialization_example_4(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing serialization example 5" << std::endl;
	assert(serialization_example_5(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing serialization example 6" << std::endl;
	assert(serialization_example_6(lZorba)); 
  std::cout << std::endl;

  std::cout << "executing serialization example 7" << std::endl;
	assert(serialization_example_7(lZorba)); 
  std::cout << std::endl;

  return 0;
}
