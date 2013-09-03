/****************************************************

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

****************************************************/

struct Interval {
 	int start;
 	int end;
 	Interval() : start(0), end(0) {}
 	Interval(int s, int e) : start(s), end(e) {}
};

struct comp {
	bool operator()(const Interval& lhs, const Interval& rhs) 
	{
		return lhs.start < rhs.start;
	}
};

class Solution {
public:
    std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval)
	{
		std::vector<Interval> ret;
		intervals.push_back(newInterval);
		std::sort(intervals.begin(), intervals.end(), comp());
		ret.push_back(intervals[0]);
		for (uint i = 1; i < intervals.size(); ++i) {
			if (ret.back().end < intervals[i].start) ret.push_back(intervals[i]);
			else ret.back().end = std::max(ret.back().end, intervals[i].end);
		}

		return ret;
	}

	/*** the other methods...
	static bool comp(const Interval& lhs, const Interval& rhs) 
	{
		return lhs.start < rhs.start;
	} ***/
};
