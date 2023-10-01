#include "Player.h"
#include <GL/glut.h>

Player::Player(float startX, float startY, float barWidth, float barHeight, float scoreX, float scoreY)
    : playerBar(startX, startY, barWidth, barHeight), playerScore(scoreX, scoreY) {}

const Bar& Player::getBar() const {
    return playerBar;
}

const Score& Player::getScore() const {
    return playerScore;
}

void Player::moveBarUp(int maxY, int barSpeed) {
    // Verifique se a barra está abaixo do limite superior
    if (playerBar.getY() + playerBar.getHeight() + barSpeed <= maxY) {
        playerBar.moveUp(barSpeed);
    }
}

void Player::moveBarDown(int minY, int barSpeed) {
    // Verifique se a barra está acima do limite inferior
    if (playerBar.getY() - barSpeed >= minY) {
        playerBar.moveDown(barSpeed);
    }
}

void Player::increaseScore() {
    playerScore.increaseScore();
}

void Player::draw() const {
    // Desenha a barra do jogador
    playerBar.draw();
    // Exibe a pontuação
    playerScore.draw();
}
