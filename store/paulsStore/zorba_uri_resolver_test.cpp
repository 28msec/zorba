/**
 * @file zorba_uri_resolver_test.cpp
 * @author Paul Pedersen
 * @copyright 2006-2007 FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "zorba_uri_resolver.h"
#include "source.h"
#include "runtime/zorba.h"
#include "util/rchandle.h"
#include "util/tokenbuf.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[]) 
{
  try {
		string line;
		zorba* zorp = new zorba();
		uri_resolver* urires_p = new zorba_uri_resolver();
		while (true) {
			if (cin.eof()) break;
			getline(cin, line);
			if (line.length()==0) continue;
			if (line=="quit" || line=="exit") break;

			tokenbuf tok(line.c_str(), " ");
			tokenbuf::token_iterator it = tok.begin();
			tokenbuf::token_iterator end = tok.end();
			if (it==end) continue;
			string path = *it;

			rchandle<source> src_h = urires_p->resolve(path);
			istream* is_p = src_h->get_input(zorp);

			if (is_p==NULL) {
				cout << "source(" << path << ") -- not found\n";
				continue;
			}

			while (true) {
				if (is_p->eof()) break;
				getline(*is_p, line);
				cout << line << endl;
			}

		}

  } catch (xqp_exception& e1) {
    cout << "Application exception: " << e1.what() << '\t' << e1.get_msg() << endl;
  } catch (exception& e2) {
    cout << "System exception: " << e2.what() << endl;
  } catch (...) {
    cout << "Unhandled exception\n";
  }
	
}

