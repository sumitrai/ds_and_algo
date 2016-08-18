TOPDIR=..
include $(TOPDIR)/include.mk

SRC_FILES=$(shell ls *.c)
OBJ_FILES=$(SRC_FILES:.c=.o)
BINS=$(SRC_FILES:.c=)

all: slist slist_prob1

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
