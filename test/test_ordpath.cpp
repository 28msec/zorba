

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

    zorba::store::OrdPath path;
    path.compress(dewey1);

    std::cout << "ordpath = " << path.show() << std::endl;
  }

  if (varMap.count("insert") != 0)
  {
    parseDeweyString(deweyStrVector[0], dewey1);
    parseDeweyString(deweyStrVector[1], dewey2);

    zorba::store::OrdPath path1;
    zorba::store::OrdPath path2;
    zorba::store::OrdPath path;

    try
    {
      path1.compress(dewey1);
      path2.compress(dewey2);

      if (verbose)
      {
        std::cout << "ordpath1 = " << path1.show() << std::endl;
        std::cout << "ordpath2 = " << path2.show() << std::endl;
      }

      zorba::store::OrdPath::insertInto(path1, path2, path);

      std::cout << "ordpath = " << path.show() << std::endl;
    }
    catch (zorba::ZorbaException& e)
    {
      std::cout << e << std::endl;
    }
  }

  return 0;
}
