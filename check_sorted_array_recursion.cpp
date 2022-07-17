#include <bits/stdc++.h>
using namespace std;
//method 1
bool checkSortedArray(int i,vector<int> arr) {
    if(i==arr.size()-2)
        return true;
    if(arr[i] > arr[i+1])
        return false;
    i = i + 1;
    checkSortedArray(i,arr);
}
//method 2- best and easy
bool isSorted(int arr[],int n) {
    if(n==1 or n==0) // n==0 because empty array is also sorted
        return true;
    if(arr[0] < arr[1] and isSorted(arr+1,n-1)) // checks for the remaining array
        return true;
    return false;
}

int main()
{
    vector<int> arr = {0,4,2,3};
    int arr1[] = {0,1,2,6};
    if(isSorted(arr1,4)) cout<<"Sorted array"<<endl;
    else cout<<"Not Sorted array"<<endl;
    if(checkSortedArray(0,arr)) cout<<"Sorted";
    else cout<<"Not Sorted";

    return 0;
}
