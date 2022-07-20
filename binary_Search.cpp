//method 1 using two pointer 
int binarySearch(int *arr,int n,int key) {
    int s = 0;
    int e = n-1;
    while(s<=e) {
        int mid = (s+e)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return -1;
}

//method 2 using recursion
int binarySearch(int *arr,int s,int e,int key) {
    if(s>e)
        return -1;
    int mid = (s+e)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]<key) {
        return binarySearch(arr,mid+1,e,key);
    }else {
        return binarySearch(arr,s,mid-1,key);
    }
}
