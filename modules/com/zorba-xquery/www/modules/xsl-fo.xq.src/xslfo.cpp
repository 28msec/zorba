/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <list>

#include <zorba/base64.h>
#include <zorba/empty_sequence.h>
#include <zorba/error_list.h>
#include <zorba/external_function.h>
#include <zorba/external_module.h>
#include <zorba/file.h>
#include <zorba/item_factory.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/zorba.h>
#include <zorba/zorba_exception.h>
#include <zorba/zorbastring.h>

#include "JavaVMSingelton.h"

#define XSL_MODULE_NAMESPACE "http://www.zorba-xquery.com/modules/xsl-fo"

class JavaException {
};

#define CHECK_EXCEPTION(env)  if ((lException = env->ExceptionOccurred())) throw JavaException()

namespace zorba { namespace xslfo {
 
class GeneratePDFFunction : public PureStatelessExternalFunction {
  private:
    const ExternalModule* theModule;
    ItemFactory* theFactory;
  public:
    GeneratePDFFunction(const ExternalModule* aModule) :
      theModule(aModule), theFactory(Zorba::getInstance(0)->getItemFactory()) {}
    ~GeneratePDFFunction() {
      JavaVMSingelton::destroyInstance();
    }

  public:
    virtual String getURI() const { return theModule->getURI(); }

    virtual String getLocalName() const { return "generator-impl"; }

    virtual ItemSequence_t 
    evaluate(const StatelessExternalFunction::Arguments_t& args) const;
};

class FindApacheFopFunction : public PureStatelessExternalFunction {
  private:
    const ExternalModule* theModule;
    ItemFactory* theFactory;
  private:
    void throwError(std::string aName) const;
  public:
    FindApacheFopFunction(const ExternalModule* aModule) :
      theModule(aModule), theFactory(Zorba::getInstance(0)->getItemFactory()) {}

    virtual String getURI() const { return theModule->getURI(); }

    virtual String getLocalName() const { return "find-apache-fop"; }

    virtual ItemSequence_t 
    evaluate(const StatelessExternalFunction::Arguments_t& args) const;
};

class XSLFOModule : public ExternalModule {
  private:
    StatelessExternalFunction* generatePDF;
    StatelessExternalFunction* findFop;
  public:
    XSLFOModule() :
      generatePDF(new GeneratePDFFunction(this)),
      findFop(new FindApacheFopFunction(this))
  {}
    ~XSLFOModule() {
      delete generatePDF;
      delete findFop;
    }

    virtual String getURI() const { return XSL_MODULE_NAMESPACE; }

    virtual StatelessExternalFunction* getExternalFunction(const String& localName);

