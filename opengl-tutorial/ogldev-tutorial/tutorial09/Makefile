CC := gcc
CXX := g++

LIBS := -lGL -lGLEW -lglut -lassimp

PWD := $(shell pwd)
INCDIR := $(PWD)/../include
COMMONDIR := $(PWD)/../common

CXXFLAGS := -I$(PWD)/.. -I$(INCDIR)
SRCFILES := $(wildcard ./*.cpp) $(wildcard $(COMMONDIR)/*.cpp)

TARGET := tutorial09

OBJS := $(SRCFILES:.cpp=.o)
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(TARGET) *.o $(COMMONDIR)/*.o