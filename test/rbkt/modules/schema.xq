(: Test module with a schema :)
module namespace schema = "http://www.zorba-xquery.com/modules/myschema";

import schema namespace sch = "http://www.zorba-xquery.com/modules/theschema";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

declare function schema:test() {
  validate { <sch:a>1</sch:a> }
};
