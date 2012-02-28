(: Bug 921624. This test will take a very long time if the XHTML DTD is :)
(: not available on the local filesystem, so it should be run with a    :)
(: short timeout (~5 seconds).                                          :)

import schema namespace bogus = "http://example.com/BOGUS";
1
