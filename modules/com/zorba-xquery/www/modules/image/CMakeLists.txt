FIND_PACKAGE(ImageMagick COMPONENTS Magick++ MagickCore MagickWand)

IF (ImageMagick_FOUND)
  MESSAGE(STATUS "Found ImageMagick include dirs ${ImageMagick_INCLUDE_DIRS}")
  MESSAGE(STATUS "Found ImageMagick libraries ${ImageMagick_LIBRARIES}")

  INCLUDE_DIRECTORIES("${ImageMagick_INCLUDE_DIRS}")
  ADD_LIBRARY(image_commons STATIC image.src/image_function.cpp image.src/image_module.cpp) 
  ADD_LIBRARY(image_c STATIC image_c.src/draw_in_c.cpp) 
  TARGET_LINK_LIBRARIES(image_commons ${ImageMagick_LIBRARIES})
  INCLUDE_DIRECTORIES("image.src")
  INCLUDE_DIRECTORIES("image_c.src")
  GENERATE_MODULE_LIBRARY(basicschema "image_c;image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(manipulationschema "image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(paintschema "image_c;image_commons;${ImageMagick_LIBRARIES}")
  GENERATE_MODULE_LIBRARY(animationschema "image_commons;${ImageMagick_LIBRARIES}")

ELSE (ImageMagick_FOUND)
  MESSAGE(STATUS "Magick++   component found: ${ImageMagick_Magick++_FOUND}")
  MESSAGE(STATUS "MagickCore component found: ${ImageMagick_MagickCore_FOUND}")
  MESSAGE(STATUS "MagickWand component found: ${ImageMagick_MagickWand_FOUND}")

  MESSAGE(STATUS "If you want to use image handling functionality please install the ImageMagick library containing these 3 components: Magick++, MagickCore, MagickWand.\n Please note that on some OS ImageMagick and libMagick++ are 2 different packages and you need to install both of them.")
ENDIF (ImageMagick_FOUND)
