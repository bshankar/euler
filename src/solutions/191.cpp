#include <iostream>
typedef unsigned int ui;
using namespace std;


int main() {
  int f[30][2] = {};
  // values computed using brute force
  f[0][0] = 2; f[1][0] = 4; f[2][0] = 7;
  f[0][1] = 3; f[1][1] = 8; f[2][1] = 19;

  for (int i = 3; i < 30; ++i) 
    for (int j = 0; j < 2; ++j) { 
      f[i][j] = f[i-1][j] + f[i-2][j] + f[i-3][j];
      if (j)
        f[i][j] += f[i-1][j-1] + f[i-2][j-1] + f[i-3][j-1];
    }

  cout << f[29][1] << endl;
}
