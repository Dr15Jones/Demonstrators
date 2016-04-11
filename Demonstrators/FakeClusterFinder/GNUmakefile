#
# This is an example GNUmakefile for my packages
#

# specific names for this package
DICT  = Demonstrators_FakeClusterFinderDict
SHLIB = libDemonstrators_FakeClusterFinder.so
SOURCES = $(filter-out $(DICT).cxx, $(wildcard *.cxx))
FMWK_HEADERS = LinkDef.h $(DICT).h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))
OBJECTS = $(SOURCES:.cxx=.o)

# include options for this package
INCFLAGS = -I$(LARLITE_USERDEVDIR)/Demonstrators  #Include itself
INCFLAGS += $(shell larlite-config --includes)
INCFLAGS += -I$(LARDATAOBJ_INC)
INCFLAGS += -I$(LARCOREOBJ_INC)

# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)

# CINT flag
CINTFLAGS += "-p"

LDFLAGS += $(shell larlite-config --libs)
LDFLAGS += -L$(LARDATAOBJ_LIB) -llardataobj_RecoBase

include $(LARLITE_BASEDIR)/Makefile/Makefile.${OSNAME}

# call the common GNUmakefile
include $(LARLITE_BASEDIR)/Makefile/GNUmakefile.CORE

