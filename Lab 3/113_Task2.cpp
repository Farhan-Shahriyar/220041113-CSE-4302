#include <iostream>
#include <iomanip>
using namespace std;

class Temperature{
private:
    double temperatureValue;
    char temperatureUnit;
    bool isValid;
    bool wasConverted;
public:
    void assign(double value, char unit){
        if ((unit=='C' && value<-273.15) || (unit=='F' && value<-459.67) || (unit=='K' && value<0)){
            cout<<"Error: Temperature lower than absolute zero." << endl;
            isValid = false;
        }
        else if(unit=='C' || unit=='F' || unit=='K'){
            temperatureValue = value;
            temperatureUnit = unit;
            isValid = true;
        }
        else{
            cout<<"Error: Invalid temperature unit."<<endl;
            isValid = false;
        }
    }
    double convert(char targetUnit){
        wasConverted = true;
        if (!isValid){
            cout<<"Error: Invalid temperature data. Cannot convert."<<endl;
            return 0;
        }
        switch(temperatureUnit){
            case 'C':
                if(targetUnit=='F') {
                    temperatureValue = (temperatureValue * 9.0 / 5.0) + 32.0;
                    temperatureUnit = 'F';
                }
                else if(targetUnit=='K') {
                    temperatureValue += 273.15;
                    temperatureUnit = 'K';
                }
                break;
            case 'F':
                if(targetUnit=='C'){
                    temperatureValue = (temperatureValue - 32.0) * 5.0 / 9.0;
                    temperatureUnit = 'C';
                }
                else if(targetUnit == 'K'){
                    temperatureValue = (temperatureValue - 32.0) * 5.0 / 9.0 + 273.15;
                    temperatureUnit = 'K';
                }
                break;
            case 'K':
                if(targetUnit == 'C'){
                    temperatureValue -= 273.15;
                    temperatureUnit = 'C';
                }
                else if(targetUnit == 'F'){
                    temperatureValue = (temperatureValue - 273.15) * 9.0 / 5.0 + 32.0;
                    temperatureUnit = 'F';
                }
                break;
        }
        return temperatureValue;
    }

    void print() const {
        if(isValid){
            cout << fixed << setprecision(2);
            cout << "The temperature is " << temperatureValue << " " << (temperatureUnit == 'C' ? "Celsius" : (temperatureUnit == 'F' ? "Fahrenheit" : "Kelvin")) << "." << endl;
        }
        else{
            cout<<"Temperature data is invalid."<<endl;
        }
    }
};

int main(){
    Temperature temp;
    temp.assign(36.5, 'C');
    temp.print();
    temp.convert('K');
    temp.print();
    temp.assign(-500, 'F');
    temp.print();
    return 0;
}
