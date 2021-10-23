#include <vector>
#include <algorithm>

using namespace std;

int left(int i)
{
    return i * 2 + 1; 
}

int right(int i)
{
    return i * 2 + 2;
}

void max_heapify(vector<int>& a, int i, int hSize)
{
    int l = left(i);
    int r = right(i);
    int largest;
    
    if (l <= hSize && a[l] > a[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= hSize && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(a[i], a[largest]);
        max_heapify(a, largest, hSize);
    }
}

void build_maxHeap(vector<int>& a)
{
    int hSize = a.size() - 1;
    for (int i = hSize / 2; i >= 0; i--)
    {
        max_heapify(a, i, hSize);
    }
}

vector<int> heapsort(vector<int>& a, int k)
{
    int hSize = a.size() - 1;
    build_maxHeap(a);
    for (int i = a.size() - 1; i >= k; i--)
    {
        swap(a[0], a[i]);
        hSize = hSize - 1;
        max_heapify(a, 0, hSize);
    }

    return a;
}

vector<int> solution(vector<int> a, int k) {
    return heapsort(a, k);
}