#ifndef SHIP_H
#define SHIP_H

class Ship {
public: 
    Ship(int size, int startX, int startY, bool horizontal);
    void hit();                 
    bool isSunk() const;      
    int getSize() const;
    int getStartX() const;
    int getStartY() const; 
    bool isHorizontal() const;  

    int size;        
    int startX;      
    int startY;     
    bool horizontal; 
    int hits;     
};

#endif
