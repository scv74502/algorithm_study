#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long mcm(vector<int> p)
{
    int n = p.size() - 1;
    long long m = [n][n];
}

int main()
{
    int num, pnum;
    vector<int> p;
    cin >> num;
    for(int i = 0; i <= num; i++)
    {
        cin >> pnum;
        p.push_back(pnum);
    }
    cout << mcm(p) << endl;
    return 0;
}