//time complexity - o(nlogn)
//worst time complexity - 0(n^2)
#include <bits/stdc++.h>
using namespace std;
int partition(int *arr,int s,int e) {
    int pivot = arr[e];
    int i = s-1;  //-1 
    int j = s;    // 0 
    while(j<e) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}
void quickSort(int *arr,int s,int e){
    if(s>=e)
        return;
    int p = partition(arr,s,e); // return correct index of pivot element
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main()
{
    int arr[] = {2,5,4,3,3,1,9};
    int n = sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    for(int i : arr) {
        cout<<i<<" ";
    }
    return 0;
}
