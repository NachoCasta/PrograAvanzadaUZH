#pragma once

#include <iostream>
#include <vector>
using namespace std;

class RPN {
private:
  vector<int> stack;
public:
  void push(int element);
  int pop();
  void operation(string operation);
  void min();
  RPN();
  std::istringstream ask_input();
  void print_stack();
  void main_loop();
};
