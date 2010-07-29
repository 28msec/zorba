FIND_PACKAGE(ImageMagick COMPONENTS Magick++ MagickCore)

IF (ImageMagick_FOUND) 
  MESSAGE("Found ImageMagick:  ${ImageMagick_FOUND}")
  MESSAGE("Found ImageMagick include dirs ${ImageMagick_INCLUDE_DIRS}")
  MESSAGE("Found ImageMagick libraries ${ImageMagick_LIBRARIES}")

  INCLUDE_DIRECTORIES("${ImageMagick_INCLUDE_DIRS}")
  ADD_LIBRARY(image_commons STATIC image.src/image_function.cpp image.src/image_module.cpp) 
  TARGET_LINK_LIBRARIES(image_commons ${ImageMagick_LIBRARIES})
  INCLUDE_DIRECTORIES("image.src")
 
  GENERATE_MODULE_LIBRARY(basic "image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(manipulation "image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(paint "image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(animation "image_commons;${ImageMagick_LIBRARIES}")


ELSE (ImageMagick_FOUND)
    MESSAGE("ImageMagick not found -- if you want to use image handling functionality please install the ImageMagick library")
ENDIF (ImageMagick_FOUND)
