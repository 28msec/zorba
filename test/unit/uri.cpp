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
#include "zorbatypes/xqpstring.h"
#include "zorbatypes/URI.h"
#include "zorbaerrors/error_manager.h"
#include <zorba/zorba.h>
#include <zorba/store_manager.h>

struct URITestEntry
{
  zorba::xqpStringStore base;
  zorba::xqpStringStore uri;
  zorba::xqpStringStore text;
  zorba::xqpStringStore scheme;
  int                   port;
  zorba::xqpStringStore fragment;
  zorba::xqpStringStore host;
  zorba::xqpStringStore regbased_authority;
  zorba::xqpStringStore path;
  zorba::xqpStringStore userinfo;
  zorba::xqpStringStore query;
  zorba::xqpStringStore path_notation;
};

using namespace zorba;

int uri(int argc, char* argv[]) 
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba *lZorba = Zorba::getInstance(lStore);

  zorba::xqpString foo("/b");
  if (foo.endsWith("/.."))
    std::cout << foo << " ends with " << "/.." << std::endl;
  if (foo.endsWith("/\\.\\."))
    std::cout << foo << " ends with " << "/\\.\\." << std::endl;

  URITestEntry tests[] = 
  {
    {
      "",
      "http:///",
      "http:///",
      "http",
      0,
      "",
      "",
      "",
      "/",
      "",
      "",
      "/" // path notation
    },
    {
      "",
      "http://www.zorba-xquery.com/",
      "http://www.zorba-xquery.com/",
      "http",
      0,
      "",
      "www.zorba-xquery.com",
      "",
      "/",
      "",
      "",
      "com/zorba-xquery/www/" // path notation
    },
    {
      "",
      "http://www.zorba-xquery.com/?abc=true",
      "http://www.zorba-xquery.com/?abc=true",
      "http",
      0,
      "",
      "www.zorba-xquery.com",
      "",
      "/",
      "",
      "abc=true",
      "com/zorba-xquery/www/" // path notation
    },
    {
      "",
      "http://www.zorba-xquery.com:8080/?abc=true",
      "http://www.zorba-xquery.com:8080/?abc=true",
      "http",
      8080,
      "",
      "www.zorba-xquery.com",
      "",
      "/",
      "",
      "abc=true",
      "com/zorba-xquery/www/" // path notation
    },
    {
      "",
      "http://user@www.zorba-xquery.com:8080/?abc=true",
      "http://user@www.zorba-xquery.com:8080/?abc=true",
      "http",
      8080,
      "",
      "www.zorba-xquery.com",
      "",
      "/",
      "user",
      "abc=true",
      "com/zorba-xquery/www/" // path notation
    },
    {
      "",
      "http://user@www.zorba-xquery.com:8080/path1/path2?abc=true",
      "http://user@www.zorba-xquery.com:8080/path1/path2?abc=true",
      "http",
      8080,
      "",
      "www.zorba-xquery.com",
      "",
      "/path1/path2",
      "user",
      "abc=true",
      "com/zorba-xquery/www/path1/path2" // path notation
    },
    {
      "",
      "http://user@www.zorba-xquery.com:8080/path1/path2?abc=true&bcd=false#fragment",
      "http://user@www.zorba-xquery.com:8080/path1/path2?abc=true&bcd=false#fragment",
      "http",
      8080,
      "fragment",
      "www.zorba-xquery.com",
      "",
      "/path1/path2",
      "user",
      "abc=true&bcd=false",
      "com/zorba-xquery/www/path1/path2" // path notation
    },
    {
      "",
      "ftp://ftp.is.co.za/rfc/rfc1808.txt",
      "ftp://ftp.is.co.za/rfc/rfc1808.txt",
      "ftp",
      0,
      "",
      "ftp.is.co.za",
      "",
      "/rfc/rfc1808.txt",
      "",
      "",
      "za/co/is/ftp/rfc/rfc1808.txt" // path notation
    },
    {
      "",
      "http://thomas@[2001:6f8:9000:876:cccc:bbbb::]:123/test",
      "http://thomas@[2001:6f8:9000:876:cccc:bbbb::]:123/test",
      "http",
      123,
      "",
      "[2001:6f8:9000:876:cccc:bbbb::]",
      "",
      "/test",
      "thomas",
      "",
      "[2001:6f8:9000:876:cccc:bbbb::]/test" // path notation
    },
    // uri resolver tests
    {
      "http://a/b/c/d;p?q",
      "g",
      "http://a/b/c/g",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/g",
      "",
      "",
      "a/b/c/g" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "./g",
      "http://a/b/c/g",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/g",
      "",
      "",
      "a/b/c/g" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "g/",
      "http://a/b/c/g/",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/g/",
      "",
      "",
      "a/b/c/g/" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "/g",
      "http://a/g",
      "http",
      0,
      "",
      "a",
      "",
      "/g",
      "",
      "",
      "a/g" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "?y",
      "http://a/b/c/?y",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/",
      "",
      "y",
      "a/b/c/" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "g?y",
      "http://a/b/c/g?y",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/g",
      "",
      "y",
      "a/b/c/g" // path notation
    } //,
  //{
  //  "http://a/b/c/d;p?q",
  //  "#s",
  //  "http://a/b/c/d;p?q#s",
  //  "http",
  //  0,
  //  "s",
  //  "a",
  //  "",
  //  "/b/c/g",
  //  "",
  //  ""
  //}
    ,
    {
      "http://a/b/c/d;p?q",
      "g#s",
      "http://a/b/c/g#s",
      "http",
      0,
      "s",
      "a",
      "",
      "/b/c/g",
      "",
      "",
      "a/b/c/g" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "g?y#s",
      "http://a/b/c/g?y#s",
      "http",
      0,
      "s",
      "a",
      "",
      "/b/c/g",
      "",
      "y",
      "a/b/c/g" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      ";x",
      "http://a/b/c/;x",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/;x",
      "",
      "",
      "a/b/c/;x" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "g;x",
      "http://a/b/c/g;x",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/g;x",
      "",
      "",
      "a/b/c/g;x" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "g;x?y#s",
      "http://a/b/c/g;x?y#s",
      "http",
      0,
      "s",
      "a",
      "",
      "/b/c/g;x",
      "",
      "y",
      "a/b/c/g;x" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      ".",
      "http://a/b/c/",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/",
      "",
      "",
      "a/b/c/" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "./",
      "http://a/b/c/",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/",
      "",
      "",
      "a/b/c/" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "..",
      "http://a/b/",
      "http",
      0,
      "",
      "a",
      "",
      "/b/",
      "",
      "",
      "a/b/" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "../",
      "http://a/b/",
      "http",
      0,
      "",
      "a",
      "",
      "/b/",
      "",
      "",
      "a/b/" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "../g",
      "http://a/b/g",
      "http",
      0,
      "",
      "a",
      "",
      "/b/g",
      "",
      "",
      "a/b/g" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "../..",
      "http://a/",
      "http",
      0,
      "",
      "a",
      "",
      "/",
      "",
      "",
      "a/" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "../../",
      "http://a/",
      "http",
      0,
      "",
      "a",
      "",
      "/",
      "",
      "",
      "a/" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "../../g",
      "http://a/g",
      "http",
      0,
      "",
      "a",
      "",
      "/g",
      "",
      "",
      "a/g" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "g;x=1/./y",
      "http://a/b/c/g;x=1/y",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/g;x=1/y",
      "",
      "",
      "a/b/c/g;x=1/y" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "g;x=1/../y",
      "http://a/b/c/y",
      "http",
      0,
      "",
      "a",
      "",
      "/b/c/y",
      "",
      "",
      "a/b/c/y" // path notation
    },
    {
      "http://a/b/c/d;p?q",
      "g#s/../x",
      "http://a/b/c/g#s/../x",
      "http",
      0,
      "s/../x",
      "a",
      "",
      "/b/c/g",
      "",
      "",
      "a/b/c/g" // path notation
    },
    {
      "",
      "http://www.msb.de",
      "http://www.msb.de",
      "http",
      0,
      "",
      "www.msb.de",
      "",
      "",
      "",
      "",
      "de/msb/www" // path notation
    },
    {
      "http://www.msb.de/",
      "lib/helpers",
      "http://www.msb.de/lib/helpers",
      "http",
      0,
      "",
      "www.msb.de",
      "",
      "/lib/helpers",
      "",
      "",
      "de/msb/www/lib/helpers" // path notation
    },
    {
      "",
      "file:///d:/a/b/c",
      "file:///d:/a/b/c",
      "file",
      0,
      "",
      "",
      "",
      "/d:/a/b/c",
      "",
      "",
      "/d:/a/b/c" // path notation
    },
    {
      "",
      "file://localhost/d:/a/b/c",
      "file://localhost/d:/a/b/c",
      "file",
      0,
      "",
      "localhost",
      "",
      "/d:/a/b/c",
      "",
      "",
      "localhost/d:/a/b/c" // path notation
    },
    {
      "file://localhost",
      "/Ångström/b/c",
      "file://localhost/Ångström/b/c",
      "file",
      0,
      "",
      "localhost",
      "",
      "/Ångström/b/c",
      "",
      "",
      "localhost/Ångström/b/c" // path notation
    }
  }; // URITestEntry tests[]


  const unsigned int test_count = sizeof(tests) / sizeof(tests[0]);

  try 
  {
    for (unsigned int i = 0; i < test_count; ++i)
    {
      std::cout << "executing test number " << i << " with uri "
                << tests[i].uri.c_str() << std::endl;

      zorba::URI uri;
      zorba::URI relativized;
      zorba::URI base;

      if (tests[i].base.empty()) 
      {
        uri = zorba::URI(&tests[i].uri);
      }
      else
      {
        base = zorba::URI(&tests[i].base);
        uri = zorba::URI(base, &tests[i].uri);
        relativized = zorba::URI(uri, base);
      }

      if (!uri.toString()->byteEqual(&tests[i].text))  
      {
        std::cerr << "uri text " << uri.toString()->c_str() << " is not equal to "
                  << tests[i].text.c_str() << std::endl;
        return 2;
      }

      xqpStringStore_t scheme = uri.get_scheme();
      if (!scheme->byteEqual(&tests[i].scheme))
        return 3;

      if (uri.get_port() != tests[i].port) 
      {
        std::cerr << "port " << uri.get_port() << " is not equal to "
                  << tests[i].port << std::endl;
        return 4;
      }

      xqpStringStore_t frag;
      uri.get_fragment(frag);
      if (!frag->byteEqual(&tests[i].fragment)) 
      {
        std::cerr << "fragment " << frag->c_str() << " is not equal to "
                  << tests[i].fragment.c_str() << std::endl;
        return 5;
      }

      if (!uri.get_host()->byteEqual(&tests[i].host)) 
      {
        std::cerr << "host " << uri.get_host()->c_str() << " is not equal to "
                  << tests[i].host.c_str() << std::endl;
        return 6;
      }

      xqpStringStore_t auth;
      uri.get_reg_based_authority(auth);
      if (!auth->byteEqual(&tests[i].regbased_authority)) 
      {
        std::cerr << "regbased_authority " << auth->c_str()
                  << " is not equal to " 
                  << tests[i].regbased_authority.c_str() << std::endl;
        return 7;
      }

      xqpStringStore_t user;
      uri.get_user_info(user);
      if (! user->byteEqual(&tests[i].userinfo)) 
      {
        std::cerr << "userinfo " << user->c_str() << " is not equal to "
                  << tests[i].userinfo.c_str() << std::endl;
        return 8;
      }

      xqpStringStore_t path;
      uri.get_path(path);
      if (!path->byteEqual(&tests[i].path)) 
      {
        std::cerr << "path " << path->c_str() << " is not equal to "
                  << tests[i].path.c_str() << std::endl;
        return 9;
      }

      xqpStringStore_t query;
      uri.get_query(query);
      if (!query->byteEqual(&tests[i].query))
      {
        std::cerr << "query " << query->c_str() << " is not equal to "
                  << tests[i].query.c_str() << std::endl;
        return 10;
      }

      xqpStringStore_t base_path;
      base.get_path(base_path);

      if (!tests[i].base.empty() && path->positionOf(base_path, NULL) == 0) 
      {
        if (!relativized.toString()->byteEqual(&tests[i].uri)) 
        {
          std::cerr << "relativized uri " << relativized.toString()->c_str()
                    << " is not equal to relative " << tests[i].uri.c_str() 
                    << " which was relativized using base " << tests[i].base.c_str()
                    << std::endl;
          return 11;
        }
        else
        {
          std::cerr << "relativized uri " << relativized.toString()->c_str()
                    << std::endl;
        }
      }

      if (!uri.toPathNotation()->byteEqual(&tests[i].path_notation)) 
      {
        std::cerr << "path notation " << uri.toPathNotation()->c_str()
                  << " is not equal to " 
                  << tests[i].path_notation.c_str() << std::endl;
        return 12;
      }
      std::cout << "result: " << uri.toString()->c_str() << std::endl;
      std::cout << "path notation: " << uri.toPathNotation()->c_str() << std::endl;
      std::cout << "--------------------------------------------------" << std::endl;
    }
  }
  catch (zorba::error::ZorbaError & e)
  {
    std::cerr << e.theDescription << std::endl;
    return 11;
  }

  zorba::xqpString lToEncode("/a /b/c");
  zorba::xqpString lEncoded = lToEncode.encodeForUri("/",1);
  std::cout << "encoded " << lEncoded << std::endl;

  std::cout << "decoded " << lEncoded.decodeFromUri() << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;

}
