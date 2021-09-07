include $(ROOT)/usr/include/make/PRdefs

NUSTDINCDIR = $(ROOT)/usr/include/nustd
NUSYSINCDIR = $(ROOT)/usr/include/nusys
NUSYSLIBDIR = $(ROOT)/usr/lib/nusys

LIB = $(ROOT)/usr/lib
LPR = $(LIB)/PR
INC = $(ROOT)/usr/include

LCDEFS = -DDEBUG -DNU_DEBUG -DF3DEX_GBI_2 -DN64 -DUSB_INLINE_FIX
LCINCS = -I. -I$(NUSTDINCDIR) -I$(NUSYSINCDIR) -I$(ROOT)/usr/include/PR
LCOPTS = -G 0 -O2
LDFLAGS = $(MKDEPOPT) -L$(LIB) -L$(NUSYSLIBDIR) -ln_mus_d -lnualstl_n_d -ln_audio_sc -lnusys_d -lultra_d -L$(N64_LIBGCCDIR) -lgcc -lnustd

OPTIMIZER = -g

APP = asteroids.out

TARGETS = asteroids.n64

CODEFILES = $(wildcard *.c)

CODEOBJECTS = $(CODEFILES:.c=.o) $(NUSYSLIBDIR)/nusys.o

DATAFILES =

DATAOBJECTS = $(DATAFILES:.c=.o)

CODESEGMENT = codesegment.o

OBJECTS = $(CODESEGMENT) $(DATAOBJECTS)

default: $(TARGETS)

include $(COMMONRULES)

$(CODESEGMENT): $(CODEOBJECTS) GNUmakefile
	$(LD) -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS)

$(TARGETS): $(OBJECTS) spec
	$(MAKEROM) spec -I$(NUSYSINCDIR) -r $(TARGETS) -e $(APP)
	makemask $(TARGETS)
