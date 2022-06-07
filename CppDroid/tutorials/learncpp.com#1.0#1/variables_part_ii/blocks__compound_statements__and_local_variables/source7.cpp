int main()
{ // start outer block
    using namespace std;

    int x = 5;

    { // start nested block
        int y = 7;
        // we can see both x and y from here
        cout << x << " + " << y << " = " << x + y;
    } // y destroyed here

    // y can not be used here because it was already destroyed!

    return 0;
} // x is destroyed here