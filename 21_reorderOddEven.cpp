#include <iostream>

void swap(int& a, int& b);

void reorderOddEven(int* pData, unsigned int length)
{
	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		if ((pData[left] & 1) == 0)
		{
			if ((pData[right] & 1) == 1)
				swap(pData[left], pData[right]);
			else
				right--;
		}
		else
		{
			if ((pData[right] & 1) == 1)
				left++;
			else
			{
				left++;
				right--;
			}
		}
	}

}

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void printData(int* pData, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (i < length - 1)
			std::cout << pData[i] << ", ";
		else
			std::cout << pData[i] << ".";
	}
}


// ====================测试代码====================
void PrintArray(int numbers[], int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d\t", numbers[i]);

	printf("\n");
}

void Test(const char* testName, int numbers[], int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = numbers[i];
	}

	printf("Test for solution 1:\n");
	PrintArray(numbers, length);
	reorderOddEven(numbers, length);
	PrintArray(numbers, length);
#if 0
	printf("Test for solution 2:\n");
	PrintArray(copy, length);
	ReorderOddEven_2(copy, length);
	PrintArray(copy, length);
#endif

	delete[] copy;
}

void Test1()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int));
}

void Test2()
{
	int numbers[] = { 2, 4, 6, 1, 3, 5, 7 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3()
{
	int numbers[] = { 1, 3, 5, 7, 2, 4, 6 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4()
{
	int numbers[] = { 1 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5()
{
	int numbers[] = { 2 };
	Test("Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6()
{
	Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}

#if 0
int main()
{
	int data[] = { 1, 2, 3, 4, 5 };
	int length = sizeof(data) / sizeof(int);
	reorderOddEven(data, length);

	printData(data, length);
	
	return 0;
}
#endif
