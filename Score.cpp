// Score.cpp

#include "Score.h"
#include <GL/glut.h>
#include <string>

Score::Score(float x, float y)
    : score(0), x(x), y(y) {}

int Score::getScore() const {
    return score;
}

void Score::resetScore() {
    this->score = 0;
}

void Score::increaseScore() {
    this->score += 1;
}

void Score::draw() const {
    
    // Define a cor do texto (branco)
    glColor3f(1.0f, 1.0f, 1.0f);

    // Converte a pontuação (int) para uma string
    std::string scoreStr = std::to_string(score);

    // Define a posição do texto
    glRasterPos2f(x, y);

    // Renderiza o texto na posição especificada
    for (char const &c : scoreStr) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24  , c);
    }
}
