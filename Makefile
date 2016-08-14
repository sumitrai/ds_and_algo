TOPDIR=$(PWD)
include $(TOPDIR)/include.mk

main: main.o $(ARCHIVE)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

archive: $(ARCHIVE)

$(ARCHIVE): lib/list.o
	ar -r $(ARCHIVE) lib/*.o

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

.PHONY: tags
tags:
	find $(TOPDIR) -type f -name "*.[ch]" | xargs ctags
	find -type f -name "*.[ch]" -exec etags -a {} \;

.PHONY: clean
clean:
	rm -f  *.a *.o lib/*.o main tags TAGS

.PHONY: help
help:
	@echo "============ Build Targets ============"
	@echo "main       compile main binary from main.c"
	@echo "archive    export all library functions as $(ARCHIVE) that your application"
	@echo "           can linked against"
	@echo
	@echo "============ Cleaning Targets ============"
	@echo "clean      clean the source by deleting all object/archive/tag files"
	@echo
	@echo "============ Other Targets ============"
	@echo "tags       create tag files for vim/emacs"
