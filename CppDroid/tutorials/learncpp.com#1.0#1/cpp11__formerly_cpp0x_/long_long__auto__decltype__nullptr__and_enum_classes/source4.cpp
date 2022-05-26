decltype(5) x; // x will be type int because 5 is an int
decltype(x) y = 6; // y will be type int because x is an int
auto z = x; // z will type type int