# Copyright 2006-2013 The FLWOR Foundation.
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

ADD_SUBDIRECTORY(util-tests)
ADD_SUBDIRECTORY(atomic)
ADD_SUBDIRECTORY(full-text)
ADD_SUBDIRECTORY(functx)
ADD_SUBDIRECTORY(dateTime)
ADD_SUBDIRECTORY(ftp-client)
ADD_SUBDIRECTORY(http-client)
ADD_SUBDIRECTORY(item)
ADD_SUBDIRECTORY(json)
ADD_SUBDIRECTORY(jsound)
ADD_SUBDIRECTORY(org)
ADD_SUBDIRECTORY(schema)
ADD_SUBDIRECTORY(sctx)
ADD_SUBDIRECTORY(dctx)
ADD_SUBDIRECTORY(sequence)
ADD_SUBDIRECTORY(sleep)
ADD_SUBDIRECTORY(store)
ADD_SUBDIRECTORY(structured-items)
ADD_SUBDIRECTORY(uri)
ADD_SUBDIRECTORY(w3c)
ADD_SUBDIRECTORY(xml)    
ADD_SUBDIRECTORY(xqdoc)
ADD_SUBDIRECTORY(zorba-query)
ADD_SUBDIRECTORY(reflection)

IF (ZORBA_WITH_DEBUGGER)
  ADD_SUBDIRECTORY(debugger)
ENDIF (ZORBA_WITH_DEBUGGER)

ADD_DEFINITIONS(-Dzorba_EXPORTS)
ADD_SUBDIRECTORY(util-curl)
REMOVE_DEFINITIONS(-Dzorba_EXPORTS)

# Add external module projects - any subdirectories of a directory
# named "zorba_modules" as a sibling to the main Zorba source
# directory.

# This is complicated and more than a little hacky. We need to add all
# the module subdirectories, but some may depend on others so we can't
# simply add them alphabetically. Here we determine their project
# names and dependencies by manually reading their CMakeLists.txt
# files (as text files). We form a directed graph (which isn't easy in
# CMake) then produce a topological sort to load the modules in
# order. Note that this will not work if there are cyclical
# dependencies between modules; if we ever need that ability, this
# will get more complicated.

FILE (GLOB modules_dir_items
  RELATIVE "${ZORBA_MODULES_DIR}"
  "${ZORBA_MODULES_DIR}/[a-zA-Z0-9]*")

# Filter out non-directories
SET (module_dirs)
FOREACH (module_dir ${modules_dir_items})
  IF (IS_DIRECTORY "${ZORBA_MODULES_DIR}/${module_dir}")
    LIST(APPEND module_dirs "${module_dir}")
  ENDIF (IS_DIRECTORY "${ZORBA_MODULES_DIR}/${module_dir}")
ENDFOREACH (module_dir)

# First, form a simple list of all known module projects in the
# variable "module_projects". Also, for each project, set a variable
# named eg. "zorba-email-module_DIR" with the path to that project's
# directory, relative to ZORBA_MODULES_DIR.
SET (project_regex "[Pp][Rr][Oo][Jj][Ee][Cc][Tt] *\\( *([^ )]*)")
SET (module_projects)
FOREACH (module_dir ${module_dirs})
  SET (module_project)
  SET (cmakelists_file "${ZORBA_MODULES_DIR}/${module_dir}/CMakeLists.txt")
  FILE (STRINGS "${cmakelists_file}" cmakelists REGEX "${project_regex}")
  FOREACH (line ${cmakelists})

    IF (line MATCHES "${project_regex}")
      IF (NOT "${module_project}" STREQUAL "")
	MESSAGE (FATAL_ERROR
	  "${cmakelists_file} contains duplicate PROJECT() statements - "
	  "cannot parse!")
      ENDIF (NOT "${module_project}" STREQUAL "")
      SET (module_project "${CMAKE_MATCH_1}")
      LIST (APPEND module_projects "${module_project}")
      SET ("${module_project}_DIR" "${module_dir}")

      # Print the found module name
      SET (status "Found module project ${module_project}")
      STRING (LENGTH "${status}" statuslen)
      SET (border "")
      FOREACH (i RANGE 1 ${statuslen})
        # The '+' is as in "zorba addition"
        SET (border "${border}+")
      ENDFOREACH (i)
      MESSAGE (STATUS "${border}")
      MESSAGE (STATUS "${status}")
      MESSAGE (STATUS "${border}")

    ENDIF (line MATCHES "${project_regex}")
  ENDFOREACH (line)

  IF (NOT module_project)
    MESSAGE (FATAL_ERROR "Directory ${ZORBA_MODULES_DIR}/${module_dir} "
      "does not contain a recognizable CMake project.")
  ENDIF (NOT module_project)

ENDFOREACH (module_dir)

