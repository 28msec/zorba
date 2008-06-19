/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/errors.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/positional_options.hpp>

#include  "zorbaerrors/errors.h"
#include  "store/naive/simple_store.h"
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
  std::vector<long> deweyParent;

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
    ("compare,r",
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

    zorba::simplestore::OrdPath path;
    path.compress(dewey1);

    std::cout << "ordpath = " << path.show() << std::endl;
  }

  if (varMap.count("insert") != 0)
  {
    parseDeweyString(deweyStrVector[0], dewey1);
    parseDeweyString(deweyStrVector[1], dewey2);

    zorba::simplestore::OrdPath parent;
    zorba::simplestore::OrdPath path1;
    zorba::simplestore::OrdPath path2;
    zorba::simplestore::OrdPath path;

    try
    {
      ulong i = dewey1.size() - 2;
      while (i > 0 && dewey1[i] % 2 == 0)
        i--;

      for (ulong j = 0; j <= i; j++)
        deweyParent.push_back(dewey1[j]);

      parent.compress(deweyParent);
      path1.compress(dewey1);
      path2.compress(dewey2);

      if (verbose)
      {
        std::cout << "ordpath parent = " << parent.show() << std::endl;
        std::cout << "ordpath1 = " << path1.show() << std::endl;
        std::cout << "ordpath2 = " << path2.show() << std::endl;
      }

      zorba::simplestore::OrdPath::insertInto(parent, path1, path2, path);

      std::cout << "ordpath = " << path.show() << std::endl;
    }
    catch (zorba::error::ZorbaError& e)
    {
      std::cout << e.theDescription << std::endl;
      return 1;
    }
  }

  if (varMap.count("compare") != 0)
  {
    parseDeweyString(deweyStrVector[0], dewey1);
    parseDeweyString(deweyStrVector[1], dewey2);

    zorba::simplestore::OrdPath path1;
    zorba::simplestore::OrdPath path2;

    path1.compress(dewey1);
    path2.compress(dewey2);

    if (verbose)
    {
      std::cout << "ordpath1 = " << path1.show() << std::endl;
      std::cout << "ordpath2 = " << path2.show() << std::endl;
    }

    zorba::simplestore::OrdPath::RelativePosition pos;
    pos = path1.getRelativePosition(path2);
    switch (pos)
    {
    case zorba::simplestore::OrdPath::SELF:
      std::cout << "SELF" << std::endl; break;
    case zorba::simplestore::OrdPath::DESCENDANT:
      std::cout << "DESCENDANT" << std::endl; break;
    case zorba::simplestore::OrdPath::ANCESTOR:
      std::cout << "ANCESTOR" << std::endl; break;
    case zorba::simplestore::OrdPath::FOLLOWING:
      std::cout << "FOLLOWING" << std::endl; break;
    case zorba::simplestore::OrdPath::PRECEDING:
      std::cout << "PRECEDING" << std::endl; break;
    }
  }

  return 0;
}
