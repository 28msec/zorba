# Copyright 2006-2011 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# QQQ Note: this file was originally the 1998 version of xml.xsd. It should
# probably be replaced with a later revision.
DECLARE_ZORBA_SCHEMA(URI "http://www.w3.org/2001/xml.xsd" FILE xml.xsd)

DECLARE_ZORBA_SCHEMA(URI "http://www.w3.org/2010/xslt-xquery-serialization"
  FILE xslt-xquery-serialization.xsd)

# XDM and PUL
DECLARE_ZORBA_SCHEMA(URI "http://www.zorba-xquery.com/schemas/pul"
  FILE pul.xsd)
DECLARE_ZORBA_SCHEMA(URI "http://www.zorba-xquery.com/schemas/complete-pul"
  FILE complete-pul.xsd)
DECLARE_ZORBA_SCHEMA(URI "http://www.zorba-xquery.com/schemas/xdm"
  FILE xdm.xsd)

# XQueryX
DECLARE_ZORBA_SCHEMA(URI "http://www.w3.org/2005/XQueryX"
FILE XQueryX.xsd)

# The following are DTDs, not schemas, but (currently at least) we
# only ever load them when an imported schema file references them
# (which, in turn, only happens in error cases - see bug 921624). So,
# we install them as schemas. Yes, this means they'll have an ".xsd"
# extension in the uri directory, but that's OK because Zorba will
# look for them with that extension.
DECLARE_ZORBA_SCHEMA(
  URI "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"
  FILE "xhtml/xhtml1-transitional.dtd")
DECLARE_ZORBA_SCHEMA(
  URI "http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd"
  FILE "xhtml/xhtml1-frameset.dtd")
DECLARE_ZORBA_SCHEMA(
  URI "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"
  FILE "xhtml/xhtml1-strict.dtd")
DECLARE_ZORBA_SCHEMA(
  URI "http://www.w3.org/TR/xhtml1/DTD/xhtml-lat1.ent"
  FILE "xhtml/xhtml-lat1.ent")
DECLARE_ZORBA_SCHEMA(
  URI "http://www.w3.org/TR/xhtml1/DTD/xhtml-special.ent"
  FILE "xhtml/xhtml-special.ent")
DECLARE_ZORBA_SCHEMA(
  URI "http://www.w3.org/TR/xhtml1/DTD/xhtml-symbol.ent"
  FILE "xhtml/xhtml-symbol.ent")
