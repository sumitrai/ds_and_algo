TOPDIR=..
include $(TOPDIR)/include.mk

SRC_FILES=$(shell ls *.c)
OBJ_FILES=$(SRC_FILES:.c=.o)
BINS=$(SRC_FILES:.c=)

all: $(BINS)

bt_%: bt_%.o $(ARCHIVE)
	make -C $(TOPDIR) archive  # always update upper libraries
	$(CC) $^ -o $@

ut_%: ut_%.o $(ARCHIVE)
	make -C $(TOPDIR) archive  # always update upper libraries
	$(CC) $^ -o $@

%: %.o $(ARCHIVE)
	make -C $(TOPDIR) archive  # always update upper libraries
	$(CC) $^ -o $@
	
.PHONY: run
run: $(BINS)
	@echo "=================================================="
	@echo "Test Cases Begin"
	@echo "=================================================="	
	for file in $(BINS); do ./$$file; done
	@echo "=================== END =========================="

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) $(BINS)
