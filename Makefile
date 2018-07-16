#!/bin/make -f

ARCH      := $(shell uname -m)
CXXFLAGS  := -O3
OBJDIR    := $(ARCH)-bin
TESTDIR   := test

OBJFILES  := randomize.o
INCFILES  := dim1algebra.hpp

$(OBJDIR)/randomize.o: $(TESTDIR)/randomize.cpp $(INCFILES)
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

$(OBJDIR)/randomize: $(OBJDIR)/randomize.o
	$(CXX) $< -I. -o $@ 

all: $(OBJDIR)/randomize

.PHONY: all 
