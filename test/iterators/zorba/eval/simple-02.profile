{
    "iterator-tree": {
        "kind": "FLWORIterator",
        "prof-calls": 1,
        "prof-next-calls": "REMOVED",
        "prof-cpu": "REMOVED",
        "prof-wall": "REMOVED",
        "prof-name": "FLWORIterator",
        "iterators": [
            {
                "kind": "ForVariable",
                "name": "i",
                "iterators": [
                    {
                        "kind": "OpToIterator",
                        "prof-calls": 1,
                        "prof-next-calls": "REMOVED",
                        "prof-cpu": "REMOVED",
                        "prof-wall": "REMOVED",
                        "prof-name": "op:to",
                        "iterators": [
                            {
                                "kind": "SingletonIterator",
                                "value": "xs:integer(1)",
                                "prof-calls": 1,
                                "prof-next-calls": "REMOVED",
                                "prof-cpu": "REMOVED",
                                "prof-wall": "REMOVED",
                                "prof-name": "SingletonIterator"
                            },
                            {
                                "kind": "SingletonIterator",
                                "value": "xs:integer(3)",
                                "prof-calls": 1,
                                "prof-next-calls": "REMOVED",
                                "prof-cpu": "REMOVED",
                                "prof-wall": "REMOVED",
                                "prof-name": "SingletonIterator"
                            }
                        ]
                    }
                ]
            },
            {
                "kind": "ReturnClause",
                "prof-calls": 3,
                "prof-next-calls": "REMOVED",
                "prof-cpu": "REMOVED",
                "prof-wall": "REMOVED",
                "prof-name": "EvalIterator",
                "iterators": [
                    {
                        "kind": "EvalIterator",
                        "prof-calls": 3,
                        "prof-next-calls": "REMOVED",
                        "prof-cpu": "REMOVED",
                        "prof-wall": "REMOVED",
                        "prof-name": "EvalIterator",
                        "prof-compilation-cpu": "REMOVED",
                        "prof-compilation-wall": "REMOVED",
                        "iterators": [
                            {
                                "kind": "EvalQueryIterator",
                                "prof-name": "EvalQueryIterator",
                                "prof-calls": 1,
                                "prof-next-calls": "REMOVED",
                                "prof-cpu": "REMOVED",
                                "prof-wall": "REMOVED",
                                "prof-compilation-cpu": "REMOVED",
                                "prof-compilation-wall": "REMOVED",
                                "prof-body": "1+1",
                                "iterators": [
                                    {
                                        "kind": "SingletonIterator",
                                        "value": "xs:integer(2)",
                                        "prof-calls": 1,
                                        "prof-next-calls": "REMOVED",
                                        "prof-cpu": "REMOVED",
                                        "prof-wall": "REMOVED",
                                        "prof-name": "SingletonIterator"
                                    }
                                ]
                            },
                            {
                                "kind": "EvalQueryIterator",
                                "prof-name": "EvalQueryIterator",
                                "prof-calls": 1,
                                "prof-next-calls": "REMOVED",
                                "prof-cpu": "REMOVED",
                                "prof-wall": "REMOVED",
                                "prof-compilation-cpu": "REMOVED",
                                "prof-compilation-wall": "REMOVED",
                                "prof-body": "2+2",
                                "iterators": [
                                    {
                                        "kind": "SingletonIterator",
                                        "value": "xs:integer(4)",
                                        "prof-calls": 1,
                                        "prof-next-calls": "REMOVED",
                                        "prof-cpu": "REMOVED",
                                        "prof-wall": "REMOVED",
                                        "prof-name": "SingletonIterator"
                                    }
                                ]
                            },
                            {
                                "kind": "EvalQueryIterator",
                                "prof-name": "EvalQueryIterator",
                                "prof-calls": 1,
                                "prof-next-calls": "REMOVED",
                                "prof-cpu": "REMOVED",
                                "prof-wall": "REMOVED",
                                "prof-compilation-cpu": "REMOVED",
                                "prof-compilation-wall": "REMOVED",
                                "prof-body": "3+3",
                                "iterators": [
                                    {
                                        "kind": "SingletonIterator",
                                        "value": "xs:integer(6)",
                                        "prof-calls": 1,
                                        "prof-next-calls": "REMOVED",
                                        "prof-cpu": "REMOVED",
                                        "prof-wall": "REMOVED",
                                        "prof-name": "SingletonIterator"
                                    }
                                ]
                            },
                            {
                                "kind": "ConcatStrIterator",
                                "prof-calls": 3,
                                "prof-next-calls": "REMOVED",
                                "prof-cpu": "REMOVED",
                                "prof-wall": "REMOVED",
                                "prof-name": "fn:concat",
                                "iterators": [
                                    {
                                        "kind": "ForVarIterator",
                                        "varname": "i",
                                        "prof-calls": 3,
                                        "prof-next-calls": "REMOVED",
                                        "prof-cpu": "REMOVED",
                                        "prof-wall": "REMOVED",
                                        "prof-name": "ForVarIterator"
                                    },
                                    {
                                        "kind": "SingletonIterator",
                                        "value": "xs:string(+)",
                                        "prof-calls": 3,
                                        "prof-next-calls": "REMOVED",
                                        "prof-cpu": "REMOVED",
                                        "prof-wall": "REMOVED",
                                        "prof-name": "SingletonIterator"
                                    },
                                    {
                                        "kind": "ForVarIterator",
                                        "varname": "i",
                                        "prof-calls": 3,
                                        "prof-next-calls": "REMOVED",
                                        "prof-cpu": "REMOVED",
                                        "prof-wall": "REMOVED",
                                        "prof-name": "ForVarIterator"
                                    }
                                ]
                            },
                            {
                                "kind": "ForVarIterator",
                                "varname": "i",
                                "prof-calls": 3,
                                "prof-next-calls": "REMOVED",
                                "prof-cpu": "REMOVED",
                                "prof-wall": "REMOVED",
                                "prof-name": "ForVarIterator"
                            }
                        ]
                    }
                ]
            }
        ]
    }
}