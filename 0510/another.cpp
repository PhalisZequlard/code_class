#include <iostream>
using namespace std;

class car {
protected:
    int age;
private:
    int secondHand;
public:
    int color;
    car() {
        cout << "1" << endl;
        color = 0;
        age = 2000;
        secondHand = 0;
    }
};

class toyota : public car { // 繼承
public:
    toyota() : car() {
        cout << "2" << endl;
        color = 100;
    }
};

class ford : public car {
public:
    int price;
    int wheels;
    ford() : car() {
        cout << "3" << endl;
        color = 200;
    }
};

class cross : public toyota {
public:
    cross() : toyota() {
        cout << "4" << endl;
        color = 300;
    }
};

int main() {
    car v0;
    toyota v1;
    cout << v0.color << endl;
    cout << v1.color << endl;
    return 0;
}
