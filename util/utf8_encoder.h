/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: utf8_encoder.h,v 1.1 2006/10/09 07:08:05 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_UTF8_ENCODER_H
#define XQP_UTF8_ENCODER_H

#include <string>

using namespace std;

namespace xqp {

#define BUFFSIZE 1024

class utf8_encoder
{

public:
  void encode(const char* path);
	std::string encode(const std::string&);
	std::string urlencode(const std::string&);

};


} /* namespace xqp */
#endif /* XQP_UTF8_ENCODER_H */
