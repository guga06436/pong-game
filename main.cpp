#include <GL/glut.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include "Player.h"
#include "Ball.h"

// Dimensões da janela
int const windowWidth = 800;
int const windowHeight = 600;

// Posição do placar
float const scoreCenterX = windowWidth / 2.0f;
float const scoreCenterY = windowHeight - 30.0f;

// Define velocidade inicial da bola
float const ballInitialSpeed = 0.5f;

// Define fator de velocidade da bola
float const ballSpeedInc = 0.1f;

// Define velocidade das barras
int const barSpeed = 1;

// Jogadores
Player player1(20.0f, windowHeight / 2.0f, 10.0f, 100.0f, scoreCenterX - 20.0f, scoreCenterY); // Jogador 1 à direita
Player player2(windowWidth - 20.0f, windowHeight / 2.0f, 10.0f, 100.0f, scoreCenterX + 20.0f, scoreCenterY); // Jogador 1 à esquerda

// Bola
Ball ball(windowWidth / 2.0f, windowHeight / 2.0f, 10.0f);

// Variáveis para velocidade da bola
float ballSpeedX;
float ballSpeedY;

// Variáveis para controle de teclas de cada jogador
bool keyW = false; // Tecla "W" pressionada para jogador 1
bool keyS = false; // Tecla "S" pressionada para jogador 1
bool keyUp = false; // Seta para cima pressionada para jogador 2
bool keyDown = false; // Seta para baixo pressionada para jogador 2

// Variável booleana para controlar se a função launchRandom já foi chamada
bool hasLaunched = false;

// Funcao que determina por onde a bola sera lancada no inicio
void launchRandom() {
    
    if (!hasLaunched) {
        srand(static_cast<unsigned int>(time(nullptr)));

        // Gere um ângulo aleatório entre 30 e 150 graus (ajuste conforme necessário)
        float ballAngle = rand() % 121 + 30; // Intervalo de 30 a 150 graus

        // Converta o ângulo para radianos
        float ballAngleRadians = ballAngle * M_PI / 180.0;

        // Determine a velocidade da bola com base no ângulo (ajuste a velocidade conforme necessário)
        ballSpeedX = ballInitialSpeed * cos(ballAngleRadians);
        ballSpeedY = ballInitialSpeed * sin(ballAngleRadians);

        // Escolha aleatoriamente a direção da bola (esquerda ou direita)
        if (rand() % 2 == 0) {
            ballSpeedX = -ballSpeedX; // Inverte a direção para a esquerda
        }

        // Marque que a função já foi chamada
        hasLaunched = true;
    }
}

// Função que verifica colisao nas extremidades da janela e com o jogador
void checkCollision() {
    float ballX = ball.getX();
    float ballY = ball.getY();
    float ballRadius = ball.getRadius();

    // Verifique a colisão com a parede esquerda
    if (ballX - ballRadius < 0) {
        // Implementar ponto para o player2
    }

    // Verifique a colisão com a parede direita
    else if (ballX + ballRadius > windowWidth) {
        // Implementar ponto para o player1
    }

    // Verifique a colisão com a parede superior
    else if (ballY + ballRadius > windowHeight) {
        ballSpeedY = -ballSpeedY; // Inverta a velocidade vertical para refletir na parede
    }

    // Verifique a colisão com a parede inferior
    else if (ballY - ballRadius < 0) {
        ballSpeedY = -ballSpeedY; // Inverta a velocidade vertical para refletir na parede
    }

    // Verifica colisão da bola com o player1
    else if (ballX - ballRadius < player1.getBar().getX() &&
         ballY >= player1.getBar().getY() && ballY <= player1.getBar().getY() + player1.getBar().getHeight()) {
        ballSpeedX = -ballSpeedX; // Inverta a velocidade horizontal para refletir na barra
        // Incrementa velocidade da bola
        ballSpeedX += ballSpeedInc;
        ballSpeedY += ballSpeedInc;
    }

    // Verifica colisão da bola com o player2
    else if (ballX + ballRadius > player2.getBar().getX() &&
         ballY >= player2.getBar().getY() && ballY <= player2.getBar().getY() + player2.getBar().getHeight()) {
        ballSpeedX = -ballSpeedX; // Inverta a velocidade horizontal para refletir na barra
        // Incrementa velocidade da bola
        ballSpeedX -= ballSpeedInc; 
        ballSpeedY -= ballSpeedInc;
    }
    
}

// Função para movimentar as barras dos jogadores
void movePlayersBars() {
    if (keyW) {
        player1.moveBarUp(windowHeight, barSpeed);
    }
    if (keyS) {
        player1.moveBarDown(0, barSpeed);
    }
    if (keyUp) {
        player2.moveBarUp(windowHeight, barSpeed);
    }
    if (keyDown) {
        player2.moveBarDown(0, barSpeed);
    }
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Movimente as barras dos jogadores
    movePlayersBars();

    // Desenha os jogadores
    player1.draw();
    player2.draw();

    // Verifica se houve colisao da bola com a parede
    checkCollision();

    // Atualiza a posição da bola
    ball.move(ballSpeedX, ballSpeedY);

    // Desenha a bola
    ball.draw();

    glutSwapBuffers();
}

void eventNormalKey(GLubyte key, GLint x, GLint y){
    if(key == 'w' || key == 'W')
        keyW = true;
    
    if(key == 's' || key == 'S')
        keyS = true;

    glutPostRedisplay();
}

void eventNormalKeyUp(GLubyte key, GLint x, GLint y){
    if(key == 'w' || key == 'W')
        keyW = false;
    
    if(key == 's' || key == 'S')
        keyS = false;

    glutPostRedisplay();
}

void eventSpecialKey(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        keyUp = true;
    }
    
    if (key == GLUT_KEY_DOWN) {
        keyDown = true;
    }

    glutPostRedisplay();
}

void eventSpecialKeyUp(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        keyUp = false;
    }
    
    if (key == GLUT_KEY_DOWN) {
        keyDown = false;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {

    // Define a direcao inicial aleatoria da bola
    launchRandom();

    // Configuracoes Iniciais
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Habilita o double buffering
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Jogo Pong");

    // Execucao
    init();
    glutDisplayFunc(display);

    // Registra funções de teclado
    glutKeyboardFunc(eventNormalKey);
    glutKeyboardUpFunc(eventNormalKeyUp);
    glutSpecialFunc(eventSpecialKey);
    glutSpecialUpFunc(eventSpecialKeyUp);

    glutIdleFunc(display); // Defina a função idle para atualizar a tela continuamente
    glutMainLoop();

    return 0;
}