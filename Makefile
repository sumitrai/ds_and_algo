TOPDIR=$(shell pwd)
include $(TOPDIR)/include.mk

all: main test

main: main.o $(ARCHIVE)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

.PHONY: test
test: $(ARCHIVE)
	make -C $(TESTS_DIR)

.PHONY:
run_tests: test
	make -C $(TESTS_DIR) run

archive: $(ARCHIVE)

$(ARCHIVE): lib/list.o lib/binary_tree.o
	ar -r $(ARCHIVE) lib/*.o

.PHONY: tags
tags: ctags etags

.PHONY: ctags
ctags:
	find $(TOPDIR) -type f -name "*.[ch]" | xargs ctags

.PHONY: etags
etags:
	find -type f -name "*.[ch]" -exec etags -a {} \;

.PHONY: clean
clean:
	rm -f  *.a *.o lib/*.o main tags TAGS
	make -C $(TESTS_DIR) clean

.PHONY: help
help:
	@echo "============ Build Targets ============"
	@echo "main       compile main binary from main.c"
	@echo "archive    export all library functions as $(ARCHIVE) that your application"
	@echo "           can linked against"
	@echo
	@echo "============ Test Targets ============"
	@echo "test       compile all the tests"
	@echo "run_tests  run all the tests"
	@echo
	@echo "============ Cleaning Targets ============"
	@echo "clean      clean the source by deleting all object/archive/tag files"
	@echo
	@echo "============ Other Targets ============"
	@echo "tags       create tag files for vim/emacs"
