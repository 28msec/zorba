# Copyright 2006-2008 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Add a target to import FOTS
ADD_CUSTOM_TARGET(fots-import
  COMMAND "${CMAKE_COMMAND}" 
  -D "ZORBA=${ZORBA_EXE}"
  -D "BUILDDIR=${PROJECT_BINARY_DIR}"
  -P "${CMAKE_CURRENT_SOURCE_DIR}/ImportFOTS.cmake"
  COMMAND "${CMAKE_COMMAND}" "${PROJECT_SOURCE_DIR}"
  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")

# Create cached version of activate setting
SET (ZORBA_FOTS_ACTIVATE inactive CACHE STRING "Which FOTS tests to activate")
MARK_AS_ADVANCED (ZORBA_FOTS_ACTIVATE)

# Add targets to set activate flag
ADD_CUSTOM_TARGET(fots-activate-sets
  COMMAND "${CMAKE_COMMAND}"
  -D "ZORBA_FOTS_ACTIVATE=sets" "${PROJECT_SOURCE_DIR}"
  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")
ADD_CUSTOM_TARGET(fots-activate-cases
  COMMAND "${CMAKE_COMMAND}"
  -D "ZORBA_FOTS_ACTIVATE=cases" "${PROJECT_SOURCE_DIR}"
  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")
ADD_CUSTOM_TARGET(fots-deactivate
  COMMAND "${CMAKE_COMMAND}"
  -D "ZORBA_FOTS_ACTIVATE=inactive" "${PROJECT_SOURCE_DIR}"
  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")

# Load FOTS test scripts (if they exist) depending on flag
IF ("${ZORBA_FOTS_ACTIVATE}" STREQUAL "sets")
  MESSAGE (STATUS "Adding FOTS test-set tests")
  SET (_fotsscript "${CMAKE_CURRENT_BINARY_DIR}/FOTSSetTests.cmake")
ELSEIF ("${ZORBA_FOTS_ACTIVATE}" STREQUAL "cases")
  MESSAGE (STATUS "Adding FOTS test-case tests (may take a while...)")
  SET (_fotsscript "${CMAKE_CURRENT_BINARY_DIR}/FOTSCaseTests.cmake")
ELSE ("${ZORBA_FOTS_ACTIVATE}" STREQUAL "sets")
  SET (_fotsscript "")
ENDIF ("${ZORBA_FOTS_ACTIVATE}" STREQUAL "sets")
IF (NOT _fotsscript STREQUAL "")
  IF (EXISTS "${_fotsscript}")
    INCLUDE ("${_fotsscript}")
  ELSE (EXISTS "${_fotsscript}")
    MESSAGE (WARNING "...${_fotsscript} does not exist, not adding FOTS tests "
      "after all (did you forget to run the 'fots-import' target?)")
  ENDIF (EXISTS "${_fotsscript}")
ENDIF (NOT _fotsscript STREQUAL "")

# Customized macro for FOTS tests
MACRO (expected_fots_failure)
  PARSE_ARGUMENTS (EFF "" "" "SLOW;CRASH;DISPUTED" ${ARGN})
  LIST (LENGTH EFF_DEFAULT_ARGS _numargs)
  IF (NOT _numargs EQUAL 3)
    MESSAGE (FATAL_ERROR "Invalid arguments to EXPECTED_FOTS_FAILURE: ${ARGN}")
  ENDIF (NOT _numargs EQUAL 3)
  LIST (GET EFF_DEFAULT_ARGS 0 test_set)
  LIST (GET EFF_DEFAULT_ARGS 1 test_case)
  LIST (GET EFF_DEFAULT_ARGS 2 bugid)

  # First add test_set name to list of test_sets, if it's not already there
  GET_PROPERTY (_test_sets GLOBAL PROPERTY "_ALL_FOTS_TEST_SETS_")
  LIST (FIND _test_sets ${test_set} _found)
  IF (_found EQUAL -1)
    SET_PROPERTY (GLOBAL APPEND PROPERTY "_ALL_FOTS_TEST_SETS_" ${test_set})
  ENDIF (_found EQUAL -1)

  # Determine "notrun" status
  SET (_notrun)
  SET (_finalStatus)
  SET (_disputed)
  IF (EFF_SLOW)
    SET (_notrun true)
    SET (_finalStatus pass)
  ENDIF (EFF_SLOW)
  IF (EFF_CRASH)
    SET (_notrun true)
    SET (_finalStatus fail)
  ENDIF (EFF_CRASH)
  IF (EFF_DISPUTED)
    SET (_disputed true)
  ENDIF (EFF_DISPUTED)

  # Append three values per test case - case name, bugnum, notRun
  SET_PROPERTY (GLOBAL APPEND PROPERTY "_FOTS_${test_set}_CASES_"
    ${test_case} ${bugid} "${_notrun}" "${_finalStatus}" "${_disputed}")
ENDMACRO (expected_fots_failure)


##
## Place all known failing FOTS tests here!
##
#"slow" tests. These are not run but are marked as 'pass' by FOTS driver.
EXPECTED_FOTS_FAILURE (SLOW fn-subsequence cbcl-subsequence-011 1069794)
EXPECTED_FOTS_FAILURE (SLOW fn-subsequence cbcl-subsequence-012 1069794)
EXPECTED_FOTS_FAILURE (SLOW fn-subsequence cbcl-subsequence-013 1069794)
EXPECTED_FOTS_FAILURE (SLOW fn-subsequence cbcl-subsequence-014 1069794)
EXPECTED_FOTS_FAILURE (SLOW fn-matches.re re00987 1131313)
EXPECTED_FOTS_FAILURE (SLOW app-Demos itunes 0)

# Couple tests that don't work on the old RQ machine.
IF (ZORBA_OLD_RQ_MACHINE)
  EXPECTED_FOTS_FAILURE (SLOW app-CatalogCheck Catalog002 0)
  EXPECTED_FOTS_FAILURE (SLOW app-FunctxFn functx-fn-tokenize-7 0)
  EXPECTED_FOTS_FAILURE (SLOW app-FunctxFn functx-fn-tokenize-all 0)
ENDIF (ZORBA_OLD_RQ_MACHINE)

# The following test-cases will fail by default.
# However they all pass if one sets the following environment variables:
#   QTTEST='42'
#   QTTEST2='other'
#   QTTESTEMPTY=''
# The remote queue machine does this.
#EXPECTED_FOTS_FAILURE (SLOW fn-available-environment-variables fn-available-environment-variables-011 1187692)
#EXPECTED_FOTS_FAILURE (SLOW fn-environment-variable environment-variable-005 1187692)
#EXPECTED_FOTS_FAILURE (SLOW fn-environment-variable environment-variable-006 1187692)
#EXPECTED_FOTS_FAILURE (SLOW fn-environment-variable environment-variable-007 1187692)

#"crashing/hanging" tests. These are not run but marked as 'tooBig' by FOTS driver.
EXPECTED_FOTS_FAILURE (CRASH fn-matches.re re00975 1070533)
EXPECTED_FOTS_FAILURE (CRASH fn-matches.re re00976 1070533)
EXPECTED_FOTS_FAILURE (CRASH fn-matches.re re00976a 1070533)

#"disputed" tests. These test are run but marked as 'pass' by FOTS driver.
#All these entries should have a *valid* opened bug number from W3C bugzilla.
EXPECTED_FOTS_FAILURE (DISPUTED misc-XMLEdition XML10-4ed-Excluded-char-1 13869)

# This test passes on the old and new RQ machines, but fails for Sorin.
#EXPECTED_FOTS_FAILURE (fn-normalize-unicode fn-normalize-unicode-11 0)

EXPECTED_FOTS_FAILURE (fn-fold-left fold-left-009 1187685)
EXPECTED_FOTS_FAILURE (fn-for-each-pair fn-for-each-pair-026 1187685)
EXPECTED_FOTS_FAILURE (fn-for-each-pair fn-for-each-pair-034 000)
EXPECTED_FOTS_FAILURE (fn-for-each-pair fn-for-each-pair-035 000)
EXPECTED_FOTS_FAILURE (fn-format-number numberformat20 1167641)
EXPECTED_FOTS_FAILURE (fn-format-number numberformat60a 1167609)
EXPECTED_FOTS_FAILURE (fn-format-number numberformat60m 1167609)
EXPECTED_FOTS_FAILURE (fn-format-number numberformat60o 1167609)
EXPECTED_FOTS_FAILURE (fn-format-number numberformat60q 1167609)
EXPECTED_FOTS_FAILURE (fn-format-number numberformat63 1167609)
EXPECTED_FOTS_FAILURE (fn-format-number numberformat64 1167609)
EXPECTED_FOTS_FAILURE (fn-format-number numberformat83 1167641)
EXPECTED_FOTS_FAILURE (fn-format-number numberformat87 1167641)
EXPECTED_FOTS_FAILURE (fn-format-number numberformat88 1167641)
EXPECTED_FOTS_FAILURE (fn-format-number cbcl-fn-format-number-003 1200494)
EXPECTED_FOTS_FAILURE (fn-function-lookup fn-function-lookup-062 1187685)
EXPECTED_FOTS_FAILURE (fn-in-scope-prefixes K2-InScopePrefixesFunc-25 1200498)
EXPECTED_FOTS_FAILURE (fn-matches cbcl-matches-038 1131304)
EXPECTED_FOTS_FAILURE (fn-normalize-space fn-normalize-space-23 1187802)
EXPECTED_FOTS_FAILURE (fn-normalize-space fn-normalize-space-25 1187802)
EXPECTED_FOTS_FAILURE (fn-parse-xml parse-xml-010 1189927)
EXPECTED_FOTS_FAILURE (fn-parse-xml parse-xml-011 1188260)
EXPECTED_FOTS_FAILURE (fn-parse-xml-fragment parse-xml-fragment-016 1188269)
EXPECTED_FOTS_FAILURE (fn-parse-xml-fragment parse-xml-fragment-017 1188269)
EXPECTED_FOTS_FAILURE (fn-parse-xml-fragment parse-xml-fragment-020 1188269)
EXPECTED_FOTS_FAILURE (fn-resolve-uri fn-resolve-uri-26 1188088)
EXPECTED_FOTS_FAILURE (fn-resolve-uri fn-resolve-uri-28 1188088)
EXPECTED_FOTS_FAILURE (fn-serialize serialize-xml-007a 1188122)
EXPECTED_FOTS_FAILURE (fn-serialize serialize-xml-008 1188122)
EXPECTED_FOTS_FAILURE (fn-unparsed-text fn-unparsed-text-038 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text fn-unparsed-text-039 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text fn-unparsed-text-042 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text fn-unparsed-text-050 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-available fn-unparsed-text-available-023 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-available fn-unparsed-text-available-024 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-available fn-unparsed-text-available-036 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-available fn-unparsed-text-available-037 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-available fn-unparsed-text-available-038 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-lines fn-unparsed-text-lines-038 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-lines fn-unparsed-text-lines-039 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-lines fn-unparsed-text-lines-042 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-lines fn-unparsed-text-lines-049 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-lines fn-unparsed-text-lines-050 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-lines fn-unparsed-text-lines-051 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-lines fn-unparsed-text-lines-052 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-lines fn-unparsed-text-lines-053 1123835)
EXPECTED_FOTS_FAILURE (fn-unparsed-text-lines fn-unparsed-text-lines-054 1123835)
EXPECTED_FOTS_FAILURE (math-acos math-acos-003 1188109)
EXPECTED_FOTS_FAILURE (misc-CombinedErrorCodes XQST0093a 1188116)
EXPECTED_FOTS_FAILURE (misc-CombinedErrorCodes XQST0085 1204471)
EXPECTED_FOTS_FAILURE (misc-HigherOrderFunctions xqhof11 1188329)
EXPECTED_FOTS_FAILURE (misc-HigherOrderFunctions xqhof12 1188299)
EXPECTED_FOTS_FAILURE (misc-Serialization K2-Serialization-1 1188122)
EXPECTED_FOTS_FAILURE (misc-Serialization K2-Serialization-2 1188122)
EXPECTED_FOTS_FAILURE (misc-Serialization K2-Serialization-3 1188122)
EXPECTED_FOTS_FAILURE (misc-Serialization K2-Serialization-4 1188122)
EXPECTED_FOTS_FAILURE (misc-Serialization K2-Serialization-5 1188122)
EXPECTED_FOTS_FAILURE (misc-Serialization K2-Serialization-6 1188122)
EXPECTED_FOTS_FAILURE (misc-Serialization K2-Serialization-9 1188122)
EXPECTED_FOTS_FAILURE (misc-Serialization K2-Serialization-10 1188122)
EXPECTED_FOTS_FAILURE (misc-Serialization Serialization-html-23 1190714)
EXPECTED_FOTS_FAILURE (misc-Serialization Serialization-html-24 1190714)
EXPECTED_FOTS_FAILURE (misc-XMLEdition XML11-1ed-Included-char-1 1188324)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-3 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-30 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-31 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-32 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-assertion-1 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-assertion-2 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-assertion-3 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-assertion-4 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-assertion-5 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-assertion-6 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-assertion-7 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-assertion-8 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-assertion-9 1172270)
EXPECTED_FOTS_FAILURE (prod-Annotation annotation-assertion-10 1172270)
EXPECTED_FOTS_FAILURE (prod-BaseURIDecl K2-BaseURIProlog-5 1133806)
EXPECTED_FOTS_FAILURE (prod-CastableExpr CastableAs653 124)
EXPECTED_FOTS_FAILURE (prod-CastableExpr CastableAs654 124)
EXPECTED_FOTS_FAILURE (prod-CastableExpr CastableAs655 124)
EXPECTED_FOTS_FAILURE (prod-CastableExpr CastableAs656 124)
EXPECTED_FOTS_FAILURE (prod-CastableExpr CastableAs657 124)
EXPECTED_FOTS_FAILURE (prod-CastableExpr CastableAs658 124)
EXPECTED_FOTS_FAILURE (prod-CastExpr CastAsNamespaceSensitiveType-11 1188279)
EXPECTED_FOTS_FAILURE (prod-CastExpr CastAsNamespaceSensitiveType-12 1188279)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-UnionType-17 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-UnionType-22 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-UnionType-23 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-UnionType-24 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-UnionType-32 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-UnionType-35 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-ListType-3 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-ListType-23 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-ListType-25 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-ListType-26 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-ListType-27 1110217)
EXPECTED_FOTS_FAILURE (prod-CastExpr.schema CastAs-ListType-31 1110217)
EXPECTED_FOTS_FAILURE (prod-CompDocConstructor K2-ConDocNode-2 1188302)
EXPECTED_FOTS_FAILURE (prod-DirElemConstructor cbcl-directconelem-001 1200498)
EXPECTED_FOTS_FAILURE (prod-DirElemConstructor cbcl-directconelem-002 1200498)
EXPECTED_FOTS_FAILURE (prod-DirElemContent Constr-cont-charref-2 1130998)
EXPECTED_FOTS_FAILURE (prod-FunctionCall FunctionCall-007 1114221)
EXPECTED_FOTS_FAILURE (prod-FunctionCall FunctionCall-008 1114221)
EXPECTED_FOTS_FAILURE (prod-FunctionCall FunctionCall-031 1114221)
EXPECTED_FOTS_FAILURE (prod-FunctionCall FunctionCall-033 1114221)
EXPECTED_FOTS_FAILURE (prod-FunctionCall FunctionCall-037 1114221)
EXPECTED_FOTS_FAILURE (prod-FunctionCall FunctionCall-038 1114221)
EXPECTED_FOTS_FAILURE (prod-FunctionCall FunctionCall-039 1114221)
EXPECTED_FOTS_FAILURE (prod-FunctionCall function-call-reserved-function-names-014 1114221)
EXPECTED_FOTS_FAILURE (prod-FunctionCall function-call-reserved-function-names-015 1114221)
EXPECTED_FOTS_FAILURE (prod-FunctionCall function-call-reserved-function-names-016 1114221)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-001 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-003 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-005 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-007 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-009 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-012 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-013 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-015 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-017 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-019 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-021 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-023 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-025 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-027 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-029 1147547)
EXPECTED_FOTS_FAILURE (prod-FunctionDecl function-decl-reserved-function-names-031 1147547)
EXPECTED_FOTS_FAILURE (prod-InstanceofExpr instanceof113 1110217)
EXPECTED_FOTS_FAILURE (prod-InstanceofExpr instanceof139 1110217)
EXPECTED_FOTS_FAILURE (prod-InstanceofExpr instanceof140 1110217)
EXPECTED_FOTS_FAILURE (prod-InstanceofExpr cbcl-instance-of-001 1110217)
EXPECTED_FOTS_FAILURE (prod-EQName eqname-017 1188240)
EXPECTED_FOTS_FAILURE (prod-Literal K2-Literals-7 1188234)
EXPECTED_FOTS_FAILURE (prod-Literal K2-Literals-20 1188231)
EXPECTED_FOTS_FAILURE (prod-Literal K-Literals-30 1188320)
EXPECTED_FOTS_FAILURE (prod-ModuleImport modules-collide-var-001 1173638)
EXPECTED_FOTS_FAILURE (prod-ModuleImport modules-collide-fn-001 1173638)
EXPECTED_FOTS_FAILURE (prod-ModuleImport module-URIs-1 1160015)
EXPECTED_FOTS_FAILURE (prod-ModuleImport module-URIs-2 1160015)
EXPECTED_FOTS_FAILURE (prod-ModuleImport module-URIs-3 1160015)
EXPECTED_FOTS_FAILURE (prod-ModuleImport module-URIs-12 1160015)
EXPECTED_FOTS_FAILURE (prod-ModuleImport module-URIs-17 1160015)
EXPECTED_FOTS_FAILURE (prod-ModuleImport module-URIs-18 1160015)
EXPECTED_FOTS_FAILURE (prod-NamedFunctionRef function-literal-062 1187685)
EXPECTED_FOTS_FAILURE (prod-NameTest K2-NameTest-30 1200498)
EXPECTED_FOTS_FAILURE (prod-NameTest K2-NameTest-31 1200498)
EXPECTED_FOTS_FAILURE (prod-OptionDecl.serialization Serialization-003 1188159)
EXPECTED_FOTS_FAILURE (prod-OrderByClause orderBy40 1172258)
EXPECTED_FOTS_FAILURE (prod-OrderByClause orderBy41 1172258)
EXPECTED_FOTS_FAILURE (prod-OrderByClause orderBy49 1172258)
EXPECTED_FOTS_FAILURE (prod-OrderByClause orderBy50 1172258)
EXPECTED_FOTS_FAILURE (prod-OrderByClause orderBy51 1172258)
EXPECTED_FOTS_FAILURE (prod-OrderByClause orderBy59 1172258)
EXPECTED_FOTS_FAILURE (prod-RequireProhibitFeature require-schema-aware-1-s 1185996)
EXPECTED_FOTS_FAILURE (prod-RequireProhibitFeature require-schema-aware-2-s 1185996)
EXPECTED_FOTS_FAILURE (prod-RequireProhibitFeature prohibit-schema-aware-1-s 1185996)
EXPECTED_FOTS_FAILURE (prod-RequireProhibitFeature prohibit-schema-aware-2-s 1185996)
EXPECTED_FOTS_FAILURE (prod-RequireProhibitFeature require-schema-aware-5-s 1185996)
EXPECTED_FOTS_FAILURE (prod-RequireProhibitFeature prohibit-schema-aware-3-s 1185996)
EXPECTED_FOTS_FAILURE (prod-SchemaImport cbcl-schema-element-1 1174898)
EXPECTED_FOTS_FAILURE (prod-SchemaImport cbcl-schema-element-2 1174898)
EXPECTED_FOTS_FAILURE (prod-SchemaImport cbcl-schema-element-4 1174898)
EXPECTED_FOTS_FAILURE (prod-SchemaImport cbcl-schema-element-5 1174898)
EXPECTED_FOTS_FAILURE (prod-SchemaImport cbcl-schema-element-8 1174898)
EXPECTED_FOTS_FAILURE (prod-SchemaImport cbcl-validated-schema-element-1 1174898)
EXPECTED_FOTS_FAILURE (prod-SchemaImport cbcl-validated-schema-element-3 1174898)
EXPECTED_FOTS_FAILURE (prod-SchemaImport cbcl-validated-schema-element-4 1174898)
EXPECTED_FOTS_FAILURE (prod-SchemaImport qischema040 1175741)
EXPECTED_FOTS_FAILURE (prod-SchemaImport qischema040a 1175741)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-001 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-002 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-003 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-004 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-005 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-006 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-007 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-008 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-009 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-010 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-011 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-032 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-020 1170441)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-021 1170441)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-022 1170441)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-023 1170441)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-024 1170441)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-025 1170441)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-030 1172267)
EXPECTED_FOTS_FAILURE (prod-SchemaImport substitution-031 1172267)
EXPECTED_FOTS_FAILURE (prod-TypeswitchExpr typeswitch-113 1188251)
EXPECTED_FOTS_FAILURE (prod-ValidateExpr validateexpr-41 1188309)
EXPECTED_FOTS_FAILURE (prod-VersionDecl VersionDecl-v1-processor-and-v3-query 1188247)
EXPECTED_FOTS_FAILURE (prod-VersionDecl version_declaration-023-v3 1188247)
EXPECTED_FOTS_FAILURE (xs-anyURI cbcl-anyURI-002 1188242)
EXPECTED_FOTS_FAILURE (xs-anyURI cbcl-anyURI-006 1188242)
EXPECTED_FOTS_FAILURE (xs-base64Binary base64-115 1188287)
EXPECTED_FOTS_FAILURE (xs-error xs-error-005 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-006 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-007 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-015 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-016 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-020 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-028 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-034 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-035 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-037 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-041 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-042 1170470)
EXPECTED_FOTS_FAILURE (xs-error xs-error-049 1170470)

