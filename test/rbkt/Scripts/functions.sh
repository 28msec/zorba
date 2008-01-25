#!/bin/bash


################################################################################
#                                                                              #
#                                   rbkt usage                                 #
#                                                                              #
################################################################################


function usage ()
{
  echo "rbkt.sh [-b bucketName [-q queryName]] [-d displayFormat] [-h]"
  echo "or"
  echo "rbkt.sh [-b bucketName1 ... bucketNameN] [-d displayFormat] [-h]"
  echo
  echo "Run a single query, or all the queries inside a directory (bucket), or all"
  echo "the queries in a list of buckets, or all the queries that can be found"
  echo "anywhere inside the Queries dir."
  echo 
  echo "Options : "
  echo
  echo "-b: Specifies the query bucket to run. <bucketName> is used to construct"
  echo "    the full pathnames for the directories that contain a group of queries,"
  echo "    their expected results, and their actual results. For example, if"
  echo "    bucketName is foo, rbkt will run queries in .../test/rbkt/Queries/foo"
  echo
  echo "-q: The query to run. The query string is in file <queryName>.xq inside"
  echo "    the .../test/rbkt/Queries/<bucketName> directory."
  echo
  echo "-d: Specifies the display format for the query results. Currently, this"
  echo "    may be one of xml or show. The default is xml"
  echo
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
  #echo; echo "buildDirEnv: Checking/Building Environment Directories"

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


#
# params: 
#
# $1 queryFile
# $2 querySpecFile
# $3 displayFormat
#
function run_query
{
  local queryFile="$1"
  local querySpecFile="$2"
  local displayFormat=$3

  local error=0

  local EXE=${zorbaExecDir}/apitest

  if [ ! -e "${EXE}" ]; then
    echo "ERROR 1 run_query: binary executable ${EXE} not found"
    exit 17
  fi

  cd ${queryFile%/*}

  #echo "queryFile = ${queryFile}"
  #echo "querySpecFile = ${querySpecFile}"

  if test -f $querySpecFile; then
      XARGS=`egrep ^Args: ${querySpecFile} | cut -f2- -d:`
      ERRS=`egrep ^Error: ${querySpecFile} | cut -f2- -d:`
  else
      XARGS=""
      ERRS=""
  fi

  #echo "XARGS = ${XARGS}"

  SEDARG=`echo ${testRootDir} | sed -r 's/\//\\\\\//g'`

  echo "s/\$RBKT_SRC_DIR/$SEDARG/g" > sedargs

  XARGS=`echo ${XARGS} | sed -f sedargs`

  rm sedargs

  if [ $displayFormat == "xml" ]; then
    #echo "${EXE} ${XARGS} -r -o ${queryFile}.res ${queryFile} 2> ${queryFile}.err"
    ${EXE} ${XARGS} -r -o "${queryFile}.res" "${queryFile}" 2> ${queryFile}.err
  else
    ${EXE} -o "${queryFile}.res" "${queryFile}" 2> "${queryFile}.err"
  fi
  error=$?
  if [ ${error} != 0 ]; then
    echo "ERROR 2 run_query: ${EXE} $1 failed with error code ${error}"
    # To allow more queries to be run by the caller, do not propagate error
  fi
  
  cd - >/dev/null

  return 0
}


#
# params
#
# $1 bucketName 
# $2 queryName  
# $3 displayFormat
#
function run_query_in_bucket
{
  local bucketName="$1"
  local queryName="$2"
  local displayFormat=$3

  local error=0

  local inputDir="${queriesDir}/${bucketName}"
  local queryFile="${inputDir}/${queryName}.xq"
  local querySpec="${inputDir}/${queryName}.spec"

  local expResultsDir="${expQueryResultsDir}/${bucketName}"
  local fmtExt=""
  if [ $displayFormat == "xml" ]; then
    fmtExt="xml"
  else
    fmtExt="show"
  fi
  local expResultFile="${expResultsDir}/${queryName}.${fmtExt}.res"

  local resultsDir="${queryResultsDir}/${bucketName}"
  local resultFile="${resultsDir}/${queryName}.${fmtExt}.res"
  local errorsFile="${resultsDir}/${queryName}.${fmtExt}.err"
  local diffFile="${resultsDir}/${queryName}.${fmtExt}.diff"

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
  run_query "${queryFile}" "${querySpec}" ${displayFormat}
  error=$?
  if [ ${error} != 0 ]; then
    echo "ERROR 3 run_query_in_bucket: run_query failed with error code ${error}"
    return ${error}
  fi

  #
  # apitest creates the result file in the same dir as the query file.
  # So, we must move the result file to the result dir.
  #
  # If no result file was generated, then we create an empty one.
  #
  if [ -s "${inputDir}/${queryName}.xq.res.err" ]; then
      cat "${inputDir}/${queryName}.xq.res.err" | head -1 | cut -f1 -d':' > "${inputDir}/${queryName}.xq.res"
  fi

  mkdir -p `dirname ${resultFile}`
  if [ -e "${inputDir}/${queryName}.xq.res" ]; then
    cat "${inputDir}/${queryName}.xq.res" | ${scriptsDir}/tidy_xmlfrag >"${resultFile}"
    if [ ! -f "${resultFile}" ]; then echo "ERROR 12 run_query_in_bucket: could not create output file"; exit 19; fi
    rm "${inputDir}/${queryName}.xq.res"
  else
    touch "${resultFile}"
    if [ $? != 0 ]; then echo "ERROR 13 run_query_in_bucket: touch failed"; exit 19; fi
  fi

  if [ -e "${inputDir}/${queryName}.xq.err" ]; then
    mv "${inputDir}/${queryName}.xq.err" ${errorsFile}
  fi

  #
  # Do the diffs
  #
  if [ -e "${expResultFile}" ]; then
    cat "${expResultFile}" | ${scriptsDir}/tidy_xmlfrag | diff -I '^Duration.*:' "${resultFile}" - > "${diffFile}"
    #cat "${expResultFile}" | diff -I '^Duration.*:' "${resultFile}" - > "${diffFile}"
  else
    echo "Missing expected results for ${queryName}"
    cp "${queryFile}" "${diffFile}"
    if [ $? != 0 ]; then echo "ERROR 21 run_query_in_bucket: cp failed"; exit 19; fi
  fi

  if [ -s "${diffFile}" ]; then
    echo "FAILURE: ${bucketName} / ${queryName}"
    echo
    echo >> rbkt_summary.txt
    echo "FAILURE : -bucket ${bucketName} -query ${queryName}" >> rbkt_summary.txt
    echo >> rbkt_summary.txt
    let failedQueries=failedQueries+1 
  else
    echo "SUCCESS: ${bucketName} / ${queryName}"
    echo
  fi

  let totalQueries=totalQueries+1

  return 0
}


#
# params:
#
# $1 bucketName
# $2 displayFormat
#
function run_bucket() 
{
  local bucketName="$1"
  local displayFormat=$2
  local error=0
  local queryList=""
  local q=""
  local queryName=""

  if [ ! -e "${queriesDir}/${bucketName}" ]; then
    echo "ERROR 1 run_bucket: bucket ${queriesDir}/${bucketName} does not exist"
    return 17
  fi

  queryList=`mktemp`
  (cd "${queriesDir}/${bucketName}"; find . -name '*.xq' | cut -f2- -d/ ) > $queryList
  
  # Uses fd 3 for reading queries.
  # Nasty, but remember there can be many queries, and redirection
  # applies for the entire while loop.
  while read -u3 q; do
    queryName=`echo $q | sed -e 's/.xq$//g'`
    run_query_in_bucket "${bucketName}" "${queryName}" ${displayFormat}
    error=$?
    if [ ${error} != 0 ]; then
      echo "ERROR 3 run_bucket: run_bucket failed with error code ${error}"
      return ${error}
    fi
  done 3< $queryList

  rm -f $queryList

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
    echo "Missing expected results for ${docName}"
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
  cd - >/dev/null

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
