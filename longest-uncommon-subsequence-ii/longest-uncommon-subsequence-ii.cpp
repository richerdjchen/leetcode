class Solution {
public:
    bool check(string s1, string s2) {
        int A = s1.size();
        int B = s2.size();
        while(A > 0 && B > 0) {
            int i = s1.size() - A;
            int j = s2.size() - B;
            if (s1[i] == s2[j])
                A--;
            B--;
        }
        return A == 0;
    }
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        for (int i = 0; i < strs.size(); i++) {
            bool isSub = false;
            int curLen = strs[i].size();
            for (int j = 0; j < strs.size(); j++) {
                if (i != j && check(strs[i], strs[j])) {
                    isSub = true;
                    break;
                }
            }
            if (!isSub)
                maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};