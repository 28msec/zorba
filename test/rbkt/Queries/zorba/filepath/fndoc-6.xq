(: This is actually just a test case for the test: URI resolver - it should :)
(: resolve a relative URI relative to RBKT_SRC_DIR. :)

declare base-uri "test:///foo";
fn:doc("Queries/zorba/filepath/input.xml")
