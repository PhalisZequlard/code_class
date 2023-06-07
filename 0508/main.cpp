// 0508 物件導向 EDITOR:SHAIN|ZEQULARD|HOWZEN
#include <iostream>
using namespace std;

class studentScore {
protected: // 內部專用
private:   // 私人
  string ID, Name;
  float score1 /*, score2, score3*/;
public: // 公開
  studentScore(
    string str_Name = "NO_NAME",
    string str_ID = "NO_DATA",
    int int_score1 = 0
  ) {
    Name = str_Name;
    ID = str_ID;
    score1 = int_score1;
  }
  void SHOW_SCORE() {
    if (Name == "NO_NAME") {
      cout << "NO_DATA" << endl;
    } else {
      cout << Name << "'s SCORE IS: " << score1 << endl;
    }
  }
  void SET_DATA(
    string str_Name = "NO_NAME", 
    string str_ID = "NO_DATA",
    int int_score1 = 0
  ) {
    Name = str_Name;
    ID = str_ID;
    score1 = int_score1;
  }
};

int main() {
  studentScore myDATA;
  studentScore myDATA_0;
  studentScore myDATA_1;
  studentScore *myDATA_2;
  studentScore myDATA_3;
  myDATA_2 = new studentScore;

  myDATA_0.SHOW_SCORE();

  // myDATA_1.Name = "THENAME1";
  // myDATA_1.ID = "5b0g0000";
  // myDATA_1.score1 = 100;
  myDATA_1.SET_DATA("THENAME1", "5b0g0000", 100);
  myDATA_1.SHOW_SCORE();
  myDATA.SET_DATA("THENAME0", "5b0g0000", 80);

  myDATA_2->SET_DATA("THENAME2");
  myDATA_2->SHOW_SCORE();

  // myDATA_3.Name = "THENAME3";
  // myDATA_3.ID = "5b0g0000";
  // myDATA_3.score1 = 50;
  myDATA_3.SET_DATA("THENAME3", "5b0g0000", 50);
  myDATA_3.SHOW_SCORE();

  return 0;
}

// ok this work >w< ☕︎🦿☕☕☕☕☕☕☕🔱☢️☢️〽️🈸🈸♋♋
// GOOD
//"THENAME"
// Bank += 30NTD*2*6
//haha nigger 