#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>


template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> s;
  typename std::set<T>::iterator it;
  typename std::set<T>::iterator it2;

  for (it = s1.begin(); it != s1.end(); ++it) {
    if (s2.find(*it) != s2.end()) {
      s.insert(*it);
    }
  }
  return s;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> s;
  typename std::set<T>::iterator it;

  for (it = s1.begin(); it != s1.end(); ++it) {
    s.insert(*it);
  }
  for (it = s2.begin(); it != s2.end(); ++it) {
    if (s.find(*it) == s.end()) {
      s.insert(*it);
    }
  }
  return s;
}


std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
