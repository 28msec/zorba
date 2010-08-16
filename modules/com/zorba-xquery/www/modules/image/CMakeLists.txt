FIND_PACKAGE(ImageMagick COMPONENTS Magick++ MagickCore MagickWand)

IF (ImageMagick_FOUND) 
  MESSAGE(STATUS "Found ImageMagick:  ${ImageMagick_FOUND}")
  MESSAGE(STATUS "Found ImageMagick include dirs ${ImageMagick_INCLUDE_DIRS}")
  MESSAGE(STATUS "Found ImageMagick libraries ${ImageMagick_LIBRARIES}")

  INCLUDE_DIRECTORIES("${ImageMagick_INCLUDE_DIRS}")
  ADD_LIBRARY(image_commons STATIC image.src/image_function.cpp image.src/image_module.cpp) 
  ADD_LIBRARY(image_c STATIC image_c.src/draw_in_c.cpp) 
  TARGET_LINK_LIBRARIES(image_commons ${ImageMagick_LIBRARIES})
  INCLUDE_DIRECTORIES("image.src")
  INCLUDE_DIRECTORIES("image_c.src")
  GENERATE_MODULE_LIBRARY(basic "image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(manipulation "image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(paint "image_c;image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(animation "image_commons;${ImageMagick_LIBRARIES}")


ELSE (ImageMagick_FOUND)
    MESSAGE("ImageMagick not found -- if you want to use image handling functionality please install the ImageMagick library")
ENDIF (ImageMagick_FOUND)
