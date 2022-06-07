char strHello[] = "Hello, world!";

int nIndex;
do
{
    std::cout << "Enter an index: ";
    std::cin >> nIndex;
} while (nIndex < 0 || nIndex >= strlen(strHello));

std::cout << "Letter #" << nIndex << " is " << strHello[nIndex] << std::endl;