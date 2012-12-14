(:
  Syntax error with an improved error message:
  mismatched starting and closing tag
:)
    
declare function local:foo() 
{
  <section>
    <p> 
      text
      <p> 
        text
      </p>
      <p> 
        text
      </p>
    </section>
};

local:foo()
