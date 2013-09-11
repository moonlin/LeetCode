/*******************************************************
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*******************************************************/

struct comp {
	bool operator()(const Interval& lhs, const Interval& rhs)
	{
		return lhs.start < rhs.start;
	}
};

class Solution {
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals)
	{
		std::vector<Interval> ret;
		if (intervals.empty()) return ret;

		std::sort(intervals.begin(), intervals.end(), comp());
		ret.push_back(intervals[0]);
		for (uint i = 1; i < intervals.size(); ++i) {
			if (ret.back().end < intervals[i].start) ret.push_back(intervals[i]);
			else ret.back().end = std::max(ret.back().end, intervals[i].end);
		}

		return ret;
	}

};
