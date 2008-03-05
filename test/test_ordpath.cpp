

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/errors.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/positional_options.hpp>

#include <zorba/errors.h>
#include <zorba/xqp_exception.h>
#include  "store/naive/ordpath.h"


bool verbose = false;


void parseDeweyString(const std::string& deweyStr, std::vector<long>& dewey)
{
  const char* p1 = deweyStr.c_str();

  while (*p1 != '\0')
  {
    if (!isdigit(*p1) && *p1 != '-' && *p1 != '+')
    {
      p1++;
      continue;
    }

    if (*p1 == '-' && !isdigit(*(p1+1)))
    {
      p1++;
      continue;
    }

    long comp = atoi(p1);
    dewey.push_back(comp);

    if (*p1 == '-')
      p1++;

    while (isdigit(*p1))
      p1++;
  }

  if (verbose)
  {
    std::cout << "dewey = ";
    for (ulong i = 0; i < dewey.size(); i++)
      std::cout << dewey[i] << " ";
    std::cout << std::endl; 
  }
}


void compressDewey(std::vector<long>& dewey, zorba::OrdPath& path)
{
  for (ulong i = 0; i < dewey.size(); i++)
    path.appendComp(dewey[i]);
}


int main(int argc, char * argv[])
{
  std::vector<std::string> deweyStrVector;
  std::string deweyStr;
  std::vector<long> dewey1;
  std::vector<long> dewey2;

  boost::program_options::options_description options("Options");
  options.add_options()
    ("verbose,v", ""
    )
    ("compress,c",
     boost::program_options::value<std::string>(&deweyStr),
     "provide dewey id as string of numbers separated by spaces"
    )
    ("insert,i",
     boost::program_options::value<std::vector<std::string> >(&deweyStrVector)->multitoken(),
     "provide 2 dewey ids as strings of numbers separated by spaces"
    )
    ;

  boost::program_options::variables_map varMap;

  // parse the command line options
  store(boost::program_options::command_line_parser(argc, argv).
        options(options).run(), varMap);

  notify(varMap);

  if (varMap.count("verbose") != 0)
    verbose = true;

  if (varMap.count("compress") != 0)
  {
    parseDeweyString(deweyStr, dewey1);

    zorba::OrdPath path;
    compressDewey(dewey1, path);

    std::cout << "ordpath = " << path.show() << std::endl;
  }

  if (varMap.count("insert") != 0)
  {
    parseDeweyString(deweyStrVector[0], dewey1);
    parseDeweyString(deweyStrVector[1], dewey2);

    zorba::OrdPath path1;
    zorba::OrdPath path2;
    zorba::OrdPath path;

    try
    {
      compressDewey(dewey1, path1);
      compressDewey(dewey2, path2);

      if (verbose)
      {
        std::cout << "ordpath1 = " << path1.show() << std::endl;
        std::cout << "ordpath2 = " << path2.show() << std::endl;
      }

      zorba::OrdPath::insert(path1, path2, path);

      std::cout << "ordpath = " << path.show() << std::endl;
    }
    catch (zorba::ZorbaException& e)
    {
      std::cout << e << std::endl;
    }
  }

  return 0;
}
