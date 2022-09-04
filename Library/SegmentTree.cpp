#include <bits/stdc++.h>
using namespace std;
int segmentArr[1000];

void buildSegmentTree(int arr[], int idx, int low, int high)
{
    if(low == high)
    {
        segmentArr[idx] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    buildSegmentTree(arr,2 * idx + 1, low, mid);
    buildSegmentTree(arr,2 * idx + 2, mid + 1, high);
    segmentArr[idx] = max(segmentArr[2 * idx + 1], segmentArr[2 * idx + 2]);
}

int rangeQuery(int idx, int low, int high, int l, int r)
{
    if(low >= l && high <= r)
        return segmentArr[idx];
    if(high < l || low > r)
        return INT_MIN;
    int mid = (low + high)/2;
    int left = rangeQuery(2 * idx + 1, low, mid, l , r);
    int right = rangeQuery(2 * idx + 2, mid + 1, high, l , r);
    return max(left, right);
}

int main()
{
    int n;
    cout<<"Enter no. of elements : "<<endl;
    cin >> n;
    int arr[n];
    cout<<"Enter elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    cout << "Enter Queries \n";    
    buildSegmentTree(arr,0, 0, n-1);
    
    int q;
    cin >> q;
    for(int i=1;i<=q;i++)
    {
        int l, r;
        cin >> l >> r;
        cout << rangeQuery(0, 0, n-1, l , r) << "\n";
    }
    return 0;
    
}