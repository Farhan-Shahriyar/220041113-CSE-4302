#include <iostream>
using namespace std;

class Time{
private:
    int hr;
    int min;
    int sec;
public:
    Time() : hr(0), min(0), sec(0){}
    int hours() const{
        return hr;
    }
    int minutes() const{
        return min;
    }
    int seconds() const{
        return sec;
    }
    void reset(int h, int m, int s) {
        hr = h % 24;
        min = m % 60;
        sec = s % 60;
    }
    void advance(int h, int m, int s) {
        int totalSeconds = sec + s;
        int extraMinutes = totalSeconds / 60;
        sec = totalSeconds % 60;
        int totalMinutes = min + m + extraMinutes;
        int extraHours = totalMinutes / 60;
        min = totalMinutes % 60;
        hr = (hr + h + extraHours) % 24;
    }
    void print() const{
        cout << (hr < 10 ? "0" : "") << hr << ":"<< (min < 10 ? "0" : "") << min << ":"<< (sec < 10 ? "0" : "") << sec << endl;
    }
};

int main(){
    Time timeObj;
    timeObj.reset(10, 25, 28);
    timeObj.print();
    timeObj.advance(13, 45, 34);
    timeObj.print();
    return 0;
}
