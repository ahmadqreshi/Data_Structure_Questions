#include<bits/stdc++.h>
using namespace std;
int isArraySorted(int s[], int n) {
  int a = 1, d = 1, i = 0;

  while ((a == 1 || d == 1) && i < n - 1) {
    if (s[i] < s[i+1])
      d = 0;
    else if (s[i] > s[i+1])
      a = 0;
    i++;
  }

  if (a == 1)
    return 1;
  else if (d == 1)
    return 2;
  else
    return 0;
}
int main() {
    int arr[]= {5,5,5,4,3,2};
    int n = sizeof(arr)/sizeof(int);
    int res = isArraySorted(arr,n);
    switch (res) {
        case 0 :
        cout<<"Array is not sorted"<<endl;
        break;
        case 1 :
        cout<<"Ascending order"<<endl;
        break;
        case 2:
        cout<<"descending order"<<endl;
        break;
    }
    return 0;
}
