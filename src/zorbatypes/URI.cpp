/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: URI.cpp,v 1.1 2006/10/09 07:07:49 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#include <sstream>
#include <iostream>

#include "common/common.h"

#include "URI.h"

#ifdef WIN32
	#include <algorithm>
#endif

using namespace std;
namespace zorba {

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

#define T_COLON           0x01        /* ':' */
#define T_SLASH           0x02        /* '/' */
#define T_QUESTION        0x04        /* '?' */
#define T_HASH            0x08        /* '#' */
#define T_NUL             0x80        /* '\0' */
#define NOTEND_SCHEME     (0xff)
#define NOTEND_HOSTINFO   (T_SLASH | T_QUESTION | T_HASH | T_NUL)
#define NOTEND_PATH       (T_QUESTION | T_HASH | T_NUL)
/*
  It works like this:
    if (uri_delims[ch] & NOTEND_foobar) {
      then we're not at a delimiter for foobar
    }
*/
static const unsigned char uri_delims[256] = {
    T_NUL,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,T_HASH,0,0,0,0,
    0,0,0,0,0,0,0,T_SLASH,0,0,0,0,0,0,0,0,0,0,T_COLON,0,
    0,0,0,T_QUESTION,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

static URI::Scheme schemes[] = {
  URI::Scheme("http",    HTTP_DEFAULT_PORT),
  URI::Scheme("ftp",     FTP_DEFAULT_PORT),
  URI::Scheme("https",   HTTPS_DEFAULT_PORT),
  URI::Scheme("gopher",  GOPHER_DEFAULT_PORT),
  URI::Scheme("ldap",    LDAP_DEFAULT_PORT),
  URI::Scheme("nntp",    NNTP_DEFAULT_PORT),
  URI::Scheme("snews",   SNEWS_DEFAULT_PORT),
  URI::Scheme("imap",    IMAP_DEFAULT_PORT),
  URI::Scheme("pop",     POP_DEFAULT_PORT),
  URI::Scheme("sip",     SIP_DEFAULT_PORT),
  URI::Scheme("rtsp",    RTSP_DEFAULT_PORT),
  URI::Scheme("wais",    WAIS_DEFAULT_PORT),
  URI::Scheme("z39.50r", WAIS_DEFAULT_PORT),
  URI::Scheme("z39.50s", WAIS_DEFAULT_PORT),
  URI::Scheme("prospero",PROSPERO_DEFAULT_PORT),
  URI::Scheme("nfs",     NFS_DEFAULT_PORT),
  URI::Scheme("tip",     TIP_DEFAULT_PORT),
  URI::Scheme("acap",    ACAP_DEFAULT_PORT),
  URI::Scheme("telnet",  TELNET_DEFAULT_PORT),
  URI::Scheme("ssh",     SSH_DEFAULT_PORT),
  URI::Scheme( NULL,			0xFFFF )     /* unknown port */
};


static int uri_port_of_scheme(const char *schemeStr)
{
	URI::Scheme* scheme;
	if (schemeStr) {
		for (scheme = schemes; scheme->name != NULL; ++scheme) {
			if (strcasecmp(schemeStr, scheme->name) == 0) {
				return scheme->default_port;
			}
		}
	}
	return 0;
}

URI::~URI() {}

URI::URI(
	URI const& uri)
:
	scheme(uri.scheme),
	hostinfo(uri.hostinfo),
	user(uri.user),
	password(uri.password),
	hostname(uri.hostname),
	port_str(uri.port_str),
	hostandport(uri.hostandport),
	path(uri.path),
	query(uri.query),
	fragment(uri.fragment),
	port(uri.port),
	errnum(uri.errnum),
	dns_looked_up(uri.dns_looked_up),
	dns_resolved(uri.dns_resolved)
{
}

URI::URI(
	string const& uriStr )
:
	port_str("80"),
	port(HTTP_DEFAULT_PORT),
	errnum(URI_OK),
	dns_looked_up(false),
	dns_resolved(false)
{
	uint32_t n = uriStr.length();
	char *uribuf;
	uribuf = (char*)malloc((n+1)*sizeof(char));
	memset(uribuf, '\0', (n+1)*sizeof(char));
	memcpy(uribuf, uriStr.c_str(), n);
	init_uri(uribuf);
	free(uribuf);
}

URI::URI(
	char const* uri)
:
	port_str("80"),
	port(HTTP_DEFAULT_PORT),
	errnum(URI_OK),
	dns_looked_up(false),
	dns_resolved(false)
{
	init_uri(uri);
}

void URI::init_uri(
	char const* uri)
{
	const char *s;
	const char *s1;
	const char *hostp;
	int v6_offset1 = 0;
	int v6_offset2 = 0;

  if (uri[0] == '/') {
		// assume backward branch prediction taken, common case = fall through

deal_with_path:

		// We expect uri to point to first character of path.
    // The path could be empty, (e.g.) 'http://foobar?query'.
		s = uri;
		while ((uri_delims[*(unsigned char *)s] & NOTEND_PATH) == 0) {
			//cerr << "uri_delims[" << (*s) << "] = " << uri_delims[*(unsigned char *)s] << endl;
			++s;
		}
		if (s != uri) path = string(uri, 0, s-uri);
    if (*s == 0) return;
		if (*s == '?') {
			++s;
			s1 = strchr(s, '#');
			if (s1) {
				fragment = string(s1+1);
				query = string(s, 0, s1-s);
			} else {
				query = string(s);
			}
			return;
		}

		// otherwise it's a fragment 
		fragment = string(s+1);
		return;
	}


	// find the scheme:
	s = uri;
	while ((uri_delims[*(unsigned char *)s] & NOTEND_SCHEME) == 0) { ++s; }

	// scheme must be non-empty and followed by '://'
	if (s==uri || s[0] != ':' || s[1] != '/' || s[2] != '/') {
		goto deal_with_path;        /* backwards predicted taken! */
	}

	scheme = string(uri, 0, s-uri);
	s += 3;
	hostp = s;
	while ((uri_delims[*(unsigned char *)s] & NOTEND_HOSTINFO) == 0) { ++s; }
	uri = s;        /* whatever follows hostinfo is start of uri */
	hostinfo = string(hostp, 0, uri-hostp);

	/* If there's a username:password@host:port, the @ we want is the last @.
	 * Note that hostinfo is definitely not the first character of the original
	 * uri, therefore  &hostinfo[-1] < &hostinfo[0] ... and this loop is valid.
	 */
	do { --s; } while (s >= hostp && *s != '@');

	if (s < hostp) {
		// assume backward branch prediction taken, common case = fall through

deal_with_host:

		/* We expect hostinfo to point to the first character of
		 * the hostname.  If there's a port it is the first colon,
		 * except with IPv6.
		 */
		if (*hostp == '[') {
			v6_offset1 = 1;
			v6_offset2 = 2;
			s = (const char*)memchr(hostp, ']', uri-hostp);
			if (s == NULL) { errnum = URI_BADHOST; return; }
			if (*++s != ':') { s = NULL; /* no port */ }
		} else {
			s = (const char*)memchr(hostp, ':', uri-hostp);
		}

		if (s == NULL) { // we expect the common case to have no port
			hostname = string(hostp+v6_offset1, 0, uri-hostp-v6_offset2);
                        transform(hostname.begin(),
                                  hostname.end(),
                                  hostname.begin(),
                                  (int(*)(int))tolower);
			hostandport = hostname;
			goto deal_with_path;
		}
		hostname = string(hostp+v6_offset1, 0, s-hostp-v6_offset2);
                transform(hostname.begin(),
                          hostname.end(),
                          hostname.begin(),
                          (int(*)(int))tolower);
		hostandport = hostname;
		++s;
		port_str = string(s, 0, uri-s);
		if (port_str != "80") hostandport += ":" + port_str;

		if (uri != s) {
			char *endstr;
			port = strtol(port_str.c_str(), &endstr, 10);
			if (*endstr=='\0') goto deal_with_path;
			errnum = URI_BADCHAR; // invalid character after ':'
			return;
		}
		port = uri_port_of_scheme(scheme.c_str());
		goto deal_with_path;
	}

	// first colon delimits username:password 
	s1 = (const char*)memchr(hostp, ':', s - hostp);
	if (s1) {
		user = string(hostp, 0, s1-hostp);
		++s1;
		password = string(s1, 0, s-s1);
	} else {
		user = string(hostp, 0, s-hostp);
	}
	hostp = s+1;
	goto deal_with_host;
}


// set_* methods can change components of aggregate members
void URI::update()
{
  hostinfo = "";
  hostandport = "";
  port_str = "";

  if (user.length()) {
    hostinfo += user;
    if (password.length()) hostinfo += ":" + password;
    hostinfo += "@";
  }
  hostinfo += hostname;
  hostandport = hostname;
  if (port != 80) {
    ostringstream oss;
    oss << port;
    port_str = oss.str();
    hostinfo += ":" + port_str;
    hostandport += ":" + port_str;
  }
}


string URI::toString() const
{
	ostringstream oss;
	if (scheme.length()>0)		oss << scheme;
	if (hostname.length()>0)	oss << "://" << hostname;
	if (port!=0 && port!=80)	oss << ':' << port;
	if (path.length()>0)			oss << (path[0]!='/' ? "/" : "") << path;
	if (query.length()>0)			oss << '?' << query;
	if (fragment.length()>0)	oss << '#' << fragment;
	return oss.str();
}


}	/* namespace zorba */

