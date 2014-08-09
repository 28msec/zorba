{
  "iterator-tree":
    {
      "kind": "FnConcatIterator",
      "prof-calls": 1,
      "prof-next-calls": 15,
      "prof-cpu": 1.45306,
      "prof-wall": 1.44988,
      "prof-name": "op:concatenate",
      "iterators": [
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.996801,
          "prof-wall": 0.994848,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 0,
          "prof-cache-misses": 1,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(2)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.003094,
              "prof-wall": 0.001926,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.314654,
              "prof-wall": 0.313097,
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
                      "prof-cpu": 0.015753,
                      "prof-wall": 0.014853,
                      "prof-name": "LetVarIterator ($x)"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 2,
                  "prof-cpu": 0.200914,
                  "prof-wall": 0.200448,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 2,
                      "prof-cpu": 0.200914,
                      "prof-wall": 0.200448,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 2,
                          "prof-cpu": 0.168548,
                          "prof-wall": 0.166537,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.001578,
                              "prof-wall": 0.000905,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.00111,
                              "prof-wall": 0.000465,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 2,
                          "prof-cpu": 0.014648,
                          "prof-wall": 0.013755,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 1,
                              "prof-cpu": 0.001017,
                              "prof-wall": 0.000598,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 1,
                              "prof-cpu": 0.000698,
                              "prof-wall": 0.000283,
                              "prof-name": "ForVarIterator ($x)"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.008243,
                          "prof-wall": 0.008038,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.002423,
                              "prof-wall": 0.002215,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000414,
                                  "prof-wall": 0.000172,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000407,
                                  "prof-wall": 0.000196,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.001217,
                              "prof-wall": 0.001011,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.003478,
                              "prof-wall": 0.003272,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000346,
                                  "prof-wall": 0.000135,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000337,
                                  "prof-wall": 0.000131,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.00149,
                                  "prof-wall": 0.001289,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0.000371,
                                      "prof-wall": 0.000163,
                                      "prof-name": "ForVarIterator ($x)"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0.000324,
                                      "prof-wall": 0.00012,
                                      "prof-name": "ForVarIterator ($x)"
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
          "prof-cpu": 0.001299,
          "prof-wall": 0.000666,
          "prof-name": "SingletonIterator"
        },
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 1,
          "prof-cpu": 0.106532,
          "prof-wall": 0.104892,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 0,
          "prof-cache-misses": 1,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(12)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.001216,
              "prof-wall": 0.0005,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 1,
              "prof-cpu": 0.05057,
              "prof-wall": 0.049529,
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
                      "prof-cpu": 0.00577,
                      "prof-wall": 0.005016,
                      "prof-name": "LetVarIterator ($x)"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 1,
                  "prof-cpu": 0.025337,
                  "prof-wall": 0.024891,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 1,
                      "prof-cpu": 0.025337,
                      "prof-wall": 0.024891,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 2,
                          "prof-cpu": 0.008599,
                          "prof-wall": 0.007976,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.00135,
                              "prof-wall": 0.000695,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.001062,
                              "prof-wall": 0.000433,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.001693,
                          "prof-wall": 0.001489,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000356,
                              "prof-wall": 0.000149,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000391,
                              "prof-wall": 0.000187,
                              "prof-name": "ForVarIterator ($x)"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 1,
                          "prof-cpu": 0.01209,
                          "prof-wall": 0.011572,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.004776,
                              "prof-wall": 0.004128,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.000961,
                                  "prof-wall": 0.000346,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.000939,
                                  "prof-wall": 0.000312,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 1,
                              "prof-cpu": 0.001468,
                              "prof-wall": 0.001023,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.003534,
                              "prof-wall": 0.003331,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000357,
                                  "prof-wall": 0.000147,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000331,
                                  "prof-wall": 0.000126,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.001525,
                                  "prof-wall": 0.00132,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0.000355,
                                      "prof-wall": 0.00015,
                                      "prof-name": "ForVarIterator ($x)"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0.000324,
                                      "prof-wall": 0.000118,
                                      "prof-name": "ForVarIterator ($x)"
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
          "prof-cpu": 0.001192,
          "prof-wall": 0.000575,
          "prof-name": "SingletonIterator"
        },
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.06462,
          "prof-wall": 0.062094,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 1,
          "prof-cache-misses": 0,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(2)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.001311,
              "prof-wall": 0.000603,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 0,
              "prof-cpu": 0.022354,
              "prof-wall": 0.021798,
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
                      "prof-cpu": 0.0016,
                      "prof-wall": 0.00129,
                      "prof-name": "LetVarIterator ($x)"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 0,
                  "prof-cpu": 0.012287,
                  "prof-wall": 0.012094,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 0,
                      "prof-cpu": 0.012287,
                      "prof-wall": 0.012094,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.002234,
                          "prof-wall": 0.002028,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.00044,
                              "prof-wall": 0.000232,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000368,
                              "prof-wall": 0.000161,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.001506,
                          "prof-wall": 0.001303,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000359,
                              "prof-wall": 0.00015,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000323,
                              "prof-wall": 0.00012,
                              "prof-name": "ForVarIterator ($x)"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.007332,
                          "prof-wall": 0.007136,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.001665,
                              "prof-wall": 0.001462,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.00034,
                                  "prof-wall": 0.000135,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000322,
                                  "prof-wall": 0.000116,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.001505,
                              "prof-wall": 0.001299,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.003211,
                              "prof-wall": 0.003009,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000352,
                                  "prof-wall": 0.000146,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000332,
                                  "prof-wall": 0.000129,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.001414,
                                  "prof-wall": 0.001212,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0.000344,
                                      "prof-wall": 0.000138,
                                      "prof-name": "ForVarIterator ($x)"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0.000329,
                                      "prof-wall": 0.000123,
                                      "prof-name": "ForVarIterator ($x)"
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
          "prof-cpu": 0.001079,
          "prof-wall": 0.000448,
          "prof-name": "SingletonIterator"
        },
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 1,
          "prof-cpu": 0.046267,
          "prof-wall": 0.044641,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 1,
          "prof-cache-misses": 0,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(12)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.001264,
              "prof-wall": 0.000578,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 0,
              "prof-cpu": 0.020489,
              "prof-wall": 0.019864,
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
                      "prof-cpu": 0.001663,
                      "prof-wall": 0.001361,
                      "prof-name": "LetVarIterator ($x)"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 0,
                  "prof-cpu": 0.011558,
                  "prof-wall": 0.011365,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 0,
                      "prof-cpu": 0.011558,
                      "prof-wall": 0.011365,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.00234,
                          "prof-wall": 0.002133,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000418,
                              "prof-wall": 0.000213,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000422,
                              "prof-wall": 0.000164,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.001492,
                          "prof-wall": 0.001287,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000353,
                              "prof-wall": 0.000145,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000318,
                              "prof-wall": 0.000115,
                              "prof-name": "ForVarIterator ($x)"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.006688,
                          "prof-wall": 0.006491,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.001604,
                              "prof-wall": 0.0014,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000348,
                                  "prof-wall": 0.000136,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000323,
                                  "prof-wall": 0.000118,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000967,
                              "prof-wall": 0.000756,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.003181,
                              "prof-wall": 0.002978,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000341,
                                  "prof-wall": 0.000136,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000325,
                                  "prof-wall": 0.000121,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.001416,
                                  "prof-wall": 0.001213,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0.000345,
                                      "prof-wall": 0.000139,
                                      "prof-name": "ForVarIterator ($x)"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0.000321,
                                      "prof-wall": 0.000118,
                                      "prof-name": "ForVarIterator ($x)"
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
          "prof-cpu": 0.001276,
          "prof-wall": 0.000661,
          "prof-name": "SingletonIterator"
        },
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 4,
          "prof-cpu": 0.153575,
          "prof-wall": 0.148169,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 0,
          "prof-cache-misses": 1,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(22)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.001197,
              "prof-wall": 0.000505,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 4,
              "prof-cpu": 0.065073,
              "prof-wall": 0.062367,
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
                      "prof-cpu": 0.00745,
                      "prof-wall": 0.006447,
                      "prof-name": "LetVarIterator ($x)"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 4,
                  "prof-cpu": 0.042569,
                  "prof-wall": 0.041443,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 4,
                      "prof-cpu": 0.042569,
                      "prof-wall": 0.041443,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 2,
                          "prof-cpu": 0.008686,
                          "prof-wall": 0.008072,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.001156,
                              "prof-wall": 0.000509,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.0017,
                              "prof-wall": 0.001082,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.001593,
                          "prof-wall": 0.001386,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000366,
                              "prof-wall": 0.000153,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000327,
                              "prof-wall": 0.000123,
                              "prof-name": "ForVarIterator ($x)"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 4,
                          "prof-cpu": 0.027132,
                          "prof-wall": 0.025983,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 2,
                              "prof-cpu": 0.004765,
                              "prof-wall": 0.004151,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.000965,
                                  "prof-wall": 0.000342,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.001039,
                                  "prof-wall": 0.000406,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000592,
                              "prof-wall": 0.000387,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 4,
                              "prof-cpu": 0.017517,
                              "prof-wall": 0.01616,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.001872,
                                  "prof-wall": 0.000634,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.001244,
                                  "prof-wall": 0.000416,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 2,
                                  "prof-cpu": 0.008856,
                                  "prof-wall": 0.007542,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 1,
                                      "prof-cpu": 0.000793,
                                      "prof-wall": 0.000334,
                                      "prof-name": "ForVarIterator ($x)"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 1,
                                      "prof-cpu": 0.000719,
                                      "prof-wall": 0.000202,
                                      "prof-name": "ForVarIterator ($x)"
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
          "prof-cpu": 0.002035,
          "prof-wall": 0.000998,
          "prof-name": "SingletonIterator"
        },
        {
          "kind": "UDFunctionCallIterator",
          "function": "local:test-01-cache",
          "cached-across-snapshots": true,
          "prof-calls": 1,
          "prof-next-calls": 4,
          "prof-cpu": 0.053603,
          "prof-wall": 0.051356,
          "prof-name": "local:test-01-cache",
          "prof-cache-hits": 1,
          "prof-cache-misses": 0,
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(22)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.001277,
              "prof-wall": 0.000581,
              "prof-name": "SingletonIterator"
            },
            {
              "kind": "FLWORIterator",
              "prof-calls": 1,
              "prof-next-calls": 0,
              "prof-cpu": 0.024545,
              "prof-wall": 0.023949,
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
                      "prof-cpu": 0.001969,
                      "prof-wall": 0.00168,
                      "prof-name": "LetVarIterator ($x)"
                    }
                  ]
                },
                {
                  "kind": "ReturnClause",
                  "prof-calls": 1,
                  "prof-next-calls": 0,
                  "prof-cpu": 0.012273,
                  "prof-wall": 0.01208,
                  "prof-name": "IfThenElseIterator",
                  "iterators": [
                    {
                      "kind": "IfThenElseIterator",
                      "prof-calls": 1,
                      "prof-next-calls": 0,
                      "prof-cpu": 0.012273,
                      "prof-wall": 0.01208,
                      "prof-name": "IfThenElseIterator",
                      "iterators": [
                        {
                          "kind": "TypedValueCompareIterator_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.002725,
                          "prof-wall": 0.002518,
                          "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000537,
                              "prof-wall": 0.000294,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "SingletonIterator",
                              "value": "xs:integer(10)",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000392,
                              "prof-wall": 0.000188,
                              "prof-name": "SingletonIterator"
                            }
                          ]
                        },
                        {
                          "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.001615,
                          "prof-wall": 0.001408,
                          "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                          "iterators": [
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.00035,
                              "prof-wall": 0.000144,
                              "prof-name": "ForVarIterator ($x)"
                            },
                            {
                              "kind": "ForVarIterator",
                              "varname": "x",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000322,
                              "prof-wall": 0.000119,
                              "prof-name": "ForVarIterator ($x)"
                            }
                          ]
                        },
                        {
                          "kind": "IfThenElseIterator",
                          "prof-calls": 1,
                          "prof-next-calls": 0,
                          "prof-cpu": 0.006844,
                          "prof-wall": 0.006646,
                          "prof-name": "IfThenElseIterator",
                          "iterators": [
                            {
                              "kind": "TypedValueCompareIterator_INTEGER",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.001647,
                              "prof-wall": 0.00144,
                              "prof-name": "TypedValueCompareIterator<store::XS_INTEGER>",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000369,
                                  "prof-wall": 0.000165,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:integer(20)",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000323,
                                  "prof-wall": 0.000121,
                                  "prof-name": "SingletonIterator"
                                }
                              ]
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.000991,
                              "prof-wall": 0.000782,
                              "prof-name": "op:concatenate"
                            },
                            {
                              "kind": "FnConcatIterator",
                              "prof-calls": 1,
                              "prof-next-calls": 0,
                              "prof-cpu": 0.003256,
                              "prof-wall": 0.003055,
                              "prof-name": "op:concatenate",
                              "iterators": [
                                {
                                  "kind": "ForVarIterator",
                                  "varname": "x",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000356,
                                  "prof-wall": 0.00015,
                                  "prof-name": "ForVarIterator ($x)"
                                },
                                {
                                  "kind": "SingletonIterator",
                                  "value": "xs:string( == )",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.000333,
                                  "prof-wall": 0.000126,
                                  "prof-name": "SingletonIterator"
                                },
                                {
                                  "kind": "SpecificNumArithIterator_MultiplyOperation_INTEGER",
                                  "prof-calls": 1,
                                  "prof-next-calls": 0,
                                  "prof-cpu": 0.001456,
                                  "prof-wall": 0.001253,
                                  "prof-name": "SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>",
                                  "iterators": [
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0.000347,
                                      "prof-wall": 0.000141,
                                      "prof-name": "ForVarIterator ($x)"
                                    },
                                    {
                                      "kind": "ForVarIterator",
                                      "varname": "x",
                                      "prof-calls": 1,
                                      "prof-next-calls": 0,
                                      "prof-cpu": 0.00036,
                                      "prof-wall": 0.000155,
                                      "prof-name": "ForVarIterator ($x)"
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
          "prof-cpu": 0.001151,
          "prof-wall": 0.000536,
          "prof-name": "SingletonIterator"
        }
      ]
    }
}
