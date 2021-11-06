#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> c, int money)
{
	int dp[11][1001] = {0};
	dp[0][0] = 1;

	for (int idx = 0; idx <= c.size(); idx++)
	{
		for (int i = 1; i <= c.size() - 1; i++)
		{
			int coinval = c[i];
			for (int j = 0; j <= money; j++)
			{
				if (j < coinval)//0 ~ j-1 까지는 변함 없음
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i][j - coinval] + dp[i - 1][j];
			}
		}
	}
	return dp[c.size()-1][money];
}

int main()
{
	int rpt;
	cin >> rpt;
	for (int i = 0; i < rpt; i++)
	{
		int n, money;
		cin >> money;
		cin >> n;
		vector<int> coins = {0};

		for (int i = 0; i < n; i++)
		{
			int value;
			cin >> value;
			coins.push_back(value);
		}
		cout << solution(coins, money) << "\n";
	}
	return 0;
}