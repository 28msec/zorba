#include "signature.h"
#include "store/api/item.h"

using namespace std;

namespace zorba {

  signature::signature (store::Item_t name, xqtref_t arg1,
                        bool variadic, xqtref_t return_type)
    : signature_base (variadic),
      qname_p(name)
  {
    argv.push_back(return_type);
    argv.push_back(arg1);
  }

signature::signature(
  store::Item_t name,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
}

signature::signature(
  store::Item_t name,
  xqtref_t arg1,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
  argv.push_back(arg1);
}

signature::signature(
  store::Item_t name,
  xqtref_t arg1,
  xqtref_t arg2,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
  argv.push_back(arg1);
  argv.push_back(arg2);
}

signature::signature(
  store::Item_t name,
  xqtref_t arg1,
  xqtref_t arg2,
  xqtref_t arg3,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
  argv.push_back(arg1);
  argv.push_back(arg2);
  argv.push_back(arg3);
}

signature::signature(
  store::Item_t name,
  xqtref_t arg1,
  xqtref_t arg2,
  xqtref_t arg3,
  xqtref_t arg4,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
  argv.push_back(arg1);
  argv.push_back(arg2);
  argv.push_back(arg3);
  argv.push_back(arg4);
}

signature::signature(store::Item_t name,
                     const vector<xqtref_t>& _argv,
                     xqtref_t return_type)
  : qname_p(name)
{
  argv.push_back (return_type);
  copy (_argv.begin (), _argv.end (), back_inserter (argv));
}

signature::~signature()
{
}


} /* namespace zorba */

