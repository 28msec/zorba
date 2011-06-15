# Copyright 2006-2011 The FLWOR Foundation.
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

# Script to download external modules for Zorba.

# Usage: cmake [ -Dopt=value ...] -P DownloadModules.cmake
#   Be sure all -D options come before -P !
#   Valid options:
#      modname = short module name (see modules/ExternalModules.conf);
#                may be a semicolon-separated list
#      allmodules = if true, download all known modules
#      outdir = full path to Zorba's external modules directory to download
#               modules into (will be created if necessary)

# Figure out what directory we're running in - ExternalModules.txt is here too
get_filename_component (cwd ${CMAKE_CURRENT_LIST_FILE} PATH)

# Find SVN
FIND_PROGRAM(SVN_EXECUTABLE svn DOC "subversion command line client")
IF(NOT SVN_EXECUTABLE)
  message (FATAL_ERROR "Subversion is required; not found")
ENDIF(NOT SVN_EXECUTABLE)
set (svn "${SVN_EXECUTABLE}")

# Check parameters
if (NOT outdir)
  message (FATAL_ERROR "Please pass -Doutdir.")
endif (NOT outdir)
if (NOT IS_DIRECTORY "${outdir}")
  file (MAKE_DIRECTORY "${outdir}")
endif (NOT IS_DIRECTORY "${outdir}")

if (NOT modname AND NOT allmodules)
  message (FATAL_ERROR "Please specify either -Dmodname=<name> or -Dallmodules=1")
endif (NOT modname AND NOT allmodules)

# Load ExternalModules.conf
file (STRINGS "${cwd}/ExternalModules.conf" modlines REGEX "^[^#]")

# Iterate through each line
foreach (modline ${modlines})
  string (STRIP "${modline}" modline)
  if (modline)
    separate_arguments (_modargs UNIX_COMMAND "${modline}")
    list (GET _modargs 0 _modname)
    list (GET _modargs 1 _modvc)
    list (GET _modargs 2 _modurl)

    # See if this is a module short-name we care about
    set (_getmod)
    if (allmodules)
      set (_getmod 1)
    else (allmodules)
      list (FIND modname ${_modname} _modfound)
      if (NOT ${_modfound} EQUAL -1)
        set (_getmod 1)
      endif (NOT ${_modfound} EQUAL -1)
    endif (allmodules)

    # Ensure we recognize vc-type
    if (NOT ${_modvc} STREQUAL "svn")
      message (FATAL_ERROR "Unknown vc-type '${_modvc}' for module "
        "'${_modname}' in modules/ExternalModules.conf!")
    endif (NOT ${_modvc} STREQUAL "svn")

    # Download
    if (_getmod)
      message ("Downloading module '${_modname}'...")
      # QQQ Ridiculous and slow hack, but Sourceforge has been incredibly
      # unreliable lately so this is the best choice I've got to make
      # the remote queue semi-stable
      foreach (s 1 2)
        execute_process (COMMAND "${svn}" checkout "${_modurl}" "${_modname}"
          WORKING_DIRECTORY "${outdir}")
      endforeach (s 1 2)
    endif (_getmod)
  endif (modline)
endforeach (modline)
