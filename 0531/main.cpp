#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

class calender {
  private:
    friend class worker;
    friend ostream & operator <<(ostream &out, const calender &c);
    struct tm date;
    string note;
  public:
    calender(string n = "沒事", int y = 2023, int m = 5, int d = 31, int hh = 12, int mm = 0, int ss = 0) {
      note = n;
      date.tm_year = y - 1900;
      date.tm_mon = m - 1;
      date.tm_mday = d;
      date.tm_hour = hh;
      date.tm_min = mm;
      date.tm_sec = ss;
      date.tm_wday = 3;
    }
    struct tm getTime() {
      return date;
    }
};

class worker {
  private:
    friend void addTask(calender &a);
    friend void removeTask(calender &a)
    calender data[5];
    int counter = 0;
  public:
    run() {
      int i;
      time_t now;
      struct tm a, *b;
      double s;a
      while (true) {
        for (i=0; i<counter; i++) {
          time(&now);
          a = data[i].getTime;
          s = difftime(now, mktime(&a));
          if(s == 0) {
            cout << data[i].note << endl;
          } else {
            cout << asctime(lacaltime(&now)) << endl;
          }
        }
        _speep(1000);
      }
    }
    void addTask(calender &a) {
      data[counter] = a;
      counter++;
    }
}

ostream & operator <<(ostream &out, const calender &c) {
  out << "你設定" << asctime(&(c.date)) << "顯示" << c.note;
  return out;
}

int main() {
  calender c1("起床", 2023, 5, 31, 9, 10, 0);
  calender c2("起床", 2023, 5, 31, 9, 10, 0);
  calender c3("起床", 2023, 5, 31, 9, 54, 0);

  worker p1;
  p1.addTask(c1);

  cout << c1;
  return 0;
}
