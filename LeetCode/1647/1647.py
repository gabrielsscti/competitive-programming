from LeetCode.test_framework import test


class Solution:
    def minDeletions(self, s: str) -> int:
        letter_map = {}
        for letter in s:
            if letter not in letter_map:
                letter_map[letter] = 1
            else:
                letter_map[letter] += 1
        frequencies = list(letter_map.values())
        frequencies_set = set(frequencies)

        not_used_frequencies = []

        for i in range(max(frequencies), 0, -1):
            if i not in frequencies_set:
                not_used_frequencies.append(i)

        frequencies_count = {}
        for frequency in frequencies:
            if frequency not in frequencies_count:
                frequencies_count[frequency] = 1
            else:
                frequencies_count[frequency] += 1

        sorted_frequencies = frequencies
        sorted_frequencies.sort(reverse=True)

        resp = 0
        not_used_frequencies_count = 0

        for freq in sorted_frequencies:
            if frequencies_count[freq] == 1:
                continue
            if not_used_frequencies_count == len(not_used_frequencies):
                resp += freq
            for i in range(not_used_frequencies_count, len(not_used_frequencies)):
                not_used_frequencies_count += 1
                if not_used_frequencies[i] < freq:
                    resp += freq - not_used_frequencies[i]
                    break
                if not_used_frequencies_count == len(not_used_frequencies):
                    resp += freq
            frequencies_count[freq] -= 1
        return resp



inputs = ["aab", "aaabbbcc", "ceabaacb", "aabbcccccdddeefffff", "bbcebab"]
truth = [0, 2, 2, 4, 2]
_ = Solution()
test(inputs, truth, _.minDeletions, True)