    virtual void destroy() {
      delete this;
    }
};

StatelessExternalFunction* XSLFOModule::getExternalFunction(const String& localName) {
  if (localName == "generator-impl") {
    return generatePDF;
  } else if (localName == "find-apache-fop") {
    return findFop;
  }
  return 0;
}

void FindApacheFopFunction::throwError(std::string aName) const {
  throw ZORBA_EXCEPTION( ZXQP0021_USER_ERROR, ERROR_PARAMS( aName ) );
}

ItemSequence_t FindApacheFopFunction::evaluate(const StatelessExternalFunction::Arguments_t& args) const
{
  std::string lDirectorySeparator(File::getDirectorySeparator());
  std::string lFopHome;
  {
    char* lFopHomeEnv = getenv("FOP_HOME");
    if (lFopHomeEnv != 0) {
      lFopHome = lFopHomeEnv;
    }
#ifdef APPLE
    else {
      // If Apache FOP is installed with Mac Ports, FOP
      // is typicaly installed in /opt/local/share/java/fop,
      // so we check here, if the installation directory can
      // be found in this directory.
      std::string lFopPath("/opt/local/share/java/fop/");
      File_t lRootDir = File::createFile(lFopPath);
      if (lRootDir->exists() && lRootDir->isDirectory()) {
        DirectoryIterator_t lFiles = lRootDir->files();
        std::string lFileName;
        // The FOP directory is in a subdirectory with the version
        // number - so we check all subdirectories to get the final
        // path.
        while (lFiles->next(lFileName)) {
          File_t lFile = File::createFile(lFopPath + lFileName);
          if (lFile->isDirectory()) {
            std::stringstream lStr(lFileName);
            double lDirDouble = 0.0;
            if (lStr >> lDirDouble) {
              if (lDirDouble != 0.0) {
                lFopHome = lFopPath + lFileName;
                break;
              }
            }
          }
        }
      }
    }
#endif
  }
  std::string lFopLibDir;
  {
    char* lEnv = getenv("FOP_LIB_DIR");
    if (lEnv != 0) {
      lFopLibDir = lEnv;
    }
#ifdef LINUX
    // on a Ubuntu installation, all required
    // jar files should be in /usr/share/java
    // if Apache FOP is installed.
    else {
      lFopLibDir = "/usr/share/java";
    }
#endif
  }
  // If neither a path to the fop install dir, nor a path
  // to the jar files was found so far, we throw an exception.
  if (lFopHome == "" && lFopLibDir == "") {
    throwError("None of the envroinment variables FOP_HOME and FOP_LIB_DIR has bin set.");
  }
  std::string lFopJarFile;
  {
    // Here we look for the fop.jar file, which should be either in $FOP_HOME/build or 
    // in the directory, where all jar files are.
    lFopJarFile = lFopHome + lDirectorySeparator + "build" + lDirectorySeparator + "fop.jar";
    std::string lFopJarFile1 = lFopJarFile;
    File_t lJarFile = File::createFile(lFopJarFile);
    if (!lJarFile->exists()) {
      lFopJarFile = lFopLibDir + lDirectorySeparator + "fop.jar";
      lJarFile = File::createFile(lFopJarFile);
      if (!lJarFile->exists()) {
        std::string errmsg = "Could not find fop.jar. If you are using Ubuntu or Mac OS X, please make sure, ";
        errmsg += "that you have installed it, else make sure, that you have set the envroinment variable ";
        errmsg += "FOP_HOME or FOP_LIB_DIR correctly. Tried '";
        errmsg +=  lFopJarFile1;
        errmsg += "' and '";
        errmsg += lFopJarFile;
        errmsg += "'.";
        throwError(errmsg);
      }
    }
  }
  std::vector<Item> lClassPath;
  lClassPath.push_back(theFactory->createString(lFopJarFile));
  {
    std::string lJarDir = lFopLibDir;
    if (lFopHome != "")
      lJarDir = lFopHome + lDirectorySeparator + "lib";
    // This is a list of all jar files, Apache Fop depends on.
    std::list<std::string> lDeps;
    lDeps.push_back("avalon-framework");
    lDeps.push_back("batik-all");
    lDeps.push_back("commons-io");
    lDeps.push_back("commons-logging");
    lDeps.push_back("serializer");
    lDeps.push_back("xalan");
    lDeps.push_back("xmlgraphics-commons");

    File_t lJarDirF = File::createFile(lJarDir);
    DirectoryIterator_t lFiles = lJarDirF->files();
    std::string lFile; size_t count = 0;
    // We check for all files, if it is a potential dependency and add it to
    // the result
    while (lFiles->next(lFile)) {
      // If the file is not a jar file, we don't do anything
      if (lFile.substr(lFile.size() - 4, std::string::npos) != ".jar")
        continue;
      for (std::list<std::string>::iterator i = lDeps.begin(); i != lDeps.end(); ++i) {
        std::string lSub = lFile.substr(0, i->size());
        if (lSub == *i) {
          std::string lFull = lJarDir + lDirectorySeparator + lFile;
          File_t f = File::createFile(lFull);
          if (f->exists() && !f->isDirectory()) {
            lClassPath.push_back(theFactory->createString(lFull));
            // We count all jar files we add to the dependencies.
            ++count;
            break;
          }
        }
      }
    }
    // Last, we check if all dependencies are found
    if (count < lDeps.size()) {
      std::string errmsg = "Could not find ";
      errmsg += lDeps.front();
      throwError(errmsg);
    }
  }
  return ItemSequence_t(new VectorItemSequence(lClassPath));
}

ItemSequence_t GeneratePDFFunction::evaluate(const StatelessExternalFunction::Arguments_t& args) const
{
  Item classPathItem;
  Iterator_t lIter = args[2]->getIterator();
  lIter->open();
  lIter->next(classPathItem);
  lIter->close();
  lIter = args[0]->getIterator();
  lIter->open();
  Item outputFormat;
  lIter->next(outputFormat);
  lIter->close();
  jthrowable lException = 0;
  static JNIEnv* env;
  try {
    env = JavaVMSingelton::getInstance(classPathItem.getStringValue().c_str())->getEnv();
    jstring outFotmatString = env->NewStringUTF(outputFormat.getStringValue().c_str());
    // Local variables
    std::ostringstream os;
    Zorba_SerializerOptions_t lOptions;
    Serializer_t lSerializer = Serializer::createSerializer(lOptions);
    jclass fopFactoryClass;
    jobject fopFactory;
    jmethodID fopFactoryNewInstance;
    jclass byteArrayOutputStreamClass;
    jobject byteArrayOutputStream;
    jobject fop;
    jmethodID newFop;
    jclass transformerFactoryClass;
    jobject transformerFactory;
    jobject transormer;
    jclass stringReaderClass;
    jobject stringReader;
    jstring xmlUTF;
    const char* xml;
    std::string xmlString;
    jclass streamSourceClass;
    jobject streamSource;
    jobject defaultHandler;
    jclass saxResultClass;
    jobject saxResult;
    jboolean isCopy;
    jbyteArray res;
    Item base64;
    String resStore;
    jsize dataSize;
    jbyte* dataElements;

    Item item;
    lIter = args[1]->getIterator();
    lIter->open();
    lIter->next(item);
    lIter->close();
    // Searialize Item
    SingletonItemSequence lSequence(item);
    lSerializer->serialize(&lSequence, os);
    xmlString = os.str();
    xml = xmlString.c_str();

    // Create an OutputStream
    byteArrayOutputStreamClass = env->FindClass("java/io/ByteArrayOutputStream");
    CHECK_EXCEPTION(env);
    byteArrayOutputStream = env->NewObject(byteArrayOutputStreamClass,
        env->GetMethodID(byteArrayOutputStreamClass, "<init>", "()V"));
    CHECK_EXCEPTION(env);

    // Create a FopFactory instance
    fopFactoryClass = env->FindClass("org/apache/fop/apps/FopFactory");
    CHECK_EXCEPTION(env);
    fopFactoryNewInstance = env->GetStaticMethodID(fopFactoryClass, "newInstance", "()Lorg/apache/fop/apps/FopFactory;");
    CHECK_EXCEPTION(env);
    fopFactory = env->CallStaticObjectMethod(fopFactoryClass, fopFactoryNewInstance);
    CHECK_EXCEPTION(env);

    // Create the Fop
    newFop = env->GetMethodID(fopFactoryClass, "newFop", "(Ljava/lang/String;Ljava/io/OutputStream;)Lorg/apache/fop/apps/Fop;");
    CHECK_EXCEPTION(env);
    fop = env->CallObjectMethod(fopFactory,
        newFop,
        outFotmatString, byteArrayOutputStream);
    CHECK_EXCEPTION(env);

    // Create the Transformer
    transformerFactoryClass = env->FindClass("javax/xml/transform/TransformerFactory");
    CHECK_EXCEPTION(env);
    transformerFactory = env->CallStaticObjectMethod(transformerFactoryClass,
        env->GetStaticMethodID(transformerFactoryClass, "newInstance", "()Ljavax/xml/transform/TransformerFactory;"));
    CHECK_EXCEPTION(env);
    transormer = env->CallObjectMethod(transformerFactory,
        env->GetMethodID(transformerFactoryClass, "newTransformer", "()Ljavax/xml/transform/Transformer;"));
    CHECK_EXCEPTION(env);

    // Create Source
    xmlUTF = env->NewStringUTF(xml);
    stringReaderClass = env->FindClass("java/io/StringReader");
    CHECK_EXCEPTION(env);
    stringReader = env->NewObject(stringReaderClass,
        env->GetMethodID(stringReaderClass, "<init>", "(Ljava/lang/String;)V"), xmlUTF);
    CHECK_EXCEPTION(env);
    streamSourceClass = env->FindClass("javax/xml/transform/stream/StreamSource");
    CHECK_EXCEPTION(env);
    streamSource = env->NewObject(streamSourceClass,
        env->GetMethodID(streamSourceClass, "<init>", "(Ljava/io/Reader;)V"), stringReader);
    CHECK_EXCEPTION(env);

    // Create the SAXResult 
    defaultHandler = env->CallObjectMethod(fop,
        env->GetMethodID(env->FindClass("org/apache/fop/apps/Fop"), "getDefaultHandler",
          "()Lorg/xml/sax/helpers/DefaultHandler;"));
    CHECK_EXCEPTION(env);
    saxResultClass = env->FindClass("javax/xml/transform/sax/SAXResult");
    CHECK_EXCEPTION(env);
    saxResult = env->NewObject(saxResultClass,
        env->GetMethodID(saxResultClass, "<init>", "(Lorg/xml/sax/ContentHandler;)V"),
        defaultHandler);
    CHECK_EXCEPTION(env);

    // Transform
    env->CallObjectMethod(transormer,
        env->GetMethodID(env->FindClass("javax/xml/transform/Transformer"), 
          "transform", 
          "(Ljavax/xml/transform/Source;Ljavax/xml/transform/Result;)V"),
        streamSource, saxResult);
    CHECK_EXCEPTION(env);

    // Close outputstream
    env->CallObjectMethod(byteArrayOutputStream,
        env->GetMethodID(env->FindClass("java/io/OutputStream"),
          "close", "()V"));
    CHECK_EXCEPTION(env);
    saxResultClass = env->FindClass("javax/xml/transform/sax/SAXResult");
    CHECK_EXCEPTION(env);

    // Get the byte array
    res = (jbyteArray) env->CallObjectMethod(byteArrayOutputStream,
        env->GetMethodID(byteArrayOutputStreamClass, "toByteArray", "()[B"));
    CHECK_EXCEPTION(env);

    // Create the result
    dataSize = env->GetArrayLength(res);
    dataElements = env->GetByteArrayElements(res, &isCopy);

    std::string lBinaryString((const char*) dataElements, dataSize);
    std::stringstream lStream(lBinaryString);
    String base64S = encoding::Base64::encode(lStream);
    Item lRes = theFactory->createBase64Binary(base64S.c_str(), base64S.length());
    return ItemSequence_t(new SingletonItemSequence(lRes));
  } catch (VMOpenException&) {
    throw ZORBA_EXCEPTION(ZXQP0021_USER_ERROR, ERROR_PARAMS("xsl-fo:VM001|ERROR: Could not start the Java VM (is the classpath set?)") );
  } catch (JavaException&) {
    jclass stringWriterClass = env->FindClass("java/io/StringWriter");
    jclass printWriterClass = env->FindClass("java/io/PrintWriter");
    jclass throwableClass = env->FindClass("java/lang/Throwable");
    jobject stringWriter = env->NewObject(
        stringWriterClass,
        env->GetMethodID(stringWriterClass, "<init>", "()V"));
    jobject printWriter = env->NewObject(
        printWriterClass, env->GetMethodID(printWriterClass, "<init>", "(Ljava/io/Writer;)V"), stringWriter);
    env->CallObjectMethod(lException, env->GetMethodID(throwableClass, "printStackTrace", "(Ljava/io/PrintWriter;)V"), printWriter);
    //env->CallObjectMethod(printWriter, env->GetMethodID(printWriterClass, "flush", "()V"));
    jmethodID toStringMethod = env->GetMethodID(stringWriterClass, "toString", "()Ljava/lang/String;");
    jobject errorMessageObj = env->CallObjectMethod(
        stringWriter, toStringMethod);
    jstring errorMessage = (jstring) errorMessageObj;
    const char *errMsg = env->GetStringUTFChars(errorMessage, 0);
    std::stringstream s;
    s << "A Java Exception was thrown:" << std::endl << errMsg;
    env->ReleaseStringUTFChars(errorMessage, errMsg);
    std::string err("JAVA_ERROR|");
    err += s.str();
    env->ExceptionClear();
    throw ZORBA_EXCEPTION(ZXQP0021_USER_ERROR, ERROR_PARAMS( err ));
  }
  return ItemSequence_t(new EmptySequence());
}

}}; // namespace zorba, xslfo

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::xslfo::XSLFOModule();
}
