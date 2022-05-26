Something cSomething;
cSomething.GetValue(); // calls non-const GetValue();

const Something cSomething2;
cSomething2.GetValue(); // calls const GetValue();