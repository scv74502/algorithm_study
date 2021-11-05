#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getMin(vector<int> coins, int val)
{
    int cnt = 0;
    for(int i = coins.size() - 1; i >= 0; i--)
    {
        while(val >= coins[i])
        {
            val = val % coins[i];
            cnt += 1;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int value;
        int numCoin;
        vector<int> coins;

        cin >> value;
        cin >> numCoin;

        for(int j = 0; j < n; j++)
        {
            int coin;
            cin >> coin;
            coins.push_back(coin);
        }
        getMin(coins, value);
    }
    return 0;
}