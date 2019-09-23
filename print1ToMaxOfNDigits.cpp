// 解决最大数字太大超出int / long int / long long int范围： 用字符串表示数字
// char 和 int之间的类型转换要 + / - '0'
#include <iostream>


#if 1
bool Increment(char* number);
void PrintNumber(char* number);

void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;

	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}

	delete[]number;
}

bool Increment(char* number)
{
	bool isOverflow = false;
	int length = strlen(number);
	int nTakeOver = 0;

	for (int digit = length - 1; digit >= 0; digit--)
	{
		int nSum = number[digit] - '0' + nTakeOver; // char to int: 'char' - '0'
		if (digit == length - 1)
			nSum++;
		if (nSum >= 10)
		{
			if (digit == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				number[digit] = nSum + '0'; // int to char: ' int + '0' '
				nTakeOver = 1;
			}
		}
		else
		{
			number[digit] = nSum + '0';
			break;
		}
	}
	return isOverflow;
}

void PrintNumber(char* number)
{
	int length = strlen(number);
	bool begin = false;

	for (int digit = 0; digit <= length - 1; digit++)
	{
		if (number[digit] == '0' && !begin)
			continue;
		else
			begin = true;

		if (begin)
			std::cout << number[digit];
	}
	std::cout << ", ";
}
#endif

// ====================测试代码====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	Print1ToMaxOfNDigits_1(n);
	// Print1ToMaxOfNDigits_2(n);

	printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
#if 1
	Test(1);
	Test(2);
	// Test(3);
	Test(0);
	Test(-1);
#endif

	return 0;
}

