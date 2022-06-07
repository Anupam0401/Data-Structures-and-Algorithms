enum Colors
{
    COLOR_BLACK,
    COLOR_WHITE,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
};

void PrintColor(Colors eColor)
{
    using namespace std;
    if (eColor == COLOR_BLACK)
        cout << "Black";
    else if (eColor == COLOR_WHITE)
        cout << "White";
    else if (eColor == COLOR_RED)
        cout << "Red";
    else if (eColor == COLOR_GREEN)
        cout << "Green";
    else if (eColor == COLOR_BLUE)
        cout << "Blue";
    else
        cout << "Unknown";
}