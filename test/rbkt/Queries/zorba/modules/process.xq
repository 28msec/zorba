import module namespace proc = "http://www.zorba-xquery.com/modules/process"; 

block
{
  declare $stdOutTest := proc:exec("echo","hello world") ;

  declare $stdErrTest := proc:exec("echo","Ooops. an error. 1>&amp;2");

  <result>
    <out>{normalize-space(data($stdOutTest/stdout))}</out>
    <err>{normalize-space(data($stdErrTest/stderr))}</err>
  </result>;
}
