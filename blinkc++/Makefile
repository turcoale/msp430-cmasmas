###########################################
#
#  Created on: Apr 28, 2011
#      Author: mark
#
#     Copyright (c) 2011 Engine12, LLC
#
#	   www.engine12.com
#
###########################################

TOOLCHAIN   = msp430
CC          = $(TOOLCHAIN)-gcc
CXX          = $(TOOLCHAIN)-g++
AS          = $(TOOLCHAIN)-gcc -x assembler-with-cpp
#AS          = $(TOOLCHAIN)-as
LD          = $(TOOLCHAIN)-ld 
OBJCOPY     = $(TOOLCHAIN)-objcopy
OBJDUMP     = $(TOOLCHAIN)-objdump
AR          = $(TOOLCHAIN)-ar
RANLIB      = $(TOOLCHAIN)-ranlib
STRIP       = $(TOOLCHAIN)-strip
DEBUG       =  -gdwarf-2
#DEBUG      =  -DNDEBUG



PROJECT = led
MCU  = msp430x2231

GCCPATH=/opt/msp430-gcc-4.4.5

PATH := ${PATH}:${GCCPATH}/bin

#SRC = main.c

CPPSRC = 	main.cpp \
#			CTimer.cpp\
#			mini_cpp.cpp
	
ASRC = 		DCO_Library.s

# Define optimization level here -O0 -O1 -O2 -Os -03
#s = optimize for size.
OPT = -O0
	
OBJS    = $(SRC:.c=.o) $(ASRC:.s=.o) $(CPPSRC:.cpp=.o)

MCFLAGS = -mmcu=$(MCU)

ASFLAGS = $(MCFLAGS) $(DEBUG)  -I$(GCCPATH)/include/ -I$(GCCPATH)/include/msp430/

CFLAGS=$(OPT) -Wall  $(MCFLAGS) $(DEBUG) -I$(GCCPATH)/include/ -I$(GCCPATH)/include/msp430/

CPPFLAGS=$(OPT) -Wall $(MCFLAGS) $(DEBUG) -fomit-frame-pointer -fverbose-asm -I$(GCCPATH)/include/ -I$(GCCPATH)/include/msp430/
CPPFLAGS += -fno-rtti -fno-exceptions

OBJS = $(SRC:.c=.o) $(ASRC:.s=.o) $(CPPSRC:.cpp=.o)

all: $(OBJS) $(PROJECT).elf $(PROJECT).lst $(PROJECT).hex $(PROJECT).strip

%o : %c
	$(CC) -c $(CFLAGS) -I . $(INCDIR) $< -o $@

%o : %cpp
	$(CXX) -c $(CPPFLAGS) -I . $(INCDIR) $< -o $@ 

%o : %s
	$(AS) -c $(ASFLAGS) $< -o $@

		
%elf: $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(PROJECT).elf $(OBJS)
#	$(CC)  $(CFLAGS)   -o $(PROJECT).elf $(OBJS)

%strip: %elf
	$(STRIP) $(PROJECT).elf -o $(PROJECT).strip

%lst: %elf
	$(OBJDUMP) -dSst $< > $@

%hex: %elf
	$(OBJCOPY) -O ihex -S $< $@
		
		
clean:
	rm -fr $(PROJECT).elf $(PROJECT).lst $(PROJECT).hex $(PROJECT).bin $(OBJS)
