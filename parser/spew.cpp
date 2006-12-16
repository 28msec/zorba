
"Module",
{ "MainModule" },
{ "VersionDecl"  "MainModule" },
{ "LibraryModule" },
{ "VersionDecl"  "LibraryModule" },


"VersionDecl",
{ "XQUERY_VERSION"  "STRING_LITERAL"  "SEMI" },
{ "XQUERY_VERSION"  "STRING_LITERAL"  "ENCODING"  "STRING_LITERAL"  "SEMI" },


{ "MainModule" },
{ "Prolog"  "QueryBody" },
{ "QueryBody" },


"LibraryModule",
{ "ModuleDecl"  "Prolog" },


"ModuleDecl",
{ "MODULE_NAMESPACE"  "NCNAME"  "EQUALS"  "URI_LITERAL"  "SEMI" },


"Prolog",
{ "SIND_DeclList"  "SEMI" },
{ "VFO_DeclList"  "SEMI" },
{ "SIND_DeclList"  "SEMI"  "VFO_DeclList"  "SEMI" },


"SIND_DeclList",
{ "SIND_Decl" },
{ "SIND_DeclList"  "SEMI"  "SIND_Decl" },


"VFO_DeclList",
{ "VFO_Decl" },
{ "VFO_DeclList"  "SEMI"  "VFO_Decl" },


"SIND_Decl",
{ "Setter" },
{ "Import" },
{ "NamespaceDecl" },
{ "DefaultNamespaceDecl" },


"VFO_Decl",
{ "VarDecl" },
{ "FunctionDecl" },
{ "OptionDecl" },
{ "FTOptionDecl" },


"Setter",
{ "BoundarySpaceDecl" },
{ "DefaultCollationDecl" },
{ "BaseURIDecl" },
{ "ConstructionDecl" },
{ "OrderingModeDecl" },
{ "EmptyOrderDecl" },
{ "CopyNamespacesDecl" },
{ "RevalidationDecl" },


"Import",
{ "SchemaImport" },
{ "ModuleImport" },




"NamespaceDecl",
{ "DECLARE_NAMESPACE"  "NCNAME"  "EQUALS"  "URI_LITERAL" },


"BoundarySpaceDecl",
{ "DECLARE_BOUNDARY_SPACE"  "PRESERVE" },
{ "DECLARE_BOUNDARY_SPACE"  "STRIP" },


"DefaultNamespaceDecl",
{ "DECLARE_DEFAULT_ELEMENT"  "NAMESPACE"  "URI_LITERAL" },
{ "DECLARE_DEFAULT_FUNCTION"  "NAMESPACE"  "URI_LITERAL" },


"OptionDecl",
{ "DECLARE_OPTION"  "QNAME"  "STRING_LITERAL" },


"FTOptionDecl",
{ "DECLARE_FTOPTION"  "FTMatchOption" },


"OrderingModeDecl",
{ "DECLARE_ORDERING"  "ORDERED" },
{ "DECLARE_ORDERING"  "UNORDERED" },



"EmptyOrderDecl",
{ "DECLARE_DEFAULT_ORDER"  "EMPTY_GREATEST" },
{ "DECLARE_DEFAULT_ORDER"  "EMPTY_LEAST" },


"CopyNamespacesDecl",
{ "DECLARE_COPY_NAMESPACES"  "PreserveMode"  "COMMA"  "InheritMode" },


"PreserveMode",
{ "PRESERVE" },
{ "NO_PRESERVE" },


"InheritMode",
{ "INHERIT" },
{ "NO_INHERIT" },


"DefaultCollationDecl",
{ "DECLARE_DEFAULT_COLLATION"  "URI_LITERAL" },


"BaseURIDecl",
{ "DECLARE_BASE_URI"  "URI_LITERAL" },


"SchemaImport",
{ "IMPORT_SCHEMA"  "URI_LITERAL" },
{ "IMPORT_SCHEMA"  "SchemaPrefix"  "URI_LITERAL" },
{ "IMPORT_SCHEMA"  "URI_LITERAL"  "AT"  "URILiteralList" },
{ "IMPORT_SCHEMA"  "SchemaPrefix"  "URI_LITERAL"  "AT"  "URILiteralList" },


"URILiteralList",
{ "URI_LITERAL" },
{ "URILiteralList"  "COMMA"  "URI_LITERAL" },



"SchemaPrefix",
{ "NAMESPACE"  "NCNAME"  "EQUALS" },
{ "DEFAULT_ELEMENT"  "NAMESPACE" },


