TARGET = main
OBJS = main.o
CFLAGS = -Wall

$(TARGET): $(OBJS)
	g++ $(CFLAGS) $(OBJS) -o $(TARGET)

%.o : %.cpp
	g++ -c $(CFLAGS) $< -o $@



.PHONY: clean
clean: 
	rm *.o $(TARGET)