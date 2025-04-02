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
        cout<<name<<" attack with power: "<<attackpower<<endl;
        mana+=50;
    }
    virtual void defend(){
        cout<<name<<"defends"<<endl;
    }
    virtual void useSpecialAbility(){
        cout<<name<<" uses "<<specialability<<" with power "<<specialabilityP<<endl;
    }
    void damage(int num){
        cout<<name<<" takes "<<num<<" damage! Health now: "<<health<<endl;
    }
    string getname(){
        return name;
    }
    void sethealth(int num){
        health-=num;
    }
    int gethealth(){
        return health;
    }
    int getattack(){
        return attackpower;
    }
    int getmana(){
        return mana;
    }
    int getsp(){
        return specialabilityP;
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
    void damage(int num){
        cout<<"Boss takes "<<num<<" damage! Health now: "<<health<<endl;
    }
    void sethealth(int num){
        health-=num;
    }
    int gethealth(){
        return health;
    }
    int getattack(){
        return attackpower;
    }
};

class GameEngine{
public:
    void start(){
        Warrior warrior(100, 25, "Berserk Rage", 35);
        Mage mage(120, 20, "Arcane Blast", 30);
        Archer archer(90, 20, "Fire Arrow", 35);
        BossEnemy boss;
        cout<<"Game begins! Players vs Boss"<<endl;
        while(true){
            if(warrior.gethealth()>0){
                if(boss.gethealth()<=0){
                    cout<<"Boss defeated! Players win!"<<endl;
                    break;
                }
                if(warrior.getmana()>=100){
                    warrior.attack();
                    boss.sethealth(warrior.getsp());
                    boss.damage(warrior.getsp());
                }
                else{
                    warrior.attack();
                    boss.sethealth(warrior.getattack());
                    boss.damage(warrior.getattack());
                }



            }
            if(mage.gethealth()>0){
                if(boss.gethealth()<=0){
                    cout<<"Boss defeated! Players win!"<<endl;
                    break;
                }
                if(mage.getmana()>=100){
                    mage.attack();
                    boss.sethealth(mage.getsp());
                    boss.damage(mage.getsp());
                }
                else{
                    mage.attack();
                    boss.sethealth(warrior.getattack());
                    boss.damage(warrior.getattack());
                }

            }
            if(archer.gethealth()>0){
                if(boss.gethealth()<=0){
                    cout<<"Boss defeated! Players win!"<<endl;
                    break;
                }
                if(archer.getmana()>=100){
                    archer.attack();
                    boss.sethealth(archer.getsp());
                    boss.damage(archer.getsp());
                }
                else{
                    archer.attack();
                    boss.sethealth(warrior.getattack());
                    boss.damage(warrior.getattack());
                }
            }
            if(warrior.gethealth()>0){
                boss.attack(warrior);
                cout << "Warrior takes damage! Health now: "<<warrior.gethealth()<<endl;
                warrior.sethealth(boss.getattack());
                warrior.damage(boss.getattack());
            }
            if (mage.gethealth()>0){
                boss.attack(mage);
                cout<<"Mage takes damage! Health now: "<<mage.gethealth()<<endl;
                mage.sethealth(boss.getattack());
                mage.damage(boss.getattack());
            }
            if(archer.gethealth()>0){
                boss.attack(archer);
                cout<<"Archer takes damage! Health now: " << archer.gethealth()<<endl;
                archer.sethealth(boss.getattack());
                archer.damage(boss.getattack());
            }
            if(warrior.gethealth()==0 || warrior.gethealth()==0 || warrior.gethealth()==0){
                cout<<"Boss wins"<<endl;
            }
        }
    }
};

int main(){
    GameEngine g;
    g.start();
    return 0;
}

