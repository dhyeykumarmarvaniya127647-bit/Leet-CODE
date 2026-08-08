class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> sorted = pref;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        vector<long long> bit(sorted.size() + 1, 0);

        auto update = [&](int x) {
            for (; x <= (int)sorted.size(); x += x & -x)
                bit[x]++;
        };

        auto query = [&](int x) {
            long long res = 0;
            for (; x > 0; x -= x & -x)
                res += bit[x];
            return res;
        };

        long long ans = 0;

        for (int x : pref) {
            int pos = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;
            ans += query(pos - 1);
            update(pos);
        }

        return ans;
    }
};