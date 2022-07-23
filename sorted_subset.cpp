
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
void printSubset(char *input, char *output,int i,int j,vector<string> &v) {
    if(input[i]=='\0'){
        output[j] = '\0';
        string temp(output);
        v.push_back(temp);
        return;
    }
    output[j] = input[i];
    printSubset(input,output,i+1,j+1,v);
    output[j] = '\0';
    printSubset(input,output,i+1,j,v);
}
bool compare(string a, string b) { // custom compare function 
    if(a.size() ==  b.size()) {
        return a<b; //lexographic sorted order
    }
    return a.size()<b.size(); // sorted on basis of their length
}
int main()
{
    char input[] = "abc";
    char output[100];
    vector<string> list;
    printSubset(input,output,0,0,list);
    sort(list.begin(),list.end(),compare);
    for(auto x : list) {
        cout<<x<<",";
    }
    return 0;
}
