<?xml version="1.0" encoding="UTF-8"?>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Introduction To TidyLib</title>
<meta http-equiv="Content-Type" content="text/xhtml; charset=utf-8" />
<link rel="stylesheet" href="tidy.site.css" type="text/css" />
<style type="text/css">
  /**/
  table.info
  {
    border-style: none
  }
  div.content
  {
    text-align: left;
    vertical-align: text-top;
    width: 100%;
    top: 0;
  }
  div.links
  {
    vertical-align: text-top;
    /* margin-left: 0%;
    ** margin-right: 2%;
    */
    width: 30%;
    position: absolute;
    top: 0;
    left: 70%;
  }
  code
  {
    /* font-weight: bold  */
  }
  /**/
</style>
</head>
<body>
<div class="content">
<h1>What's all this about TidyLib?</h1>
<p>TidyLib, like it sounds, is a library version of Dave Raggett's
popular HTML Tidy. In fact, one of the motivations for starting the
Source Forge project was to refactor HTML Tidy as a callable
library. Although the command line tool is great, it is difficult
and inefficient to integrate into other software.</p>
<h2 id="requirements">Requirements</h2>
<p>We had several informal requirements for the library:</p>
<dl>
<dt>You Can Get There From Here</dt>
<dd>
<p>Probably the most important requirement is that the library be
easy to integrate. Because of the almost universal adoption of C
linkage, a C interface may be called from a great many programming
languages. This, and the fact that code was already in C and the
team was already most comfortable with C, led to the decision that
the library's public interface should be kept in C.</p>
<p>The other major design decision was to use opaque types in the
public interface. This allows the application to just pass in
integer around and the need to transform data types in different
languages is minimized.</p>
<p>This strategy has already paid off. It was straight-forward to
write very thin library wrappers for C++, Pascal, and COM/ATL. It
was also quick to generate a Perl wrapper using <a href="http://www.swig.org">SWIG</a>. SWIG wrappers for Python, Ruby,
Java and others should also be possible.</p>
</dd>
<dt>Don't Break Anything</dt>
<dd>
<p>Of course, Tidy must remain Tidy. It wasn't acceptable to
introduce bugs or drop (many) features. In the end, the body of
test documents proved invaluable to getting things working.</p>
</dd>
<dt>Thread Safe / Reentrant</dt>
<dd>
<p>Because there are many uses for HTML Tidy - from content
validation, content scraping to conversion to XHTML - it was
important to make TidyLib run reasonably well within server
applications as well as client side.</p>
<p>This requirement implies that the library be fully re-entrant so
that it may be used within multi-threaded applications.</p>
</dd>
<dt>Adaptable I/O</dt>
<dd>
<p>As part of the larger integration strategy, it was decided to
fully abstract all I/O. This means a (relatively) clean separation
between character encoding processing and shovelling bytes back and
forth. Internally, the library reads from "sources" and writes to
"sinks". This abstraction is used for both markup and configuration
"files". Concrete implementations are provided for file and memory
I/O. But new sources and sinks may be provided via the public
interface.</p>
</dd>
<!--
  <dt></dt>
  <dd><p></p>
  </dd>
  --></dl>
<p>We had some prior art to follow as well. Most notably,
Marc-Andre Lemburg's <a href="http://www.lemburg.com/files/python/mxTidy.html">mxTidy</a>. In
the process of writing a Python wrapper for Tidy, Marc-Andre
applied these principles and built a C library. TidyLib can be seen
as a completion of Marc's work.</p>
<h2 id="start">Getting Started</h2>
<h3>Get The Source</h3>
<p>The best way to get the lib sources is directly from CVS. If you
have CVS installed (recommended!), just execute the following
commands:</p>
<pre>
C:\src&gt; mkdir tidylib
C:\src&gt; cd tidylib
C:\src\tidylib&gt; set TIDYCVSROOT=:pserver:anonymous@cvs.sourceforge.net:/cvsroot/tidy
C:\src\tidylib&gt; cvs -d %TIDYCVSROOT% login
C:\src\tidylib&gt; cvs -d %TIDYCVSROOT% export -d C:\src\tidylib -r HEAD _
 build console htmldoc include src test
