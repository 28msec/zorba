xquery version "3.0";

(: Test module with a schema :)
module namespace schema = "http://zorba-tests.28.io/modules/myschema";

import schema namespace sch = "http://zorba-tests.28.io/modules/theschema";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

declare function schema:test() {
  validate { <sch:a>1</sch:a> }
};
