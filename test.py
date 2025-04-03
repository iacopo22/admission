from collections import defaultdict
import heapq

def groupAnagrams(nums, k):

    count = {}
    freq = [[] for i in range(len(nums) + 1)]

    print(f"{freq}")

    for num in nums:
        count[num] = 1 + count.get(num, 0)
    for num, cnt in count.items():
        freq[cnt].append(num)
        print(f"{freq}")

    res = []
    for i in range(len(freq) - 1, 0, -1):
        for num in freq[i]:
            res.append(num)
            if len(res) == k:
                return res







nums = [3,2,2,1,1,1]
k = 2
groupAnagrams(nums, k)
