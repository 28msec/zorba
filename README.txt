  ----------------------------
  FLWOR Foundation - Zorba 0.9
  ----------------------------

  Welcome to Zorba! We are pleased to announce the first release (beta version 0.9) of the Zorba. 
  Zorba is a general purpose XQuery processor implementing in C++ the W3C family of specifications. 
  It is not an XML database. The query processor has been designed to be embeddable in a variety of 
  environments such as other programming languages extended with XML processing capabilities, 
  browsers, database servers, XML message dispatchers, or smartphones. Its architecture employes a 
  modular design, which allows customizing the Zorba query processor to the environment’s needs. 
  In particular the architecture of the query processor allows a pluggable XML store 
  (e.g. main memory, DOM stores, persistent disk-based large stores, S3 stores).
  Zorba runs on most platforms and is available under the Apache license v2.

  In this first release of Zorba, the following functionalities are implemented:
  
   * XQuery 1.0 and XPath 2.0 (as in the W3C recommendation) except modules and only limited support for schema validation
   * XQuery Update Facility 1.0 (as in the evolving W3C recommendation)
   * An in-memory replaceable XML store implementing the XQuery Data Model (XDM) W3C recommendation.

  Zorba release 0.9 passes 97.6% of the W3C tests of XQuery 1.0 test suite
  and 99.4% of the XQuery Update Facility test suite. 
  However, this release is not optimized for performance (e.g indexes are not supported yet).

  The Latest Version
  ------------------

  The latest version can be found on the Zorba server project 
  page at <http://www.zorba-xquery.org/>.

  VERSIONING
  ----------
  Zorba is in the version 0.9.x still a pre-release. With version 
  1.x we will move to stable releases.
  
  STABLE RELEASES, 1.{even}.{revision}
  
  Documentation
  -------------

  The documentation is included in docs directory, as well as 
  the Zorba web site (http://www.zorba-xquery.com/).

  Installation
  ------------

  Please see the documentation on the web site or the doc/html folder
  of the package.

  Bugs and errors
  ---------------

  Bug or error reports should be sent to
  http://http://sourceforge.net/tracker/?group_id=226244&atid=1067586


  Licensing
  ---------

  Please see the file called LICENSE.txt.


  Contacts
  --------

  o If you want to be informed about new code releases, bug fixes
  and general news and information about the Zorba XQuery engine
  subscribe to the Zorba Users mailing list as described under
  <zorba-users@lists.sourceforge.net>

  o If you have a concrete bug report for Zorba please go to the
  Zorba's Bug Database and submit your report:
  <http://http://sourceforge.net/tracker/?group_id=226244&atid=1067586>

  o If you want to participate in actively developing Zorba ort
  support Zorba, please write a mail to: zorba@zorba-xquery.org
