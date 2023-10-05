# Nome do seu programa de saída
TARGET = game

# Compilador C++
CXX = g++

# Opções de compilação
CXXFLAGS = -std=c++11 -Wall

# Bibliotecas OpenGL, GLUT e SFML
LIBS = -lGL -lGLU -lglut -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Lista de arquivos de origem
SOURCES = main.cpp Player.cpp Score.cpp Bar.cpp Ball.cpp

# Objetos gerados a partir dos arquivos de origem
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