"ModuleImport",
{ "IMPORT_MODULE"  "URI_LITERAL" },
{ "IMPORT_MODULE"  "NAMESPACE"  "NCNAME"  "EQUALS"  "URI_LITERAL" },
{ "IMPORT_MODULE"  "URI_LITERAL"  "AT"  "URILiteralList" },
{ "IMPORT_MODULE"  "NAMESPACE"  "NCNAME"  "EQUALS"  "URI_LITERAL"  "AT"  "URILiteralList" },



"VarDecl",
{ "DECLARE_VARIABLE_DOLLAR"  "VARNAME"  "GETS"  "ExprSingle" },
{ "DECLARE_VARIABLE_DOLLAR"  "VARNAME"  "EXTERNAL" },
{ "DECLARE_VARIABLE_DOLLAR"  "VARNAME"  "TypeDeclaration"  "GETS"  "ExprSingle" },
{ "DECLARE_VARIABLE_DOLLAR"  "VARNAME"  "TypeDeclaration"  "EXTERNAL" },


"ConstructionDecl",
{ "DECLARE_CONSTRUCTION"  "PRESERVE" },
{ "DECLARE_CONSTRUCTION"  "STRIP" },


"FunctionDecl",
{ "DECLARE_FUNCTION"  "QNAME_LPAR"  "RPAR"  "EXTERNAL" },
{ "DECLARE_FUNCTION"  "QNAME_LPAR"  "RPAR"  "EnclosedExpr" },
{ "DECLARE_FUNCTION"  "QNAME_LPAR"  "ParamList"  "RPAR"  "EXTERNAL" },
{ "DECLARE_FUNCTION"  "QNAME_LPAR"  "ParamList"  "RPAR"  "EnclosedExpr" },
{ "DECLARE_FUNCTION"  "QNAME_LPAR"  "RPAR_AS"  "SequenceType"  "EXTERNAL" },
{ "DECLARE_FUNCTION"  "QNAME_LPAR"  "RPAR_AS"  "SequenceType"  "EnclosedExpr" },
{ "DECLARE_FUNCTION"  "QNAME_LPAR"  "ParamList"  "RPAR_AS"  "SequenceType"  "EXTERNAL" },
{ "DECLARE_FUNCTION"  "QNAME_LPAR"  "ParamList"  "RPAR_AS"  "SequenceType"  "EnclosedExpr" },
{ "DECLARE_UPDATING_FUNCTION"  "QNAME_LPAR"  "RPAR"  "EXTERNAL" },
{ "DECLARE_UPDATING_FUNCTION"  "QNAME_LPAR"  "RPAR"  "EnclosedExpr" },
{ "DECLARE_UPDATING_FUNCTION"  "QNAME_LPAR"  "ParamList"  "RPAR"  "EXTERNAL" },
{ "DECLARE_UPDATING_FUNCTION"  "QNAME_LPAR"  "ParamList"  "RPAR"  "EnclosedExpr" },
{ "DECLARE_UPDATING_FUNCTION"  "QNAME_LPAR"  "RPAR_AS"  "SequenceType"  "EXTERNAL" },
{ "DECLARE_UPDATING_FUNCTION"  "QNAME_LPAR"  "RPAR_AS"  "SequenceType"  "EnclosedExpr" },
{ "DECLARE_UPDATING_FUNCTION"  "QNAME_LPAR"  "ParamList"  "RPAR_AS"  "SequenceType"  "EXTERNAL" },
{ "DECLARE_UPDATING_FUNCTION"  "QNAME_LPAR"  "ParamList"  "RPAR_AS"  "SequenceType"  "EnclosedExpr" },


"ParamList",
{ "Param" },
{ "ParamList"  "COMMA"  "Param" },


"Param",
{ "DOLLAR"  "VARNAME" },
{ "DOLLAR"  "VARNAME"  "TypeDeclaration" },


"EnclosedExpr",
{ "LBRACE"  "Expr"  "RBRACE" },


"QueryBody",
{ "Expr" },


"Expr",
{ "ExprSingle" },
{ "Expr"  "COMMA"  "ExprSingle" },


"ExprSingle",
{ "FLWORExpr" },
{ "QuantifiedExpr" },
{ "TypeswitchExpr" },
{ "IfExpr" },
{ "OrExpr" },
{ "InsertExpr" },
{ "DeleteExpr" },
{ "RenameExpr" },
{ "ReplaceExpr" },
{ "TransformExpr" },


"FLWORExpr",
{ "ForLetClauseList"  "RETURN"  "ExprSingle" },
{ "ForLetClauseList"  "WhereClause"  "RETURN"  "ExprSingle" },
{ "ForLetClauseList"  "OrderByClause"  "RETURN"  "ExprSingle" },
{ "ForLetClauseList"  "WhereClause"  "OrderByClause"  "RETURN"  "ExprSingle" },


"ForLetClauseList",
{ "ForLetClause" },
{ "ForLetClauseList"  "ForLetClause" },


