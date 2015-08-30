#  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
#
#  Use, modification and distribution is subject to the Boost Software
#  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt)

CC=cc
CFLAGS=-c -Wfatal-errors -Wall -Wno-missing-braces -std=c++14 -MD -MP -I../terse/detail -Iexternal
LDFLAGS=-lstdc++
OBJDIR=obj
vpath %.cpp src
SOURCES=\
	alg_caller.cpp\
	algorithm_dst_concrete.cpp\
	algorithm_dst_default.cpp\
	algorithm_dst_template.cpp\
	dst_default.cpp\
	dst_elem.cpp\
	dst_template.cpp\
	methods.cpp\
	numeric_dst_concrete.cpp\
	numeric_dst_default.cpp\
	numeric_dst_template.cpp\
	src_elem.cpp\
	performance.cpp\
	tests.cpp
OBJECTS=$(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE=tests
.PHONY: all clean

all: $(SOURCES) $(EXECUTABLE)
clean:
	@rm -rf $(EXECUTABLE) $(OBJDIR) $(DEPEND)

$(OBJECTS): | $(OBJDIR)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)/%.o: %.cpp
	$(CC) -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)

-include $(patsubst %.cpp,$(OBJDIR)/%.d,$(SOURCES))
