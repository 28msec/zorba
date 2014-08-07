{
  "iterator-tree":
    {
      "kind": "FnConcatIterator",
      "prof-calls": 1,
      "prof-next-calls": 15,
      "prof-cpu": 0.57497,
      "prof-wall": 0.575301,
      "prof-name": "op:concatenate",
      "iterators": [
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.363887,
          "prof-wall": 0.364481,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 0,
          "prof-cache-misses": 1,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(2)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.001193,
              "prof-wall": 0.000982,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.034287,
              "prof-wall": 0.03422,
              "prof-name": "FLWORIterator",
              "iterators": [
                {
                  "kind": "ForVariable",
                  "name": "x",
                  "iterators": [
                    {
                      "kind": "LetVarIterator",
                      "varname": "x",
                      "prof-calls": 1,
                      "prof-next-calls": 2,
                      "prof-cpu": 0.005807,
                      "prof-wall": 0.005814,
                      "prof-name": "LetVarIterator"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 2,
                  "prof-cpu": 0.018813,
                  "prof-wall": 0.018829,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 2,
                      "prof-cpu": 0.018813,
                      "prof-wall": 0.018829,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 2,
                          "prof-cpu": 0.004511,
                          "prof-wall": 0.004531,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.000661,
                              "prof-wall": 0.000683,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.000461,
                              "prof-wall": 0.000488,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 2,
                          "prof-cpu": 0.007629,
                          "prof-wall": 0.007694,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 1,
                              "prof-cpu": 0.00026,
                              "prof-wall": 0.000281,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 1,
                              "prof-cpu": 0.000212,
                              "prof-wall": 0.000218,
                              "prof-name": "ForVarIterator"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0,
                                      "prof-wall": 0,
                                      "prof-name": "ForVarIterator"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0,
                                      "prof-wall": 0,
                                      "prof-name": "ForVarIterator"
                                    }
                                  ]
                                }
                              ]
                            }
                          ]
                        }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        },
        {
          "kind": "SingletonIterator",
          "value": "xs:string(\n)",
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.000617,
          "prof-wall": 0.000676,
          "prof-name": "SingletonIterator"
        },
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 1,
          "prof-cpu": 0.058407,
          "prof-wall": 0.058652,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 0,
          "prof-cache-misses": 1,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(12)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.000693,
              "prof-wall": 0.000623,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 1,
              "prof-cpu": 0.014334,
              "prof-wall": 0.014213,
              "prof-name": "FLWORIterator",
              "iterators": [
                {
                  "kind": "ForVariable",
                  "name": "x",
                  "iterators": [
                    {
                      "kind": "LetVarIterator",
                      "varname": "x",
                      "prof-calls": 1,
                      "prof-next-calls": 2,
                      "prof-cpu": 0.002659,
                      "prof-wall": 0.002681,
                      "prof-name": "LetVarIterator"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 1,
                  "prof-cpu": 0.009191,
                  "prof-wall": 0.009196,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 1,
                      "prof-cpu": 0.009191,
                      "prof-wall": 0.009196,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 2,
                          "prof-cpu": 0.003441,
                          "prof-wall": 0.003474,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.000503,
                              "prof-wall": 0.000511,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.00047,
                              "prof-wall": 0.000496,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 1,
                          "prof-cpu": 0.004197,
                          "prof-wall": 0.004216,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.002724,
                              "prof-wall": 0.002788,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.000456,
                                  "prof-wall": 0.000479,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.000484,
                                  "prof-wall": 0.000509,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 1,
                              "prof-cpu": 0.000337,
                              "prof-wall": 0.000347,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0,
                                      "prof-wall": 0,
                                      "prof-name": "ForVarIterator"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0,
                                      "prof-wall": 0,
                                      "prof-name": "ForVarIterator"
                                    }
                                  ]
                                }
                              ]
                            }
                          ]
                        }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        },
        {
          "kind": "SingletonIterator",
          "value": "xs:string(\n)",
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.000565,
          "prof-wall": 0.000575,
          "prof-name": "SingletonIterator"
        },
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.031097,
          "prof-wall": 0.03131,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 1,
          "prof-cache-misses": 0,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(2)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.000673,
              "prof-wall": 0.000582,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 0,
              "prof-cpu": 0,
              "prof-wall": 0,
              "prof-name": "FLWORIterator",
              "iterators": [
                {
                  "kind": "ForVariable",
                  "name": "x",
                  "iterators": [
                    {
                      "kind": "LetVarIterator",
                      "varname": "x",
                      "prof-calls": 1,
                      "prof-next-calls": 0,
                      "prof-cpu": 0,
                      "prof-wall": 0,
                      "prof-name": "LetVarIterator"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 0,
                  "prof-cpu": 0,
                  "prof-wall": 0,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 0,
                      "prof-cpu": 0,
                      "prof-wall": 0,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0,
                                      "prof-wall": 0,
                                      "prof-name": "ForVarIterator"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0,
                                      "prof-wall": 0,
                                      "prof-name": "ForVarIterator"
                                    }
                                  ]
                                }
                              ]
                            }
                          ]
                        }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        },
        {
          "kind": "SingletonIterator",
          "value": "xs:string(\n)",
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.00056,
          "prof-wall": 0.000558,
          "prof-name": "SingletonIterator"
        },
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 1,
          "prof-cpu": 0.023233,
          "prof-wall": 0.023386,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 1,
          "prof-cache-misses": 0,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(12)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.000674,
              "prof-wall": 0.000578,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 0,
              "prof-cpu": 0,
              "prof-wall": 0,
              "prof-name": "FLWORIterator",
              "iterators": [
                {
                  "kind": "ForVariable",
                  "name": "x",
                  "iterators": [
                    {
                      "kind": "LetVarIterator",
                      "varname": "x",
                      "prof-calls": 1,
                      "prof-next-calls": 0,
                      "prof-cpu": 0,
                      "prof-wall": 0,
                      "prof-name": "LetVarIterator"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 0,
                  "prof-cpu": 0,
                  "prof-wall": 0,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 0,
                      "prof-cpu": 0,
                      "prof-wall": 0,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0,
                                      "prof-wall": 0,
                                      "prof-name": "ForVarIterator"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0,
                                      "prof-wall": 0,
                                      "prof-name": "ForVarIterator"
                                    }
                                  ]
                                }
                              ]
                            }
                          ]
                        }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        },
        {
          "kind": "SingletonIterator",
          "value": "xs:string(\n)",
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.000552,
          "prof-wall": 0.000566,
          "prof-name": "SingletonIterator"
        },
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 4,
          "prof-cpu": 0.057659,
          "prof-wall": 0.057946,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 0,
          "prof-cache-misses": 1,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(22)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.00067,
              "prof-wall": 0.00058,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 4,
              "prof-cpu": 0.025168,
              "prof-wall": 0.025131,
              "prof-name": "FLWORIterator",
              "iterators": [
                {
                  "kind": "ForVariable",
                  "name": "x",
                  "iterators": [
                    {
                      "kind": "LetVarIterator",
                      "varname": "x",
                      "prof-calls": 1,
                      "prof-next-calls": 2,
                      "prof-cpu": 0.002888,
                      "prof-wall": 0.002906,
                      "prof-name": "LetVarIterator"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 4,
                  "prof-cpu": 0.018283,
                  "prof-wall": 0.018335,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 4,
                      "prof-cpu": 0.018283,
                      "prof-wall": 0.018335,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 2,
                          "prof-cpu": 0.003353,
                          "prof-wall": 0.003387,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.000507,
                              "prof-wall": 0.000534,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.000478,
                              "prof-wall": 0.000489,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 4,
                          "prof-cpu": 0.011934,
                          "prof-wall": 0.011993,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.002641,
                              "prof-wall": 0.002687,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.000468,
                                  "prof-wall": 0.000492,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.00047,
                                  "prof-wall": 0.000478,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 4,
                              "prof-cpu": 0.006828,
                              "prof-wall": 0.006875,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.000559,
                                  "prof-wall": 0.000579,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.000459,
                                  "prof-wall": 0.000481,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.003178,
                                  "prof-wall": 0.003225,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 1,
                                      "prof-cpu": 0.000257,
                                      "prof-wall": 0.000264,
                                      "prof-name": "ForVarIterator"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 1,
                                      "prof-cpu": 0.000284,
                                      "prof-wall": 0.000299,
                                      "prof-name": "ForVarIterator"
                                    }
                                  ]
                                }
                              ]
                            }
                          ]
                        }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        },
        {
          "kind": "SingletonIterator",
          "value": "xs:string(\n)",
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.000567,
          "prof-wall": 0.0006,
          "prof-name": "SingletonIterator"
        },
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 4,
          "prof-cpu": 0.023858,
          "prof-wall": 0.024041,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 1,
          "prof-cache-misses": 0,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(22)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.000664,
              "prof-wall": 0.000582,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 0,
              "prof-cpu": 0,
              "prof-wall": 0,
              "prof-name": "FLWORIterator",
              "iterators": [
                {
                  "kind": "ForVariable",
                  "name": "x",
                  "iterators": [
                    {
                      "kind": "LetVarIterator",
                      "varname": "x",
                      "prof-calls": 1,
                      "prof-next-calls": 0,
                      "prof-cpu": 0,
                      "prof-wall": 0,
                      "prof-name": "LetVarIterator"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 0,
                  "prof-cpu": 0,
                  "prof-wall": 0,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 0,
                      "prof-cpu": 0,
                      "prof-wall": 0,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "ForVarIterator"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0,
                          "prof-wall": 0,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0,
                              "prof-wall": 0,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "ForVarIterator"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0,
                                  "prof-wall": 0,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0,
                                      "prof-wall": 0,
                                      "prof-name": "ForVarIterator"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0,
                                      "prof-wall": 0,
                                      "prof-name": "ForVarIterator"
                                    }
                                  ]
                                }
                              ]
                            }
                          ]
                        }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        },
        {
          "kind": "SingletonIterator",
          "value": "xs:string(\n)",
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.000539,
          "prof-wall": 0.000561,
          "prof-name": "SingletonIterator"
        }
      ]
    }
}