"ForLetClause",
{ "ForClause" },
{ "LetClause" },


"ForClause",
{ "FOR_DOLLAR"  "VarInDeclList" },


"VarInDeclList",
{ "VarInDecl" },
{ "VarInDeclList"  "COMMA"  "DOLLAR"  "VarInDecl" },


"VarInDecl",
{ "VARNAME"  "IN"  "ExprSingle" },
{ "VARNAME"  "TypeDeclaration"  "IN"  "ExprSingle" },
{ "VARNAME"  "PositionalVar"  "IN"  "ExprSingle" },
{ "VARNAME"  "TypeDeclaration"  "PositionalVar"  "IN"  "ExprSingle" },
{ "VARNAME"  "FTScoreVar"  "IN"  "ExprSingle" },
{ "VARNAME"  "TypeDeclaration"  "FTScoreVar"  "IN"  "ExprSingle" },
{ "VARNAME"  "PositionalVar"  "FTScoreVar"  "IN"  "ExprSingle" },
{ "VARNAME"  "TypeDeclaration"  "PositionalVar"  "FTScoreVar"  "IN"  "ExprSingle" },


"PositionalVar",
{ "AT"  "DOLLAR"  "VARNAME" },


{ "/* full-text extension */" },
"FTScoreVar",
{ "SCORE"  "DOLLAR"  "VARNAME" },


"LetClause",
{ "LET_DOLLAR VarGetsDeclList" },
{ "	" },


"VarGetsDeclList",
{ "VarGetsDecl" },
{ "VarGetsDeclList"  "COMMA"  "DOLLAR"  "VarGetsDecl" },


"VarGetsDecl",
{ "VARNAME"  "GETS"  "ExprSingle" },
{ "VARNAME"  "TypeDeclaration"  "GETS"  "ExprSingle" },
{ "VARNAME"  "FTScoreVar"  "GETS"  "ExprSingle" },
{ "VARNAME"  "TypeDeclaration"  "FTScoreVar"  "GETS"  "ExprSingle" },



"WhereClause",
{ "WHERE"  "ExprSingle" },


"OrderByClause",
{ "ORDER_BY"  "OrderSpecList" },
{ "STABLE_ORDER_BY"  "OrderSpecList" },
{ "						true);" },


"OrderSpecList",
{ "OrderSpec" },
{ "OrderSpecList"  "COMMA"  "OrderSpec" },


"OrderSpec",
{ "ExprSingle" },
{ "ExprSingle OrderModifier" },


"OrderModifier",
{ "OrderDirSpec" },
{ "OrderEmptySpec" },
{ "OrderCollationSpec" },
{ "OrderDirSpec"  "OrderEmptySpec" },
{ "OrderDirSpec"  "OrderCollationSpec" },
{ "OrderEmptySpec"  "OrderCollationSpec" },
{ "OrderDirSpec"  "OrderEmptySpec"  "OrderCollationSpec" },


"OrderDirSpec",
{ "ASCENDING" },
{ "DESCENDING" },


{ "OrderEmptySpec:" },
{ "EMPTY_GREATEST" },
{ "EMPTY_LEAST" },


"OrderCollationSpec",
{ "COLLATION"  "URI_LITERAL" },


"QuantifiedExpr",
{ "SOME_DOLLAR"  "QVarInDeclList"  "SATISFIES"  "ExprSingle" },
{ "EVERY_DOLLAR"  "QVarInDeclList"  "SATISFIES"  "ExprSingle" },


"QVarInDeclList",
{ "QVarInDecl"  "%prec QVARINDECLLIST_REDUCE" },
{ "QVarInDecl"  "COMMA_DOLLAR"  "QVarInDeclList" },


"QVarInDecl",
{ "VARNAME"  "IN"  "ExprSingle" },
{ "VARNAME"  "TypeDeclaration"  "IN"  "ExprSingle" },


"TypeswitchExpr",
{ "TYPESWITCH_LPAR"  "Expr"  "RPAR"  "CaseClauseList"  "DEFAULT"  "RETURN"  "ExprSingle" },
{ "TYPESWITCH_LPAR"  "Expr"  "RPAR"  "CaseClauseList"  "DEFAULT"  "DOLLAR"  "VARNAME"  "RETURN"  "ExprSingle" },


"CaseClauseList",
{ "CaseClause" },
{ "CaseClauseList"  "CaseClause" },


"CaseClause",
{ "CASE"  "SequenceType"  "RETURN"  "ExprSingle" },
{ "CASE"  "DOLLAR"  "VARNAME"  "AS"  "SequenceType"  "RETURN"  "ExprSingle" },


"IfExpr",
{ "IF_LPAR"  "Expr"  "RPAR"  "THEN"  "ExprSingle"  "ELSE"  "ExprSingle" },


