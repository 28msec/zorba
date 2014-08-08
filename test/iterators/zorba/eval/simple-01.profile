{
    "iterator-tree": {
        "kind": "EvalIterator",
        "prof-calls": 1,
        "prof-next-calls": "REMOVED",
        "prof-cpu": "REMOVED",
        "prof-wall": "REMOVED",
        "prof-name": "EvalIterator",
        "prof-compilation-cpu": 0.839114,
        "prof-compilation-wall": 0.840121,
        "iterators": [
            {
                "kind": "EvalQueryIterator",
                "prof-name": "EvalQueryIterator",
                "prof-calls": 1,
                "prof-next-calls": "REMOVED",
                "prof-cpu": "REMOVED",
                "prof-wall": "REMOVED",
                "prof-compilation-cpu": 0.839114,
                "prof-compilation-wall": 0.840121,
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
                "kind": "SingletonIterator",
                "value": "xs:string(1+1)",
                "prof-calls": 1,
                "prof-next-calls": "REMOVED",
                "prof-cpu": "REMOVED",
                "prof-wall": "REMOVED",
                "prof-name": "SingletonIterator"
            }
        ]
    }
}