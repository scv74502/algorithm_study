#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>

using namespace std;
long long dp[102][102];
long long sum[103];

long long solution(int wlen, vector<int> wcut)
{
	int cut = wcut.size();
	int cnt = 0;

	vector<int> lvec;
	for (int i = 0; i < cut; i++)
	{
		lvec.push_back(wcut[i] - cnt);
		cnt = wcut[i];
	}
	lvec.push_back(wlen - wcut[cut - 1]);


	long long dp[1020][1020];
	long long sum[1020];
	sum[0] = 0;

	for (int i = 0; i < lvec.size(); i++)
	{
		sum[i + 1] = sum[i] + lvec[i];
	}


	for (int i = 1; i <= lvec.size(); i++)
	{
		for (int j = 1; j <= lvec.size(); j++)
		{
			dp[j][i + j] = LLONG_MAX;
			for (int k = j; k < i + j; k++)
			{
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
			}
		}
	}

	return dp[1][lvec.size()];

	//메모리 동적할당 해제.
	for (int i = 0; i < lvec.size() + 1; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	delete[] sum;

}

int main()
{
	int rpt;
	cin >> rpt;
	for (int i = 0; i < rpt; i++)
	{
		int wlen, cut;	// wood length, times to cut wood
		cin >> wlen >> cut;	//input woodlength, times to cut
		vector<int> wcut;
		for (int i = 0; i < cut; i++)
		{
			int cloc;	// location to cut
			cin >> cloc;
			wcut.push_back(cloc);
		}

		cout << solution(wlen, wcut) << "\n";
	}
}

