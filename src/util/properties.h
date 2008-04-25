#ifndef ZORBA_PROPERTIES_H
#define ZORBA_PROPERTIES_H

#include <string>
#include <fstream>
#include <vector>

namespace zorba {

  // TODO remove the properties from the system
  // only use them for the command line tools
  class Properties {
    private:
      static bool theLoaded;
      
      // Program Options which are used somewhere
      std::string theQuery;
      bool theTraceParsing;
      bool theTraceScanning;
      bool theUseSerializer;
      bool theUseOptimizer;
      std::string theResultFile;
      bool theUseResultFile;
      bool theAbortWhenFatalError;
      bool theInlineQuery;
      bool thePrintQuery;
      bool thePrintTime;
      bool thePrintAST;
      bool thePrintNormalizedExpressions;
      bool thePrintTranslatedExpressions;
      bool thePrintOptimizedExpressions;
      bool thePrintIntermediateOptimizations;
      bool thePrintIteratorTree;
      bool thePrintItemFlow;
      bool theStableIteratorIds;
      bool theNoTreeIds;
#ifndef NDEBUG
      bool theTraceTranslator;
      bool theTraceCodegen;
      long theStoreTraceLevel;
#endif
      bool theCompileOnly;
      int theTimezone;
      std::vector<std::string> theExternalVars;            
      /**
       * Constructor.
       * The default values of the properties are set here! Boost Program Options
       * default values do not work because parts of the parsing might not be executed
       * because of the command line or the property file is not parsed.
       */
      Properties();

      /**
       * Gets the Operation System folger where the properties of the current 
       * user are saved.
       * Linux, Mac: /home/username
       * Windows Vista: C:\Users\username\Application Data
       * Windows XP: C:\Documents and Settings\username\Application Data
       * 
       * @param aFolderURI 
       * @return true, if found
       */
      bool 
      getOSConfigFolder(std::string& aFolderURI);
      
      /**
       * Gets the location of the zorba property in the operation system.
       * 
       * Linux, Mac: /home/username/.zorba/properties.cfg
       * Windows Vista: C:\Users\username\Application Data\zorba\properties.cfg
       * Windows XP: C:\Documents and Settings\username\Application Data\zorba\properties.cfg
       * 
       * @param aFileURI 
       * @return true, if found
       */
      bool 
      getOSConfigFile(std::string& aFileURI);
    
      /**
       * Parses the program options.
       * 
       * @param argc 
       * @param argv[] 
       * @param aNoCmdLineOptions true, if command line options should not be considered.
       * @return false, if the parsing didn't work
       */
      bool 
      loadProps(int argc, char *argv[], bool aNoCmdLineOptions = false);
    
    public:
      static Properties* 
      instance(bool aCheckLoad = true);
      
      /**
       * Parses the command line arguments and the property file for properties.
       * The url of the property file is searched in the command line's arguments under the name property-file.
       * If this argument is not found, the property file is search in the current
       * directory under the name properties.cfg. If not found there, it is searched in the
       * config folder for zorba of the operation system. This folder is defined as follows:
       * - Linux, Mac: /home/username/.zorba/properties.cfg
       * - Windows Vista: C:\Users\username\Application Data\zorba\properties.cfg
       * - Windows XP: C:\Documents and Settings\username\Application Data\zorba\properties.cfg
       * 
       * 
       * @return true if parsing was successful, else false
       */
      static bool 
      load(int argc, char *argv[]);
      
      // Getters
      const std::string& 
      getQuery() { return theQuery; }
      bool
      traceParsing() { return theTraceParsing; }

      bool
      traceScanning() { return theTraceScanning; }

      bool
      useSerializer() { return theUseSerializer; }

      bool useOptimizer() { return theUseOptimizer; }
      
      const std::string& getResultFile() { return theResultFile; }
      bool
      useResultFile() { return theUseResultFile; }
      
      bool
      abortWhenFatalError() { return theAbortWhenFatalError; }
      
      bool
      inlineQuery() { return theInlineQuery; }
      
      bool
      printQuery()  { return thePrintQuery; }
      
      bool
      printTime()  { return thePrintTime; }
      
      bool
      printAST()   { return thePrintAST; }
      
      bool
      printNormalizedExpressions() { return thePrintNormalizedExpressions; }
      
      bool
      printTranslatedExpressions() { return thePrintTranslatedExpressions; }
      
      bool
      printOptimizedExpressions() { return thePrintOptimizedExpressions; }
      
      bool
      printIntermediateOptimizations() { return thePrintIntermediateOptimizations; }

      bool
      printIteratorTree() { return thePrintIteratorTree; }

      bool
      printItemFlow() { return thePrintItemFlow; }

      bool
      stableIteratorIds() { return theStableIteratorIds; }

      bool
      noTreeIds() { return theNoTreeIds; }

      bool
      compileOnly () { return theCompileOnly; }

      int
      timezone () { return theTimezone; }

#ifndef NDEBUG
      bool
      traceCodegen() { return theTraceCodegen; }
      
      bool
      traceTranslator() { return theTraceTranslator; }

      long
      storeTraceLevel() { return theStoreTraceLevel; }
#endif

      std::vector<std::pair<std::string,std::string> > getExternalVars();
      
  }; /* class Properties */
} /* namespace zorba */
#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
