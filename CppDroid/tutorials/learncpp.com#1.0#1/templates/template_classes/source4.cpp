int main()
{
	Array<int> anArray(12);
	Array<double> adArray(12);

	for (int nCount = 0; nCount < 12; nCount++)
	{
		anArray[nCount] = nCount;
		adArray[nCount] = nCount + 0.5;
	}

	for (int nCount = 11; nCount >= 0; nCount----;)
		std::cout << anArray[nCount] << "\t" << adArray[nCount] << std::endl;

	return 0;
}