# Initialize FOTSExpectedFailures.xml
SET (fots_expected_failures_file "${CMAKE_BINARY_DIR}/FOTSExpectedFailures.xml")
# QQQ For now, we output the outer <failures> element so we can load this
# using fn:doc(). This should probably go away.
FILE (WRITE "${fots_expected_failures_file}" "<failures>\n")

# Loop through test sets
GET_PROPERTY (_test_sets GLOBAL PROPERTY "_ALL_FOTS_TEST_SETS_")
FOREACH (_test_set ${_test_sets})
  FILE (APPEND "${fots_expected_failures_file}"
    "  <TestSet name=\"${_test_set}\">\n")
  # Loop through the test cases for each test set
  GET_PROPERTY (_test_cases GLOBAL PROPERTY "_FOTS_${_test_set}_CASES_")
  WHILE (_test_cases)
    # Pop off three items and write out entry
    LIST (GET _test_cases 0 _test_case)
    LIST (GET _test_cases 1 _bugnum)
    LIST (GET _test_cases 2 _notrun)
    LIST (GET _test_cases 3 _finalStatus)
    LIST (GET _test_cases 4 _disputed)
    LIST (REMOVE_AT _test_cases 0 1 2 3 4)
    IF (_notrun)
      SET (_notrun " notRun=\"true\"")
    ENDIF (_notrun)
    IF (_finalStatus)
      SET (_finalStatus " finalStatus=\"${_finalStatus}\"")
    ENDIF (_finalStatus)
    IF (_disputed)
      SET (_disputed " finalStatus=\"disputed\"")
    ENDIF (_disputed)
    FILE (APPEND "${fots_expected_failures_file}"
      "    <Test name=\"${_test_case}\" bug=\"${_bugnum}\"${_notrun}${_finalStatus}${_disputed}/>\n")
  ENDWHILE (_test_cases)
  FILE (APPEND "${fots_expected_failures_file}"  "  </TestSet>\n")
ENDFOREACH (_test_set)

# QQQ Have to close this outer element, which means you can't call
# EXPECTED_FOTS_FAILURE from any other CMakeLists.txt.
FILE (APPEND "${fots_expected_failures_file}" "</failures>\n")
