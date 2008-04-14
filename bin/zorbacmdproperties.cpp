#include "zorbacmdproperties.h"

#include <boost/program_options/parsers.hpp>
#include <boost/program_options/errors.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/positional_options.hpp>
#include <fstream>
#include <iostream>

bool
ZorbaCMDProperties::loadProperties(int argc, char* argv[])
{
  boost::program_options::options_description lGenericOptions ( "Generic Options" );
  lGenericOptions.add_options()
    ( "version", "Print program version")

    ( "help,h", "Print the help list")
    ;

  boost::program_options::options_description lOutputOptions ( "Output Options" );
  lOutputOptions.add_options()
    ("timing,t", "Print timing information")

    ("output-file,o", boost::program_options::value<std::string>(&theOutputFile), 
     "Write the result to the given file")

    ("serialize-html", "Serialize the result as HTML")

    ("indent", "Indent output")

    ("print-query", "Print the query")

    ("byte-order-mark", "Set the byte-order-mark for the serializer.")

    ("omit-xml-declaration", "Omit the XML declaration.")
    ;

  boost::program_options::options_description lStaticContextOptions ( "Static Context Options" );
  lStaticContextOptions.add_options() 
    ("base-uri", boost::program_options::value<std::string>(&theBaseUri)->default_value(""), 
     "Specify the base URI property of the static context")

    ("boundary-space", boost::program_options::value<std::string>(&theBoundarySpace)->default_value(""),
     "Sets the boundary-space policy in the static context. Values allowed are strip or preserve.")

    ("default-collation", 
     boost::program_options::value<std::string>(&theDefaultCollation)->default_value(""), 
     "Add the given collation and set the value of the default collation in the static context to the given collation.")

    ("construction-mode", 
     boost::program_options::value<std::string>(&theConstructionMode)->default_value(""), 
     "Set the construction mode in the static context. Values allowed are strip or preserve.")

    ("ordering-mode", boost::program_options::value<std::string>(&theOrderingMode)->default_value(""),
     "Set the ordering mode in the static context. Values allowed are ordered or unordered.")
    ;

  boost::program_options::options_description lExecutionOptions ( "Execution Options" );
  lExecutionOptions.add_options()
    ("multiple,m", boost::program_options::value<int>(&theMultipleExecutions), 
     "Execute the given query multiple times")

    ("inline,i", "Inline the query, i.e. do not treat the last argument as file")
    ("external-variable,e", boost::program_options::value<std::vector<std::string> >(&theExternalVarsString), 
     "Provide the value for a variable given a file (name=file) or a value (name:=value)")

    ("context-item", boost::program_options::value<std::string> (&theContextItem), 
     "Provide the context item given an XML document in a file")

    ("optimization-level", boost::program_options::value<std::string>(&theOptLevel)->default_value("O1"),
     "Optimization level for compiling the query (i.e. O0, O1)")
    ;

  boost::program_options::options_description lHiddenOptions ("Hidden Options" );
  lHiddenOptions.add_options()
    ("query,q", boost::program_options::value<std::string>(&theQueryOrFile), 
     "the query inline or in a file")
    ;

  boost::program_options::positional_options_description lPositionalOptions;
  lPositionalOptions.add ( "query", -1 );

  boost::program_options::options_description lAllOptions;
  lAllOptions.add(lGenericOptions).add(lOutputOptions).add(lExecutionOptions)
             .add(lStaticContextOptions).add(lHiddenOptions);

  theVisibleOptions.add(lGenericOptions).add(lOutputOptions).add(lStaticContextOptions)
                   .add(lExecutionOptions);

  boost::program_options::variables_map lVarMap;

  // parse the command line options
  store ( boost::program_options::command_line_parser ( argc, argv ).
        options ( lAllOptions ).positional( lPositionalOptions ).run(), lVarMap );

  notify ( lVarMap );

  if ( theBoundarySpace.size() != 0 )
  {
    if ( ! (theBoundarySpace.compare("strip") == 0 || theBoundarySpace.compare("preserve") == 0 ))
    {
      std::cerr << "Only strip and preserve are allowed as values for the option boundary-space." 
                << std::endl;
      return false;
    }
  }

  if ( theConstructionMode.size() != 0 )
  {
    if ( ! (theConstructionMode.compare("strip") == 0 || theConstructionMode.compare("preserve") == 0 ))
    {
      std::cerr << "Only strip and preserve are allowed as values for the option construction-mode." 
                << std::endl;
      return false;
    }
  }

  if ( theOrderingMode.size() != 0 )
  {
    if ( ! (theOrderingMode.compare("ordered") == 0 || theOrderingMode.compare("unordered") == 0 ))
    {
      std::cerr << "Only ordered and unordered are allowed as values for the option ordering-mode." 
                << std::endl;
      return false;
    }
  }

  if ( ! (theOptLevel.compare("O0") == 0 || theOptLevel.compare("O1") == 0 ))
  {
    std::cerr << "Only O0 or O1 are allowed as values for the option opt-level." << std::endl;
    return false;
  }

  std::vector<std::string>::const_iterator lIter = theExternalVarsString.begin();
  std::vector<std::string>::const_iterator lEnd = theExternalVarsString.end();
  for (; lIter != lEnd; ++lIter) 
  {
    std::string lStr = *lIter;
    std::string::size_type lPos = lStr.find_first_of("=");
    std::string lVarName = lStr.substr(0, lPos);
    std::string lValue = lStr.substr(lPos + 1);
    bool lInlineFile = true;
    if (lVarName.at(lVarName.size()-1) == ':')
    {
      lInlineFile = false;
      lVarName.resize(lVarName.size()-1); // remove the :
    }
    ExternalVariable lExternalVariable;
    lExternalVariable.var_name = lVarName;
    lExternalVariable.var_value = lValue;
    lExternalVariable.inline_file = lInlineFile;
    theExternalVars.push_back(lExternalVariable);
  }

  // general
  thePrintVersion       = (lVarMap.count("version") != 0);
  thePrintHelp          = (lVarMap.count("help") != 0);
  thePrintQuery         = (lVarMap.count("print-query") != 0);

  // execution
  theTiming             = (lVarMap.count("timing") != 0);
  theMultipleExecutions = ((lVarMap.count("multiple")!=0)?lVarMap["multiple"].as<int>():1);
  theInlineQuery        = (lVarMap.count("inline") != 0);

  // output
  theSerializeAsHTML    = (lVarMap.count("serialize-html") != 0);
  theIndent             = (lVarMap.count("indent") != 0);
  theByteOrderMark      = (lVarMap.count("byte-order-mark") != 0);
  theOmitXMLDeclaration = (lVarMap.count("omit-xml-declaration") != 0);

  return true;

}
