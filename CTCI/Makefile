MAKEFLAGS+=-j16

SRCDIR:=.
OBJDIR:=obj
DEPDIR:=dep

SRCS:=$(shell find $(SRCDIR) -name "*.cpp")
OBJS:=$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS:=$(SRCS:$(SRCDIR)/%.cpp=$(DEPDIR)/%.d)
TREE:=$(patsubst %/,%,$(dir $(OBJS)))
CPPFLAGS=-MMD -MP -MF $(@:$(OBJDIR)/%.o=$(DEPDIR)/%.d)

.PHONY: all clean

all: $(OBJS)

.SECONDEXPANSION:
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $$(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

$(TREE): %:
	mkdir -p $@
	mkdir -p $(@:$(OBJDIR)%=$(DEPDIR)%)

clean:
	$(RM) -r $(OBJDIR) $(DEPDIR)

ifeq "$(MAKECMDGOALS)" ""
-include $(DEPS)
endif