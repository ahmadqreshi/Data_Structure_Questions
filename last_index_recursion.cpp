
#include <iostream>
using namespace std;
int findLastOcc(int arr[],int n,int key) {
    if(n==0) return -1;
    int lastOcc = findLastOcc(arr+1,n-1,key);
    if(lastOcc==-1){
        if(arr[0]==key)
            return 0;
        else return -1;
    }else return lastOcc+1;
}

int main()
{
    int arr[] = {1,3,4,5,4,8,4,4};
    cout<<findLastOcc(arr,8,4);
    return 0;
}
