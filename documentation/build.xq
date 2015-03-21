import module namespace fs = "http://expath.org/ns/file";

import module namespace json = "http://www.zorba-xquery.com/modules/xqdoc/json" at "json.xq";
import module namespace doxy = "http://www.zorba-xquery.com/doxygen" at "doxygen.xq";
import module namespace doxyj = "http://www.zorba-xquery.com/doxygen/json" at "doxygen-json.xq";

declare function local:expand($current, $elms)
{
  for $elm in $elms
  let $id := $elm/@id/string()
  let $label := $elm/@label/string()
  return if($elm instance of element(module)) then
  {
    "label": $label,
    "id": $id,
    "ns": $elm/@ns/string(), 
    "url": "modules/" || replace(replace($elm/@ns/string(), "http://", ""), "/", "_") || ".json"
  }
  else
  {
    "label": $label,
    "id": $id,
    "children": [
      local:expand(($current, $id), $elm/*)
    ]
  }
};

for $file at $i in fs:list(".")
where fs:is-directory($file)
  for $name in fs:list($file || "/modules/xml")
  let $xqdoc := parse-xml(fs:read-text($file || "/modules/xml/" || $name))
  where exists($xqdoc/*:xqdoc)
  let $html := json:convert($xqdoc/*)
  return fs:write-text($file || "/modules/" || substring-before($name, ".xml") || ".json", serialize($html, ())); 


for $file at $i in fs:list(".")
where fs:is-directory($file)
  for $name in fs:list($file || "/zorba/xml")
  let $doxy := parse-xml(fs:read-text($file || "/zorba/xml/" || $name))
  where exists($doxy/doxygen)
  let $html := doxy:html($doxy/doxygen, substring-before($file, "-"), "zorba")
  let $json := doxyj:json($doxy/doxygen, substring-before($file, "-"), "zorba")
  return {
    trace($name, "Name");
    trace($json, "JSON");
    (:serialize(trace($json, "JSON"), ());:)
(:
fs:write-text($file || "/zorba/" || substring-before($name, ".xml") || ".html", serialize($html, ()));
    fs:write-text($file || "/zorba/" || substring-before($name, ".xml") || ".json", serialize($json, ()));
  :)  
  };

{
  "versions":
    [
      for $file at $i in fs:list(".")
      where fs:is-directory($file)
      let $tokens := tokenize($file, "-")
      let $version := $tokens[1]
      let $codename := $tokens[2]
      order by $version descending
      count $c
      return {
        "id": "",
        "latest": $c eq 1,
        "version": $version,
        "codename": $codename,
        "children": [
          let $modules := doc($file || "/modules/modules.xml")/modules/section
          return local:expand((), $modules)
          ,
          {
            "id": "zorba",
            "label": "End-User Docs",
            "children": [
              {
                "id": "xml_json",
                "label": "XQuery &amp; JSONiq",
                "url": "zorba/xml_json.html"
              },
              {
                "id": "build",
                "label": "Build Instructions",
                "children": [
                  {
                    "label": "Overview",
                    "id": "build",
                    "url": "zorba/build.html"
                  },
                  {
                    "label": "Prerequisites",
                    "id": "build_prerequisites",
                    "url": "zorba/build_prerequisites.html"
                  },
                  {
                    "label": "Preparing",
                    "id": "build_prepare",
                    "url": "zorba/build_prepare.html"
                  },
                  {
                    "label": "Configuring",
                    "id": "configure_zorba",
                    "url": "zorba/configure_zorba.html"
                  },
                  {
                    "label": "Building and Installing",
                    "id": "build_and_install",
                    "url": "zorba/build_and_install.html"
                  },
                  {
                    "label": "Build Notes",
                    "id": "build_notes",
                    "children": [
                      {
                        "id": "build_ubuntu",
                        "label": "Ubuntu/Debian Linux",
                        "url": "zorba/build_ubuntu.html"
                      },
                      {
                        "id": "build_windows",
                        "label": "Windows",
                        "url": "zorba/build_windows.html"
                      },
                      {
                        "id": "build_macos",
                        "label": "Mac OS X",
                        "url": "zorba/build_macos.html"
                      }
                    ]
                  }
                ]
              },
              {
                "label": "Install",
                "id": "install",
                "children":[
                {
                  "id": "php_ubuntu_tutorial",
                  "label": "PHP 5 - Ubuntu Installation",
                  "url": "zorba/php_ubuntu_tutorial.html"
                },
                {
                  "id": "php_windows_tutorial",
                  "label": "PHP 5 - Windows Installation",
                  "url": "zorba/php_windows_tutorial.html"
                },
                {
                  "id": "python_windows_tutorial",
                  "label": "Python - Windows Installation",
                  "url": "zorba/python_windows_tutorial.html"
                }
                ]
              },
              {
                "id": "cli",
                "label": "Command Line Utility",
                "url": "zorba/commandline.html"
              },
              {
                  "label": "General Architecture",
                  "id": "architecture",
                  "children": [{
                    "id": "data_lifecycle",
                    "label": "Data Lifecycle",
                    "url": "zorba/data_lifecycle.html"
                  },
                  {
                    "id": "schema_lifecycle",
                    "label": "Schema Lifecycle",
                    "url": "zorba/schema_lifecycle.html"
                  },
                  {
                    "id": "uriresolvers",
                    "label": "URI Resolvers",
                    "url": "zorba/uriresolvers.html"
                  },
                  {
                    "id": "data_converters",
                    "label": "Data Converters",
                    "url": "zorba/data_converters.html"
                  },
                  {
                    "id": "ft",
                    "label": "Full Text",
                    "children": [
                      {
                        "id": "ft_intro",
                        "label": "Overview",
                        "url": "zorba/ft_intro.html"
                      },   
                      {
                        "id": "ft_stemmer",
                        "label": "Stemming",
                        "url": "zorba/ft_stemmer.html"
                      },   
                      {
                        "id": "ft_thesaurus",
                        "label": "Thesaurus",
                        "url": "zorba/ft_thesaurus.html"
                      },   
                      {
                        "id": "ft_tokenizer",
                        "label": "Tokenizer",
                        "url": "zorba/ft_tokenizer.html"
                      }
                    ]
                  },
                  
                  {
                    "id": "errors_warnings",
                    "url": "zorba/errors_warnings.html",
                    "label": "Errors and Warnings"
                  },
                  {
                    "id": "dependencies",
                    "label": "Dependencies",
                    "url": "zorba/dependencies.html"
                  },
                  {
                    "id": "memory_management",
                    "url": "zorba/memory_management.html",
                    "label": "Memory Management"
                  },
                  {
                    "id": "memory_leaks",
                    "url": "zorba/memory_leaks.html",
                    "label": "Memory Leaks"
                  }]
              },
              {
                "id": "modules",
                "label": "Library Modules",
                "children": [
                  {
                    "id": "modules_using",
                    "url": "zorba/modules_using.html",
                    "label": "Using Modules"
                  },
                  {
                    "id": "modules_authoring",
                    "url": "zorba/modules_authoring.html",
                    "label": "Writing Modules"
                  },
                  {
                    "id": "modules_building_in",
                    "url": "zorba/modules_building_in.html",
                    "label": "Building Modules"
                  },
                  {
                    "id": "external_functions",
                    "url": "zorba/external_functions.html",
                    "label": "External Functions"
                  }
                ]
              },
              {
                "id": "scripting_tutorial",
                "url": "zorba/scripting_tutorial.html",
                "label": "Scripting"
              },
              {
                "id": "specifications",
                "label": "Specifications",
                "children": [
                  {
                    "id": "overview",
                    "label": "Overview",
                    "url": "zorba/overview.html"
                  },
                  {
                    "id": "xqddf",
                    "label": "Data Definition Facility",
                    "url": "zorba/xqddf.html"
                  },
                  {
                    "id": "options_and_annotations",
                    "label": "Zorba Specific Options and Annotations",
                    "url": "zorba/options_and_annotations.html"
                  }
                ]
              }
            ]
          },
          {
            "id": "languages",
            "label": "Language Bindings",
            "children": [
              {
                "id": "cxx",
                "label": "C++",
                "href": "http://docs.zorba.io.s3-website-us-east-1.amazonaws.com/3.0.0/cxx/"
              }
              , 
              {
                "id": "c",
                "label": "C",
                "href": "http://docs.zorba.io.s3-website-us-east-1.amazonaws.com/3.0.0/c/"
              }
              ,
              {
                "id": "csharp",
                "label": "C#",
                "href": "http://docs.zorba.io.s3-website-us-east-1.amazonaws.com/3.0.0/csharp/"
              }
              ,
              {
                "id": "php",
                "label": "PHP",
                "href": "http://docs.zorba.io.s3-website-us-east-1.amazonaws.com/3.0.0/php/"
              }
              ,
              {
                "id": "java",
                "label": "Java",
                "href": "http://docs.zorba.io.s3-website-us-east-1.amazonaws.com/3.0.0/java/"
              }
              ,
              {
                "id": "xqj",
                "label": "XQJ",
                "href": "http://docs.zorba.io.s3-website-us-east-1.amazonaws.com/3.0.0/xqj/"
              }
              ,
              {
                "id": "python",
                "label": "Python",
                "href": "http://docs.zorba.io.s3-website-us-east-1.amazonaws.com/3.0.0/python/"
              }
              ,
              {
                "id": "ruby",
                "label": "Ruby",
                "href": "http://docs.zorba.io.s3-website-us-east-1.amazonaws.com/3.0.0/ruby/"
              }
            ]
          }
        ]
      }
    ]
}
