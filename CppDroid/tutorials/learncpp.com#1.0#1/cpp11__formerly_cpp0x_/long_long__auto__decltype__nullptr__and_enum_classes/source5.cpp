const std::vector<int> v(5); // declare a vector v
auto a = v[0]; // a will be type int because v[0] is an int
decltype(v[0]) b = 1; // b will be type const int&, which is the return type of std::vector<int>::operator[](size_type) const