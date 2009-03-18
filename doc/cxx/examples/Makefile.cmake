# Copyright 2006-2008 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LDLIBS = -lzorba_simplestore -licuuc -licudata -licui18n 
CPPFLAGS = -I@CMAKE_INSTALL_PREFIX@/include/zorba
LDFLAGS = -L@CMAKE_INSTALL_PREFIX@/lib

all: examples

examples: examples.cpp simple.cpp sax2.cpp errors.cpp context.cpp serialization.cpp chaining.cpp external_functions.cpp datamanager.cpp uri_resolvers.cpp debugger.cpp
