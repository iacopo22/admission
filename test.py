from collections import defaultdict

def groupAnagrams(nums, k):

        res = defaultdict(int)
        output = []

        for num in nums:
            res[num] += 1

        print(f"{res}")
        res = sorted(res, key=res.get)
        print(f"{res}")



        print(f"{output}")


nums = [3,2,2,1,1,1]
k = 2
groupAnagrams(nums, k)
