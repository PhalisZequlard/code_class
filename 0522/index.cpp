#include <iostream>  // cout
#include <string>    // string
#include <fstream>   // ifstream
#include <sstream>   // istringstream
#include <algorithm> // swap
using namespace std;

class score {
  friend ifstream& operator >>(ifstream& in, score& b);
  friend ostream& operator <<(ostream& out, score b);
  int n;
  string* name;
  string* id;
  float* value;
public:
  score(int a = 0) { // how many student (0 is default)
    n = a;
    name = new string[n];
    id = new string[n];
    value = new float[n];
  }
  ~score() {
    delete[]name;
    delete[]id;
    delete[]value;
  }
  void set_n(int x){
    if(n <= 0){
      n = x;
      name = new string[n];
      id = new string[n];
      value = new float[n];
    } else {
      // delete[]name;
      // delete[]id;
      // delete[]value;
      name = new string[n];
      id = new string[n];
      value = new float[n];
    }
  }
  void show() {
    if (n > 0) {
      cout << "姓名\t學號\t\t成績" << endl;
      for (int x = 0; x < n; x++) {
        cout << name[x] << "\t" << id[x] << "\t" << value[x] << endl;
      }
    }
  }
  void sorting() {
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (value[i] < value[j]) {
          swap(name[i], name[j]);
          swap(id[i], id[j]);
          swap(value[i], value[j]);
        }
      }
    }
  }
  int get_n() const {
    return n;
  }
};
ifstream& operator >>(ifstream& in, score& b) {  // 修改參數型別為 reference
  int counter = 0;
  if(in.is_open()){
    string line;
    while(getline(in,line)){
      counter += 1;// 得知檔案有幾筆資料
    }
    b.set_n(counter);
    in.clear();
    in.seekg(0,ios::beg);
    int i = 0;
    while (getline(in, line)) {
      istringstream stream(line);
      string s;
      getline(stream, s, ',');
      b.name[i] = s;
      getline(stream, s, ',');
      b.id[i] = s;
      getline(stream, s, ',');
      b.value[i] = stof(s);
      i++;
    }
  } else {
    cout << "file open fail" << endl;
  }
  return in;
}
ostream& operator <<(ostream& out, score b) {
  if (b.n > 0) {
    cout << "姓名\t學號\t\t成績" << endl;
    for (int x = 0; x < b.n; x++) {
      out << b.name[x] << "\t" << b.id[x] << "\t" << b.value[x] << endl;
    }
  }
  return out;
}

int main() {
  int studentCount = 47; 
  score csie_2_a;
  ifstream myFile("stu.txt");
  ifstream myFile2("stu2.txt");

  myFile >> csie_2_a;
  // cout << "output fil_1 (total: " << csie_2_a.get_n() << ")" << endl;
  csie_2_a.sorting();
  cout << csie_2_a;
  myFile.close();

  myFile2 >> csie_2_a;
  // cout << "output fil_2 (total: " << csie_2_a.get_n() << ")" << endl;
  csie_2_a.sorting();
  cout << csie_2_a;
  myFile2.close();
  return 0;
}
