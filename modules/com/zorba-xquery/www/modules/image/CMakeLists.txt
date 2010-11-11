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
#
FIND_PACKAGE(ImageMagick COMPONENTS Magick++ MagickCore MagickWand)

IF (ImageMagick_FOUND)
  MESSAGE(STATUS "Found ImageMagick include dirs ${ImageMagick_INCLUDE_DIRS}")
  MESSAGE(STATUS "Found ImageMagick libraries ${ImageMagick_LIBRARIES}")

  INCLUDE_DIRECTORIES("${ImageMagick_INCLUDE_DIRS}")
  ADD_LIBRARY(image_commons STATIC image.xq.src/image_function.cpp image.xq.src/image_module.cpp) 
  ADD_LIBRARY(image_c STATIC image_c.src/draw_in_c.cpp) 
  TARGET_LINK_LIBRARIES(image_commons ${ImageMagick_LIBRARIES})
  INCLUDE_DIRECTORIES("image.xq.src")
  INCLUDE_DIRECTORIES("image_c.src")
  GENERATE_MODULE_LIBRARY(basic "image_c;image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(manipulation "image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(paintschema "image_c;image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(animation "image_commons;${ImageMagick_LIBRARIES}")

ELSE (ImageMagick_FOUND)
  MESSAGE(STATUS "Magick++   component found: ${ImageMagick_Magick++_FOUND}")
  MESSAGE(STATUS "MagickCore component found: ${ImageMagick_MagickCore_FOUND}")
  MESSAGE(STATUS "MagickWand component found: ${ImageMagick_MagickWand_FOUND}")

  MESSAGE(STATUS "If you want to use image handling functionality please install the ImageMagick library containing these 3 components: Magick++, MagickCore, MagickWand.\n Please note that on some OS\n- ImageMagick and\n- libMagick++ (on OpenSuse) or ImageMagick-c++(on Fedora)\n are 2 different packages and you need to install both of them and additionally their development packages.")
ENDIF (ImageMagick_FOUND)
