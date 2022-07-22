def test(inputs, truth, func, verbose = True):
    for i in range(len(inputs)):
        output = func(inputs[i])
        if truth[i] != output:
            if verbose:
                print(f"Test {i + 1}:\nExp:\t{str(truth[i])}\nGot:\t{str(output)}")
        else:
            if verbose:
                print(f"Test {i + 1} is correct")

class Solution:
    def get_reverse(self, val : str) -> str:
        return val[::-1]

    def longestPalindrome(self, words: list[str]) -> int:
        count_pairs = {}
        for word in words:
            if word not in count_pairs:
                count_pairs[word] = 1
            else:
                count_pairs[word] += 1
        res = 0
        for pair in count_pairs:
            count = count_pairs[pair]
            reversed_pair = self.get_reverse(pair)
            if reversed_pair not in count_pairs:
                continue

            count_inversed = count_pairs[reversed_pair]

            count_using = 0
            if pair[0] == pair[1]:
                count_using = count // 2
            else:
                count_using = min(count, count_inversed)

            res += count_using * 4
            count_pairs[pair] -= count_using
            count_pairs[self.get_reverse(pair)] -= count_using
        
        if res % 2 == 0:
            for pair in count_pairs:
                count = count_pairs[pair]
                if count > 0:
                    if pair[0] == pair[1]:
                        res += 2
                        break

        return res



inputs = [["lc","cl","gg"], ["ab","ty","yt","lc","cl","ab"], ["cc","ll","xx"], ["cc","ll","xx", "ll"], ["ab","ty","yt","lc","cl","ab","ba"]]
outputs = [6, 8, 2, 6, 12]
test(inputs, outputs, Solution().longestPalindrome)