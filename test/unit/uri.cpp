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
  zorba::xqpString base;
  zorba::xqpString uri;
  zorba::xqpString text;
  zorba::xqpString scheme;
  int              port;
  zorba::xqpString fragment;
  zorba::xqpString host;
  zorba::xqpString regbased_authority;
  zorba::xqpString path;
  zorba::xqpString userinfo;
  zorba::xqpString query;
  zorba::xqpString path_notation;
};

using namespace zorba;

int uri(int argc, char* argv[]) 
{
  simplestore::SimpleStore* lStore = zorba::StoreManager::getStore();
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
      "/a/b/c",
      "file://localhost/a/b/c",
      "file",
      0,
      "",
      "localhost",
      "",
      "/a/b/c",
      "",
      "",
      "localhost/a/b/c" // path notation
    }
  }; // URITestEntry tests[]


  const unsigned int test_count = sizeof(tests) / sizeof(tests[0]);
  try {
    for (unsigned int i = 0; i < test_count; ++i) {
      std::cout << "executing test number " << i << " with uri " << tests[i].uri << std::endl;

      zorba::URI uri;
      zorba::URI relativized;
      zorba::URI base;
      if (tests[i].base.empty()) {
        uri = zorba::URI(tests[i].uri);
      } else  {
        base = zorba::URI(tests[i].base);
        uri = zorba::URI(base, tests[i].uri);
        relativized = zorba::URI(uri, base);
      }
      if (uri.toString() != tests[i].text)  {
        std::cerr << "uri text " << uri.toString() << " is not equal to " << tests[i].text << std::endl;
        return 2;
      }
      if (uri.get_scheme() != tests[i].scheme)
        return 3;
      if (uri.get_port() != tests[i].port) {
        std::cerr << "port " << uri.get_port() << " is not equal to " << tests[i].port << std::endl;
        return 4;
      }
      if (uri.get_fragment() != tests[i].fragment) {
        std::cerr << "fragment " << uri.get_fragment() << " is not equal to " << tests[i].fragment << std::endl;
        return 5;
      }
      if (uri.get_host() != tests[i].host) {
        std::cerr << "host " << uri.get_host() << " is not equal to " << tests[i].host << std::endl;
        return 6;
      }
      if (uri.get_reg_based_authority() != tests[i].regbased_authority) {
        std::cerr << "regbased_authority " << uri.get_reg_based_authority() << " is not equal to " 
                  << tests[i].regbased_authority << std::endl;
        return 7;
      }
      if (uri.get_user_info() != tests[i].userinfo) {
        std::cerr << "userinfo " << uri.get_user_info() << " is not equal to " << tests[i].userinfo << std::endl;
        return 8;
      }
      if (uri.get_path() != tests[i].path) {
        std::cerr << "path " << uri.get_path() << " is not equal to " << tests[i].path << std::endl;
        return 9;
      }
      if (uri.get_query() != tests[i].query) {
        std::cerr << "query " << uri.get_query() << " is not equal to " << tests[i].query << std::endl;
        return 10;
      }
      if (!tests[i].base.empty() && uri.get_path().indexOf(base.get_path()) == 0) {
        if (relativized.toString() != tests[i].uri) {
          std::cerr << "relativized uri " << relativized.toString() << " is not equal to relative " << tests[i].uri 
                    << " which was relativized using base " << tests[i].base << std::endl;
          return 11;
        } else {
          std::cerr << "relativized uri " << relativized.toString() << std::endl;
        }
      }
      if (uri.toPathNotation() != tests[i].path_notation) {
        std::cerr << "path notation " << uri.toPathNotation() << " is not equal to " 
                  << tests[i].path_notation << std::endl;
        return 12;
      }
      std::cout << "result: " << uri.toString() << std::endl;
      std::cout << "path notation: " << uri.toPathNotation() << std::endl;
      std::cout << "--------------------------------------------------" << std::endl;
    }
  } catch (zorba::error::ZorbaError & e) {
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
