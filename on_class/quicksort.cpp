#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int hoare_swap = 0;
int lomuto_swap = 0;
int hoare_comp = 0;
int lomuto_comp = 0;


int partiton_hoare(vector<int>& v, int low, int high)
{
	int pivot = v[low];
	int i = low - 1;
	int j = high + 1;
	while (1)
	{
		do
		{
			hoare_comp = hoare_comp + 1;	// hoare comp increase
			i += 1;
		} 
		while (v[i] < pivot);	// comparison
		
		do
		{
			hoare_comp = hoare_comp + 1;	// hoare comp increase
			j -= 1;

		} 
		while (v[j] > pivot);	// comparison

		if (i < j)
		{
			hoare_swap = hoare_swap + 1;
			swap(v[i], v[j]);	// swap
		}
		else
			return j;
	}
}

void quicksort1(vector<int>& v, int low, int high)	// hoare
{
	if (low < high)
	{
		int q = partiton_hoare(v, low, high);
		quicksort1(v, low, q);
		quicksort1(v, q + 1, high);
	}
}

int partiton_lomuto(vector<int>& v, int low, int high)
{
	int pivot = v[low];
	int j = low;
	for(int i = low + 1; i <= high; i++)
	{
		lomuto_comp = lomuto_comp + 1;
		if(v[i] < pivot)
		{
			j = j + 1;
			lomuto_swap = lomuto_swap + 1;
			swap(v[i], v[j]);
		}
	}
	int pivot_pos = j;
	lomuto_swap = lomuto_swap + 1;
	swap(v[pivot_pos], v[low]);
	return pivot_pos;
}

void quicksort2(vector<int>& v, int low, int high)	// lomuto
{
	if (low >= high)
		return;
	int p = partiton_lomuto(v, low, high);
	quicksort2(v, low, p-1);
	quicksort2(v, p + 1, high);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> vec;
		int m;
		cin >> m;
		
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;
			vec.push_back(num);
		}

		quicksort1(vec, 0, vec.size() - 1);
		// for(int i = 0; i < vec.size();i++)
		// {
		// 	cout << vec[i] << endl;
		// }

		quicksort2(vec, 0, vec.size() - 1);
		// for(int i = 0; i < vec.size();i++)
		// {
		// 	cout << vec[i] << endl;
		// }


		cout << hoare_swap << ' ' << lomuto_swap << ' ' << hoare_comp << ' ' << lomuto_comp << endl;

		hoare_swap = 0;
 		lomuto_swap = 0;
 		hoare_comp = 0;
	 	lomuto_comp = 0;
	}
	return 0;
}
