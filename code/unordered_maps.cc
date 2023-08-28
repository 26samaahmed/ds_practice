#include<iostream>
#include<unordered_map>
#include<iterator>

// in progress
/*
Exercise 2: Word Frequency Counter
Create a program that reads a paragraph of text and uses an unordered map to count the frequency of each word. Ignore punctuation and consider words 
in a case-insensitive manner.
*/


int main() {
  std::unordered_map<std::string, int> map; 
  // the first value is the key and the second is the value
  map["blue"] = 1;
  map["red"] = 4;
  map["green"] = 2;
  for (auto x: map) {
    std::cout << x.first << ": " << x.second << "\n"; // this won't print the map in order. It's random unlike maps
  }
  std::cout << map.at("blue") << "\n";

  for (auto i = map.begin(); i != map.end(); i++) {
        std::cout << i->first << ": " << i->second << "\n"; // iterating through the map
  }

  std::cout << "green appears: " << map.count("green") << "\n"; // checks if green exists in the map. Returns 1 if true, else false
  std::cout << "orange appears: " << map.count("orange") << "\n"; 
  std::string name = "my name is sama";
  std::cout << name.substr() << "\n";

}