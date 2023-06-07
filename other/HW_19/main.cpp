#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
  // Clear terminal
  system("clear");
  ifstream fin("PlayerINFO.txt");
  if (!fin) {
    cout << "檔案開啟失敗\n";
    return 1;
  }
  vector<int> data;
  int line;
  while (fin >> line) {
    if (data.empty() || line > data.back()) {
      data.push_back(line);
    }
    else {
      data.insert(data.begin(), line);
    }
  }
  cout << " 總共有: " << data.size() << "筆資料" << endl;
  cout << " =======================";
  int printCount = 0;
  for (auto i : data) {
    if (printCount == 0 || printCount % 5 == 0) {
      cout << endl;
      cout << setw(4) << i;
    }
    else {
      cout << setw(5) << i;
    }
    printCount++;
  }
  cout << "\n =======================" << endl;
  return 0;
}
