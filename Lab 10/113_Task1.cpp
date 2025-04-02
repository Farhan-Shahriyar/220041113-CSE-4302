#include<bits/stdc++.h>
using namespace std;

class CharacterAction{
public:
    virtual void attack() = 0;
    virtual void defend() = 0;
    virtual void useSpecialAbility() = 0;
    virtual void displayStats() const = 0;
};

class BaseCharacter : public CharacterAction{
protected:
    string name;
    int health;
    int mana;
    int attackpower;
    string specialability;
    int specialabilityP;
public:
    BaseCharacter(string n, int h, int a, string s, int sp) : name(n), health(h), mana(0), attackpower(a), specialability(s), specialabilityP(sp){}
    virtual void displayStats() const{
        cout<<"Name: "<<name<<endl<<"Health: "<<health<<endl<<"Mana: "<<0<<endl;
    }
    virtual void attack(){
        cout<<name<<" attack with power: "<<attackpower<<endl;;
    }
    virtual void defend(){
        cout<<name<<"defends"<<endl;
    }
    virtual void useSpecialAbility(){
        cout<<name<<" uses "<<specialability<<" with power "<<specialabilityP<<endl;
    }
    string getname(){
        return name;
    }

};

class Warrior : public BaseCharacter{
public:
    Warrior(int h, int a, string s, int sp) : BaseCharacter("Warrior", h, a, s, sp){}
};

class Mage : public BaseCharacter{
public:
    Mage(int h, int a, string s, int sp) : BaseCharacter("Mage", h, a, s, sp){}
};

class Archer : public BaseCharacter{
public:
    Archer(int h, int a, string s, int sp) : BaseCharacter("Archer", h, a, s, sp){}
};

class BossEnemy{
    int health;
    int attackpower;
public:
    BossEnemy() : health(150), attackpower(30){}
    void attack(BaseCharacter target){
        cout<<"Boss attacks "<<target.getname()<<" with power "<<attackpower<<"!"<<endl;
    }
};

int main(){
    BaseCharacter *ptr[3];
    ptr[0] = new Warrior(100, 25, "Berserk Rage", 35);
    ptr[1] = new Mage(120, 20, "Arcane Blast", 30);
    ptr[2] = new Warrior(90, 20, "Fire Arrow", 35);
    for(int i=0; i<3; i++){
        ptr[i]->displayStats();
    }
}
