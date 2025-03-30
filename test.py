
def twoSum(nums, target):

    dictionary = {}

        for i, n in enumerate(nums):
            dictionary[n] = i

        for n in dictionary:
            diff = target - n
            if diff in dictionary and dictionary[diff] != i:
                return [i, dictionary[diff]]




twoSum([3,3], 6)

