TARGET := euler_007.elf

SRC := main.c

CFLAGS := -pedantic -Wall -Wextra  
CFLAGS += -Wno-coverage-mismatch  -Wdouble-promotion
CFLAGS += -Wmissing-include-dirs
CFLAGS += -Wswitch-default  -Wswitch-enum
CFLAGS += -Wunused-parameter  -Wstrict-overflow=5
CFLAGS += -Wtrampolines  -Wfloat-equal  -Wdeclaration-after-statement
CFLAGS += -Wshadow  -Wbad-function-cast  -Wcast-qual
CFLAGS += -Wcast-align  -Wconversion  -Wjump-misses-init
CFLAGS += -Wlogical-op  -Waggregate-return  -Wstrict-prototypes
CFLAGS += -Wmissing-prototypes  -Wnormalized=nfkc  -Wpacked
CFLAGS += -Wpacked-bitfield-compat
CFLAGS += -Wnested-externs  -Winline  -Winvalid-pch
CFLAGS += -Wvla  -Wstack-protector

CFLAGS += -Wformat=2
CFLAGS += -Wcomment  -Winit-self 

CFLAGS += -fstack-usage -fstack-protector-all
CFLAGS += -pipe  -std=gnu99  -g3 -O2
CFLAGS += -D_FORTIFY_SOURCE=2

all: $(SRC)  Makefile
	gcc $(CFLAGS) -o $(TARGET) $(SRC)

clean: 
	-rm $(TARGET)
	-rm *~  main.su
	-rm core*


