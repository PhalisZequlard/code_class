#include <iostream>
using namespace std;

class point {
  friend point &operator+(point &a, int b);
  int x, y;

public:
  point(int a=0, int b=0) {
    x=a;
    y=b;
  }
  void show() {
    cout << x << " " << y << endl;
  }
};

point &operator+(point &a, int b) {
  a.x = a.x + b;
  a.y = a.y + b;
  return a;
}

int main() {
  point x(10, 20);
  point y;
  x.show();
  y = x + 10;
  y.show();
  return 0;
}
