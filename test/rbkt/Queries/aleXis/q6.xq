import module namespace
fn-zorba-util="http://www.zorba-xquery.com/zorba/util-functions";
<test>
<q1>{fn-zorba-util:tidy('<HTML>
<HEAD>
<TITLE>[ #426885 ] Definition list w/Center crashes</TITLE>
</HEAD>
<BODY>
<CENTER><H1>Heading 1</H1></CENTER>
<DT><IMG src="redball.gif"><B>Term 1</B></DT>
<DT><IMG src="redball.gif"><B>Term 2</B><HR></DT>
<CENTER><H1>Heading 2</H1></CENTER>
<UL>
<DT><IMG src="redball.gif"><B>Term 3</B></DT>
<DT><IMG src="redball.gif"><B>Term 4</B><HR></DT>
</UL>
</BODY>
</HTML>')}</q1>
<q2>{fn-zorba-util:tidy('<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html>
<head>
  <title>[#427663] Line endings not supported correctly</title>
</head>
<body>
<p>This is a carriage return^MThis is a Unix line-ending
This is a DOS line ending^M

</body>
</html>
')}</q2></test>

