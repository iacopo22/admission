from collections import defaultdict

def groupAnagrams(nums, k):

        res = {}
        output = []

        for num in nums:
            res[num] = 1 + res.get(res[num], 0)

        tuple(sort(res.values()))

        for i in range(k):
            output.append(res.keys())



nums = [1,1,1,2,2,3]
k = 2
groupAnagrams(nums, k)
