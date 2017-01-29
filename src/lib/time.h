#ifndef TIME_H
#define TIME_H

#include <chrono>
typedef chrono::stead_clock::time_point time_t;

void printTimeElapsed(time_t begin, time_t end) {
  auto timeDiff = chrono::duration_cast<chrono::microseconds> (end - begin); 

  string timeDiffStr;

  auto second = 1000000;
  auto minute = second*60,
       hour = second*3600;

  if (timeDiff > second) {
      if (timeDiff > hour) {
        // hours
        timeDiffStr += to_string(timeDiff/hour) + "h ";
        timeDiff %= hour;
      }

      if (timeDiff > minute) {
        // minutes
        timeDiffStr += to_string(timeDiff/minute) + "m ";
        timeDiff %= minute;
      }

      // seconds
      timeDiffStr += to_string(double(timeDiff)/second);
      timeDiffStr = timeDiffStr.substr(0, timeDiffStr.find(".") + 2) + "s";
    }
    else if (timeDiff > 1000)
      timeDiffStr = to_string(timeDiff) + " ms";
    else 
      timeDiffStr = to_string(timeDiff) + " us";

  cout << "Total time elapsed: " << timeDiffStr << endl;
}

#endif
