#ifndef PLAYER_H
#define PLAYER_H

#include "Bar.h"
#include "Score.h"

class Player {
public:
    Player(float startX, float startY, float barWidth, float barHeight, float scoreX, float scoreY); // Construtor

    const Bar& getBar() const;
    const Score& getScore() const;

    void moveBarUp(int maxY, int barSpeed);
    void moveBarDown(int minY, int barSpeed);
    void increaseScore();
    void resetScore();
    void draw() const; // Função para desenhar o jogador usando OpenGL

private:
    Bar playerBar;
    Score playerScore;
};

#endif