"OrExpr",
{ "AndExpr" },
{ "OrExpr"  "OR"  "AndExpr" },


"AndExpr",
{ "ComparisonExpr" },
{ "AndExpr"  "AND"  "ComparisonExpr" },


"ComparisonExpr",
{ "FTContainsExpr" },
{ "FTContainsExpr"  "ValueComp"  "FTContainsExpr" },
{ "FTContainsExpr"  "GeneralComp"  "FTContainsExpr" },
{ "FTContainsExpr"  "NodeComp"  "FTContainsExpr" },


"FTContainsExpr",
{ "RangeExpr"  "%prec FTCONTAINS_REDUCE" },
{ "RangeExpr"  "FTCONTAINS"  "FTSelection" },
{ "RangeExpr"  "FTCONTAINS"  "FTSelection"  "FTIgnoreOption" },


"RangeExpr",
{ "AdditiveExpr"  "%prec RANGE_REDUCE" },
{ "AdditiveExpr"  "TO"  "AdditiveExpr" },


"AdditiveExpr",
{ "MultiplicativeExpr"  "%prec ADDITIVE_REDUCE" },
{ "AdditiveExpr"  "PLUS"  "MultiplicativeExpr" },
{ "						AdditiveExpr::plus," },
{ "AdditiveExpr"  "MINUS"  "MultiplicativeExpr" },
{ "						AdditiveExpr::minus," },


"MultiplicativeExpr",
{ "UnionExpr"  "%prec MULTIPLICATIVE_REDUCE" },
{ "MultiplicativeExpr"  "STAR"  "UnionExpr" },
{ "MultiplicativeExpr"  "DIV"  "UnionExpr" },
{ "MultiplicativeExpr"  "IDIV"  "UnionExpr" },
{ "MultiplicativeExpr"  "MOD"  "UnionExpr" },


"UnionExpr",
{ "IntersectExceptExpr"  "%prec UNION_REDUCE" },
{ "UnionExpr"  "UNION"  "IntersectExceptExpr" },
{ "UnionExpr"  "VBAR"  "IntersectExceptExpr" },


"IntersectExceptExpr",
{ "InstanceofExpr"  "%prec INTERSECT_EXCEPT_REDUCE" },
{ "IntersectExceptExpr"  "INTERSECT"  "InstanceofExpr" },
{ "IntersectExceptExpr"  "EXCEPT"  "InstanceofExpr" },


"InstanceofExpr",
{ "TreatExpr" },
{ "TreatExpr"  "INSTANCE_OF"  "SequenceType" },


"TreatExpr",
{ "CastableExpr" },
{ "CastableExpr"  "TREAT_AS"  "SequenceType" },


"CastableExpr",
{ "CastExpr" },
{ "CastExpr"  "CASTABLE_AS"  "SingleType" },


"CastExpr",
{ "UnaryExpr" },
{ "UnaryExpr"  "CAST_AS"  "SingleType" },


"UnaryExpr",
{ "ValueExpr" },
{ "SignList"  "ValueExpr" },


"SignList",
{ "PLUS" },
{ "MINUS" },
{ "SignList"  "PLUS" },
{ "SignList"  "MINUS" },


"ValueExpr",
{ "ValidateExpr" },
{ "PathExpr" },
{ "ExtensionExpr" },


"GeneralComp",
{ "EQUALS" },
{ "NE" },
{ "LT" },
{ "LE" },
{ "GT" },
{ "GE" },


"ValueComp",
{ "VAL_EQ" },
{ "VAL_NE" },
{ "VAL_LT" },
{ "VAL_LE" },
{ "VAL_GT" },
{ "VAL_GE" },


"NodeComp",
{ "IS" },
{ "PRECEDES" },
{ "FOLLOWS" },



"ValidateExpr",
{ "VALIDATE_LBRACE"  "Expr"  "RBRACE" },
{ "VALIDATE_MODE"  "LBRACE"  "Expr"  "RBRACE" },


"ExtensionExpr",
{ "PragmaList"  "LBRACE"  "RBRACE" },
{ "PragmaList"  "LBRACE"  "Expr"  "RBRACE" },


"PragmaList",
{ "Pragma" },
{ "PragmaList"  "Pragma" },


"Pragma",
{ "PRAGMA_BEGIN"  "QNAME"  "PRAGMA_LITERAL"  "PRAGMA_END" },



"PathExpr",
{ "LEADING_LONE_SLASH" },
{ "SLASH"  "RelativePathExpr" },
{ "SLASH_SLASH"  "RelativePathExpr" },
{ "RelativePathExpr" },


