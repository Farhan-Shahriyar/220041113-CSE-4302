#include<bits/stdc++.h>
using namespace std;

class Artwork{
protected:
    string title;
    string artist;
    double price;
    double discount;
public:
    Artwork(string t, string a, double p) : title(t), artist(a), price(p), discount(0){}
    virtual ~Artwork(){}
    virtual void displayDetails() const{
         cout<<"title: "<<title<<endl<<"artist: "<<artist<<endl<<"price before discount: "<<price<<endl<<"price after discount: "<<price-discount<<endl;
    }
    virtual void applyDiscount(float percentage) = 0;
};

class Painting : public Artwork{
private:
    string medium;
public:
    Painting(string t, string a, double p, string m) : Artwork(t, a, p), medium(m){}
    ~Painting(){}
    void applyDiscount(float percentage){
        discount = price * percentage * 0.01;
    }
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
    void applyDiscount(float percentage){
        percentage = 0;
    }
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
    void applyDiscount(float percentage){
        discount = price * (percentage+1) * 0.01;
    }
    void displayDetails() const{
        Artwork::displayDetails();
        cout<<"resolution: "<<resolution<<endl;
    }

};

void displayGalleryDetails(Artwork* gallery[], int Size){
    for (int i = 0; i<Size; i++){
        gallery[i]->displayDetails();
    }
}

int main(){
    Artwork* arts[10];
    arts[0] = new Painting("Paintaing 1", "Person 1", 1000.0, "Acrylic");
    arts[1] = new Sculpture("Sculpture 1", "Person 2", 1000.0, "Bronze");
    arts[2] = new DigitalArt("DigitalArt 1", "Person 3", 1000.0, "800x100");
    displayGalleryDetails(arts, 2);
    return 0;
}
