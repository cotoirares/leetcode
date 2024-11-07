class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(intervals)
        intervals.sort()
        result = []
        for i in range(n):
            start = intervals[i][0]
            end = intervals[i][1]
            if result and result[-1][1] >= end:
                continue
            for j in range(i + 1, n):
                if intervals[j][0] <= end:
                    end = max(end, intervals[j][1])
            result.append([start, end])
        return result

