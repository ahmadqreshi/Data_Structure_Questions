//o(logn)
#include <bits/stdc++.h>
using namespace std;
//approach divide array into two part 
int rotated_binary_search(int *arr,int n,int key) {
    int s = 0;
    int e = n-1;
    while(s<=e) {
        int mid = (s+e)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[s] <= arr[mid]) { // mid lie on first part
            if(key>=arr[s] and key<=arr[mid]) {
                e = mid-1;
            }else {
                s = mid+1; 
            }
        }else { // mid lie on second part
            if(key>=arr[mid+1] and key<=arr[e]) {
                s = mid+1;
            }else {
                e = mid-1;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[] = {5,6,7,8,9,0,1,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    int index = rotated_binary_search(arr,n,6);
    cout<<index; //output- 1
    return 0;
}
