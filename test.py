
def twoSum(nums, target):

      dictionary = {}

      for i, n in enumerate(nums):
            dictionary[n] = i

      for n in enumerate(nums):
            print(f"{n}")
            diff = target - n
            if diff in dictionary and dictionary[diff] != i:
                return [i, dictionary[diff]]




twoSum([2,7,11,15], 9)

