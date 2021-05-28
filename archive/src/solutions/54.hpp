#include "../lib/euler.hpp"

// map<char,int> values;
// vector<string> h1(5), h2(5);

// void setValues() {
//   values['1'] = 1;
//   values['2'] = 2;
//   values['3'] = 3;
//   values['4'] = 4;
//   values['5'] = 5;
//   values['6'] = 6;
//   values['7'] = 7;
//   values['8'] = 8;
//   values['9'] = 9;
//   values['J'] = 11;
//   values['Q'] = 12;
//   values['K'] = 13;
//   values['A'] = 14;
// }


// int getValue(string card) {
//   if (card[0] == '1') {
//     if (card[1] == '0')
//       return 10;
//     return 1;
//   }
//   return values[card[0]];
// }


// char getSuit(string card) {
//   return card[card.size() - 1];
// }


// bool lesser(string x, string y) {
//   return getValue(x) < getValue(y);
// }


// bool isRoyalFlush(string* h) {
//   for (int i = 0; i < 5; ++i)
//     if (getValue(h[i]) != 10 + i)
//       return false;
//   return true;
// }


// int highestCard(string* h) {
//   return getValue(h[4]);
// }


// bool isStraight(string* h) {
//   int v = getValue(h[0]);
//   for (int i = 1; i < 5; ++i)
//     if (getValue(h[i]) != v + i)
//       return false;
//   return true;
// }


// bool isFlush(string* h) {
//   char suit = getSuit(h[0]);
//   for (int i = 1; i < 5; ++i)
//     if (getSuit(h[i]) != suit)
//       return false;
//   return true;
// }


// bool playerOneWins() {
//   int scores[2] = {0, 0};

  // if (isRoyalFlush(h1)) scores[0] += 100000000;
  // if (isRoyalFlush(h2)) scores[1] += 100000000;
  // if (isFlush(h1)) scores[0] += 10000000;
  // if (isFlush(h2)) scores[1] += 10000000;
  // if (isStraight(h1)) scores[0] += 1000000;
  // if (isStraight(h2)) scores[1] += 1000000;

  // // similar kinds
  // map<int,int> cnt, cnt1;
  // for (int i = 0; i < 5; ++i) {
  //   cnt[getValue(h1[i])]++;
  //   cnt1[getValue(h2[i])]++;
  // }

  // for (auto it = cnt.begin(); it != cnt.end(); ++it) {
  //   scores[0] += 1000*it->second*it->second;
  // }

  // for (auto it = cnt1.begin(); it != cnt1.end(); ++it) {
  //   scores[1] += 1000*it->second*it->second;
  // }
  
  // scores[0] += highestCard(h1);
  // scores[1] += highestCard(h2);

  // if (scores[0] > scores[1])
  //   return true;
  // return false;
// }



string euler54() {

//   ifstream file("src/data/54.txt");

//   for (int i = 0; i < 5; ++i) 
//     h1[i] = h2[i] = "";
  
//   int ans = 0;

//   for (int i = 0; i < 1000; ++i) {
//     for (int j = 0; j < 10; ++j) {
//       if (j < 5)
//         file >> h1[j];
//       else
//         file >> h2[j - 5];
//     }  
//     sort(h1.begin(), h1.end(), lesser);
//     sort(h2.begin(), h2.end(), lesser);
//     ans += playerOneWins();
//   }
//   return to_string(ans);
  return to_string(1);
}
