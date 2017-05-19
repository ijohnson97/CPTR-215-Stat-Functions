#include <algorithm> // Includes vector sort
#include <cmath>     // Contains pow & sqrt functions
#include <iomanip>   // Sets decimal precision
#include <iostream>  // used to format and output text
#include <vector>    // Allows creation and manipulation of vectors

using namespace std;

// Calculate Mean
double getMean(vector<double> userNums) {
  double totalNums = 0.0;

  for (unsigned int i = 0; i < userNums.size(); ++i) {
    totalNums += userNums.at(i);
  }

  return (totalNums / userNums.size());
}

// Calculate median
double median(vector<double> userNums) {
  sort(userNums.begin(), userNums.end());

  if ((userNums.size() - 1) % 2 == 0) {
    return userNums.at(userNums.size() / 2);
  } else {
    return 0.5 * (userNums.at(userNums.size() / 2) +
                  userNums.at(userNums.size() / 2 - 1));
  }
}

// Calculate Range
double range(vector<double> userNums) {
  // Define variables for storing max and min
  double maxVal = userNums.at(0);
  double minVal = userNums.at(0);
  unsigned int i = 1;

  for (i = 1; i < userNums.size(); i++) {
    if (userNums.at(i) < minVal) {
      minVal = userNums.at(i);
    }
    if (userNums.at(i) > maxVal) {
      maxVal = userNums.at(i);
    }
  }

  return maxVal - minVal;
}

// Calculate StdDev
double stdDev(vector<double> userNums) {
  double standardDev = 0.0;
  double mean = getMean(userNums);

  // iterate through vector
  for (unsigned int i = 0; i < userNums.size(); i++) {
    standardDev += pow(userNums.at(i) - mean, 2);
  }

  return sqrt(standardDev / userNums.size());
}

int main() {
  cout << "One-variable statistics" << endl;
  cout << "Type your numbers (separated by whitespace) followed by EOF (^D on "
          "Linux/macOS, ^Z on Windows):"
       << endl;

  vector<double> userNums;
  double userNum = 0.0;

  // Collect input
  while (cin) {
    cin >> userNum;
    userNums.push_back(userNum);
  }
  userNums.resize(userNums.size() - 1); // Fixes redundent last value problem.

  // Output vector
  for (unsigned int i = 0; i < userNums.size(); i++) {
    cout << fixed << setprecision(3);
    cout << userNums.at(i) << ' ';
  }
  cout << endl;

  cout << fixed << setprecision(3); // Sets number of decimal places to be used

  // setw() will right justify (I think)
  cout << setw(8) << left << "Mean:" << setw(7) << right << getMean(userNums)
       << endl;
  cout << setw(8) << left << "Median:" << setw(7) << right << median(userNums)
       << endl;
  cout << setw(8) << left << "Range:" << setw(7) << right << range(userNums)
       << endl;
  cout << setw(8) << left << "StdDev:" << setw(7) << right << stdDev(userNums)
       << endl;
}
