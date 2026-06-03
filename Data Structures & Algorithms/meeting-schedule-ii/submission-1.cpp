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
        int res = 0;
        sort(intervals.begin(), intervals.end(),
                [](const Interval& I1, const Interval& I2) {
            return I1.end < I2.end;
        });
        multiset<int> st;
        for(auto& x: intervals) {
            if(st.lower_bound(-x.start) != st.end()) {
                st.erase(st.lower_bound(-x.start));
            } else {
                ++res;
            }
            st.insert(-x.end);
        }
        return res;
    }
};
