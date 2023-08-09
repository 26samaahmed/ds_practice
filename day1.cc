// opening a file and reading the content inside using ifstream/ofstream
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "class.cc"
#include "linkedlist.cc"
using namespace std;
/*
ofstream myfile;
myfile.open("example.txt"); // creates a file called example.txt
myfile << "reading file"; //inserting a sentence in the file
myfile.close(); 
}
*/
int main() {

  list<int> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  for (int b: data) {
    cout << b << endl;
  }

  vector<int> values;
  values.push_back(6);
  values.push_back(5);
  for (int i; i < values.size(); i++) {
    cout << values[i] << "\n";
  }
  cout << values.size() << "\n";

  Person object1 = {"sama", 18, "computer science"};
  cout << "i am " << object1.GetName() << ". I am " << object1.GetAge() << " years old. I'm a " << object1.GetMajor() << " major\n";

  
  return 0;
}

// to compile then run, do g++ -std=c++11 day1.cc -o day1 then ./day1

// size_t represents the size of an object in bytes