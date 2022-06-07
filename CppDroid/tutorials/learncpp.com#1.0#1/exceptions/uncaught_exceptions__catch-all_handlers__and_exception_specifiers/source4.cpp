int main()
{

    try
    {
        RunGame();
    }
    catch(...)
    {
        cerr << "Abnormal termination" << endl;
    }

    SaveState(); // Save user's game
    return 1;
}