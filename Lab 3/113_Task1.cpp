#include <iostream>
using namespace std;

class Counter {
private:
    int stepSize;
    int totalCount;
public:
    Counter() : totalCount(0), stepSize(0) {}
    void setIncrementStep(int step) {
        stepSize = step;
    }
    void increment() {
        totalCount += stepSize;
    }
    int getCount() const {
        return totalCount;
    }
    void resetCount() {
        totalCount = 0;
    }
};

int main() {
    Counter obj;
    cout<<"Initial count: "<<obj.getCount()<<endl;
    obj.increment();
    cout<<"After first increment: "<<obj.getCount()<<endl;
    obj.setIncrementStep(5);
    obj.increment();
    cout<<"After setting step size to 5 and incrementing: "<<obj.getCount()<<endl;
    obj.resetCount();
    cout<<"After reset: "<<obj.getCount()<<endl;
    return 0;
}