</pre>
<p>When CVS prompts you for the password, just hit ENTER. The
underscore (_) above denotes line continuation. Do not type it in,
just use one long command line. The procedure is similar for Unix
variants. Just translate to the appropriate path separator for your
file system and do not use the -d &lt;dir&gt; option. Copy and
paste the above into a script or batch file. For the truly lazy,
you can pull a gzipped source tarball from the Tidy <a href="http://tidy.sourceforge.net/#source">Project Page</a>.</p>
<h3>Build It</h3>
<p>For an overview of build options, see build/readme.txt. It
describes the overall layout and more info on supported build
systems.</p>
<h4>Unix / GNU</h4>
<p>For GNU gcc, just use the gmake
<code>build/gmake/Makefile</code>. The usual target is
<code>all</code>. If you want a debug build, use the
<code>debug</code> target. For other Unix compilers, you may have
to set the CC macro to point to your compiler, usually just
<code>cc</code>. The same, large number of Unix systems are
supported "out of the box" as Tidy Classic. Tidy usually does a
good job of automatically identifying the current platform. If not,
tweak platform.h as needed and send us a patch!</p>
<p>If you are using GCC/MinGW, you should use gmake as well.</p>
<p>In addition, there are targets for <code>clean</code> and
<code>install</code>. Be sure to look at the Makefile before using
<code>install</code> to make sure the binaries, headers and library
go where you want. By default, <code>/usr/bin</code>,
<code>/usr/include</code>, and <code>/usr/lib</code>, respectively.
There are macros in the Makefile to customize your
installation.</p>
<pre>
make all
</pre>
<h4>Windows / Visual C++</h4>
<p>For VC++, use you can use either <code>msvc/Makefile.vc6</code>
on the command line or <code>build/msvc/tidy.dsw</code> in the IDE.
As the names imply, these work with Visual C++ version 6.0. Service
Pack 3 is highly recommended. Makefile.vc6 supports the same
targets: <code>all</code>, <code>debug</code>, <code>clean</code>
and <code>install</code> are all available.</p>
<p><code>nmake /f Makefile.vc6 all</code></p>
<h4>GNU AutoConf/AutoMake</h4>
<p>The input files to drive the GNU AutoConf tool set have been
added. See <code>build/gnuauto/readme.txt</code> for instructions
on how to use GNU build tools with Tidy.</p>
<h2 id="example">Example</h2>
<p>Perhaps the easiest way to understand how to call Tidy is to see
a simple program that uses it. A basic thing to know about the API
is that functions that return an integer use the following
values:</p>
<dl>
<dt>0 == Success</dt>
<dd>
<p>Good to go.</p>
</dd>
<dt>1 == Warnings, No Errors</dt>
<dd>
<p>Check error buffer or track error messages for details.</p>
</dd>
<dt>2 == Errors and Warnings</dt>
<dd>
<p>By default, Tidy will not produce output. You can force output
with the <a href="http://tidy.sourceforge.net/docs/quickref.html#force-output"><code>
TidyForceOutput</code></a> option. As with warnings, check error
buffer or track error messages for details.</p>
</dd>
<dt>&lt;0 == Severe error</dt>
<dd>
<p>Usually value equals <code>-errno</code>. See errno.h.</p>
</dd>
</dl>
<p>Also, by default, warning and error messages are sent to
<code>stderr</code>. You can redirect diagnostic output using
either <code>tidySetErrorFile()</code> or
<code>tidySetErrorBuffer()</code>. See <code>tidy.h</code> for
details.</p>
<pre>
#include &lt;tidy.h&gt;
#include &lt;buffio.h&gt;
#include &lt;stdio.h&gt;
#include &lt;errno.h&gt;