# Next, form the DAG. This comprises one list containing only those
# module projects that some other module project depends on
# (dep_module_projects), and a series of CMake variables named
# eg. "zorba-email-module_DEPS" containing the module projects that
# the named project depends on. Doing this unfortunately requires us
# to read through all CMakeLists.txt files again.
SET (find_package_regex
  "[Ff][Ii][Nn][Dd]_[Pp][Aa][Cc][Kk][Aa][Gg][Ee] *\\( *([^ )]*)")
SET (dep_module_projects)
FOREACH (module_dir ${module_dirs})
  SET (module_project)
  SET (cmakelists_file "${ZORBA_MODULES_DIR}/${module_dir}/CMakeLists.txt")
  FILE (STRINGS "${cmakelists_file}" cmakelists
    REGEX "${project_regex}|${find_package_regex}")
  FOREACH (line ${cmakelists})
    IF (line MATCHES "${project_regex}")
      # Don't have to do error checking here; was done in last pass.
      SET (module_project "${CMAKE_MATCH_1}")
    ELSEIF (line MATCHES "${find_package_regex}")
      SET (dependee ${CMAKE_MATCH_1})
      # Ensure this dependency is a known module project, and not some
      # other dependency like "Zorba" - don't want those in the DAG.
      LIST (FIND module_projects "${dependee}" is_known)
      IF (is_known GREATER -1)
	message (STATUS "${module_project} depends on ${dependee}")
	# Save the dependency in a variable based on the current project
	LIST (APPEND "${module_project}_DEPS" ${dependee})
	# Also add this dependee to dep_module_projects
	LIST (APPEND dep_module_projects ${dependee})
      ENDIF (is_known GREATER -1)
    ENDIF (line MATCHES "${project_regex}")
  ENDFOREACH (line)

ENDFOREACH (module_dir)


# Now, transform the DAG into a dependency-ordered list. See
# http://en.wikipedia.org/wiki/Topological_sorting .
SET (no_deps)
SET (visited)
SET (ordered_modules)
MACRO (VISIT mod_name)
  LIST (FIND visited "${mod_name}" is_visited)
  IF (is_visited EQUAL -1)
    # Haven't seen this module before; iterate through modules that depend on it
    LIST (APPEND visited "${mod_name}")
    FOREACH (depender ${${mod_name}_DEPS})
      VISIT ("${depender}")
    ENDFOREACH (depender)
    # Now that all modules that depend on it have been added, add this one
    LIST (APPEND ordered_modules "${mod_name}")
  ELSE (is_visited EQUAL -1)
  ENDIF (is_visited EQUAL -1)
ENDMACRO (VISIT)
# Annoying - LIST(REMOVE_DUPLICATES) dies if the list is empty.
LIST (LENGTH dep_module_projects num_deps)
IF (num_deps GREATER 0)
  LIST (REMOVE_DUPLICATES dep_module_projects)
ENDIF (num_deps GREATER 0)
FOREACH (module_project ${module_projects})
  # Only initially visit those modules projects that do NOT have any
  # module projects depending on them; that is, only visit those module
  # projects that are NOT in dep_module_projects.
  LIST (FIND dep_module_projects "${module_project}" is_dep)
  IF (is_dep EQUAL -1)
    VISIT (${module_project})
  ENDIF (is_dep EQUAL -1)

ENDFOREACH (module_project)

# Each of these projects will also want to be able to
# FIND_PACKAGE(Zorba), so add our own build dir to the CMake module
# path
LIST (APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

# Now, iterate through all the module projects again and actually add
# them to this Zorba project. Create a binary directory for them
# inside our own.
FOREACH (module_project ${ordered_modules})
  # Create the module binary directory and add it to CMAKE_PREFIX_PATH
  # so other modules can find it. Then, add the module project
  # directory.
  SET (module_dir "${${module_project}_DIR}")
  SET (module_builddir "${CMAKE_BINARY_DIR}/zorba_modules/${module_project}")
  FILE (MAKE_DIRECTORY "${module_builddir}")
  LIST (APPEND CMAKE_PREFIX_PATH "${module_builddir}")
  ADD_SUBDIRECTORY("${ZORBA_MODULES_DIR}/${module_dir}"
    "${CMAKE_BINARY_DIR}/zorba_modules/${module_project}")
ENDFOREACH (module_project)

# error and warning modules
DECLARE_ZORBA_MODULE( FILE pregenerated/zorba-errors.xq
  URI "http://zorba.io/errors" )
DECLARE_ZORBA_MODULE( FILE pregenerated/zorba-warnings.xq
  URI "http://zorba.io/warnings" )
DECLARE_ZORBA_MODULE( FILE pregenerated/jsoniq-errors.xq
  URI "http://jsoniq.org/errors" )

MESSAGE(STATUS "End modules")

# vim:set et sw=2 ts=2:
