
SUBDIRS		= \
				context \
				errors \
				exprtree \
				functions \
				listeners \
				parser \
				runtime \
				testing \
				types \
				utf8 \
				util \
				serialization \
				store

# Include global Makefile rules
ROOT_PATH		= .
include $(ROOT_PATH)/Makefile.rules


query_exec:
	$(MAKE) test -C testing
