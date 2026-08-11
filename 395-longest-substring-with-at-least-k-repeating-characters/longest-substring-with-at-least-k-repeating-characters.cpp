class Solution {
public:
    int longestSubstring(string s, int k) {
        if  (s.empty()) return 0;

        vector<int> f(26);
        for   (char c : s) f[c-'a']++;

        for (int i = 0; i < s.size(); i++)
            if (f[s[i]-'a'] < k)
                return max(longestSubstring(s.substr(0,i),k),
                           longestSubstring(s.substr(i+1),k));

        return s.size();
    }
};