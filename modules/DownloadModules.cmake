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
#      allmodules = if true: download all known modules
#      outdir = full path to Zorba's external modules directory to download
#               modules into (will be created if necessary)
#      notags = if true: ignore tags, check out HEAD revision of module(s)
#               (bzr only - svn uses different URLs for tags)

# Figure out what directory we're running in - ExternalModules.txt is here too
get_filename_component (cwd ${CMAKE_CURRENT_LIST_FILE} PATH)

# Find SVN
FIND_PROGRAM(svn svn DOC "subversion command line client")

# Find BZR
FIND_PROGRAM(bzr bzr DOC "bazaar command line client")

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
    set (_modtag)
    list (LENGTH _modargs _modargslen)
    if (_modargslen GREATER 3)
      list (GET _modargs 3 _modtag)
    endif (_modargslen GREATER 3)

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

    # Download
    if (_getmod)
      message ("Downloading module '${_modname}'...")
      # We try three times, to account for network weirdnesses
      foreach (i 1 2 3)
	# First delete the output directory, in case there's a partial
	# download from a previous attempt
	file (REMOVE_RECURSE "${outdir}/${_modname}")

	set (_status)

	if (${_modvc} STREQUAL "svn")
          if (NOT svn)
            message (FATAL_ERROR
              "Subversion client not found - required for ${_modname} module!")
          endif (NOT svn)
          execute_process (COMMAND "${svn}" checkout "${_modurl}" "${_modname}"
            WORKING_DIRECTORY "${outdir}" TIMEOUT 60 RESULT_VARIABLE _status)

	elseif (${_modvc} STREQUAL "bzr")
          if (NOT bzr)
            message (FATAL_ERROR
              "Bazaar client not found - required for ${_modname} module!")
          endif (NOT bzr)

          set (_modtagargs)
          if (_modtag AND NOT notags)
            set (_modtagargs "-r" "${_modtag}")
          endif (_modtag AND NOT notags)
          execute_process (COMMAND "${bzr}" branch "${_modurl}" "${_modname}"
            ${_modtagargs} WORKING_DIRECTORY "${outdir}" TIMEOUT 60
	    RESULT_VARIABLE _status)

	else (${_modvc} STREQUAL "svn")
          message (FATAL_ERROR "Unknown vc-type '${_modvc}' for module "
            "'${_modname}' in modules/ExternalModules.conf!")

	endif (${_modvc} STREQUAL "svn")

	if ("${_status}" EQUAL 0)
	  # Success
	  break ()
	else ("${_status}" EQUAL 0)
	  message (WARNING "Attempt ${i}: Failed to download '${_modname}' (${_status})")
	endif ("${_status}" EQUAL 0)

      endforeach (i)
    endif (_getmod)

    # Ensure we successfully downloaded something good
    if (NOT EXISTS "${outdir}/${_modname}/CMakeLists.txt")
      message (FATAL_ERROR "Failed to download '${_modname}' after 3 attempts, giving up.")
    endif (NOT EXISTS "${outdir}/${_modname}/CMakeLists.txt")

  endif (modline)
endforeach (modline)
