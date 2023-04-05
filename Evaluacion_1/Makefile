TARGET = $(BINDIR)/main
INCDIR = ./inc
OBJDIR = ./obj
BINDIR = ./bin
SRCDIR = ./src
TESTDIR = ./testing
CPPFLAGS = -Wall -I$(INCDIR)
CC = g++
OBJS   = $(OBJDIR)/main.o \
		 $(OBJDIR)/State.o \
		 $(OBJDIR)/Stack.o \
		 $(OBJDIR)/Game.o \
		 $(OBJDIR)/Restrictions.o

TESTOBJS = $(OBJDIR)/Binary.o \

$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(TARGET)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) -c -MD $(CPPFLAGS) $< -o $@

-include $(OBJDIR)/*.d

.PHONY: clean
clean: 
	rm -f -r $(OBJDIR) $(BINDIR)