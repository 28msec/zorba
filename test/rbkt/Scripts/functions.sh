#!/bin/bash


################################################################################
#                                                                              #
#                                   rbkt usage                                 #
#                                                                              #
################################################################################


function usage ()
{
  echo "rbkt.sh [-b bucketName [-q queryName]] [-h]"
  echo
  echo "Run a single query, or all the queries inside a directory (bucket), or all"
  echo "the queries that can be found anywhere inside the Queries dir."
  echo 
  echo "-b bucketName: bucketName is a relative pathname used to construct full"
  echo " pathnames for the directories that contain a group of queries, their"
  echo " expected results, and their actual results. For example, if bucketName"
  echo " is foo, rbkt will run queries in "
  echo "specify 3 directories:"
  echo "     (a) a directory where files containing query strings are located;"
  echo "            in this case the pathname is relative to the Queries directory"
  echo "            in the test environment"
  echo "        (b) the directory where the query-results files will be written;"
  echo "            in this case the pathname is relative to Output/dump"
  echo "            If not specified, all of the directories under Queries will be "
  echo "            visited, and the queries in them run."
  echo "-q : The query to run. The query string is in file <queryName>.xq inside"
  echo "         the bucketName directory."
  echo "-h : help"
}


################################################################################
#                                                                              #
#                                 Test Directories                             #
#                                                                              #
################################################################################

#
# Function to check the existence of the required test dirs and to create
# the results dir.
#
function buildDirEnv
{
  echo; echo "buildDirEnv: Checking/Building Environment Directories"

  if [ ! -d ${zorbaRepos} ]; then
     echo "ERROR 5 buildDirEnv: zorba root directory ${sorbaRepos} does not exist"
     return 5
  fi

  if [ ! -d ${testRootDir} ]; then
     echo "ERROR 10 buildDirEnv: test root directory ${testRootDir} does not exist"
     return 10
  fi

  if [ ! -d $scriptsDir ]; then
     echo "ERROR 14 buildDirEnv: test scripts directory $scriptsDir does not exist"
     return 14
  fi

  if [ ! -d ${queriesDir} ]; then
     echo "ERROR 12 buildDirEnv: queries directory ${queriesDir} does not exist"
     return 12
  fi
  if [ ! -d ${expQueryResultsDir} ]; then
     echo "ERROR 13 buildDirEnv: expected results directory ${expQueryResultsDir} does not exist"
     return 13
  fi

  mkdir -p ${queryResultsDir}

  if [ ! -d ${docsDir} ]; then
     echo "ERROR 12 buildDirEnv: source docs directory ${docsDir} does not exist"
     return 12
  fi
  if [ ! -d ${expLoaderResultsDir} ]; then
     echo "ERROR 13 buildDirEnv: expected docs directory ${expLoaderResultsDir} does not exist"
     return 13
  fi

  mkdir -p ${loaderResultsDir}

  return 0
}


################################################################################
#                                                                              #
#                                 Running Queries                              #
#                                                                              #
################################################################################


#params: 
#
# $1 - queryFile  : Full pathname of the file that contains the query string
function run_query
{
  local error=0

  local queryFile="$1"

  local EXE=${zorbaExecDir}/apitest

  if [ ! -e "${EXE}" ]; then
    echo "ERROR 1 run_query: binary executable ${EXE} not found"
    exit 17
  fi

  ${EXE} -o "${queryFile}.res" "${queryFile}"
  error=$?
  if [ ${error} != 0 ]; then
    echo "ERROR 2 run_query: ${EXE} $1 failed with error code ${error}"
    # To allow more queries to be run by the caller, do not propagate error
  fi

  return 0
}


