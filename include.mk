CFLAGS=-g -Wall
INCLUDES=-I $(TOPDIR)/include
ARCHIVE=$(TOPDIR)/ds_algo.a
TESTS_DIR=$(TOPDIR)/tests

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
