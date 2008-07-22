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
#include <algorithm>
#include <functional>
#include <cassert>

namespace zorba {

  template <typename adaptable_unary> class binderonly {
  public:
    typedef typename adaptable_unary::argument_type argument_type;
    typedef typename adaptable_unary::result_type result_type;
  private:
    argument_type &arg;
    adaptable_unary &f;

  public:
    binderonly (adaptable_unary &f_, argument_type &arg_)
      : f (f_), arg (arg_)
    {}
    result_type operator () () {
      return f (arg);
    }
  };
  
  template <typename adaptable_unary> binderonly<adaptable_unary> bindonly (adaptable_unary &f, typename adaptable_unary::argument_type &arg) {
    return binderonly<adaptable_unary> (f, arg);
  }

  template <typename T> class stack_generator {
    std::stack<T> &stk;
  public:
    stack_generator (std::stack<T> &stk_) : stk (stk_) {}
    T operator () () {
      assert (! stk.empty ());
      T x = stk.top ();
      stk.pop ();
      return x;
    }
  };

  template <typename T> stack_generator<T> stack_to_generator (std::stack<T> &stk) {
    return stack_generator<T> (stk);
  }

  // Not officially in namespace std, so we put it in xqp
  template <class InputIterator, class Size, class OutputIterator>
  OutputIterator copy_n(InputIterator first, Size count, 
                        OutputIterator result) {
    for (Size n = 0; n < count; n++, *result++ = *first++)
      ;
    return result;
  }

};
  
/*
 * Local variables:
 * mode: c++
 * End:
 */
