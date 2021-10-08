TOPDIR=..
include $(TOPDIR)/include.mk

SRC_FILES=$(shell ls *.c)
OBJ_FILES=$(SRC_FILES:.c=.o)
BINS=$(SRC_FILES:.c=)

all: $(BINS)

bt_%: bt_%.o $(ARCHIVE)
	make -C $(TOPDIR) archive  # always update upper libraries
	$(CC) $^ -o $@

bt_prob1_print_all_leaves: bt_prob1_print_all_leaves.o $(ARCHIVE)
	$(CC) $^ $(ARCHIVE) -o $@


slist_prob1: slist_prob1.o $(ARCHIVE)
	$(CC) $^ $(ARCHIVE) -o $@

slist: slist.o $(ARCHIVE)
	$(CC) $^ -o $@

.PHONY: run
run:
	@echo "=================================================="
	@echo "Singly Linked List Begin"
	@echo "=================================================="	

	./slist
	./slist_prob1
	@echo "=================== END =========================="

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) $(BINS)
