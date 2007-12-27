
#include "system/zorba_engine_easy.h"
#include "api/external/xquery_easy.h"
#include "system/zorba_engine.h"
#include <fstream>
#include <string>

namespace xqp{

XQuerySimple_t XQuerySimpleFactory::createQuery(const char* aQueryString,xqp_string	xquery_source_uri)
{
	if(!aQueryString || !aQueryString[0])
		return NULL;

	return new Zorba_XQuerySimple(aQueryString, xquery_source_uri);
}

XQuerySimple_t XQuerySimpleFactory::createQueryFromFile(const char* xquery_file)
{
	std::fstream		xqf(xquery_file);
	if(!xqf.is_open())
		return NULL;

	std::string query_text = "";
	std::string	temp;

  // warning: this method of reading a file might trim the 
  // whitespace at the end of lines
  while (getline(xqf, temp))
  {
    if (query_text != "")
      query_text += "\n";
    
    query_text += temp;
  }

	return new Zorba_XQuerySimple(query_text.c_str(), xquery_file);

}


static ZorbaEngine_SingleThread*		g_single_thread_engine = NULL;

ZorbaEngine_SingleThread::ZorbaEngine_SingleThread()
{
	ZorbaEngine& the_real_engine = ZorbaEngine::getInstance();
	the_real_engine.initThread();
}


ZorbaEngine_SingleThread::~ZorbaEngine_SingleThread()
{
	ZorbaEngine& the_real_engine = ZorbaEngine::getInstance();
	the_real_engine.uninitThread();
	the_real_engine.shutdown();
	g_single_thread_engine = NULL;
}


ZorbaEngine_SingleThread_t	ZorbaEngine_SingleThread::getInstance()
{
	if(!g_single_thread_engine)
		g_single_thread_engine = new ZorbaEngine_SingleThread();
	return g_single_thread_engine;
}

}//end namespace xqp
