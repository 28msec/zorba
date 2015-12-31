#!/bin/bash
set -e

function show_usage()
{
  echo "No action specified. Allowed actions are:"
  echo "ssh                - to start an ssh server (requires running docker in detached mode (-d))"
  echo "cmake              - to prepare for the build of zorba"
  echo "make               - to build zorba"
  echo "enable-extra-tests - to enable fots tests"
  echo "ctest ...          - to run the test suite. Extra arguments are passed to ctest"
}

if [ "$#" -eq "0" ]
then
  show_usage
  exit 1
fi

ACTION=$1
case "$ACTION" in
  ssh)
    /usr/sbin/sshd -D
    ;;
  cmake)
    rm -rf /zorba/build
    mkdir /zorba/build
    cd /zorba/build
    cmake -DZORBA_MODULES_DIR="/zorba/zorba_modules" -DZORBA_XQUERYX:BOOL=1 -DZORBA_TEST_XQUERYX:BOOL=1 -DZORBA_WITH_BIG_INTEGER=1 -DCMAKE_BUILD_TYPE=Release -DZORBA_TEST_PLAN_SERIALIZATION:BOOL=1 -DZORBATEST_USE_MT_XQTS:BOOL=1 "/zorba/zorba"    
    ;;
  make)
    cd /zorba/build
    make -j8
    ;;
  enable-extra-tests)
    cd /zorba/build
    /zorba/zorba/import_tests.sh /zorba/zorba /zorba/build
    make fots-activate-sets
    ;;
  ctest)
    cd /zorba/build
    env QTTEST=42 QTTEST2=other QTTESTEMPTY='' ctest -j2 -T Test --output-on-failure ${@:2}
    ;;
  help)
    show_usage
    exit 0
    ;;
  *)
    show_usage
    exit 1
    ;;
esac