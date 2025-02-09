class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end()) return 0;
        unordered_set<string> beginSet{beginWord}, endSet{endWord};
        int level = 1;
        while(!beginSet.empty() && !endSet.empty()){
            if(beginSet.size() > endSet.size()) swap(beginSet, endSet);
            unordered_set<string> nextSet;
            for(auto word : beginSet){
                for(int i = 0; i < word.size(); i++){
                    char original = word[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        word[i] = c;
                        if(endSet.find(word) != endSet.end()) return level + 1;
                        if(dict.find(word) != dict.end()){
                            nextSet.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            beginSet = nextSet;
            level++;
        }
        return 0;
    }
};