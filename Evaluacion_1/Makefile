TARGET = $(BINDIR)/main
INCDIR = ./inc
OBJDIR = ./obj
BINDIR = ./bin
SRCDIR = ./src
CPPFLAGS = -Wall -I$(INCDIR)
CC = g++
OBJS   = $(OBJDIR)/main.o \
		 $(OBJDIR)/Node.o \
		 $(OBJDIR)/Restrictions.o

$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(TARGET)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) -c -MD $(CPPFLAGS) $< -o $@

-include $(OBJDIR)/*.d

.PHONY: clean
clean: 
	rm -r $(OBJDIR) $(BINDIR)