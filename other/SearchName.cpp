// edit by: Phalis_Zequlard (2023/04/18) version 13.0 
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
string name, firstName, secondName, thirdName, lastName[5];
float firstScore[3] = {0}, secondScore[3] = {0}, thirdScore[3] = {0}, lastScore[5][3] = {0};
int searchName(string theName) {
  ifstream myfile("mystring.txt");
  if(!myfile.is_open()){cout << "Error opening file" << endl;return 0;}
  float score1, score2, score3;
  string name, id, email;
  while(!myfile.eof()) {
    getline(myfile, name, ',');
    getline(myfile, id, ',');
    myfile >> score1;
    myfile.ignore();
    myfile >> score2;
    myfile.ignore();
    myfile >> score3;
    myfile.ignore();
    if (id == theName) {
      cout << name << "考" << score1 << "分"<< endl;
      return 1;
    }
  }
  myfile.close();
  return 0;
}
int main() {
  string theID;cout<<"請輸入要查詢同學的學號:";cin >> theID;
  if(searchName(theID)) {
    cout << endl;
  } else {
    cout << "查無此人" << endl;
  }
  return 0;
}