./xquery_test use-cases/q1.xqy >q1.out
./xquery_test use-cases/q2.xqy >q2.out
./xquery_test use-cases/q3.xqy >q3.out
./xquery_test use-cases/q4.xqy >q4.out
./xquery_test use-cases/q5.xqy >q5.out
./xquery_test use-cases/q6.xqy >q6.out
./xquery_test use-cases/q7.xqy >q7.out
./xquery_test use-cases/q8.xqy >q8.out
./xquery_test use-cases/q9.xqy >q9.out
./xquery_test use-cases/q10.xqy >q10.out
./xquery_test use-cases/q11.xqy >q11.out
./xquery_test use-cases/q12.xqy >q12.out

fgrep 'QueryBody' q1.out >t1.out
fgrep 'QueryBody' q2.out >t2.out
fgrep 'QueryBody' q3.out >t3.out
fgrep 'QueryBody' q4.out >t4.out
fgrep 'QueryBody' q5.out >t5.out
fgrep 'QueryBody' q6.out >t6.out
fgrep 'QueryBody' q7.out >t7.out
fgrep 'QueryBody' q8.out >t8.out
fgrep 'QueryBody' q9.out >t9.out
fgrep 'QueryBody' q10.out >t10.out
fgrep 'QueryBody' q11.out >t11.out
fgrep 'QueryBody' q12.out >t12.out

