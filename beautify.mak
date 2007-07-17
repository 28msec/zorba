ifdef V
  ifeq ("$(origin V)", "command line")
    ifeq ($(V), 1)
      Q := ""
    else
      Q := "@"
    endif
  endif
endif
ifndef Q
  Q := "@"
endif

ifndef CXX
  CXX := c++
endif
ifndef AR
  AR := ar
endif
ifeq ($(Q), "@")
  CXX_CMD := $(CXX)
  CXX = @echo CXX  '->' $@; $(CXX_CMD)
  AR_CMD := $(AR)
  AR = @echo AR  '->' $@; $(AR_CMD)
  NO_STDOUT := >/dev/null
else
  NO_STDOUT =
endif
