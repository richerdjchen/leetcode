bool clipSort(vector<int> i, vector<int> j) {
    if (i[0] == j[0])
        return i[1] > j[1];
    else
        return i[0] < j[0];
}
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(time+1, -1);
        dp[0] = 0;
        int range = 0;
        sort(clips.begin(), clips.end(), clipSort);
        for (int i = 0; i < clips.size(); i++) {
            int end = clips[i][1];
            if (end <= range)
                continue;
            if (range > time)
                break;
            range = end;
            int start = clips[i][0];
            if (dp[start] == -1)
                return -1;
            int dist = dp[start] + 1;
            if (end > time) 
                end = time;
            while(end > start && (dp[end] == -1 || dist < dp[end])) {
                dp[end] = dist;
                end--;
            }
        }
        return dp[time];
    }
};