
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


plan_visitor_test:
	$(MAKE) test -C runtime


.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) $(TARGET) -C $@