"RelativePathExpr",
{ "StepExpr"  "%prec STEP_REDUCE" },
{ "StepExpr"  "SLASH"  "RelativePathExpr" },
{ "StepExpr"  "SLASH_SLASH"  "RelativePathExpr" },


"StepExpr",
{ "AxisStep" },
{ "FilterExpr" },


"AxisStep",
{ "ForwardStep" },
{ "ForwardStep"  "PredicateList" },
{ "ReverseStep" },
{ "ReverseStep"  "PredicateList" },


"ForwardStep",
{ "ForwardAxis"  "NodeTest" },
{ "AbbrevForwardStep" },


"ForwardAxis",
{ "CHILD_AXIS" },
{ "DESCENDANT_AXIS" },
{ "ATTRIBUTE_AXIS" },
{ "SELF_AXIS" },
{ "DESCENDANT_OR_SELF_AXIS" },
{ "FOLLOWING_SIBLING_AXIS" },
{ "FOLLOWING_AXIS" },


"AbbrevForwardStep",
{ "NodeTest" },
{ "AT_SIGN"  "NodeTest" },
{ "						true);" },


"ReverseStep",
{ "ReverseAxis"  "NodeTest" },
{ "DOT_DOT" },


"ReverseAxis",
{ "PARENT_AXIS" },
{ "ANCESTOR_AXIS" },
{ "PRECEDING_SIBLING_AXIS" },
{ "PRECEDING_AXIS" },
{ "ANCESTOR_OR_SELF_AXIS" },


"NodeTest",
{ "KindTest" },
{ "NameTest" },


"NameTest",
{ "QNAME" },
{ "Wildcard" },


"Wildcard",
{ "STAR" },
{ "ELEM_WILDCARD" },
{ "PREFIX_WILDCARD" },


"FilterExpr",
{ "PrimaryExpr" },
{ "PrimaryExpr"  "PredicateList" },


"PredicateList",
{ "Predicate" },
{ "PredicateList"  "Predicate" },


"Predicate",
{ "LBRACK"  "Expr"  "RBRACK" },



"PrimaryExpr",
{ "Literal" },
{ "VarRef" },
{ "ParenthesizedExpr" },
{ "ContextItemExpr" },
{ "FunctionCall" },
{ "Constructor" },
{ "OrderedExpr" },
{ "UnorderedExpr" },


"Literal",
{ "NumericLiteral" },
{ "StringLiteral" },


"NumericLiteral",
{ "INTEGER_LITERAL" },
{ "DECIMAL_LITERAL" },
{ "DOUBLE_LITERAL" },


"VarRef",
{ "DOLLAR"  "VARNAME" },


"ParenthesizedExpr",
{ "LPAR"  "RPAR" },
{ "LPAR"  "Expr"  "RPAR" },


"ContextItemExpr",
{ "DOT" },


"OrderedExpr",
{ "ORDERED_LBRACE"  "Expr"  "RBRACE" },


"UnorderedExpr",
{ "UNORDERED_LBRACE"  "Expr"  "RBRACE" },


"FunctionCall",
{ "QNAME_LPAR"  "RPAR" },
{ "QNAME_LPAR"  "ArgList"  "RPAR" },


"ArgList",
{ "ExprSingle" },
{ "ArgList"  "COMMA"  "ExprSingle" },


"Constructor",
{ "DirectConstructor" },
{ "ComputedConstructor" },


"DirectConstructor",
{ "DirElemConstructor" },
{ "DirCommentConstructor" },
{ "DirPIConstructor" },

"DirElemConstructor",
{ "START_TAG"  "QNAME"  "EMPTY_TAG_END" },
{ "START_TAG"  "QNAME"  "DirAttributeList EMPTY_TAG_END" },
{ "START_TAG"  "QNAME"  "TAG_END"  "DirElemContentList"  "START_TAG_END"  "QNAME"  "TAG_END" },
{ "START_TAG"  "QNAME"  "DirAttributeList TAG_END"  "DirElemContentList"  "START_TAG_END"  "QNAME"  "TAG_END" },


"DirElemContentList",
{ "DirElemContent" },
{ "DirElemContentList"  "DirElemContent" },


"DirAttributeList",
{ "DirAttr" },
{ "DirAttributeList"  "DirAttr" },


"DirAttr",
{ "QNAME"  "EQUALS"  "DirAttributeValue" },


"DirAttributeValue",
{ "QUOTE"  "QuoteAttrContentList"  "QUOTE" },
{ "APOS"  "AposAttrContentList"  "APOS" },


"QuoteAttrContentList",
{ "ESCAPE_QUOTE" },
{ "QuoteAttrValueContent" },
{ "QuoteAttrContentList"  "ESCAPE_QUOTE" },
{ "QuoteAttrContentList"  "QuoteAttrValueContent" },


