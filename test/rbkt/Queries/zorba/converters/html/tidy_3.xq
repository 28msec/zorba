import module namespace html="http://www.zorba-xquery.com/modules/convertors/html";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/html-options";

html:parse('<HTML>
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
</HTML>')