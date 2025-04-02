#ifndef COORDINATE_H
#define COORDINATE_H
#include<bits/stdc++.h>
using namespace std;

class Coordinate{
private:
    float abscissa;
    float oordinate;
public:
    Coordinate();
    Coordinate(float x, float y);
    ~Coordinate(){}
    void display() const;
    float operator-(Coordinate c);
    float getDistance() const;
    void move_x(float val);
    void move_y(float val);
    void Move(float x_val, float y_val);
    bool operator>(const Coordinate& c) const;
    bool operator<(const Coordinate& c) const;
    bool operator<=(const Coordinate &c) const;
    bool operator==(const Coordinate &c) const;
    bool operator!=(const Coordinate &c) const;
};

void randomAssignment(Coordinate coordinate[], int Size);

void highest(Coordinate coord[], int Size);

void lowest(Coordinate coord[], int Size);

#endif
