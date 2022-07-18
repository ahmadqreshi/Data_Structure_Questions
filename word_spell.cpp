//word spell
#include <bits/stdc++.h>
using namespace std;
void word_spell(int n,string words[]) {
    if(n==0)
        return;
    word_spell(n/10,words);
    int last_digit = n%10;
    cout<<words[last_digit]<<" ";
}
int main()
{
    string words[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    word_spell(1234567,words);
    return 0;
}
