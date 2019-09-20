/*
  数据排列越随机快速排序效率越高。
*/

#include <iostream>


int division(int* data, int first, int last)
{
	int left = first;
	int right = last;
	int sign = data[first];

	while (left < right)
	{
		while (sign <= data[right] && left < right)
			right--;
		data[left] = data[right];

		while (sign >= data[left] && left < right)
			left++;
		data[right] = data[left];

		if (right == left)
		{
			data[right] = sign;
			return right;
		}
	}
	return -1;
}


int quickSort(int* data, int first, int last)
{
	if (first == last)
		return 0;

	int middle = division(data, first, last);
	if (middle > first)
		quickSort(data, first, middle - 1);
	if (middle < last)
		quickSort(data, middle + 1, last);

}


int main()
{
	int s[10] = { 4, 8, 3, 9, 2, 5, 0, 6, 1, 7 };
	quickSort(s, 0, 9);
	
	for (int i = 0; i < 10; i++)
		std::cout << s[i] << ", ";
	return 0;
}
