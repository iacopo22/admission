from collections import defaultdict

def groupAnagrams(nums, k):

        res = defaultdict(int)
        output = []

        for num in nums:
            res[num] += 1

        print(f"{output}")

        sorted(res, key=res.get)

        for i in range(k):
            output.append(res.keys())

        print(f"{output}")



nums = [1,1,1,2,2,3]
k = 2
groupAnagrams(nums, k)
