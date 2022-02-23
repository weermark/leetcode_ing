class Solution {
public:
    bool isAnagram(string s, string t) {
        // record the frequency that 1-26 alphabet appear int string
        int record[26] = {0};
        // record the asci
        int index;
        
        for(int i = 0; i < s.size(); i++){
            index = s[i] - 'a';
            record[index]++;
        }
        for(int i = 0; i < t.size(); i++){
            index = t[i] - 'a';
            record[index]--;
        }
        for(int i = 0; i < 26; i++){
            // if value not equal to zero, it must not be anagram
            if(record[i] != 0)
                return false;
        }
        return true;
    }
};
