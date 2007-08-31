
# SUBDIRS		= \
# 				context \
# 				dom \
# 				errors \
# 				exprtree \
# 				functions \
# 				listeners \
# 				parser \
# 				runtime \
# 				store \
# 				testing \
# 				types \
# 				util \
# 				values \
# 				zorba
				
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
				util \
				store


all: TARGET=all
all: subdirs


test: TARGET=test
test: subdirs

clean: TARGET=clean
clean: subdirs


query_exec:
	$(MAKE) test -C testing


.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) $(TARGET) -C $@
