(: 
   Implementations MUST NOT define annotation assertions in the following 
   reserved namespaces; it is an error for users to create annotation 
   assertions in the following reserved namespaces [err:XQST0045]:
    
     http://www.w3.org/XML/1998/namespace
     
     http://www.w3.org/2001/XMLSchema
 
     http://www.w3.org/2001/XMLSchema-instance
 
     http://www.w3.org/2005/xpath-functions
 
     http://www.w3.org/2005/xpath-functions/math
:)

declare %fn:nonexistent variable $var := 3;

$var
