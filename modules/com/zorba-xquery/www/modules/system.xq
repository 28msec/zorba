(:
 : Copyright 2006-2009 The FLWOR Foundation.
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
(:~
 : The system module allows users to access information of the operating
 : system and the XQuery processor.
 : The properties which are accessible are all environment variables plus
 : the ones listed in this module as variables.
 : The variables are just defining string and are only there for a better
 : user experiance.
 :
 : @author Markus Pilman
 :)
module namespace system = 'http://www.zorba-xquery.com/modules/system';

(:~
 : The name of the operating system.
 :)
declare variable $system:os-name as xs:string := "os.name";

(:~
 : The name of the computer the process is running on.
 :)
declare variable $system:os-node-name as xs:string := "os.node.name";

(:~
 : ONLY WINDOWS: The major version number of the Windows installation or
 : an empty string if the process does not run on a Windows installation.
 :)
declare variable $system:os-version-major as xs:string := "os.version.major";

(:~
 : ONLY WINDOWS: The minor version number of the Windows installation or
 : an empty string if the process does not run on a Windows installation.
 :)
declare variable $system:os-version-minor as xs:string := "os.version.minor";

(:~
 : ONLY WINDOWS: The build number of the Windows installation or
 : an empty string if the process does not run on a Windows installation.
 :)
declare variable $system:os-version-build as xs:string := "os.version.build";

(:~
 : ONLY UNIX: The release of this UNIX installation or
 : an empty string if the process does not run on a UNIX/Linux installation.
 :)
declare variable $system:os-version-release as xs:string := "os.version.release";
(:~
 : ONLY UNIX: The version of this UNIX installation or
 : an empty string if the process does not run on a UNIX/Linux installation.
 :)
declare variable $system:os-version-version as xs:string := "os.version.version";

(:~
 : The version of the Operating System.
 :)
declare variable $system:os-version as xs:string := "os.version";

(:~
 : The name of the processor architecture (for example x86 or x86_64).
 :)
declare variable $system:os-arch as xs:string := "os.arch";

(:~
 : The linux distribution, zorba is running on. This of course is only
 : available under Linux.
 :)
declare variable $system:linux-distributor as xs:string := "linux.distributor";

(:~
 : The version of the linux distribution, zorba is running on. This of course is only
 : available under Linux.
 :)
declare variable $system:linux-distributor-version as xs:string := "linux.distributor.version";

(:~
 : The username, with which this process was started.
 :)
declare variable $system:user-name as xs:string := "user.name";

(:~
 : The zorba module path, that is the paths in which zorba looks
 : for modules.
 :)
declare variable $system:zorba-module-path as xs:string := "zorba.module.path";

(:~
 : Helper variable to get the zorba version in the format Major.Minor.Patch
 :)
declare variable $system:zorba-version as xs:string := "zorba.version";

(:~
 : Helper variable to get the zorba major version
 :)
declare variable $system:zorba-version-major as xs:string := "zorba.version.major";

(:~
 : Helper variable to get the zorba minor version
 :)
declare variable $system:zorba-version-minor as xs:string := "zorba.version.minor";

(:~
 : Helper variable to get the zorba patch version
 :)
declare variable $system:zorba-version-patch as xs:string := "zorba.version.patch";

(:~
 : Gets a property with a given name. If the property is not found, the function
 : will return an empty sequence. To access a environment variable, the user needs
 : to prefix the name of the variable with "env.". For example: to get the PATH,
 : one can use system:property("env.PATH").
 :
 : @param $name The name of the property.
 : @return The value of the asked property.
 :)
declare %nondeterministic function system:property($name as xs:string) as xs:string? external;

(:~
 : This function retrieves all names of all defined properties. These are
 : the ones defined in this module as variables and all defined environment
 : variables.
 :
 : @return A list of all property names.
 :)
declare %nondeterministic function system:properties() as xs:string* external;

