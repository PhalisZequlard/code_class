#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
// '姚映辰,5b0g0009,35,74.9,54.95'separate into 5 variables
int main() {
  string str = "姚映辰,5b0g0009,35,74.9,54.95";
  string name, id, email;
  float score1, score2, score3;
  istringstream ss(str);
  getline(ss, name, ',');
  getline(ss, id, ',');
  getline(ss, email, ',');
  ss >> score1;
  ss.ignore();
  ss >> score2;
  ss.ignore();
  ss >> score3;
  cout << name << endl;
  cout << id << endl;
  cout << email << endl;
  cout << score1 << endl;
  cout << score2 << endl;
  cout << score3 << endl;
  return 0;
}