#include <iostream>
// creating a class to remember what i took in c++ before i start data structures
class Person {
  public:
  //default constructor with no parameters to intialzie the member variables
  Person() : name_(""), age_(0), major_("") {};
  Person(std::string name, int age, std::string major) : name_(name), age_(age), major_(major) {};


  // setters
  void SetName(std::string name) {
    name_ = name;
  }

  void SetAge(int age) {
    age_ = age;
  }

  void SetMajor(std::string major) {
    major_ = major;
  }

  // getters

  std::string GetName() {
    return name_;
  }

  int GetAge() {
    return age_;
  }

  std::string GetMajor() {
    return major_;
  }

  private:
  std::string name_;
  int age_;
  std::string major_;
};