void CallC()
{
	std::cout << "C called" << std::endl;
}
void CallB()
{
	std::cout << "B called" << std::endl;
	CallC();
}

void CallA()
{
	CallB();
	CallC();
}

int main()
{
	CallA();

    return 0;
}