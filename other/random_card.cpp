#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int pick_card(){
  int allcards[4][13]={};
  int card_kind = rand() % 4;
  int card_num = rand() % 13;
  return(sw12(card_kind, card_num));
}
int sw12(int card_kind, int card_num){
  switch (card_kind) {
    case 0:
      cout << "♥︎";
      break;
    case 1:
      cout << "♦︎︎";
      break;
    case 2:
      cout << "♠︎︎";
      break;
    case 3:
      cout << "♣︎︎";
      break;
    default:
      break;
  }
  if (card_num == 12) {
    cout << " K";
  } else if (card_num == 11) {
    cout << " Q";
  } else if (card_num == 10) {
    cout << " J";
  } else {
    cout << " " << card_num+1;
  }
  return(card_num);
}
int main() {
  int run_times = 1;
  srand(time(NULL));
  for (int i = 0; i < run_times; i++) {
    pick_card();
  }
  return 0;
}