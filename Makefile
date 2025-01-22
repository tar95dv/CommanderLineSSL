CXX=g++
CXXFLAGS=-Wall -lfmt -lmenu -lpanel -lform -lncurses -lcrypto
SOURCES=./src/main.cpp ./src/hot_keys.cpp ./src/fenster.cpp ./src/kryptographie.cpp ./src/settings_theme.cpp
HEADERS=./include/global.h ./include/hot_keys.h ./include/fenster.h ./include/kryptographie.h ./include/settings_theme.h


all: ./src/main.cpp
	$(CXX) -o ./build/main $(SOURCES) $(HEADERS) $(CXXFLAGS)

clean:
	rm -f ./build/*
