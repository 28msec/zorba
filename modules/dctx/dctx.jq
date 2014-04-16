jsoniq version "1.0";

(:
 : Copyright 2006-2014 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

(:===========================================================================:)

(:~
 : This module provides functions that gets components of the dynamic context.
 :
 : @author Federico Cavalieri
 : @project Zorba/Dynamic Context
 :)
module namespace dctx = "http://zorba.io/modules/dctx";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : <p>Retrieves the current snapshot id.</p>
 :
 : <p>The returned id is opaque and should not be used for reasoning about time.
 : The only guarantee is that the value returned by this function increases each
 : time a snapshot finishes.</p>
 :
 : @return the current snapshot id.
 :)
declare function dctx:snapshot-id()
  as xs:unsignedLong external;
