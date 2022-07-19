// by using array
#include <iostream>
using namespace std;
void merge(int arr[],int s,int mid,int e) {
    int n = mid-s + 1;
    int m = e-mid;
    int l[n];
    int r[m];
    for(int i=0;i<n;i++){
        l[i] = arr[s+i];
    }
    for(int j=0;j<m;j++) {
        r[j] = arr[mid+1+j];
    }
    int i=0,j=0,k=s;
    while(i<n and j<m) {
        if(l[i]<=r[j]){
            arr[k++] = l[i++];
        }else {
            arr[k++] = r[j++];
        }
    }
    while(i<n) {
        arr[k++] = l[i++];
    }
    while(j<m) {
        arr[k++] = r[j++];
    }
}
void mergeSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}
int main()
{
    int arr[] = {3,2,8,7,9,0};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    for(int i : arr) {
        cout<<i<<" ";
    }

    return 0;
}




//by using temp vector
#include<bits/stdc++.h>
using namespace std;
void merge(int *arr,int s,int mid,int e) {
    int i = s;
    int j = mid+1;
    vector<int> temp;
    while(i<=mid and j<=e){
        if(arr[i]<=arr[j])
            temp.push_back(arr[i++]);
        else 
            temp.push_back(arr[j++]);
    }
    while(i<=mid) {
        temp.push_back(arr[i++]);
    }
    while(j<=e) {
        temp.push_back(arr[j++]);
    }
    int k=0;
    for(int idx = s ; idx <=e ; idx++) {
        arr[idx] = temp[k++];
    }
}
void mergeSort(int *arr,int s,int e) {
    if(s>=e)
        return;
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}
int main() {
    int arr[]={2,1,4,3,5,7,6,0};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    for(auto i : arr) {
        cout<<i<<" ";
    }
    return 0;
}
