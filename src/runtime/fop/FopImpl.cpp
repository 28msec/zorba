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

#include "runtime/fop/FopImpl.h"

#include "store/api/item_factory.h"
#include "runtime/api/runtimecb.h"
#include "context/static_context.h"
#include "runtime/util/iterator_impl.h"
#include "zorbaerrors/error_manager.h"
#include "api/serialization/serializer.h"
#include "zorbatypes/binary.h"
#include "system/globalenv.h"

#include "util/JavaVMSingelton.h"

#include <iostream>

#define CHECK_EXCEPTION(env)  if (env->ExceptionOccurred()) env->ExceptionDescribe()


namespace zorba {
  bool ZorbaFopIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    static JNIEnv* env = JavaVMSingelton::getInstance()->getEnv();
    store::Item_t item;

    PlanIteratorState* state;

    // Local variables
    std::ostringstream os;
    error::ErrorManager lErrorManager;
    serializer lSerializer(&lErrorManager);
    jclass fopFactoryClass;
    jobject fopFactory;
    jmethodID fopFactoryNewInstance;
    jclass byteArrayOutputStreamClass;
    jobject byteArrayOutputStream;
    jclass mimeConstantsClass;
    jfieldID mimeField;
    jobject mimeType;
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
    Base64 base64;
    const char* baseString;
    std::vector<char> binData;
    std::vector<char> binDataRes;
    xqpString resStore;
    jsize dataSize;
    jbyte* dataElements;

    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
    CONSUME(item, 0);
    // Searialize Item
    lSerializer.set_parameter("omit-xml-declaration", "no");
    lSerializer.serialize(item, os);
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
    mimeConstantsClass = env->FindClass("org/apache/fop/apps/MimeConstants");
    CHECK_EXCEPTION(env);
    mimeField = env->GetStaticFieldID(mimeConstantsClass, "MIME_PDF", "Ljava/lang/String;");
    CHECK_EXCEPTION(env);
    mimeType = env->GetStaticObjectField(mimeConstantsClass, mimeField);
    CHECK_EXCEPTION(env);
    newFop = env->GetMethodID(fopFactoryClass, "newFop", "(Ljava/lang/String;Ljava/io/OutputStream;)Lorg/apache/fop/apps/Fop;");
    CHECK_EXCEPTION(env);
    fop = env->CallObjectMethod(fopFactory,
      newFop,
      mimeType, byteArrayOutputStream);
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
    for (jsize i = 0; i < dataSize; i++) {
      binData.push_back(dataElements[i]);
    }
    //resStore = new xqpStringStore(baseString, strlen(baseString));
    Base64::encode(binData, binDataRes);
    for (std::vector<char>::iterator iter = binDataRes.begin(); iter != binDataRes.end(); iter++) {
      resStore += *iter;
    }
    Base64::parseString(resStore, base64);

    STACK_PUSH(GENV_ITEMFACTORY->createBase64Binary(result, base64), state);
    STACK_END(state)
  }
}
