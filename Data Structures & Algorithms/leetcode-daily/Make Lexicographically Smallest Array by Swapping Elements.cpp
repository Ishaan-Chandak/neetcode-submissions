// not a medium problem at all
// invovles pairing elements in groups
// mapping each element to its group + having a map to store all the elements in one group
// then traversing the array - finding the group of the number - replacing the current value with the smallest element of its group, and then removing that element from the group
// this will give lexicograpgically smallest array


class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        int curr = 0;
        unordered_map<int, int> numg;
        numg[sorted[0]] = curr;

        unordered_map<int, list<int>> groups;
        groups[curr].push_back(sorted[0]);

        for(int i = 1; i<n; i++) {
            if(abs(sorted[i-1] - sorted[i]) > limit) curr++;

            if(groups.find(curr) == groups.end()) groups[curr] = list<int>();

            numg[sorted[i]] = curr;
            groups[curr].push_back(sorted[i]);
        }

        for(int i=0; i<n; i++) {
            int temp = nums[i];
            int grp = numg[temp];
            int rep = groups[grp].front();
            groups[grp].pop_front();
            nums[i] = rep;
        }

        return nums;
    }
};