"AposAttrContentList",
{ "ESCAPE_APOS" },
{ "AposAttrValueContent" },
{ "AposAttrContentList"  "ESCAPE_APOS" },
{ "AposAttrContentList"  "AposAttrValueContent" },


"QuoteAttrValueContent",
{ "QUOTE_ATTR_CONTENT" },
{ "CommonContent" },


"AposAttrValueContent",
{ "APOS_ATTR_CONTENT" },
{ "CommonContent" },


"DirElemContent",
{ "DirectConstructor" },
{ "ELEMENT_CONTENT" },
{ "CDataSection" },
{ "CommonContent" },


"CommonContent",
{ "ENTITY_REF" },
{ "CHAR_REF_LITERAL" },
{ "DOUBLE_LBRACE" },
{ "DOUBLE_RBRACE" },
{ "EnclosedExpr" },


"DirCommentConstructor",
{ "XML_COMMENT_BEGIN"  "EXPR_COMMENT_LITERAL"  "XML_COMMENT_END" },



"DirPIConstructor",
{ "PI_BEGIN"  "PI_TARGET_LITERAL"  "PI_END" },
{ "PI_BEGIN"  "PI_TARGET_LITERAL"  "CHAR_LITERAL"  "PI_END" },



"CDataSection",
{ "CDATA_BEGIN"  "CHAR_LITERAL"  "CDATA_END" },


"ComputedConstructor",
{ "CompDocConstructor" },
{ "CompElemConstructor" },
{ "CompAttrConstructor" },
{ "CompTextConstructor" },
{ "CompCommentConstructor" },
{ "CompPIConstructor" },


"CompDocConstructor",
{ "DOCUMENT_LBRACE"  "Expr"  "RBRACE" },


"CompElemConstructor",
{ "ELEMENT_QNAME_LBRACE"  "RBRACE" },
{ "ELEMENT_QNAME_LBRACE"  "Expr"  "RBRACE" },
{ "ELEMENT_LBRACE"  "Expr"  "RBRACE"  "LBRACE"  "RBRACE" },
{ "ELEMENT_LBRACE"  "Expr"  "RBRACE"  "LBRACE"  "Expr"  "RBRACE" },



"CompAttrConstructor",
{ "ATTRIBUTE_QNAME_LBRACE"  "RBRACE" },
{ "ATTRIBUTE_QNAME_LBRACE"  "Expr"  "RBRACE" },
{ "ATTRIBUTE_LBRACE"  "Expr"  "RBRACE"  "LBRACE"  "RBRACE" },
{ "ATTRIBUTE_LBRACE"  "Expr"  "RBRACE"  "LBRACE"  "Expr"  "RBRACE" },


"CompTextConstructor",
{ "TEXT_LBRACE"  "Expr"  "RBRACE" },


"CompCommentConstructor",
{ "COMMENT_LBRACE"  "Expr"  "RBRACE" },


"CompPIConstructor",
{ "PROCESSING_INSTRUCTION"  "NCNAME"  "LBRACE"  "RBRACE" },
{ "PROCESSING_INSTRUCTION"  "NCNAME"  "LBRACE"  "Expr"  "RBRACE" },
{ "PROCESSING_INSTRUCTION"  "LBRACE"  "Expr"  "RBRACE LBRACE"  "RBRACE" },
{ "PROCESSING_INSTRUCTION"  "LBRACE"  "Expr"  "RBRACE LBRACE"  "Expr"  "RBRACE" },


"SingleType",
{ "AtomicType" },
{ "AtomicType"  "HOOK" },


"TypeDeclaration",
{ "AS"  "SequenceType" },


"SequenceType",
{ "ItemType"  "%prec SEQUENCE_TYPE_REDUCE" },
{ "ItemType"  "OccurrenceIndicator" },
{ "VOID_TEST" },


"OccurrenceIndicator",
{ "OCCURS_HOOK" },
{ "OCCURS_STAR" },
{ "OCCURS_PLUS" },


"ItemType",
{ "AtomicType" },
{ "KindTest" },
{ "ITEM_TEST" },


"AtomicType",
{ "QNAME" },


"KindTest",
{ "DocumentTest" },
{ "ElementTest" },
{ "AttributeTest" },
{ "SchemaElementTest" },
{ "SchemaAttributeTest" },
{ "PITest" },
{ "CommentTest" },
{ "TextTest" },
{ "AnyKindTest" },


"AnyKindTest",
{ "NODE_LPAR"  "RPAR" },


"DocumentTest",
{ "DOCUMENT_NODE_LPAR"  "RPAR" },
{ "DOCUMENT_NODE_LPAR"  "ElementTest"  "RPAR" },
{ "DOCUMENT_NODE_LPAR"  "SchemaElementTest"  "RPAR" },


