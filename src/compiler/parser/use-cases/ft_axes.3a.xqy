doc("http://bstore1.example.com/full-text.xml")
/books/book[@number="3" and count((./content/part/
component(subcomponent | subcomponent/subsubcomponent) 
ftcontains "flow diagram.?" with wildcards 
and ancestor::books//(subcomponent | subcomponent/
subsubcomponent) ftcontains "human computer 
interaction"))>0]/(metadata/title | ./content)
