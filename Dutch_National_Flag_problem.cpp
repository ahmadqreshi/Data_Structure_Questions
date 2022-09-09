//sort an array of 0s,1s and 2s

#include <bits/stdc++.h>
using namespace std;

void sortColor(int *arr,int n) {
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high){
        if(arr[mid]==0) {
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        } else if(arr[mid]==1) {
            mid++;
        } else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main()
{
    int arr[] = {0, 1, 2, 0, 1, 2};
    int n = sizeof(arr)/sizeof(int);
    sortColor(arr,n);
    for(auto x : arr) {
        cout<<x<<" ";
    }
    return 0;
}
