class Solution {
public:
    bool isAnagram(string s, string t) {
     if(s.length() != t.length())
     return false;

     vector<int>string(26,0);

     for(int i = 0; i < s.length();i++){
        string[s[i] - 'a'] ++;
        string[t[i] - 'a'] --;
     }
     for(int i = 0; i < 26; i++){
        if(string[i] != 0) return false;
     }
     return true;
    }
};
