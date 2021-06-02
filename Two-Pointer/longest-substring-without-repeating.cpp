// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>mp;
        int len = s.size(), mx = 0;
        for(int i =0, j = 0;i <len;i++){
            if(mp.find(s[i]) != mp.end())
                if(mp[s[i]] >= j){
                    j = mp[s[i]] + 1;
                }
            mp[s[i]] = i;
            mx = max(mx, i-j+1);
        }
        return mx;
    }
};
