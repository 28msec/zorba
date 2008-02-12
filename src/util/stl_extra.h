#include <algorithm>
#include <functional>

namespace xqp {

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
    for (Size n = 0; n < count; n++, *result++ = *first++);
    return result;
  }

};
  
/*
 * Local variables:
 * mode: c++
 * End:
 */
