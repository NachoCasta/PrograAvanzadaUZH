#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Element {
private:
  int number;
public:
  Element(int n): number(n) {}
  void print() { cout << "I am element number " << number << endl; }
};

int main(int argc, char *argv[])
{
  Element e1(1), e2(2), e3(3);
  vector<Element*> elements;
  elements.push_back(&e1);
  elements.push_back(&e2);
  elements.push_back(&e3);

  for_each(elements.begin(), elements.end(), mem_fun(&Element::print));

  return 0;
}
