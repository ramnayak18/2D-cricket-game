SFMLPATH = C:\\SFML-2.5.1
SFML_INC = $(SFMLPATH)\\include
SFML_LIB = $(SFMLPATH)\\lib 
LFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-network -lsfml-system
CC = g++
CFLAGS = -c
OBJS = main.o playWindow.o aboutWindow.o helpWindow.o menuWindow.o levelswindow.o tile.o pitch.o marker.o stump.o bail.o crease.o bat.o ball.o batsman.o
SRCS = *.cpp
BIN = main.exe

$(BIN): $(OBJS); \
$(CC) -o $(BIN) -L $(SFML_LIB) $(OBJS) $(LFLAGS)

$(OBJS): %.o: %.cpp; \
$(CC) $(CFLAGS) $< -I $(SFML_INC)