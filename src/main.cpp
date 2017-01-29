#include "solutions/solution.h"

void intro() {
  cout << HEADER
       << BOLD << "Euler " << "v0.1" << endl
       << "author: Bhavani Shankar (ebs@openmailbox.org)" << endl
       << "================================================="
       << ENDC << endl << endl;
}


void printSolution(int n) {
  if (n < 0 or n > PROBLEMS - 1)
    cout << "Valid problem numbers are: 1 to 1000" << endl;
  else {
    if (solutions[n]) {
      cout << "Problem "<< n + 1 << ": "
           << BOLD << OKGREEN << UNDERLINE << (solutions[n])() << ENDC << endl;	
    }
    else
      cout << FAIL << "I didn't solve this problem yet!" << ENDC << endl;
  }
}


int main(int argc, char **argv) {  
  intro();
  initSolutions();

  auto begin = chrono::steady_clock::now();
  if (argc == 2) {
    int n = atoi(argv[1]);
    printSolution(n - 1);
  } else {
    cout << FAIL  << "Solving all problems!" << ENDC << endl << endl;
    
    for (int n = 0; n < PROBLEMS; ++n) 
      if (solutions[n])
        printSolution(n);
  }
  auto end = chrono::steady_clock::now();
  cout << endl;
  printTimeElapsed(begin, end);
}
