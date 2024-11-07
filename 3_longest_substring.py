class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        if len(s) == 1:
            return 1
        used_char = []
        current_substring = ""
        max_substring = ""
        for i in range(len(s)):
            if s[i] not in used_char:
                current_substring += s[i]
                used_char.append(s[i])
            else:
                if len(current_substring) > len(max_substring):
                    max_substring = current_substring
                current_substring = current_substring[current_substring.index(s[i])+1:] + s[i]
                used_char = list(current_substring)
        if len(current_substring) > len(max_substring):
            max_substring = current_substring
        return len(max_substring)
        
