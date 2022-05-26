int main()
{
    enum class Color
    {
        RED,
        BLUE
    };

    enum class Fruit
    {
        BANANA,
        APPLE
    };

    Color a = Color::RED; // note: RED is not accessible any more, we have to use Color::RED
    Fruit b = Fruit::BANANA; // note: BANANA is not accessible any more, we have to use Fruit::BANANA

    if (a == b) // compile error here, as the compiler doesn't know how to compare different types Color and Fruit
        cout << "a and b are equal" << endl;
    else
        cout << "a and b are not equal" << endl;

    return 0;
}