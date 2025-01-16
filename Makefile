CXX=g++
CXXFLAGS=-Wall -lfmt -lmenu -lpanel -lform -lncurses
SOURCES=main.cpp hot_keys.cpp
HEADERS=global.h hot_keys.h


full: main.cpp
	$(CXX) -o main $(SOURCES) $(HEADERS) $(CXXFLAGS)

