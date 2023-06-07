#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

char* printTime() {
  auto now = chrono::system_clock::now();
  time_t t = chrono::system_clock::to_time_t(now);
  static char buffer[11];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&t));
  return buffer;
}

class BMI {
  float height, weight, bmi;
  string name, date;
  int age;
public:
  BMI (
      string name = "no_name",
      int age = 0,
      float height = 0,
      float weight = 0,
      string date = "0000-00-00"
    ) {
    this->name = name;
    this->age = age;
    this->height = height;
    this->weight = weight;
    this->date = date;
    this->bmi = cal_bmi(height, weight);
  }
private:
  float cal_bmi(float height, float weight) {
    return (weight / (height * height));
  }

public:
  friend istream& operator>>(istream& is, BMI& bmi) {
    cout << "請輸入你的姓名：";
    is >> bmi.name;
    cout << "請輸入你的年齡：";
    is >> bmi.age;
    do {
      cout << "請輸入你的身高：";
      is >> bmi.height;
    } while (bmi.height > 2);
    cout << "請輸入你的體重：";
    is >> bmi.weight;
    bmi.bmi = bmi.cal_bmi(bmi.height, bmi.weight);
    bmi.date = printTime();
    return is;
  }

  friend ostream& operator<<(ostream& os, const BMI& bmi) {
    os << "姓名: " << bmi.name << ", 今年 " << bmi.age << " 歲, 身高 " << bmi.height << " 公分, 體重 " << bmi.weight << " 公斤" << endl;
    os << "你的BMI = " << fixed << setprecision(1) << bmi.bmi << ", 量測日期是 " << bmi.date << endl;
    return os;
  }
};

// void writeToFile(const string& filename, const string& content) {
//   ofstream file(filename, ios::app);
//   if (file.is_open()) {
//     file << content;
//     file.close();
//     cout << "紀錄已儲存至檔案: " << filename << endl;
//   } else {
//     cout << "無法開啟檔案: " << filename << endl;
//   }
// }

int main() {
  BMI User;
  cin >> User;
  cout << User;
  ofstream file("records.txt");
  if (file.is_open()) {
    file << to_string(User);
    file.close();
    cout << "紀錄已儲存至檔案: " << "filename" << endl;
  } else {
    cout << "errosf";
  }

  // BMI Peter("Peter", 25, 1.80, 75.0, "2023-05-24");
  // cout << Peter;
  // string peterRecord = Peter;
  // writeToFile("records.txt", peterRecord);

  return 0;
}