int main(int argc, char **argv )
{
  const char* input = "&lt;title&gt;Foo&lt;/title&gt;&lt;p&gt;Foo!";
  TidyBuffer output = {0};
  TidyBuffer errbuf = {0};
  int rc = -1;
  Bool ok;

  TidyDoc tdoc = tidyCreate();                     // Initialize "document"
  printf( "Tidying:\t%s\n", input );

  ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );  // Convert to XHTML
  if ( ok )
    rc = tidySetErrorBuffer( tdoc, &amp;errbuf );      // Capture diagnostics
  if ( rc &gt;= 0 )
    rc = tidyParseString( tdoc, input );           // Parse the input
  if ( rc &gt;= 0 )
    rc = tidyCleanAndRepair( tdoc );               // Tidy it up!
  if ( rc &gt;= 0 )
    rc = tidyRunDiagnostics( tdoc );               // Kvetch
  if ( rc &gt; 1 )                                    // If error, force output.
    rc = ( tidyOptSetBool(tdoc, TidyForceOutput, yes) ? rc : -1 );
  if ( rc &gt;= 0 )
    rc = tidySaveBuffer( tdoc, &amp;output );          // Pretty Print

  if ( rc &gt;= 0 )
  {
    if ( rc &gt; 0 )
      printf( "\nDiagnostics:\n\n%s", errbuf.bp );
    printf( "\nAnd here is the result:\n\n%s", output.bp );
  }
  else
    printf( "A severe error (%d) occurred.\n", rc );

  tidyBufFree( &amp;output );
  tidyBufFree( &amp;errbuf );
  tidyRelease( tdoc );
  return rc;
}
</pre>
<p>Look Ma, no temp files!</p>
<h2 id="appnotes">Application Notes</h2>
<p>Of course, there are functions to parse and save both markup and
configuration files. For the adventurous, it is possible to create
new input sources and output sinks. For example, a URL source could
pull the markup from a given URL.</p>
<p>It is also worth rememebering that an application may
instantiate <em><b>any number</b></em> of document and buffer
objects. They are fairly cheap to initialize and destroy (just
memory allocation and zeroing, really), so they may be created and
destroyed locally, as needed. There is no problem keeping them
around a while for keeping state. For example, a server app might
keep a global document as a master configuration. As documents are
parsed, they can copy their configuration data from the master
instance. See <code>tidyOptCopyConfig()</code>. If the master copy
is initialized at startup, no synchronization is necessary.</p>
<h2 id="apidocs">API Docs</h2>
<p>A first draft of <a href="http://tidy.sourceforge.net/docs/api/">API Docs</a> have been
added to Tidy header files and generated using <a href="http://www.doxygen.org">Doxygen</a>.</p>
<h2 id="nightlybuild">Nightly Build</h2>
<p>The build procedures on the Source Forge Compile Farm have been
updated to produce the command line driver based on the library
sources. See <a href="http://tidy.sourceforge.net/#binaries">Tidy
Binaries</a>.</p>
<h2 id="future">Future Directions</h2>
<p>The ink isn't dry yet on TidyLib and already folks want more!
Well, waddaya expect? Several ideas have been discussed on the dev
mailing list.</p>
<dl>
<dt>Character Encoding</dt>
<dd>
<p>Currently, all character encoding support is hard wired into the
library. This means we do a poor job of supporting many popular
encodings such as GB2312, euc-kr, eastern European languages,
cyrillic, etc. Any of these languages must first be transcoded into
ISO-10646/Unicode before Tidy can work with it.</p>
<p>Two basic approaches have been proposed: just use iconv or adapt
Clark Coopers's XML::Encoding as a callable library. On the face of
it, iconv is preferable. Because it is GPL'ed, however, the license
may be incompatible. Also, there are transcription issues related
to Big5 and other code sets that may or may not be addressed by
iconv. XML::Encoding, otoh, uses the Perl Artistic License and
explicitly supports all alternate transcriptions for Big5 and
others. For more info, see <a href="http://search.cpan.org/src/COOPERCL/XML-Encoding-1.01/maps/">CPAN</a>
and <a href="issues.list.html">Tidy Issues</a>.</p>
</dd>
<dt>Error Handling</dt>
<dd><br />
<ul>
<li>Categorize errors</li>
<li>Improve message localization</li>
<li>Improve separation of parsing and diagnostics</li>
</ul>
<br /></dd>
<dt>Content Model</dt>
<dd><br />
<ul>
<li>Per-element-and-version attribute support</li>
<li>DTD Internal Subset support</li>
<li>Modular XHTML support (XHTML 1.1)</li>
</ul>
</dd>
</dl>
<p><em>Page last updated on 26 November, 2002 by C.
Reitzel</em></p>
</div>
</body>
</html>
