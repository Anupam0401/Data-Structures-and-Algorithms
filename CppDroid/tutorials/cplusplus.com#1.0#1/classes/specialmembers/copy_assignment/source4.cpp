Example5& operator= (const Example5& x) {
  *ptr = x.content();
  return *this;
}