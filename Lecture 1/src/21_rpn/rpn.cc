#include "rpn.h"

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

RPN::RPN(){

}

void RPN::push(int element){
  stack.push_back(element);
}

int RPN::pop(){
  int last = stack.back();
  stack.pop_back();
  return last;
}

void RPN::operation(string operation){
  int b = pop();
  int a = pop();
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

void RPN::min(){
  int b = pop();
  int a = pop();
  if (a < b){
    push(a);
  }
  else {
    push(b);
  }
}

void RPN::print_stack(){
  int i = 0;
  for (int elem : stack) {
    i++;
    cout << i << ": " << elem << endl;
  }
}

std::istringstream RPN::ask_input() {
  string line;
  cout << "Command: ";
  std::getline(cin, line);
  std::istringstream iss(line);
  return iss;
}

void RPN::main_loop(){
  string command;
  int n;
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
