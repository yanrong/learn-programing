PWD := $(shell pwd)
CC := gcc
CXX := g++

COMMON := $(PWD)/../../common
CFLAGS :=
CXXFLAGS := -I$(PWD)/../../ -I$(COMMON)
LDFLAGS := -lGL -lGLEW -lglfw -ldl -lassimp

HEADERCSOURCE := $(COMMON)/glad.c
HEADERCCSOURCE := $(COMMON)/fileSystem.cc $(COMMON)/shader_s.cc \
	$(COMMON)/camera.cc $(COMMON)/model.cc $(COMMON)/mesh.cc
CCSOURCE := asteroidsInstanced.cc

CCEXECUTABLE := $(CCSOURCE:.cc=)
COBJS := $(HEADERCSOURCE:.c=.o)
CCOBJES := $(HEADERCCSOURCE:.cc=.o)

all: $(CCEXECUTABLE)

$(COBJS) : $(HEADERCSOURCE)
	$(CC) -c -o $@ $< $(LDFLAGS) $(CFLAGS)

#define explicit rule compile each cpp file to .o file
#$(COMMON)/%.o: %.cpp
#	$(CXX) -c -o $@ $< $(CXXFLAGS)
#$(COMMON)/%.o: %.c
#	$(CC) -c -o $@ $< $(CXXFLAGS)

#we add the .o file to dependency list, it will automatically generate .o by implicit rules
$(CCEXECUTABLE): $(CCSOURCE) $(COBJS) $(CCOBJES)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

.PHONY: installclean

installclean:
	rm -rf $(CCEXECUTABLE)

.PHONY: clean

clean: installclean
	rm -rf *.o $(COMMON)/*.o