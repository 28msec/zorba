#!/bin/bash

error=0

#
# The environment variable zorbaRepos must be defined. It should point to a
# directory containing a zorba repository (e.g., /home/markos/zorba/xquery) 
#
if [ ! ${zorbaRepos} ]; then
   echo "ERROR 1 rbkt.sh: zorbaRepos environment variable is not set"
   exit 1
fi


#
# Directory containing the query_exec binary.
#
binPath=${zorbaRepos}/Build/test

#
# testRootDir is the root directory of the test environment. It contains the
# the scripts, the test queries and their expected results. It is also under
# this directory where all output from the tests is stored.
#
testRootDir=${zorbaRepos}/test/rbkt

# The following dirs MUST exist under the testRootDir.
queriesDir=${testRootDir}/Queries
expResultsDir=${testRootDir}/ExpResults
scriptsDir=${testRootDir}/Scripts

# This is the dir where all query results are stored. This dir is created
# by the buildDirEnv function, if it does not exist already.
resultsDir=${testRootDir}/Results


#
# sourcing of common functions
#
if [ ! -e ${scriptsDir}/functions.sh ]; then
   echo "ERROR 3 rbkt.sh: ${scriptsDir}/functions.sh does not exist"
   exit 3
fi

source ${scriptsDir}/functions.sh

trap '' 12

#
# Argument parsing
#
bucketName=""
queryName=""
numruns=1

state=0
while [ $1 ]
do
   case $1 in
   -b)        state=1;;
   -q)        state=2;;
   -numruns)  state=6;;
   -h)        usage ; exit;;
    *) case $state in
       1) bucketName="$1"; state=0 ;;
       2) queryName="$1"; state=0 ;;
       6) numruns=${1}; state=0;;
       *) echo "ERROR 6 rbkt.sh: Wrong parameter $1"; usage; exit 6;;
       esac ;;
    esac
    shift
done

if [ $state -ne 0 ]; then
  echo "ERROR 7 rbkt.sh: Wrong arg list"; usage; exit 7;
fi


#
# Building env directories and runtime env
#
buildDirEnv
error=$?
if [ ${error} -ne 0 ]; then
  echo "ERROR 10 rbkt.sh: buildDirEnv function failed with error code ${error}"
  exit ${error}
fi


#
# Run queries
#
#echo; echo "Running Queries"
failedQueries=0
totalQueries=0

rm -f rbkt_summary.txt

if [ "${bucketName}" != "" ]; then

  if [ "${queryName}" != "" ]; then
    run_query_in_bucket "${bucketName}" "${queryName}" ${numruns}
    error=$?
    if [ ${error} -ne 0 ]; then
      echo "ERROR 70 rbkt.sh: run_query_in_bucket function failed with error code ${error}"
      exit ${error}
    fi
  else
    echo; echo "Running bucket ${bucketName}"
    run_bucket "${bucketName}" 
    error=$?
    if [ ${error} -ne 0 ]; then
      echo "ERROR 71 rbkt.sh: run_bucket function failed with error code ${error}"
      exit ${error}
    fi
  fi

else
  #bucketList=`find "${queriesSDir}" -mindepth 1 -type d -printf "%f\n"`
  bucketList="paths"

  for bucketName in ${bucketList}
  do
    echo; echo "Running bucket ${bucketName}"
    run_bucket "${bucketName}"
    error=$?
    if [ ${error} -ne 0 ]; then
      echo "ERROR 72 rbkt.sh: run_bucket function failed with error code ${error}"
      exit ${error}
    fi
  done
fi

echo
echo "rbkt.sh : total number of queries   = $totalQueries"
echo "rbkt.sh : number of failed queries  = $failedQueries"

echo >> rbkt_summary.txt
echo "rbkt.sh : total number of queries   = $totalQueries" >> rbkt_summary.txt
echo "rbkt.sh : number of failed queries  = $failedQueries" >> rbkt_summary.txt

if [ ${failedQueries} -gt 0 ]; then
  exit 1
else
   exit 0
fi
