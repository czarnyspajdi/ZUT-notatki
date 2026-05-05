#include <iostream>

class A {
public:
  A() { std::cout << "A "; }
  ~A() { std::cout << "~A "; }
};

class B : public A {
public:
  B() { std::cout << "B "; }
  ~B() { std::cout << "~B "; }
};

class C : public B {
public:
  C() { std::cout << "C "; }
  ~C() { std::cout << "~C "; }
};
int main() { C obj; } // A B C ~C ~B ~A
