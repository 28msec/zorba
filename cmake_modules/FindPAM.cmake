# Try to find the PAM libraries
#
# PAM_FOUND       - True if PAM library found
# PAM_INCLUDE_DIR - Directory to include to get PAM headers
# PAM_LIBRARIES   - Libraries to link against for the PAM library

if (PAM_INCLUDE_DIR AND PAM_LIBRARY)
 # Already in cache, be silent
 set(PAM_FIND_QUIETLY TRUE)
endif (PAM_INCLUDE_DIR AND PAM_LIBRARY)

find_path(PAM_INCLUDE_DIR NAMES security/pam_appl.h pam/pam_appl.h)
find_library(PAM_LIBRARY pam)
find_library(DL_LIBRARY dl)

if (PAM_INCLUDE_DIR AND PAM_LIBRARY)
 set(PAM_FOUND TRUE)
  if (DL_LIBRARY)
    set(PAM_LIBRARIES ${PAM_LIBRARY} ${DL_LIBRARY})
  else (DL_LIBRARY)
    set(PAM_LIBRARIES ${PAM_LIBRARY})
  endif (DL_LIBRARY)
endif (PAM_INCLUDE_DIR AND PAM_LIBRARY)