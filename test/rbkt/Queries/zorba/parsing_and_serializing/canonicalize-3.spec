# Old versions of libxml (like on the old RQ machine) didn't do this right,
# so we provide two "expected" results even though only the first is correct
Result: $RBKT_SRC_DIR/ExpQueryResults/zorba/parsing_and_serializing/canonicalize-3.xml.res
Result: $RBKT_SRC_DIR/ExpQueryResults/zorba/parsing_and_serializing/canonicalize-3-buggy-old-libxml.xml.res

