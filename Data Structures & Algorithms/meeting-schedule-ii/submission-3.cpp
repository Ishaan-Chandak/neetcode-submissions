/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;

        for(auto interval : intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int cnt = 0;

        int n = start.size();

        int i = 0, j = 0;

        int maxi = INT_MIN;

        while(i < n && j < n) {
            if(start[i] < end[j]) {
                cnt++;
                i++;
            } else {
                cnt--;
                j++;
            }

            maxi = max(maxi, cnt);
        }

        return maxi == INT_MIN ? 0 : maxi;
    }
};
