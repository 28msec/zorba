/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: mangle_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "function_impl.h"

#include <iostream>
#include <string>
#include <vector>

#include "../types/type.h"
#include "../types/qname.h"
#include "../util/rchandle.h"
#include "../util/tokenbuf.h"
#include "../values/values.h"

using namespace std;
namespace xqp {


string function_impl::decode_type(type::typecode t)
{
  switch (t) {
  case XS_STRING:             return "st";
  case XS_BOOLEAN:            return "bo";
  case XS_DECIMAL:            return "de";
  case XS_FLOAT:              return "fl";
  case XS_DOUBLE:             return "do";
  case XS_DURATION:           return "du";
  case XS_DATETIME:           return "dt";
  case XS_TIME:               return "ti";
  case XS_DATE:               return "da";
  case XS_GYEARMONTH:         return "ym";
  case Xs_GYEAR:              return "gy";
  case Xs_GMONTHDAY:          return "md";
  case XS_GDAY:               return "gd";
  case XS_GMONTH:             return "gm";
  case XS_HEXBINARY:          return "hx";
  case XS_BASE64BINARY:       return "64";
  case XS_ANYURI:             return "au";
  case XS_QNAME:              return "qn";
  case XS_NOTATION:           return "no";
  case XS_UNTYPED:            return "un";
  case XS_UNTYPEDATOMIC:      return "ua";
  case XS_ANYATOMICTYPE:      return "aa";
  case XS_DAYTIME_DURATION:   return "dd";
  case XS_YEARMONTH_DURATION: return "yd";
  default:                    return "??";
  }
}

type::typecode function_impl::encode_type(string const& s)
{
  if (s=="st") return XS_STRING;
  if (s=="bo") return XS_BOOLEAN;
  if (s=="de") return XS_DECIMAL;
  if (s=="fl") return XS_FLOAT;
  if (s=="do") return XS_DOUBLE;
  if (s=="du") return XS_DURATION;
  if (s=="dt") return XS_DATETIME;
  if (s=="ti") return XS_TIME;
  if (s=="da") return XS_DATE;
  if (s=="ym") return XS_GYEARMONTH;
  if (s=="gy") return XS_GYEAR;
  if (s=="md") return XS_GMONTHDAY;
  if (s=="gd") return XS_GDAY;
  if (s=="gm") return XS_GMONTH;
  if (s=="hx") return XS_HEXBINARY;
  if (s=="64") return XS_BASE64BINARY;
  if (s=="au") return XS_ANYURI;
  if (s=="qn") return XS_QNAME;
  if (s=="no") return XS_NOTATION;
  if (s=="un") return XS_UNTYPED;
  if (s=="ua") return XS_UNTYPEDATOMIC;
  if (s=="aa") return XS_ANYATOMICTYPE;
  if (s=="dd") return XS_DAYTIME_DURATION;
  if (s=="yd") return XS_YEARMONTH_DURATION;
  return XS_STRING;
}

string function_impl::mangle(signature const& sig)
{
  ostringstream oss;
  sig.fname.put(oss) << '(';
  std::vector<type::typecode>::const_iterator it = sig.arg_v.begin();
  for (; it!=sig.arg_v.end(); ++it) {
    if (it!=sig.arg_v.begin()) oss << ',';
    oss << decode_type(*it);
  } oss << ')' << decode_type(sig.ret_type);
  return oss.str();
}


rchandle<signature> function_impl::demangle(string const& sig)
{
  enum demangle_state {
    prefix,
    name,
    nsuri,
    argv,
    retyp,
    exit
  };
  
  tokenbuf tokbuf(sig.c_str(),",([]):");
  tokenbuf::token_iterator it = tokbuf.begin();
	tokenbuf::token_iterator end = tokbuf.end();
	
	string fprefix;
	string fname;
	string uri;
	rchandle<signature> sig_h;
	
	for (uint32_t state = prefix; it!=end && state!=exit; ++it) {
  	string const& term  = *it;
  	cout << "term = " << term << endl;
  	switch (state) {
    	case prefix: {
      	fprefix = term;
      	state = name;
      	break;
    	}
    	case name: {
      	fname = term;
      	state = nsuri;
      	break;
    	}
    	case nsuri: {
      	uri = term;
      	sig_h = new signature(QName(QName::qn_func,fprefix,fname));
      	state = argv;
      	break;
    	}
    	case argv: {
      	sig_h->arg_v.push_back(encode_type(term));
      	if (it.get_delim()==")") { state = retyp; }
      	break;
    	}
    	case retyp: {
      	sig_h->ret_type = encode_type(term);
      	state = exit;
      	break;
    	}
    	default: {
      	cout << "Logic error: unrecognized state: " << state << endl;
      	break;
    	}
  	}
  }
  return sig_h;
}

} /* namespace xqp */
