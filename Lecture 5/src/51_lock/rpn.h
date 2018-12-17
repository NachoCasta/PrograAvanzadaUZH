#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <complex>
#include "pvector.h"
using namespace std;

template<typename T>
class RPN {
private:
  pvector<T> stack;
public:
  RPN(string fname): stack(fname) {}
  void push(T element) {
    stack.push_back(element);
  }
  T pop() {
    T last = stack.back();
    stack.pop_back();
    return last;
  }
  void operation(string operation) {
    T b = pop();
    T a = pop();
    if (operation == "+"){
      push(a + b);
    }
    else if (operation == "-"){
      push(a - b);
    }
    else if (operation == "*"){
      push(a * b);
    }
    else if (operation == "/"){
      push(a / b);
    }
    else {
      push(a);
      push(b);
    }
  }
  void min() {
    T b = pop();
    T a = pop();
    if (a < b){
      push(a);
    }
    else {
      push(b);
    }
  }
  std::istringstream ask_input() {
    string line;
    cout << "Command: ";
    std::getline(cin, line);
    std::istringstream iss(line);
    return iss;
  }
  void print_stack() {
    int i = 0;
    for (T elem : stack) {
      i++;
      cout << i << ": " << elem << endl;
    }
  }
  void main_loop() {
    print_stack();
    string command;
    T n;
    string operations = "+-*/";
    std::istringstream iss;
    iss = ask_input();
    iss >> command;
    while (command != "q") {
      if (command == "n") {
        iss >> n;
        push(n);
      }
      else if (command == "d") {
        pop();
      }
      else if (operations.find(command) != string::npos && command.length() == 1) {
        operation(command);
      }
      else if (command == "min") {
        min();
      }
      if (iss.peek() == EOF){
        print_stack();
        iss = ask_input();
      }
      iss >> command;
    }
  }
};

template<>
void RPN<complex<double>>::min() {
  complex<double> b = pop();
  complex<double> a = pop();
  if (abs(a) < abs(b)){
    push(a);
  }
  else {
    push(b);
  }
}
