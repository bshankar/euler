#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>
#include <sstream>

using std::string;
using std::ifstream;
using std::stringstream;

template<class T>
vector<T> readVector(string fileName) {
  ifstream file(fileName);
  T element;
  vector<T> vec;
  while (file >> element)
    vec.push_back(element);
  
  return vec;
}

template<class T>
vector<vector<T>> readGrid(string fileName) {
  ifstream file(fileName);
  vector<vector<T>> vec;
  string s;
  T element;
  while (getline(file, s)) {
    vector<T> vec1;
    stringstream ss(s);
    while (ss >> element) 
      vec1.push_back(element);
    vec.push_back(vec1);
  }
  return vec;
}

#endif
