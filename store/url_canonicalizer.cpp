/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: URLCanonicalizer.cpp 384 2006-04-26 06:39:28Z paul $
 *
 *  Copyright 2005-2006 SearchMe Corporation.  All Rights Reserved.
 *
 */

// C++ headers
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <set>

// core headers
#include "Tokenizer.h"

// search headers
#include "URI.h"

// spider headers
#include "spider_params.h"
#include "URLCanonicalizer.h"

using namespace std;

namespace km {

static const bool xdigitChars[256] = {
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  false, false, false, false, false, false,
  false, true,  true,  true,  true,  true,  true,  false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false,  true,  true,  true,  true,  true,  true, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false
};

static const bool validSchemeChars[256] = {
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, true,  false, true,  false, false,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false
};

static const bool validHostnameChars[256] = {
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, true,  true,  false,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  false, false, false, false, false, false,
  false, true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  false, false, false, false, true,
  false, true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false
};
  
// reserved    = ";" | "/" | "?" | ":" | "@" | "&" | "=" | "+" | "$" | ","
static const bool reservedURIChars[256] = {
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, true,  false, false, true,  false,
  false, false, false, true,  true,  false, false, true,
  false, false, false, false, false, false, false, false,
  false, false, true,  true,  false, true,  false, true,
  true,  false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false
};

// unreserved  = alphanum | mark
// mark        = "-" | "_" | "." | "!" | "~" | "*" | "'" | "(" | ")"
//
// pchar         = unreserved | escaped |
//                 ":" | "@" | "&" | "=" | "+" | "$" | ","
static const bool unreservedPathChars[256] = {
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, true,  false, false, true,  false, true,  true,
  true,  true,  true,  true,  true,  true,  true,  false,
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  false, false, true,  false, false,
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  false, false, false, false, true,
  false, true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  false, false, false, true,  false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false
};

// unreserved  = alphanum | mark
// mark        = "-" | "_" | "." | "!" | "~" | "*" | "'" | "(" | ")"
//
// even though these are denoted unwise, there are URLs
// which use them in the query element and many servers don't
// appear to correctly unescape the escaped sequences
//
//   unwise      = "{" | "}" | "|" | "\" | "^" | "[" | "]" | "`"
static const bool unreservedQueryChars[256] = {
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, true,  false, false, false, false, false, true,
  true,  true,  true,  false, false, true,  true,  false,
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  false, false, false, false, false, false,
  false, true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false
};

//   control     = <US-ASCII coded characters 00-1F and 7F hexadecimal>
//   space       = <US-ASCII coded character 20 hexadecimal>
//   delims      = "<" | ">" | "#" | "%" | <">
//   unwise      = "{" | "}" | "|" | "\" | "^" | "[" | "]" | "`"
static const bool excludedURIChars[256] = {
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  true,  true,  true,  true,  true,  true,  true, 
  true,  false, true,  true,  false, true,  false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, true,  false, true,  false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, true,  true,  true,  true, false,
  true,  false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, true,  true,  true,  false, true,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
};

// list taken from http://data.iana.org/TLD/tlds-alpha-by-domain.txt
//   # Version 2006042501, Last Updated Wed Apr 26 08:07:01 2006 UTC
static const char *validTopLevelDomains[] = {
  "ac",
  "ad",
  "ae",
  "aero",
  "af",
  "ag",
  "ai",
  "al",
  "am",
  "an",
  "ao",
  "aq",
  "ar",
  "arpa",
  "as",
  "at",
  "au",
  "aw",
  "az",
  "ba",
  "bb",
  "bd",
  "be",
  "bf",
  "bg",
  "bh",
  "bi",
  "biz",
  "bj",
  "bm",
  "bn",
  "bo",
  "br",
  "bs",
  "bt",
  "bv",
  "bw",
  "by",
  "bz",
  "ca",
  "cat",
  "cc",
  "cd",
  "cf",
  "cg",
  "ch",
  "ci",
  "ck",
  "cl",
  "cm",
  "cn",
  "co",
  "com",
  "coop",
  "cr",
  "cu",
  "cv",
  "cx",
  "cy",
  "cz",
  "de",
  "dj",
  "dk",
  "dm",
  "do",
  "dz",
  "ec",
  "edu",
  "ee",
  "eg",
  "er",
  "es",
  "et",
  "eu",
  "fi",
  "fj",
  "fk",
  "fm",
  "fo",
  "fr",
  "ga",
  "gb",
  "gd",
  "ge",
  "gf",
  "gg",
  "gh",
  "gi",
  "gl",
  "gm",
  "gn",
  "gov",
  "gp",
  "gq",
  "gr",
  "gs",
  "gt",
  "gu",
  "gw",
  "gy",
  "hk",
  "hm",
  "hn",
  "hr",
  "ht",
  "hu",
  "id",
  "ie",
  "il",
  "im",
  "in",
  "info",
  "int",
  "io",
  "iq",
  "ir",
  "is",
  "it",
  "je",
  "jm",
  "jo",
  "jobs",
  "jp",
  "ke",
  "kg",
  "kh",
  "ki",
  "km",
  "kn",
  "kr",
  "kw",
  "ky",
  "kz",
  "la",
  "lb",
  "lc",
  "li",
  "lk",
  "lr",
  "ls",
  "lt",
  "lu",
  "lv",
  "ly",
  "ma",
  "mc",
  "md",
  "mg",
  "mh",
  "mil",
  "mk",
  "ml",
  "mm",
  "mn",
  "mo",
  "mobi",
  "mp",
  "mq",
  "mr",
  "ms",
  "mt",
  "mu",
  "museum",
  "mv",
  "mw",
  "mx",
  "my",
  "mz",
  "na",
  "name",
  "nc",
  "ne",
  "net",
  "nf",
  "ng",
  "ni",
  "nl",
  "no",
  "np",
  "nr",
  "nu",
  "nz",
  "om",
  "org",
  "pa",
  "pe",
  "pf",
  "pg",
  "ph",
  "pk",
  "pl",
  "pm",
  "pn",
  "pr",
  "pro",
  "ps",
  "pt",
  "pw",
  "py",
  "qa",
  "re",
  "ro",
  "ru",
  "rw",
  "sa",
  "sb",
  "sc",
  "sd",
  "se",
  "sg",
  "sh",
  "si",
  "sj",
  "sk",
  "sl",
  "sm",
  "sn",
  "so",
  "sr",
  "st",
  "su",
  "sv",
  "sy",
  "sz",
  "tc",
  "td",
  "tf",
  "tg",
  "th",
  "tj",
  "tk",
  "tl",
  "tm",
  "tn",
  "to",
  "tp",
  "tr",
  "travel",
  "tt",
  "tv",
  "tw",
  "tz",
  "ua",
  "ug",
  "uk",
  "um",
  "us",
  "uy",
  "uz",
  "va",
  "vc",
  "ve",
  "vg",
  "vi",
  "vn",
  "vu",
  "wf",
  "ws",
  "ye",
  "yt",
  "yu",
  "za",
  "zm",
  "zw",
  NULL
};

bool URLCanonicalizer::inittab = false;
HashMap32<char> URLCanonicalizer::TLDHash(1024, .6);

URLCanonicalizer::URLCanonicalizer(
	unsigned int loopcount,
	bool stripIndex)
{
  // init
  maxAllowedLoops = loopcount;
  stripIndexPagesInPath = stripIndex;
  loggerp = NULL;

	if (inittab == false) {
  	const char **tld;
  	for (tld = validTopLevelDomains; *tld!=NULL; ++tld) {
    	TLDHash.put(*tld, '1');
  	}
		inittab = true;
	}
}

URLCanonicalizer::~URLCanonicalizer()
{
}

void URLCanonicalizer::log(
  int log_level,
  const string& location,
  const string& msg)
{
  if (loggerp) {
    loggerp->log(log_level, "URLCanonicalizer::"+location, msg);
  } else {
    //cerr << "URLCanonicalizer::" << location << ": " << msg << endl;
  }
}

bool URLCanonicalizer::escapeChars(
  string& s,
  const string& reservedChars,
  const bool (&charTable)[256])
{
  string::iterator strIt;

  //   escape reserved chars, unescape any escaped unreserved chars
  string escapedString = "";
  for (strIt = s.begin(); strIt != s.end(); ++strIt) {
    if (reservedChars.find(*strIt)!=string::npos) {
      escapedString += *strIt;
      continue;
    }

    if (*strIt == '%') {
      // escaped char
      if (strIt + 1 == s.end() ||
          strIt + 2 == s.end()) {
        log(Logger::LOG_ERROR, "URLCanonicalize::escapeChars",
            "URL: \"" + saveurl + "\": invalid escape sequence");
        return false;
      }
      if (!xdigitChars[(int)(*(strIt+1))] ||
          !xdigitChars[(int)(*(strIt+2))]) {
        ostringstream oss;
        oss << "URL: \"";
        oss << saveurl;
        oss << "\": invalid escape sequence: '%";
        oss << *(strIt+1);
        oss << *(strIt+2);
        oss << "'";
        log(Logger::LOG_ERROR, "URLCanonicalize::escapeChars", oss.str());
        return false;
      }

      string hexcode = "";
      hexcode += *(strIt+1);
      hexcode += *(strIt+2);

      istringstream iss(hexcode);
      int encodedChar;

      std::ios_base& (*f)(std::ios_base&) = std::hex;

      if (!(iss >> f >> encodedChar) ||
          (int)iss.tellg() != (int)hexcode.size()) {
        ostringstream oss;
        oss << "URL: \"";
        oss << saveurl;
        oss << "\": could not convert escape sequence: '%";
        oss << hexcode;
        oss << "' to char";
        log(Logger::LOG_ERROR, "URLCanonicalize::escapeChars", oss.str());
        return false;
      }

      // unescape any escaped unreserved characters
      if (charTable[encodedChar]) {
        escapedString += (char)encodedChar;
        strIt += 2;
      }
      else {
        escapedString += "%";
        escapedString += ((int(*)(int))std::toupper)(*(strIt+1));
        escapedString += ((int(*)(int))std::toupper)(*(strIt+2));
        strIt += 2;
      }
    }
    else if (!charTable[(int)(*strIt)]) {
      // escape any unescaped reserved characters
      escapedString += "%";

      ostringstream oss;
      std::ios_base& (*f)(std::ios_base&) = std::hex;

      if (!(oss << f << (int)(*strIt))) {
        log(Logger::LOG_ERROR, "URLCanonicalize::escapeChars",
            "URL: \"" + saveurl + "\": non-numeric chars in port");
        return false;
      }

      string hexstring = oss.str();
      transform(hexstring.begin(),
                hexstring.end(),
                hexstring.begin(),
                (int(*)(int))std::toupper);
      if (hexstring.size() == 1) escapedString += '0';
      escapedString += hexstring;
    }
    else {
      escapedString += *strIt;
    }
  }
  s = escapedString;
  return true;
}


void
URLCanonicalizer::resolveHtmlEntities(string &s)
{
  string::size_type offset = 0;
  offset = 0;
  while ((offset = s.find("&quot;",offset)) != string::npos) {
    s.replace(offset,6,"\"");
  }
  offset = 0;
  while ((offset = s.find("&lt;",offset)) != string::npos) {
    s.replace(offset,4,"<");
  }
  offset = 0;
  while ((offset = s.find("&gt;",offset)) != string::npos) {
    s.replace(offset,4,">");
  }
  while ((offset = s.find("&amp;",offset)) != string::npos) {
    s.replace(offset,5,"&");
  }
}


bool URLCanonicalizer::containsLoop(
  const vector<string>& v,
  unsigned int maxLoops,
  unsigned int stopOffsetFromEnd = 0)
{
  // !!! TODO: implement Rabin-Karp with rolling hash for more sophistication
  unsigned int consecutiveElementCount = 1;
  HashMap32<unsigned> occurrences;
  set<unsigned> metaoccurrences;
  bool possibleLoop = false;
  unsigned i;

  if (v.size() < maxLoops) return false;

  vector<string>::const_iterator it1 = v.begin();
  vector<string>::const_iterator it2 = v.begin() + 1;
  for (; it1 != v.end(); ++it1, ++it2) {
    if (occurrences.get(*it1,i)) {
      occurrences.put(*it1,i+1);
    }
    else {
      occurrences.put(*it1,1);
    }
    if (it2 != v.end()) {
      if (*it1 == *it2) {
        if (stopOffsetFromEnd) {
          ++consecutiveElementCount;
          vector<string>::const_iterator tmpit = it2;
          for (unsigned int i=0; i<=stopOffsetFromEnd; ++i) {
            ++tmpit;
          }
          if (tmpit == v.end()) break;
        }
        else
          if (++consecutiveElementCount >= maxLoops) break;
      }
      else consecutiveElementCount = 1;
    }
  }

  HashMap32<unsigned>::HashMapIterator hit = occurrences.iterator();
  for (; !hit.done(); ++hit) {
    const HashMap32<unsigned>::Entry* e = *hit;
    if (e->val > 3) {
      if (find(metaoccurrences.begin(),metaoccurrences.end(),e->val) !=
          metaoccurrences.end()) {
        possibleLoop = true;
        break;
      }
      else {
        metaoccurrences.insert(e->val);
      }
    }
  }

  return (consecutiveElementCount >= maxLoops || possibleLoop);
}


bool URLCanonicalizer::canonicalizeUrl(string &url)
{
  string::iterator strIt;
  deque<string>::iterator qsIt;
  vector<string>::iterator vsIt;
  vector<string>::reverse_iterator vsRIt;

  if (url.size() > MAX_URL_LENGTH) {
    log(Logger::LOG_ERROR, "canonicalizeUrl",
        "URL: \"" + url + "\": url length exceeds MAX_URL_LENGTH");
    return false;
  }

  saveurl = url;

  string outUrl = "";

  // strip leading/trailing whitespace
  url.erase(0, url.find_first_not_of(" \t\n"));
  url.erase(url.find_last_not_of(" \t\n") + 1);

  URI _url = URI(url);
  if (!_url.is_ok()) {
    URI::urierr error = _url.get_errno();
    string errstring;

    switch (error) {
    case URI::URI_BADHOST: { errstring = "URI ctor: bad host"; break; }
    case URI::URI_BADCHAR: { errstring = "URI ctor: bad char"; break; }
    default: {}
    }

    log(Logger::LOG_ERROR, "canonicalizeUrl",
        "URL: \"" + url + "\": " + errstring);
    return false;
  }

  string scheme   = _url.get_scheme();
  string user     = _url.get_user();
  string password = _url.get_password();
  string hostname = _url.get_hostname();
  string port_str = _url.get_port_str();
  string path     = _url.get_path();
  string query    = _url.get_query();
  string fragment = _url.get_fragment();

  // scheme
  if (scheme.size()) {
    //   convert to lowercase
    transform (scheme.begin(),
               scheme.end(),
               scheme.begin(),
               (int(*)(int))std::tolower);
    //   validate characters
    for (strIt = scheme.begin(); strIt != scheme.end(); ++strIt) {
      if (!validSchemeChars[(int)*strIt]) {
        ostringstream oss;
        oss << "URL: \"";
        oss << url;
        oss << "\": invalid character '";
        oss << *strIt;
        oss << "' in scheme \"";
        oss << scheme;
        oss << "\"";
        log(Logger::LOG_ERROR, "canonicalizeUrl", oss.str());
        return false;
      }
    }

    //   currently only http schemes are supported
    if (scheme != "http") {
      log(Logger::LOG_ERROR, "canonicalizeUrl",
          "URL: \"" + url + "\": unsupported scheme: \"" + scheme + "\"");
      return false;
    }

    outUrl += scheme;
    outUrl += "://";
  }
  else {
    // should we default to "http" on missing scheme???
    log(Logger::LOG_ERROR, "canonicalizeUrl",
        "URL: \"" + url + "\": missing scheme");
    return false;
  }

  // user/password  (should we drop urls with authentication tokens???)
  if (user.size()) {
    outUrl += user;
    if (password.size()) {
      outUrl += ":";
      outUrl += password;
    }
    outUrl += "@";
  }

  // hostname
  if (hostname.size()) {
    //   validate characters, reject url if nonvalid chars
    for (strIt = hostname.begin(); strIt != hostname.end(); ++strIt) {
      if (!validHostnameChars[(int)*strIt]) {
        ostringstream oss;
        oss << "URL: \"";
        oss << url;
        oss << "\": invalid character '";
        oss << *strIt;
        oss << "' in hostname \"";
        oss << hostname;
        oss << "\"";
        log(Logger::LOG_ERROR, "canonicalizeUrl", oss.str());
        return false;
      }
    }
    //   convert characters to lowercase
    transform (hostname.begin(),
               hostname.end(),
               hostname.begin(),
               (int(*)(int))std::tolower);

    Tokenizer hosttok(hostname.c_str(),".",false);
    vector<string> hostnamev;
    while (hosttok.hasMoreTokens()) {
      hostnamev.push_back(hosttok.nextToken());
    }

    if (hostnamev.size() == 0) {
      // hostname was all dots
      ostringstream oss;
      oss << "URL: \"";
      oss << url;
      oss << "\": invalid hostname \"";
      oss << hostname;
      oss << "\"";
      log(Logger::LOG_ERROR, "canonicalizeUrl", oss.str());
      return false;
    }

    //   convert octal, hex, int representations of IP addrs to dec quartets
    bool allHostComponentsNumeric = true;

    if (hostnamev.size() == 1) {
      if ((hostname.substr(0,2) == "0x" &&
           hostname.find_first_not_of("0123456789",2) == string::npos) ||
          (hostname.find_first_not_of("0123456789") == string::npos))
        {
          istringstream iss(hostname);

          std::ios_base& (*f)(std::ios_base&) = std::dec;
          if (hostname.substr(0,2) == "0x") f = std::hex;
          else if (hostname.substr(0,1) == "0") {
            log(Logger::LOG_ERROR, "canonicalizeUrl",
                "URL: \"" + url + "\": octal unified IP hostname is invalid");
            return false;
          }

          unsigned long int dword;
          if (!(iss >> f >> dword) ||
              (int)iss.tellg() != (int)hostname.size()) {
            log(Logger::LOG_ERROR, "canonicalizeUrl",
                "URL: \"" + url + "\": unable to convert hostname \"" +
                hostname + "\" to dword");
            return false;
          }

          dword %= 4294967296;

          ostringstream oss;
          oss << ((dword & 0xFF000000) >> 24) << "."
              << ((dword & 0x00FF0000) >> 16) << "."
              << ((dword & 0x0000FF00) >> 8) << "."
              << (dword & 0x000000FF);

          hostname = oss.str();

          // hack!! short circuit TLD check below
          allHostComponentsNumeric = false;
          hostnamev.push_back("com");
        }
    }

    //     (iterate in reverse to short circuit on non-numeric TLDs)
    for (vsRIt = hostnamev.rbegin(); vsRIt != hostnamev.rend(); ++vsRIt) {
      if (vsRIt->substr(0,2) == "0x" &&
          vsRIt->find_first_not_of("0123456789",2) == string::npos) {
        // hex
      }
      else if (vsRIt->find_first_not_of("0123456789") == string::npos) {
        // oct/dec
      }
      else {
        allHostComponentsNumeric = false;
        break;
      }
    }

    if (allHostComponentsNumeric) {
      if (hostnamev.size() != 4) {
        log(Logger::LOG_ERROR, "canonicalizeUrl",
            "URL: \"" + url +
            "\": all hostname components numeric but not in valid IP quartet");
        return false;
      }

      ostringstream oss;
      vsIt = hostnamev.begin();
      while (true) {
        istringstream iss(*vsIt);

        std::ios_base& (*f)(std::ios_base&) = std::dec;
        if (vsIt->substr(0,2) == "0x") f = std::hex;
        else if (vsIt->substr(0,1) == "0") f = std::oct;

        unsigned int numval;
        if (!(iss >> f >> numval) || 
            (int)iss.tellg() != (int)vsIt->size()) {
          ostringstream oss;
          oss << "URL: \"";
          oss << url;
          oss << "\": unable to convert hostname component \"";
          oss << *vsIt;
          oss << "\" to integer";
          log(Logger::LOG_ERROR, "canonicalizeUrl", oss.str());
          return false;
        }

        numval %= 256;

        oss << numval;
        if (++vsIt == hostnamev.end()) break;
        else oss << ".";
      }
      hostname = oss.str();
    }

    //   validate TLD against known list
    uint32_t index;
    if (!allHostComponentsNumeric &&
        !TLDHash.find(*hostnamev.rbegin(), index)) {
      ostringstream oss;
      oss << "URL: \"";
      oss << url;
      oss << "\": invalid top level domain name '";
      oss << *hostnamev.rbegin();
      oss << "' in hostname \"";
      oss << hostname;
      oss << "\"";
      log(Logger::LOG_ERROR, "canonicalizeUrl", oss.str());
      return false;
    }

    outUrl += hostname;
  }
  else {
    log(Logger::LOG_ERROR, "canonicalizeUrl",
        "URL: \"" + url + "\": missing hostname");
    return false;
  }

  // port
  //   drop if "80"
  if( port_str.size() && port_str != "80" ) {
    if (port_str.find_first_not_of("0123456789") != string::npos) {
      log(Logger::LOG_ERROR, "canonicalizeUrl",
          "URL: \"" + url + "\": non-numeric chars in port");
      return false;
    }
    outUrl += ":";
    outUrl += port_str;
  }

  // path
  if (path.size()) {
    //   strip any trailing slash
    if (path.find_last_of((const char*)"/", path.size()) == path.size()-1) {
      path.erase(path.end()-1);
    }

    // escape chars
    string reserved = "/;=?";
    if (!escapeChars(path, reserved, unreservedPathChars)) {
      log(Logger::LOG_ERROR, "canonicalizeUrl",
          "URL: \"" + url + "\": failed to escape characters in path");
      return false;
    }

    // resolve HTML entities (why are people putting these in hrefs?!)
    resolveHtmlEntities(path);

    //   resolve '.' and '..' path elements
    Tokenizer pathtok(path.c_str(),"/",true);
    vector<string> pathv;
    string thisToken = "", lastToken = "";
    while (pathtok.hasMoreTokens()) {
      thisToken = pathtok.nextToken();
      if (lastToken.size() &&
          lastToken[lastToken.size()-1] == ':' &&
          thisToken == "//") {
        // crazy hack to preserve "://" in path string
        pathv.push_back("");
      }
      else {
        if (thisToken.size() && thisToken.find('/') == string::npos)
          pathv.push_back(thisToken);
      }
      lastToken = thisToken;
    }

    stack<string> pathStack;
    for (vsIt = pathv.begin(); vsIt != pathv.end(); ++vsIt) {
      if (*vsIt == ".") continue;
      else if (*vsIt == "..") {
        if (pathStack.empty()) continue;
        else pathStack.pop();
      }
      else pathStack.push(*vsIt);
    }

    deque<string> pathq;
    while (!pathStack.empty()) {
      pathq.push_front(pathStack.top());
      pathStack.pop();
    }
    pathv = vector<string>(pathq.begin(),pathq.end());

    // check for loops
    if (containsLoop(pathv, maxAllowedLoops, 1)) {
      log(Logger::LOG_ERROR, "canonicalizeUrl",
          "URL: \"" + url +
          "\": excessive loops detected in path \"" + path + "\"");
      return false;
    }

    //   strip index pages??? (index.htm, index.html, default.asp, default.htm)
    if (stripIndexPagesInPath) {
      while (pathv.size()) {
        string lastPathComponent = *pathv.rbegin();
        transform (lastPathComponent.begin(), lastPathComponent.end(),
                   lastPathComponent.begin(), (int(*)(int))std::tolower);

        if (lastPathComponent == "index.htm" ||
            lastPathComponent == "index.html" ||
            lastPathComponent == "default.htm" ||
            lastPathComponent == "default.asp")
          {
            pathv.pop_back();
          }
        else break;
      }
    }

    if (pathv.size()) {
      for (vsIt = pathv.begin(); vsIt != pathv.end(); ++vsIt) {
        outUrl += "/";
        outUrl += *vsIt;
      }
    }
    else {
      // we started with some path but ./..-resolved it to empty
      outUrl += "/";
    }
  }
  else {
    // empty path, canonical form is "/"
    outUrl += "/";
  }

  // query
  if (query.size()) {
    // escape chars
    string reserved = ";/?:@&=+,$";
    if (!escapeChars(query, reserved, unreservedQueryChars)) {
      log(Logger::LOG_ERROR, "canonicalizeUrl",
          "URL: \"" + url + "\": failed to escape characters in query");
      return false;
    }

    // resolve HTML entities (why are people putting these in hrefs?!)
    resolveHtmlEntities(query);

    // drop queries containing long sequences of a single repeated character
    unsigned consecutiveCharCount = 1;
    for (strIt = query.begin(); strIt+1 != query.end(); ++strIt) {
      if (*strIt == '&') continue;
      if (*strIt == *(strIt+1)) consecutiveCharCount++;
      else consecutiveCharCount = 1;
      if (consecutiveCharCount > 16) {
        log(Logger::LOG_ERROR, "canonicalizeUrl",
            "URL: \"" + url + "\": too many consecutive chars in query");
        return false;
      }
    }

    Tokenizer querytok(query.c_str(),"&",false);
    vector<string> queryv;
    while (querytok.hasMoreTokens()) {
      queryv.push_back(querytok.nextToken());
    }

    // check for loops
    if (containsLoop(queryv, maxAllowedLoops)) {
      log(Logger::LOG_ERROR, "canonicalizeUrl",
          "URL: \"" + url +
          "\": excessive loops detected in query \"" + query + "\"");
      return false;
    }

    if (queryv.size()) {
      HashMap32<unsigned> occurrences;
      string argname;
      string::size_type offset;
      unsigned i;

      vsIt = queryv.begin();
      outUrl += '?';
      outUrl += *vsIt;

      if ((offset = (*vsIt).find_first_of('=')) == string::npos)
        offset = (*vsIt).size();
      occurrences.put((*vsIt).substr(0,offset),1);

      ++vsIt;
      for (; vsIt != queryv.end(); ++vsIt) {
        outUrl += "&";
        outUrl += *vsIt;

        if ((offset = (*vsIt).find_first_of('=')) == string::npos)
          offset = (*vsIt).size();
        argname = (*vsIt).substr(0,offset);
        if (occurrences.get(argname,i)) {
          if (i>6) { // drop urls containing 8 or more identical argnames
            log(Logger::LOG_ERROR, "canonicalizeUrl",
                "URL: \"" + url +
                "\": repeated argument name in query \"" + query + "\"");
            return false;
          }
          occurrences.put(argname,i+1);
        }
        else {
          occurrences.put(argname,1);
        }
      }
    }
  }

  // fragment
  //   strip fragments

  // success!
  url = outUrl;
  return true;
}

}  /* namespace km */


