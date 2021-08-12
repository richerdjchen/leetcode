class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int,int> mp;
        for (int i = 0; i < arr.size(); i++) {
            int j = i + 1;
            int cnt = 1;
            while (j < arr.size() && arr[i] == arr[j]) {
                cnt++;
                j++;
            }
            mp.emplace(arr[i], cnt);
            i = j-1;
        }
        auto it = mp.begin();
        while(it != mp.end()) {
            cout << it->first << ", " << it->second << endl;
            while (it->second > 0) {
                auto found = mp.find(2 * it->first);
                if (found != mp.end() && found->second != 0) {
                    if (it->second >= found->second) {
                        mp[it->first] = it->second - found->second;
                        mp[found->first] = 0;
                    } else {
                        mp[found->first] = found->second - it->second;
                        mp[it->first] = 0;
                    }
                } else if (it->first % 2 == 0) {
                    found = mp.find(it->first/2);
                    if (found != mp.end() && found->second != 0) {
                        if (it->second >= found->second) {
                            mp[it->first] = it->second - found->second;
                            mp[found->first] = 0;
                        } else {
                            mp[found->first] = found->second - it->second;
                            mp[it->first] = 0;
                        }
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            it++;
        }
        return true;
    }
};