#params
#
# $1 bucketName         : See run_bucket() function
# $2 queryName          : The query name.
function run_query_in_bucket
{
  local error=0

  local bucketName="$1"
  local queryName="$2"

  local inputDir="${queriesDir}/${bucketName}"
  local queryFile="${inputDir}/${queryName}.xq"

  local expResultsDir="${expQueryResultsDir}/${bucketName}"
  local expResultFile="${expResultsDir}/${queryName}.res"

  local resultsDir="${queryResultsDir}/${bucketName}"
  local resultFile="${resultsDir}/${queryName}.res"
  local diffFile="${resultsDir}/${queryName}.diff"

  if [ ! -e "${queryFile}" ]; then
    echo "ERROR 1 run_query_in_bucket: query file ${queryFile} does not exist"
    return 17
  fi

  #
  # Create results directory, if it doesn't exist already.
  # If it exists, then clean it up.
  #
  mkdir -p "${resultsDir}"
  if [ $? != 0 ]; then echo "ERROR 2 run_query_in_bucket: mkdir -p failed"; exit 19; fi
  rm -f "${resultDir}"/${queryName}.*

  #
  # Run the query
  #
  run_query "${queryFile}"
  error=$?
  if [ ${error} != 0 ]; then
    echo "ERROR 3 run_query_in_bucket: run_query failed with error code ${error}"
    return ${error}
  fi

  #
  # query_exec creates the result file in the same dir as the query file.
  # So, we must move the result file to the result dir.
  #
  # If no result file was generated, then we create an empty one.
  #
  if [ -e "${inputDir}/${queryName}.xq.res" ]; then
    mv "${inputDir}/${queryName}.xq.res" "${resultFile}"
    if [ $? != 0 ]; then echo "ERROR 12 run_query_in_bucket: mv failed"; exit 19; fi
  else
    touch "${resultFile}"
    if [ $? != 0 ]; then echo "ERROR 13 run_query_in_bucket: touch failed"; exit 19; fi
  fi

  #
  # Do the diffs
  #
  if [ -e "${expResultFile}" ]; then
    diff -I 'Duration.*' "${resultFile}" "${expResultFile}" > "${diffFile}"
  else
    echo "unknown expected results for ${queryName}"
    cp "${queryFile}" "${diffFile}"
    if [ $? != 0 ]; then echo "ERROR 21 run_query_in_bucket: cp failed"; exit 19; fi
  fi

  if [ -s "${diffFile}" ]; then
    echo
    echo "FAILURE : -bucket ${bucketName} -query ${queryName}"
    echo
    echo >> rbkt_summary.txt
    echo "FAILURE : -bucket ${bucketName} -query ${queryName}" >> rbkt_summary.txt
    echo >> rbkt_summary.txt
    let failedQueries=failedQueries+1 
  else
    echo
    echo "SUCCESS : -bucket ${bucketName} -query ${queryName}"
    echo
  fi

  let totalQueries=totalQueries+1

  return 0
}


#
# params:
#
# $1 bucketName : This is a relative pathname that specifies 2 directories:
#                 (a) a directory that contains query files; in this case the
#                     pathname is relative to the Queries directory in the test
#                     environment.
#                 (b) a directory where the query-results file will be written;
#                     in this case the pathname is relative to the Results
#                     directory in the test environment.
#
function run_bucket() 
{
  local error=0
  local queryList=""
  local q=""
  local queryName=""
  local bucketName="$1"

  if [ ! -e "${queriesDir}/${bucketName}" ]; then
    echo "ERROR 1 run_bucket: bucket ${queriesDir}/${bucketName} does not exist"
    return 17
  fi

  cd "${queriesDir}/${bucketName}"
  #queryList=`find . -maxdepth 1 -name "*.query" -printf "%f\n"`
  queryList=`ls *.xq`
  cd -

  for q in $queryList
  do
    echo ${q} | sed -e s/".xq"/""/g  > tmp_queryFile
    for queryName in `cat tmp_queryFile`
    do 
      run_query_in_bucket "${bucketName}" "${queryName}"
      error=$?
      if [ ${error} != 0 ]; then
        echo "ERROR 3 run_bucket: run_bucket failed with error code ${error}"
        return ${error}
      fi
    done
    rm -f tmp_queryFile
  done  

  return 0
}


################################################################################
#                                                                              #
#                                 Loading Docs                                 #
#                                                                              #
################################################################################


