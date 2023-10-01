#ifndef SCORE_H
#define SCORE_H

class Score {
public:
    Score(float x, float y); // Construtor

    int getScore() const;
    void resetScore();
    void increaseScore();
    void draw() const; // Função para desenhar a pontuação usando OpenGL

private:
    int score;
    float x;
    float y;
};

#endif