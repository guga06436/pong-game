#ifndef BAR_H
#define BAR_H

class Bar {
public:
    
    Bar(float startX, float startY, float width, float height); // Construtor

    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;

    void moveUp(int barSpeed);
    void moveDown(int barSpeed);
    void draw() const; // Função para desenhar a barra usando OpenGL

private:
    float x;
    float y;
    float width;
    float height;
};

#endif