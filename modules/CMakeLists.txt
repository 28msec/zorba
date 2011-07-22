# Copyright 2006-2010 The FLWOR Foundation.
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

ADD_SUBDIRECTORY(com)
ADD_SUBDIRECTORY(org)
ADD_SUBDIRECTORY(functx)
ADD_SUBDIRECTORY(w3c)

# Add external module projects - any subdirectories of a directory
# named "zorba_modules" as a sibling to the main Zorba source
# directory.

# First, configure the moduleConfig.cmake file for each module
# project. We must do this "manually" before doing any
# ADD_SUBDIRECTORY()s, so that all the config files are built and
# ready for other modules' FIND_PACKAGE() calls. We also add all
# module build dirs to CMAKE_PREFIX_PATH for the same reason.
SET (project_regex "[Pp][Rr][Oo][Jj][Ee][Cc][Tt]")
FILE (GLOB modules_dir_items RELATIVE "${ZORBA_MODULES_DIR}" "${ZORBA_MODULES_DIR}/*")

# Filter out non-directories
SET (module_dirs)
FOREACH (module_dir ${modules_dir_items})
  IF (IS_DIRECTORY "${ZORBA_MODULES_DIR}/${module_dir}")
    LIST(APPEND module_dirs "${module_dir}")
  ENDIF (IS_DIRECTORY "${ZORBA_MODULES_DIR}/${module_dir}")
ENDFOREACH (module_dir)

FOREACH (module_dir ${module_dirs})
  # This is really kind of hacky, but I don't know a better solution without
  # introducing some sort of inter-module dependency tracking and requiring
  # consistent directory naming for external modules. What we do here is
  # read the module's CMakeLists.txt (as a text file), searching for the
  # PROJECT() declaration, so we can extract the name of the CMake project.
  SET (module_project)
  SET (cmakelists)
  FILE (STRINGS "${ZORBA_MODULES_DIR}/${module_dir}/CMakeLists.txt" cmakelists
    REGEX ${project_regex})
  FOREACH (line ${cmakelists})
    IF (line MATCHES "${project_regex} *\\(([^)]*)\\)")
      SET (module_project ${CMAKE_MATCH_1})

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

      BREAK ()
    ENDIF (line MATCHES "${project_regex} *\\(([^)]*)\\)")
  ENDFOREACH (line)

  IF (NOT module_project)
    MESSAGE (FATAL_ERROR "Directory ${ZORBA_MODULES_DIR}/${module_dir} "
      "does not contain a recognizable CMake project.")
  ENDIF (NOT module_project)

  SET (module_builddir "${CMAKE_BINARY_DIR}/zorba_modules/${module_project}")
  FILE (MAKE_DIRECTORY "${module_builddir}")
  CREATE_MODULE_CONFIG (${module_project} "${ZORBA_MODULES_DIR}/${module_dir}"
    "${module_builddir}")
  LIST (APPEND CMAKE_PREFIX_PATH "${module_builddir}")
  #SET (ZORBA_EXTERNAL_MODULES_SRCS ${ZORBA_EXTERNAL_MODULES_SRCS} ${ZORBA_MODULES_DIR}/${module_dir}/src)
ENDFOREACH (module_dir)
#SET (ZORBA_EXTERNAL_MODULES_SRCS ${ZORBA_EXTERNAL_MODULES_SRCS} PARENT_SCOPE)

# Each of these projects will also want to be able to
# FIND_PACKAGE(Zorba), so add our own build dir to the CMake module
# path
LIST (APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

SET(ZORBA_XQDOC_MAIN_EXTMODULES_XML_XQ  ${CMAKE_CURRENT_SOURCE_DIR}/../doc/zorba/xqdoc/src/xqdoc-main-extmodules-xml.xq CACHE PATH "The xqdoc xml generator for external modules")
SET(ZORBA_XQDOC_MAIN_EXTMODULES_HTML_XQ  ${CMAKE_CURRENT_SOURCE_DIR}/../doc/zorba/xqdoc/src/xqdoc-main-extmodules-html.xq CACHE PATH "The xqdoc html generator for external modules")
SET(ZORBA_EXTMODULE_XQDOC_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/../doc/zorba/xqdoc CACHE PATH "Dir where to store xqdoc generated files, xml and html")
SET(ZORBA_XHTML_REQUISITES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../doc/zorba/xqdoc CACHE PATH "Dir where to the html requisites are stored")

# Now, iterate through all the module projects again and actually add
# them to this Zorba project. Create a binary directory for them
# inside our own.
FOREACH (module_dir ${module_dirs})
  ADD_SUBDIRECTORY("${ZORBA_MODULES_DIR}/${module_dir}"
    "${CMAKE_BINARY_DIR}/zorba_modules/zorba_${module_dir}_module")
ENDFOREACH (module_dir)

MESSAGE(STATUS "End modules")