"TextTest",
{ "TEXT_LPAR"  "RPAR" },


"CommentTest",
{ "COMMENT_LPAR"  "RPAR" },


"PITest",
{ "PI_LPAR"  "RPAR" },
{ "PI_LPAR"  "NCNAME"  "RPAR" },
{ "PI_LPAR"  "STRING_LITERAL"  "RPAR" },


"AttributeTest",
{ "ATTRIBUTE_LPAR"  "RPAR" },
{ "ATTRIBUTE_LPAR"  "AttribNameOrWildcard"  "RPAR" },
{ "ATTRIBUTE_LPAR"  "AttribNameOrWildcard"  "COMMA"  "TypeName"  "RPAR" },


"AttribNameOrWildcard",
{ "AttributeName" },
{ "STAR" },


"SchemaAttributeTest",
{ "SCHEMA_ATTRIBUTE_LPAR"  "AttributeDeclaration"  "RPAR" },


"AttributeDeclaration",
{ "AttributeName" },


"ElementTest",
{ "ELEMENT_LPAR"  "RPAR" },
{ "ELEMENT_LPAR"  "ElementNameOrWildcard"  "RPAR" },
{ "ELEMENT_LPAR"  "ElementNameOrWildcard"  "COMMA"  "TypeName"  "RPAR" },
{ "ELEMENT_LPAR"  "ElementNameOrWildcard"  "COMMA"  "TypeName"  "HOOK"  "RPAR" },


"ElementNameOrWildcard",
{ "ElementName" },
{ "STAR" },


"SchemaElementTest",
{ "SCHEMA_ELEMENT_LPAR"  "ElementDeclaration"  "RPAR" },


"ElementDeclaration",
{ "ElementName" },


"AttributeName",
{ "QNAME" },


"ElementName",
{ "QNAME" },


"TypeName",
{ "QNAME" },


"StringLiteral",
{ "STRING_LITERAL" },



"RevalidationDecl",
{ "DECLARE_REVALIDATION_MODE" },


"InsertExpr",
{ "DO_INSERT"  "ExprSingle"  "INTO"  "ExprSingle" },
{ "DO_INSERT"  "ExprSingle"  "AS"  "FIRST_INTO"  "ExprSingle" },
{ "DO_INSERT"  "ExprSingle"  "AS"  "LAST_INTO"  "ExprSingle" },
{ "DO_INSERT"  "ExprSingle"  "AFTER"  "ExprSingle" },
{ "DO_INSERT"  "ExprSingle"  "BEFORE"  "ExprSingle" },


{ "DeleteExpr:" },
{ "DO_DELETE"  "ExprSingle" },


"ReplaceExpr",
{ "DO_REPLACE"  "ExprSingle"  "WITH"  "ExprSingle" },
{ "DO_REPLACE"  "VALUE_OF"  "ExprSingle"  "WITH"  "ExprSingle" },


"RenameExpr",
{ "DO_RENAME"  "ExprSingle"  "AS"  "ExprSingle" },



"TransformExpr",
{ "TRANSFORM_COPY_DOLLAR"  "VarNameList"  "MODIFY"  "ExprSingle"  "RETURN"  "ExprSingle" },


"VarNameList",
{ "VARNAME	 GETS"  "ExprSingle" },
{ "VarNameList"  "COMMA_DOLLAR"  "VARNAME"  "GETS"  "ExprSingle" },




"FTSelection",
{ "FTOr" },
{ "FTOr"  "FTMatchOptionProximityList" },
{ "FTOr"  "WEIGHT"  "RangeExpr" },
{ "FTOr"  "FTMatchOptionProximityList"  "WEIGHT"  "RangeExpr" },


"FTMatchOptionProximityList",
{ "FTMatchOption" },
{ "FTProximity" },
{ "FTMatchOptionProximityList"  "FTMatchOption" },
{ "FTMatchOptionProximityList"  "FTProximity" },


"FTOr",
{ "FTAnd" },
{ "FTOr"  "FTOR"  "FTAnd" },


"FTAnd",
{ "FTMildnot" },
{ "FTAnd"  "FTAND"  "FTMildnot" },


"FTMildnot",
{ "FTUnaryNot" },
{ "FTMildnot"  "FTNOT_IN"  "FTUnaryNot" },


"FTUnaryNot",
{ "FTWordsSelection" },
{ "FTNOT"  "FTWordsSelection" },


"FTWordsSelection",
{ "FTWords" },
{ "FTWords FTTimes" },
{ "LPAR"  "FTSelection"  "RPAR" },


"FTWords",
{ "FTWordsValue" },
{ "FTWordsValue"  "FTAnyallOption" },


"FTWordsValue",
{ "Literal" },
{ "LBRACE"  "Expr"  "RBRACE" },