#
# $1 - docFile  : Full pathname of the file that contains the document text
#
function load_doc
{
  local error=0

  local docFile="$1"

  local EXE=${zorbaExecDir}/test_store

  if [ ! -e "${EXE}" ]; then
    echo "ERROR 1 load_doc: binary executable ${EXE} not found"
    exit 17
  fi

  ${EXE} "${docFile}"
  error=$?
  if [ ${error} != 0 ]; then
    echo "ERROR 2 load_doc: ${EXE} $1 failed with error code ${error}"
    # To allow more docs to be loaded by the caller, do not propagate error
  fi

  return 0
}


#
# $1 bucketName   : See load_bucket() function
# $2 docName      : The doc name. 
#
function load_doc_in_bucket()
{
  local error=0

  local bucketName="$1"
  local docName="$2"

  local inputDir="${docsDir}/${bucketName}"
  local docFile="${inputDir}/${docName}.xml"

  local expResultsDir="${expLoaderResultsDir}/${bucketName}"
  local expResultFile="${expResultsDir}/${docName}.xml"

  local resultsDir="${loaderResultsDir}/${bucketName}"
  local resultFile="${resultsDir}/${docName}.xml"
  local diffFile="${resultsDir}/${docName}.diff"

  if [ ! -e "${docFile}" ]; then
    echo "ERROR 1 load_doc_in_bucket: doc file ${docFile} does not exist"
    return 17
  fi

  #
  # Create results directory, if it doesn't exist already.
  # If it exists, then clean it up.
  #
  mkdir -p "${resultsDir}"
  if [ $? != 0 ]; then echo "ERROR 2 load_doc_in_bucket: mkdir -p failed"; exit 19; fi
  rm -f "${resultsDir}"/${docName}.*

  #
  # Load the doc
  #
  load_doc "${docFile}"
  error=$?
  if [ ${error} != 0 ]; then
    echo "ERROR 3 load_doc_in_bucket: load_doc failed with error code ${error}"
    return ${error}
  fi

  #
  # test_store creates the result file in the same dir as the doc file.
  # So, we must move the result file to the result dir.
  #
  # If no result file was generated, then we create an empty one.
  #
  if [ -e "${inputDir}/${docName}.xml.res" ]; then
    mv "${inputDir}/${docName}.xml.res" "${resultFile}"
    if [ $? != 0 ]; then echo "ERROR 12 load_doc_in_bucket: mv failed"; exit 19; fi
  else
    touch "${resultFile}"
    if [ $? != 0 ]; then echo "ERROR 13 load_doc_in_bucket: touch failed"; exit 19; fi
  fi

  #
  # Do the diffs
  #
  if [ -e "${expResultFile}" ]; then
    diff "${resultFile}" "${expResultFile}" > "${diffFile}"
  else
    echo "unknown expected results for ${docName}"
    cp "${docFile}" "${diffFile}"
    if [ $? != 0 ]; then echo "ERROR 21 load_doc_in_bucket: cp failed"; exit 19; fi
  fi

  if [ -s "${diffFile}" ]; then
    echo
    echo "FAILURE : -bucket ${bucketName} -doc ${docName}"
    echo
    let failedDocs=failedDocs+1 
  else
    echo
    echo "SUCCESS : -bucket ${bucketName} -doc ${docName}"
    echo
  fi

  let totalDocs=totalDocs+1

  return 0
}


#
# params:
#
# $1 bucketName
#
function load_bucket() 
{
  local error=0
  local docList=""
  local d=""
  local docName=""
  local bucketName="$1"

  if [ ! -e "${docsDir}/${bucketName}" ]; then
    echo "ERROR 1 load_bucket: bucket ${docsDir}/${bucketName} does not exist"
    return 17
  fi

  cd "${docsDir}/${bucketName}"
  docList=`ls *.xml`
  cd -

  for d in $docList
  do
    echo ${d} | sed -e s/".xml"/""/g  > tmp_docFile
    for docName in `cat tmp_docFile`
    do 
      load_doc_in_bucket "${bucketName}" "${docName}"
      error=$?
      if [ ${error} != 0 ]; then
        echo "ERROR 3 load_bucket: load_bucket failed with error code ${error}"
        return ${error}
      fi
    done
    rm -f tmp_docFile
  done  

  return 0
}
