// edit by: Phalis_Zequlard (2023/04/18) version 13.0 
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
// read '姚映辰,5b0g0009,35,74.9,54.95' and separate them into 5 variables
string name, firstName, secondName, thirdName, lastName;
float firstScore[3] = {0}, secondScore[3] = {0}, thirdScore[3] = {0}, lastScore[3] = {0};
int main() {
  ifstream myfile("mystring.txt");
  if(!myfile.is_open()){cout << "Error opening file" << endl;return 0;}
  // declare variables
  string name, id, email;
  float score1, score2, score3;
  // read file line by line
  while(!myfile.eof()) {
    getline(myfile, name, ',');
    getline(myfile, id, ',');
    myfile >> score1;
    myfile.ignore();
    myfile >> score2;
    myfile.ignore();
    myfile >> score3;
    myfile.ignore();
    // cout output format control
    cout << setw(8) << "Name: "   << name   << endl;
    cout << setw(8) << "ID: "     << id     << endl;
    cout << setw(8) << "Score1: " << score1 << endl;
    cout << setw(8) << "Score2: " << score2 << endl;
    cout << setw(8) << "Score3: " << score3 << endl;
    if ((score1 + score2 + score3)/3 > (firstScore[0] + firstScore[1] + firstScore[2])/3) {
      thirdScore[0] = secondScore[0];
      thirdScore[1] = secondScore[1];
      thirdScore[2] = secondScore[2];
      secondScore[0] = firstScore[0];
      secondScore[1] = firstScore[1];
      secondScore[2] = firstScore[2];
      firstScore[0] = score1;
      firstScore[1] = score2;
      firstScore[2] = score3;
      thirdName = secondName;
      secondName = firstName;
      firstName = name;
    } else if ((score1 + score2 + score3)/3 > (secondScore[0] + secondScore[1] + secondScore[2])/3) {
      thirdScore[0] = secondScore[0];
      thirdScore[1] = secondScore[1];
      thirdScore[2] = secondScore[2];
      secondScore[0] = score1;
      secondScore[1] = score2;
      secondScore[2] = score3;
      thirdName = secondName;
      secondName = name;
    } else if ((score1 + score2 + score3)/3 > (thirdScore[0] + thirdScore[1] + thirdScore[2])/3) {
      thirdScore[0] = score1;
      thirdScore[1] = score2;
      thirdScore[2] = score3;
      thirdName = name;
    }
    if ((score1 + score2 + score3)/3 <= (lastScore[0] + lastScore[1] + lastScore[2])/3) {
      lastScore[0] = score1;
      lastScore[1] = score2;
      lastScore[2] = score3;
      lastName = name;
    }
  }
  cout << "\n\n====================================" << endl;
  // print out the top 3
  cout << "1st: " << setw(8) << firstName   << setw(5) << firstScore[0]  << setw(5) << firstScore[1]  << setw(5) << firstScore[2]  << " 平均" << setw(5) << (firstScore[0]  + firstScore[1]  + firstScore[2] )/3 << endl;
  cout << "2nd: " << setw(8) << secondName  << setw(5) << secondScore[0] << setw(5) << secondScore[1] << setw(5) << secondScore[2] << " 平均" << setw(5) << (secondScore[0] + secondScore[1] + secondScore[2])/3 << endl;
  cout << "3rd: " << setw(8) << thirdName   << setw(5) << thirdScore[0]  << setw(5) << thirdScore[1]  << setw(5) << thirdScore[2]  << " 平均" << setw(5) << (thirdScore[0]  + thirdScore[1]  + thirdScore[2] )/3 << endl;
  cout << ".\n.\n." << endl;
  cout << "last " << setw(8) << lastName    << setw(5) << lastScore[0]   << setw(5) << lastScore[1]   << setw(5) << lastScore[2]   << " 平均" << setw(5) << (lastScore[0]   + lastScore[1]   + lastScore[2]  )/3 << endl;
  cout << "====================================\n" << endl;
  myfile.close();
  return 0;
}