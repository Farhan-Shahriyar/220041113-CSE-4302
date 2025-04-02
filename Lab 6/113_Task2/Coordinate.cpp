#include "Coordinate.h"
#include<bits/stdc++.h>
using namespace std;

Coordinate :: Coordinate() : abscissa(0), oordinate(0){}

Coordinate :: Coordinate(float x, float y) : abscissa(x), oordinate(y){}

void Coordinate :: display() const{
    cout<<"("<<abscissa<<" , "<<oordinate<<")"<<endl;
}

float Coordinate :: operator-(Coordinate c){
    return sqrt(pow(abscissa-c.abscissa, 2) + pow(oordinate-c.oordinate,2));
}

float Coordinate :: getDistance() const{
    return sqrt((abscissa*abscissa) + (oordinate*oordinate));
}

void Coordinate :: move_x(float val){
    abscissa+=val;
}

void Coordinate :: move_y(float val){
    oordinate+=val;
}

void Coordinate :: Move(float x_val, float y_val){
    abscissa += x_val;
    oordinate += y_val;
}

bool Coordinate :: operator>(const Coordinate& c) const{
    return getDistance() > c.getDistance();
}

bool Coordinate :: operator<(const Coordinate& c) const{
    return getDistance() > c.getDistance();
}

bool Coordinate :: operator<=(const Coordinate &c) const{
    return getDistance() <= c.getDistance();
}

bool Coordinate :: operator==(const Coordinate &c) const{
    return getDistance() == c.getDistance();
}

bool Coordinate :: operator!=(const Coordinate &c) const{
    return getDistance() != c.getDistance();
}

void randomAssignment(Coordinate coord[], int Size){
    srand(time(0));
    for(int i=0; i<Size; i++){
        Coordinate temp((rand()%201-100), (rand()%201-100));
        coord[i] = temp;
    }
}

void highest(Coordinate coord[], int Size){
    float maximum = -1;
    Coordinate c1, c2;
    for(int i = 0; i<Size-1; i++){
        for(int j = i+1; j<Size; j++){
            float distance = coord[i] - coord[j];
            if(distance > maximum){
            maximum = distance;
            c1 = coord[i];
            c2 = coord[j];
            }
        }
    }
    cout<<"maximum distance is between: ";
    c1.display();
    c2.display();
    cout<<endl;
}

void lowest(Coordinate coord[], int Size){
    float minimum = 10000000;
    Coordinate c1, c2;
    for(int i = 0; i<Size-1; i++){
        for(int j = i+1; j<Size; j++){
            float distance = coord[i] - coord[j];
            if(distance < minimum){
            minimum = distance;
            c1 = coord[i];
            c2 = coord[j];
            }
        }
    }
    cout<<"minimum distance is between: ";
    c1.display();
    c2.display();
    cout<<endl;

}



