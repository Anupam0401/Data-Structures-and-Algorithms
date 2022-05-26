// declare global variable
int g_nMode = 1;

void doSomething()
{
    g_nMode = 2;
}

int main()
{
    g_nMode = 1;

    doSomething();

    // Programmer expects g_nMode to be 1
    // But doSomething changed it to 2!

    if (g_nMode == 1)
        cout << "No threat detected." << endl;
    else
        cout << "Launching nuclear missiles..." << endl;

    return 0;
}