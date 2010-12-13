import module namespace proc = "http://www.zorba-xquery.com/modules/process"; 

let $stdOutTest := proc:exec("echo","hello world") 
let $stdErrTest := proc:exec("echo","Ooops. an error. 1>&amp;2")
return 
  <result>
    <out>{normalize-space(data($stdOutTest/stdout))}</out>
    <err>{normalize-space(data($stdErrTest/stderr))}</err>
  </result>