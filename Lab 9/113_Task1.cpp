#include<bits/stdc++.h>
using namespace std;

class Artwork{
protected:
    string title;
    string artist;
    double price;
public:
    Artwork(string t, string a, double p) : title(t), artist(a), price(p){}
    virtual ~Artwork(){}
    virtual void displayDetails() const{
        cout<<"title: "<<title<<endl<<"artist: "<<artist<<endl<<"price: "<<price<<endl;
    }
};

class Painting : public Artwork{
private:
    string medium;
public:
    Painting(string t, string a, double p, string m) : Artwork(t, a, p), medium(m){}
    ~Painting(){}
    void displayDetails() const{
        Artwork::displayDetails();
        cout<<"medium: "<<medium<<endl;
    }
};

class Sculpture : public Artwork{
private:
    string material;
public:
    Sculpture(string t, string a, double p, string m) : Artwork(t, a, p), material(m){}
    ~Sculpture(){}
    void displayDetails() const{
        Artwork::displayDetails();
        cout<<"material: "<<material<<endl;
    }

};

class DigitalArt : public Artwork{
private:
    string resolution;
public:
    DigitalArt(string t, string a, double p, string r) : Artwork(t, a, p), resolution(r){}
    ~DigitalArt(){}
    void displayDetails() const{
        Artwork::displayDetails();
        cout<<"resolution: "<<resolution<<endl;
    }

};

int main(){
    Artwork* arts[10];
    arts[0] = new Painting("Paintaing 1", "Person 1", 1000.0, "Acrylic");
    arts[1] = new Sculpture("Sculpture 1", "Person 2", 1000.0, "Bronze");
    arts[2] = new DigitalArt("DigitalArt 1", "Person 3", 1000.0, "800x100");
    for(int i=0; i<3; i++){
        arts[i]->displayDetails();
    }
    return 0;
}
