//Check If a Word Occurs As a Prefix of Any Word in a Sentence
// method 1 not optimized
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string temp = "";
        for(int i=0;i<sentence.size();i++) {
            if(sentence[i]==' '){
                words.push_back(temp);
                temp = "";
            }else{
                temp += sentence[i];
            }
        }
        words.push_back(temp); // insert last word in the sentence
        for(int j=0;j<words.size();j++) {
            string temp1 = "";
            for(int i=0;i<words[j].size();i++){
                temp1 += words[j][i];
                if(temp1==searchWord)
                    return j+1;
            }
        }
        return -1;
    }
};

//method 2 
//time complexity - o(n)
//space complexity - o(1)
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordCount = 1;
        string word = "";
        for(int i=0;i<sentence.size();i++) {
            if(sentence[i]==' ') {
                if(word.size()>=searchWord.size() and word.substr(0,searchWord.size())==searchWord)
                    return wordCount;
                word = "";
                wordCount++;
            }else {
                word += sentence[i];
            }
        }
        if(word.size()>=searchWord.size() and word.substr(0,searchWord.size())==searchWord) // checks for the last word
            return wordCount;
        return -1;
    }
};
