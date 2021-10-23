#include <iostream>
#define swap(a,b) {int t; t=a; a=b; b=t;}
using namespace std;


void quick(int *array, int left, int right);

int main()
{
	int length;
	// cout << "배열의 크기를 입력하십시오 : ";
	cin >> length;

	int *numArray = new int[length];

	for (int i = 0;i<length;i++) {
		cin >> numArray[i];
	}
	quick(numArray, 0, length-1);
	
	// cout << "배열의 크기는 " << _msize(numArray)/sizeof(*numArray) << "입니다.\n";
	for (int i = 0; i < length; i++) {
		cout << numArray[i] << endl;
	}
	delete[] numArray;
	return 0;
} 

void quick(int* array, int left, int right)
{
	int pivot = left;
	int lpivot = left;
	int rpivot = right;

	while (lpivot < rpivot)
	{
		while (array[lpivot] <= array[pivot] && lpivot < right)
		{
			lpivot += 1;
		} 

		while (array[rpivot] >= array[pivot] && left < rpivot)
		{
			rpivot -= 1;
		}
		if (lpivot < rpivot)
		{
			swap(array[lpivot], array[rpivot]);

			continue;
		}

		swap(array[pivot], array[rpivot]);
		quick(array, left, rpivot - 1);
		quick(array, rpivot + 1, right);
	}
}