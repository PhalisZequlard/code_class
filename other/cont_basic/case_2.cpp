#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// input: 2 strings with 2 2_binary number in it, output a+b.
void printValiable(string a, string b) {
  cout << "your input:\nValiable a: "<< a << "\nValiable b: " << b << endl;
}
string add(string a, string b) {
  return 0;
}
int main() {
  string a, b;
  cin >> a >> b;
  if (a.length() > b.length()) {
    swap(a, b);
  }
  printValiable(a, b);
  add(a, b);
  return 0;
}