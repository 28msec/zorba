{
  "$invalid" : true, 
  "$expected" : "Q{http://www.example.com/my-schema}foo", 
  "$value" : {
    "k1" : 41
  }, 
  "$reason" : "value violates $constraints facet \"$$ mod 2 eq 0\" of type Q{http://www.example.com/my-schema}foo: [jerr:JNTY0004]: can not atomize an object item: an object has probably been passed where an atomic value is expected (e.g., as a key, or to a function expecting an atomic item)"
}
