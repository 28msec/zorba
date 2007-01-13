/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: [module].h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

/*______________________________________________________________________
|  
|	Gateway from mod_xqp to the C++ library libxqp.so
|_______________________________________________________________________*/


#ifndef XQP_CONTENT_HANDLER_H
#define XQP_CONTENT_HANDLER_H

void handle_request(
  request_rec* r,
  char* buf,
  int max);

#endif  /* XQP_CONTENT_HANDLER_H */

