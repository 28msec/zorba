import module namespace http = "http://expath.org/ns/http-client";
import module namespace fs = "http://expath.org/ns/file";

(: Generate Index :)

let $summaries := {
  68780805079: "We are more than proud to announce the release of Zorba 3.0, codename Kratos. Kratos contains major improvements of the JSONiq language, the language bindings, as well as all of the XQuery and JSONiq modules. Moreover, we made considerable performance improvements and fixed a huge number of bugs. Because we can’t elaborate on all changes, please refer to to the ChangeLog for an exhaustive list of changes.",
  68774681365: "The Zorba Team is proud to announce the release of Zorba 2.9, codename Io! Io includes extensions and improvements to our JSONiq support; enhanced support for Higher-Order Functions (HOF); and extensive improvements in XQuery 3.0 comformance.",
  60028721581: "The Zorba team is pleased to announce the release of Zorba 2.8, codename Hermes. Hermes ships five new modules: four brand new database drivers and a new info-extraction module for querying concepts and entities in natural language text. This release provides several improvements in the Zorba optimizer and twenty-two bug fixes (see Changelog). It is available in our download section.",
  60028669088: "An underused feature of Zorba is its capability to compile query plans for later execution.",
  60028626564: "We have heard your Feedback and developed a module to work with compressed archives (e.g. zip or tar.gz). The Archive module provides functions to create, read, and modify archives given as xs:base64Binary items. For example, it provides functions to retrieve the names or extract the values of several entries from a zip archive.",
  60028553817: "The Zorba team is pleased to announce the release of Zorba 2.7, codename Gaia. The release is a substantial step forward in terms of new features, performance improvements, and bug fixes.",
  60028475838: "xqDoc is the de facto industry standard for generating API documentation from XQuery modules.",
  60028351254: "The Atom Syndication Format (RFC 4287) is one of the most popular XML formats to aggregate XML data. Such an aggregate is called an Atom feed.",
  60028280241: "The Zorba development team is pleased to announce the release of Zorba 2.6, codename Eros. The release is available in ourdownload section.",
  60028229416: "Users are often using Zorba from different host languages. We usually see the C++ and Java APIs being used to integrate XQuery with core components. That’s the case of the 28msec platform for instance. The PHP, Python, and Ruby APIs are fairly popular for integrating Zorba into web applications. In the Zorba team, our favorite programming language is XQuery and we use XQuery as an host language for XQuery as much as possible ;-):",
  60028183183: "If you’ve ever wondered whether Zorba will support XQJ, now is the time. Starting with version 2.5 Zorba includes a XQJ layer where you can have full access to all the features specified by XQJ. The XQJ API enables Java programmers to execute XQuery against any XML data source.",
  60028135025: "Zorba is a proud partner of NoSQL Now! 2012, a conference covering the dynamic field of NoSQL technologies. This year’s edition features several XQuery-related talks and some of them will showcase new features in both XQuery 3.0 and Zorba.",
  60028086432: "Providing a schema for your data makes your applications much more robust and can enable numerous optimizations in your query processor. However, many users shy away from the complexity of XML Schema. Well, what if you could generate a schema automatically from your data? Or what if you could generate a sample instance from a big schema and modify it with your data in just a few lines of code? Now you can!",
  60028018460: "The Zorba development team is pleased to announce the release of Zorba 2.5, codename Dionysus. The release is a major step forward in terms of new features, performance improvements, and bug fixes. It is available in our download section.",
  60027975996: "Are you familiar with that awkward moment when you realize that fn:doc() is no good to deal with the 24 GB XML file you would like to process? Here’s a quick tip that will make you feel like an XML Rock Star.",
  60027902618: "Caching of function results may improve performance if computationally expensive functions are invoked multiple times with the same arguments.

  If the optimization level is O1 or higher, Zorba automatically caches results of recursive, deterministic, and non-sequential functions whose parameter and return types are subtypes of xs:anyAtomicType. Specifically, if such a function is called more than once with the same arguments, the result of the first call will be cached and subsequent calls will return the cached value without re-evaluating the function.",
  60027825488: "Zorba 2.2 significantly improves the processing of XML, JSON, and textual streams. In this post, we would like to showcase how XQuery can be leveraged to build applications on top of the Twitter Streaming API.",
  60027643315: "When you arrive in a room full of hackers decorated with 4chan memes, you know that you just landed at FOSDEM.",
  60027695561: "We are very excited to announce the release of Zorba 2.2, codename Coeus. It is available in our download section.",
  60027582262: "XML &amp; Prague. Does it get any better than this for angle brackets aficionados?
  Every year, XML Prague is one of the most exciting events of the year for the Zorba development team.
  And for the 2012 edition, the organisation committee pulled out all the stops.",
  60027332254: "The 2.1 release of Zorba comes with a new module which gives the user an API for evaluating XQuery programs from XQuery. Just like XQC for C or XQJ for Java it provides functions for preparing and evaluating arbitrary XQuery main modules.",
  60027248855: "PHP and XQuery have always been an happy couple and we are looking to build on that momentum. Our goal is to contribute a powerful toolkit to harness unstructured data in PHP developments. In this perspective, the first edition of the PHP Tour was a perfect fit to introduce developers with the possible interactions between PHP and XQuery. The aim of the talk was to explore the gain of functionality and productivity that can be achieved by introducing XQuery into PHP applications."

}
let $channel := http:send-request(<http:request href="http://zorba-nosql.tumblr.com/rss" method="GET" />)[2]/rss/channel
let $index :=  {
  "title": $channel/title/text(),
  "tags": {|
    for $tag in distinct-values($channel/item/category/string())
    return { $tag: count($channel/category/[string() eq $tag]) }
  |},
  "entries": [
    for $entry in $channel/item
    let $title := $entry/title/string()
    let $title-id := replace($title, "[^\w ]", "") ! lower-case(.) ! replace(., "\s", "-") 
    return {
      "title": $title,
      "id": "/" || $entry/guid/string() ! tokenize(., '/')[last()] || "/" || $title-id,
      "updated": $entry/pubDate/text(),
      "summary": $summaries($entry/guid/string() ! tokenize(., '/')[last()]),
      "content": $entry/description/string(),
      "tags": [
        for $cat in $entry/category
        return $cat/string()
      ]
    }
  ]
}
let $rss := http:send-request(<http:request href="http://28-io.tumblr.com/rss" method="GET" />)[2]
let $feed := <feed xmlns="http://www.w3.org/2005/Atom">
  <title>28.io - Blog</title>
  <link href="http://www.28.io/blog/atom.xml"/>
  <updated>{current-dateTime()}</updated>
  <author>
    <name>28msec</name>
  </author>
  {
    for $entry in $index("entries") ! jn:members(.)
    return <entry>
      <title>{$entry("title")}</title>
      <id>{$entry("id")}</id>
      <summary>{$entry("summary")}</summary>
      <updated>{$entry("updated")}</updated>
      <content type="html">
      {$entry("content") ! replace(., "http://zorbawebsite2.my28msec.com", "")}
      </content>
      {
        for $cat in $entry("tags") ! jn:members(.)
        return <category label="{$cat}" />
      }
    </entry>
  }
</feed>
return {
  fs:write("index.json", $index, ());
  fs:write("atom.xml", $feed, ());
}
