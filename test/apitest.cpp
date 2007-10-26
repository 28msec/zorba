

////using the C++ API

#include "zorba_api.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/simple_store.h"

//for debug
#include "compiler/parser/xquery_driver.h"
#include "util/logging/loggermanager.hh"
#include "timer.h"
#include "api/serialization/serializer.h"

#include <fstream>

using namespace xqp;


#ifndef _WIN32_WCE
int main(int argc, char* argv[])
#else
int _tmain(int argc, _TCHAR* argv[])
#endif
{
	Timer timer;
	timer.start();

	xqp::LoggerManager::logmanager()->setLoggerConfig("#1#logging.log");

  bool useResultFile = false, inline_query = false;
  bool useSerializer = false;
  std::string resultFileName;
  std::ofstream* resultFile = NULL;
	std::string		query_text = "1+1";///the default query if no file or query is specified

///pick up all the runtime options
#ifdef UNICODE
#define TEST_ARGV_FLAG( str ) (_tcscmp(*argv, _T(str)) == 0)
#else
#define TEST_ARGV_FLAG( str ) (*argv == std::string (str))
#endif

		for (++argv; argv[0]; ++argv) 
		{
			const char *fname;
			
			if (TEST_ARGV_FLAG ("-p")) {
				g_trace_parsing = true;
			} else if (TEST_ARGV_FLAG ("-s")) {
				g_trace_scanning = true;
			} else if (TEST_ARGV_FLAG ("-r")) {
				useSerializer = true;			
			} else if (TEST_ARGV_FLAG ("-o")) {
				useResultFile = true;
        resultFileName = *++argv;
      } else if (TEST_ARGV_FLAG ("-e")) {
        inline_query = true;
			} else {
        fname = *argv;
#ifndef UNICODE
        if (inline_query) {
        //  fname = "zorba_query.tmp";
        //  ofstream qf (fname);
        //  qf << *argv;
 					query_text = *argv;
       }
#endif
#ifdef UNICODE
        if(! inline_query)
				{
					char	testfile[1024];
					WideCharToMultiByte(CP_ACP, 0, // or CP_UTF8
															*argv, -1, 
															testfile, sizeof(testfile)/sizeof(char),
															NULL, NULL);
					fname = testfile;
				}
#endif
				if(!inline_query)
				{
					///read the file
					std::ifstream	qfile(fname);
					//istringstream		iss;
					qfile >> query_text;
				}
			}
		}

	///now start the zorba engine

	BasicItemFactory basicItemFactory;
	SimpleStore simpleStore;
	ZorbaFactory	zorba_factory(&basicItemFactory, &simpleStore);
	
	///some workarounds until we have a store factory
	basicItemFactory.addReference();
	simpleStore.addReference();

	///thread specific

	zorba_factory.InitThread();



	XQuery_t		query;
	query = zorba_factory.createQuery(query_text.c_str());

	query->compile();

	XQueryResult		*result;

	result = query->execute();

	if(result)
	{
		if (useResultFile)
		{
			resultFile = new ofstream(resultFileName.c_str());
			*resultFile << "Iterator run:" << std::endl << std::endl;
		}

		Item_t		it;

	 	if (useSerializer)
		{
			// *resultFile << i_p->show() << endl;
			serializer* ser = new serializer();
			ser->serialize(result, *resultFile);
			*resultFile << endl;
		}
		else
		{
			while( true )
			{
				it = result->next();
				if(it == NULL)
					break;

        if (resultFile != NULL)
					*resultFile << it->show() <<	endl;
				else
					cout << it->show() << endl;
			}
		}

		delete result;
	}//if (result)


	//delete query;
//	zorba_factory.destroyQuery(query);

	zorba_factory.UninitThread();

	timer.end();

  if (resultFile != NULL)
  {
  //  *resultFile << std::endl;
  //  timer.print(*resultFile);
  }
  else
    timer.print(cout);

	delete resultFile;
}

