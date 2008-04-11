/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: URI.h,v 1.1 2006/10/09 07:07:49 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#ifndef ZORBA_URI_H
#define ZORBA_URI_H

/*______________________________________________________________________
|
|  See RFC 2396.
|  This module parses URIs, (e.g.) URLs, into all the
|  constituent parts.  
|
|  Derived from the apache webserver URI module:
|    apr_uri.c: URI related utility things
|
|  Licensed under the Apache License, Version 2.0 (the "License");
|  You may obtain a copy of the License at
|    http://www.apache.org/licenses/LICENSE-2.0
|		 
|_______________________________________________________________________*/

#include <string>
#include <vector>

#include "util/hashfun.h"

namespace zorba {

#define FTP_DEFAULT_PORT         21
#define SSH_DEFAULT_PORT         22
#define TELNET_DEFAULT_PORT      23
#define GOPHER_DEFAULT_PORT      70
#define HTTP_DEFAULT_PORT        80
#define POP_DEFAULT_PORT        110
#define NNTP_DEFAULT_PORT       119
#define IMAP_DEFAULT_PORT       143
#define PROSPERO_DEFAULT_PORT   191
#define WAIS_DEFAULT_PORT       210
#define LDAP_DEFAULT_PORT       389
#define HTTPS_DEFAULT_PORT      443
#define RTSP_DEFAULT_PORT       554
#define SNEWS_DEFAULT_PORT      563
#define ACAP_DEFAULT_PORT       674
#define NFS_DEFAULT_PORT       2049
#define TIP_DEFAULT_PORT       3372
#define SIP_DEFAULT_PORT       5060


class URI
{
public:
	enum urierr {
		URI_OK,
		URI_BADHOST,
		URI_BADCHAR
	};

	struct Scheme {
    const char *name;
    int default_port;
		Scheme(const char* n, int p) : name(n), default_port(p) {}
		~Scheme() {}
	};

protected:	// state
	std::string scheme;							// http:, ftp:, etc.
	std::string hostinfo;						// paul@a.b.com:80
	std::string user;								// paul
	std::string password;						// passwd
	std::string hostname;						// a.b.com
	std::string port_str;						// 80
	std::string hostandport;				// a.b.com:80
	std::string path;								// a/b/c.html
	std::string query;							// ?foo=1&bar=2
	std::string fragment;						// #myanchor
	int port;
	enum urierr errnum;
	bool dns_looked_up;
	bool dns_resolved;

public:	// ctor, dtor
	URI(URI const& uri);
	URI(std::string const& uri);
	URI(char const* uri);
	~URI();

	// common initializer
	void init_uri(const char* uri);

public:	// manipulators
	const std::string& get_scheme() const		{ return scheme; }
	const std::string& get_hostinfo() const	{ return hostinfo; }
	const std::string& get_user() const			{ return user; }
	const std::string& get_password() const	{ return password; }
	const std::string& get_hostname() const	{ return hostname; }
	const std::string& get_port_str() const	{ return port_str; }
	const std::string& get_hostandport() const	{ return hostandport; }
	const std::string& get_path() const			{ return path; }
	const std::string& get_query() const		{ return query; }
	const std::string& get_fragment() const	{ return fragment; }

	int get_port() const { return port; }
	enum urierr get_errno() const { return errnum; }
	bool is_ok() const { return errnum == URI_OK; }
	bool is_dns_looked_up() const { return dns_looked_up; }
	bool is_dns_resolved() const { return dns_resolved; }

	void set_scheme(const std::string& _scheme) 		{ scheme		= _scheme; }
	void set_user(const std::string& _user) 				{ user 			= _user; update(); }
	void set_password(const std::string& _password)	{ password	= _password; update(); }
	void set_hostname(const std::string& _hostname) { hostname	= _hostname; update(); }
	void set_port(uint32_t _port) 									{ port			= _port; update(); }
	void set_path(const std::string& _path) 				{ path			= _path; }
	void set_query(const std::string& _query) 			{ query			= _query; }
	void set_fragment(const std::string& _fragment) { fragment	= _fragment; }
	void update();

	std::string toString() const;
	uint64_t hashkey() const { return hashfun::h64(toString()); }

};

}	/* namespace zorba */
#endif	/* ZORBA_URI_H */
