/*
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/
// method 1 - using sort and then check equal or not
//method 2 - using map
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        if(s.size()!=t.size())
            return false;
        for(auto x:s)
            mp[x]++;
        for(auto x:t){
            if(mp[x]>=1)
                mp[x]--;
            else
                return false;
        }
        return true;
    }
};
