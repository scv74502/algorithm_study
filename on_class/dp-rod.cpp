#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

// signature of top-down mcr, mcra
int memorizedCutRod_td(vector<int>& p, int n);

int memorizedCutRodAux_td(vector<int>& p, int n, vector<int>& r);

// signature of bottom-up cut rod
int cutRod_bu(vector<int>& p, int n);

int main()
{
	int n;
	// value of index-0 is 0
	vector<int> price = {0, 1, 5, 8, 10};
	//cout << "Input integer n : ";
	//cin >> n;
	n = price.size() - 1;
	cout << memorizedCutRod_td(price, n) << endl;
	cout << cutRod_bu(price, n) << endl;

}

// top-down
int memorizedCutRod_td(vector<int>& p, int n)
{
	vector<int> r(n + 1);
	for (int i = 0; i <= n; i++)
	{
		r[i] = -1;
	}

	return memorizedCutRodAux_td(p, n, r);
}

int memorizedCutRodAux_td(vector<int>& p, int n, vector<int>& r) 
{
	int q;
	if (r[n] >= 0)
	{
		return r[n];
	}
	if (n == 0)
	{
		q = 0;
	}
	else
	{
		q = -1;
		for (int i = 1; i <= n; i++)
		{
			q = max(q, p[i] + memorizedCutRodAux_td(p, n-i,r));
		}
	}
	r[n] = q;
	return q;
}

// bottom-up
int cutRod_bu(vector<int>& p, int n)
{
	vector<int> r(n + 1);
	r[0] = 0;
	int q;
	for (int j = 1; j <= n; j++)
	{
		q = -1;
		for (int i = 1; i <= j; i++)
		{
			q = max(q, p[i] + r[j - i]);
		}
		r[j] = q;
	}

	return r[n];
}

