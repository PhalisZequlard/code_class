#include <iostream>
#include <math.h>
using namespace std;
// input: 2 strings, change into 2 2_binary strings, output.
void printValiable(string a, string b) {
  cout << a << endl;
  cout << b << endl;
}
string add(int a, int b) {
  int c = a + b;
  // change c to 2_binary string
  int c_2binary = 0;
  int i = 0;
  while(c != 0) {
    c_2binary += (c % 2) * pow(10, i);
    c /= 2;
    i++;
  }
  return to_string(c_2binary);
}
int main() {
  string a, b;
  cin >> a >> b;
  printValiable(a, b);
  int a_int = stoi(a, nullptr, 2);
  int b_int = stoi(b, nullptr, 2);
  cout << add(a_int, b_int);
  return 0;
}