"FTProximity",
{ "FTOrderedIndicator" },
{ "FTWindow" },
{ "FTDistance" },
{ "FTScope" },
{ "FTContent" },


"FTOrderedIndicator",
{ "ORDERED" },


"FTMatchOption",
{ "FTCaseOption" },
{ "FTDiacriticsOption" },
{ "FTStemOption" },
{ "FTThesaurusOption" },
{ "FTStopwordOption" },
{ "FTLanguageOption" },
{ "FTWildCardOption" },


"FTCaseOption",
{ "LOWERCASE" },
{ "UPPERCASE" },
{ "CASE_SENSITIVE" },
{ "CASE_INSENSITIVE" },


"FTDiacriticsOption",
{ "WITH_DIACRITICS" },
{ "WITHOUT_DIACRITICS" },
{ "DIACRITICS_SENSITIVE" },
{ "DIACRITICS_INSENSITIVE" },


"FTStemOption",
{ "WITH_STEMMING" },
{ "WITHOUT_STEMMING" },


"FTThesaurusOption",
{ "WITH_THESAURUS"  "FTThesaurusID" },
{ "WITH_THESAURUS"  "DEFAULT" },
{ "WITH_THESAURUS"  "LPAR"  "FTThesaurusID"  "RPAR" },
{ "WITH_THESAURUS"  "LPAR"  "FTThesaurusID COMMA"  "FTThesaurusList"  "RPAR" },
{ "WITH_THESAURUS"  "LPAR"  "DEFAULT"  "RPAR" },
{ "WITH_THESAURUS"  "LPAR"  "DEFAULT"  "COMMA"  "FTThesaurusList"  "RPAR" },
{ "WITHOUT_THESAURUS" },


"FTThesaurusList",
{ "FTThesaurusID" },
{ "FTThesaurusList"  "COMMA"  "FTThesaurusID" },


"FTThesaurusID",
{ "AT"  "STRING_LITERAL" },
{ "AT"  "STRING_LITERAL"  "RELATIONSHIP"  "STRING_LITERAL" },
{ "AT"  "STRING_LITERAL"  "FTRange"  "LEVELS" },
{ "AT"  "STRING_LITERAL"  "RELATIONSHIP"  "STRING_LITERAL"  "FTRange"  "LEVELS" },


"FTStopwordOption",
{ "WITH_STOP_WORDS"  "FTRefOrList" },
{ "WITH_STOP_WORDS"  "FTRefOrList"  "FTInclExclStringLiteralList" },
{ "WITH_DEFAULT_STOP_WORDS" },
{ "WITH_DEFAULT_STOP_WORDS"  "FTInclExclStringLiteralList" },
{ "WITHOUT_STOP_WORDS" },


"FTInclExclStringLiteralList",
{ "FTInclExclStringLiteral" },
{ "FTInclExclStringLiteralList"  "FTInclExclStringLiteral" },


"FTRefOrList",
{ "AT"  "STRING_LITERAL" },
{ "LPAR"  "FTStringLiteralList"  "RPAR" },


"FTStringLiteralList",
{ "STRING_LITERAL" },
{ "FTStringLiteralList"  "STRING_LITERAL" },


"FTInclExclStringLiteral",
{ "UNION"  "FTRefOrList" },
{ "EXCEPT"  "FTRefOrList" },


"FTLanguageOption",
{ "LANGUAGE"  "STRING_LITERAL" },


"FTWildCardOption",
{ "WITH_WILDCARDS" },
{ "WITHOUT_WILDCARDS" },


"FTContent",
{ "AT_START" },
{ "AT_END" },
{ "ENTIRE_CONTENT" },


"FTAnyallOption",
{ "ANY" },
{ "ANY_WORD" },
{ "ALL" },
{ "ALL_WORDS" },
{ "PHRASE" },


"FTRange",
{ "EXACTLY"  "UnionExpr" },
{ "AT_LEAST"  "UnionExpr" },
{ "AT_MOST"  "UnionExpr" },
{ "FROM"  "UnionExpr"  "TO"  "UnionExpr" },


"FTDistance",
{ "DISTANCE"  "FTRange"  "FTUnit" },


"FTWindow",
{ "WINDOW"  "UnionExpr"  "FTUnit" },


"FTTimes",
{ "OCCURS"  "FTRange"  "TIMES" },


"FTScope",
{ "SAME"  "FTBigUnit" },
{ "DIFFERENT"  "FTBigUnit" },


"FTUnit",
{ "WORDS" },
{ "SENTENCES" },
{ "PARAGRAPH" },


"FTBigUnit",
{ "SENTENCE" },
{ "PARAGRAPH" },


"FTIgnoreOption",
{ "WITHOUT_CONTENT"  "UnionExpr" },

