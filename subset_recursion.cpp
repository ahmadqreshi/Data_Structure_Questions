
#include <iostream>
using namespace std;
void printSubset(char *input, char *output,int i,int j) {
    if(input[i]=='\0'){
        output[j] = '\0';
        if(output[0]=='\0') cout<<"NULL";
        cout<<output<<endl;
        return;
    }
    output[j] = input[i];
    printSubset(input,output,i+1,j+1);
    output[j] = '\0';
    printSubset(input,output,i+1,j);
}
int main()
{
    char input[] = "abc";
    char output[100];
    printSubset(input,output,0,0);
    return 0;
}
// OUPUT :
/*
abc
ab
ac
a
bc
b
c
NULL
*/
