#include <iostream>
#define swap(a,b) {int t; t=a; a=b; b=t;}
using namespace std;

void heapify(int* array, int index, int size)
{
	for (int ch = (index << 1) | 1; ch < size; index = ch, ch = ch << 1 | 1)
	{
		if (ch + 1 < size && array[ch + 1] > array[ch]) ++ch;
		if (array[ch] <= array[index]) return;
		swap(array[ch], array[index]);
	}
}

void heap(int* array, int begin, int end)
{
	int* base = array + begin;
	int size = end - begin + 1;
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(base, i, size);

	while (--size >= 1)
	{
		swap(base[0], base[size]);
		heapify(base, 0, size);
	}
} 

int main()
{
	int length;
	// cout << "배열의 크기를 입력하십시오 : ";
	cin >> length;

	int* numArray = new int[length];

	for (int i = 0; i < length; i++) {
		cin >> numArray[i];
	}
	heap(numArray, 0, length - 1);

	// cout << "배열의 크기는 " << _msize(numArray)/sizeof(*numArray) << "입니다.\n";
	for (int i = 0; i < length; i++) {
		cout << numArray[i] << endl;
	}
	delete[] numArray;
	return 0;
}