SET(MAPM_SRCS
  mapm5sin.c
  mapm_add.c
  mapm_cpi.c
  mapm_div.c
  mapm_exp.c
  mapm_fam.c
  mapm_fft.c
  mapm_flr.c
  mapm_fpf.c
  mapm_gcd.c
  mapm_lg2.c
  mapm_lg3.c
  mapm_lg4.c
  mapm_log.c
  mapm_mul.c
  mapm_pow.c
  mapm_rcp.c
  mapm_rnd.c
  mapm_set.c
  mapm_sin.c
  mapmasin.c
  mapmasn0.c
  mapmcbrt.c
  mapmcnst.c
  mapmfact.c
  mapmfmul.c
  mapmgues.c
  mapmhasn.c
  mapmhsin.c
  mapmipwr.c
  mapmistr.c
  mapmpwr2.c
  mapmrsin.c
  mapmsqrt.c
  mapmstck.c
  mapmutil.c
  mapmutl1.c
  mapmutl2.c)


IF (MSVC)
  ADD_LIBRARY(mapm ${MAPM_SRCS})
ELSE (MSVC)
  ADD_LIBRARY(mapm SHARED ${MAPM_SRCS})
ENDIF (MSVC)

SET(requiredlibs ${requiredlibs} mapm)  
