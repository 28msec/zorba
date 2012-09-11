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
// Generate Java 1.5 proper enums
//include "enums.swg"
%include "enumtypeunsafe.swg"
%include "std_string.i"

// don't do a JNI call for constants and enums.
%javaconst(1);

%typemap(jni)     char *BYTE "jbyteArray"
%typemap(jtype)   char *BYTE "byte[]"
%typemap(jstype)  char *BYTE "byte[]"
%typemap(javain)  char *BYTE "$javainput"
%typemap(freearg) char *BYTE ""
%typemap(in)      char *BYTE {
    $1 = (char *) JCALL2(GetByteArrayElements, jenv, $input, 0);
}
%typemap(argout)  char *BYTE {
    JCALL3(ReleaseByteArrayElements, jenv, $input, (jbyte *)$1, 0);
}

%typemap(directorin, descriptor="[B") char *BYTE {
    jbyteArray jb = (jenv)->NewByteArray(strlen($1));
    (jenv)->SetByteArrayRegion(jb, 0, strlen($1), (jbyte*)$1);
    $input = jb;
}
%typemap(directorout) char *BYTE {
    $1 = 0;
    if($input){
        $result = (char *) jenv->GetByteArrayElements($input, 0); 
        if(!$1) 
            return $null;
        jenv->ReleaseByteArrayElements($input, $result, 0);
    }
}

%typemap(javadirectorin) char *BYTE "$jniinput"
%typemap(javadirectorout) char *BYTE "$javacall"

%include ../zorba_api.i
