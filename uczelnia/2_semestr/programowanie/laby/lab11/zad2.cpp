class A {
public:
  virtual void f() = 0;
  virtual void g() = 0;
  virtual void h() = 0;
  virtual ~A() = default;
};

class B : public A {
public:
  void f() override { return; }
  void g() override final { return; }
  void h() override { return; }
  ~B() { return; }
};

class C final : public B {
  void f() override final { return; }
  void g() override final { return; } // błąd
  void h() override final { return; }
};
