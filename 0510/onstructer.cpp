#include <iostream>
using namespace std;

class test {
protected:
private:  
public: 
  test() {
    cout << "Constructor is called!" << endl;
  }
  ~test() {
    cout << "Destructor is called!" << endl;
  }
};

int main() {
  test *ptr1, *ptr2;
  ptr1 = new test;
  cout << "ptr1: is running" << endl;
  ptr2 = new test;
  cout << "ptr2: is running" << endl;
  delete ptr1;
  cout << "ptr1: is deleted" << endl;
  delete ptr2;
  return 0;
}