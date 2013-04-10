This directory contains scripts for integrating the Zorba FOTS Driver
(contained in the directory ../fots_driver) with CTest.

It adds four targets to the Zorba project: one to download and import
FOTS, and three to configure which kinds of CTests are added to the
project.

  fots-import: This target will download FOTS and create CTest
  scripts. This is somewhat slow (around a minute), but you only need
  to do it once. You should not need to repeat this target unless you
  delete your build directory, or you want to update to a newer FOTS.

  fots-activate-sets: This target will re-configure your project to
  include one CTest test for each FOTS test set (roughly 370 tests).
  This is the recommended approach for running FOTS tests as it
  provides a good tradeoff between testing time and test granularity.

  fots-activate-cases: This target will re-configure your project to
  include one CTest test for each FOTS test case (roughly 27000
  tests). This is only recommended when debugging a problem reported
  with a specific test case, because CTest really isn't designed for
  such a large number of tests; it will slow down considerably.

  fots-deactivate: This target will re-configure your project to
  include no CTest tests for FOTS. Use this when doing normal
  development.
