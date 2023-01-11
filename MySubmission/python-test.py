# Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

# You may assume that the intervals were initially sorted according to their start times.

# Definition for an interval.
# class Interval:
#     def _init_(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        if not intervals:
            return []
        intervals.append(newInterval)
        intervals.sort(key=lambda x: x.start)
        res = []
        for i in intervals:
            if not res or res[-1].end < i.start:
                res.append(i)
            else:
                res[-1].end = max(res[-1].end, i.end)
        return res
    