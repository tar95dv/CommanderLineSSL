CXX=g++
CXXFLAGS=-Wall -lfmt -lmenu -lpanel -lform -lncurses
SOURCES=main.cpp hot_keys.cpp fenster.cpp kryptographie.cpp settings_theme.cpp
HEADERS=global.h hot_keys.h fenster.h kryptographie.h settings_theme.h


full: main.cpp
	$(CXX) -o main $(SOURCES) $(HEADERS) $(CXXFLAGS)

