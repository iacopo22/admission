from collections import defaultdict

def groupAnagrams(nums, k):

        res = defaultdict(int)
        output = []

        for num in nums:
            res[num] += 1

        res = sorted(res, key=res.get, reverse = True)

        for i in range(k):
              output.append(res[i])

        print(f"{output}")



nums = [3,2,2,1,1,1]
k = 2
groupAnagrams(nums, k)
