
SUBDIRS		= \
				context \
				dom \
				errors \
				exprtree \
				functions \
				listeners \
				parser \
				runtime \
				store \
				types \
				util \
				values \
				zorba


all: TARGET=all
all: subdirs


test: TARGET=test
test: subdirs

clean: TARGET=clean
clean: subdirs


exec_query:
	$(MAKE) test -C testing


.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) $(TARGET) -C $@
