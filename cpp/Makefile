CC=g++
CFLAGS=-c -Wall -g -O0
ODIR = bin
SDIR = src
OUT = histogram

_OBJS = \
 Histogram.o\
 IO.o\
 main.o

OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

all: $(OUT)

$(ODIR)/%.o: $(SDIR)/%.cpp;
	@mkdir bin 2>/dev/null;\
	$(CC) $(CFLAGS) -o $@ $<;\
	printf "."

$(OUT): $(OBJS);
	@$(CC) $(OBJS) -o $(OUT);\
	printf ".\n"

.PHONY: clean
clean: ;
	@rm -rf $(OUT) bin
