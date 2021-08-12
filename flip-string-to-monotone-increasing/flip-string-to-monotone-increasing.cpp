class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips = 0;
        int count = 0;
        for (auto i : s) {
            if (i == '0') 
                flips++;
            else
                count++;
            flips = min(flips, count);
        }
        return flips;
    }
};