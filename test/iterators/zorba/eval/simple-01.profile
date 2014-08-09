{
  "iterator-tree":
    {
      "kind": "EvalIterator",
      "prof-calls": 1,
      "prof-next-calls": 2,
      "prof-cpu": 1.13624,
      "prof-wall": 1.13552,
      "prof-name": "EvalIterator",
      "prof-compilation-cpu": 0.876357,
      "prof-compilation-wall": 0.877387,
      "iterators": [
        {
          "kind": "EvalQueryIterator",
          "prof-name": "EvalQueryIterator",
          "prof-calls": 1,
          "prof-next-calls": 2,
          "prof-cpu": 0.001709,
          "prof-wall": 0.000863,
          "prof-compilation-cpu": 0.876357,
          "prof-compilation-wall": 0.877387,
          "prof-body": "1+1",
          "iterators": [
            {
              "kind": "SingletonIterator",
              "value": "xs:integer(2)",
              "prof-calls": 1,
              "prof-next-calls": 2,
              "prof-cpu": 0.001709,
              "prof-wall": 0.000863,
              "prof-name": "SingletonIterator"
            }
          ]
        },
        {
          "kind": "SingletonIterator",
          "value": "xs:string(1+1)",
          "prof-calls": 1,
          "prof-next-calls": 1,
          "prof-cpu": 0.002532,
          "prof-wall": 0.001934,
          "prof-name": "SingletonIterator"
        }
      ]
    }
}
