#include<iostream>

using namespace std;

int euclid(int a, int b)
{
	int answer;
	if (b == 0)
		answer = a;
	else
		answer = euclid(b, a % b);
	return answer;
}

int main()
{
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)	
	{
		cin >> a >> b;
		cout << euclid(a, b) << endl;
	}
	return 0;
}