#include "lib/euler.h"

#define N 1000
string (*solutions[N])();


void intro() {
  cout << "Project Euler solutions by bshankar" << endl;
  cout << "email: ebs@openmailbox.org" << endl << endl;

}


void printSolution(int n) {
  if (n < 1 or n > N)
    cout << "Valid problem numbers are: 1 to 1000" << endl;
  else {
    if (solutions[n]) {
      cout << "Project Euler problem: " << n << endl;
      cout << "Answer: " << *(solutions[n])() << endl;	
    }
    else
      cout << "I didn't solve this problem yet!" << endl;
  }
}


int main(int argc, char **argv) {  
  intro();
  auto begin = chrono::steady_clock::now();
  // if (argc == 1) {
  //   int n = atoi(argv[1]) - 1;
  //   print(solutions[n]);
  // } else {
  //   cout << "Solving all problems!" << endl;
    
  //   for (int n = 0; n <= N; ++n) 
  //     if (solutions[n])
  //       print(solutions[n]);
  // }
  auto end = chrono::steady_clock::now();

  printTimeElapsed(begin, end);
}
