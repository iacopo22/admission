from collections import defaultdict
import heapq

def groupAnagrams(nums, k):

        count = {}
        for num in nums:
            count[num] = 1 + count.get(num, 0)

        print(f"{count}")

        heap = []
        for num in count.keys():
            heapq.heappush(heap, (count[num], num))
            print(f"Heap1: {heap}")
            if len(heap) > k:
                heapq.heappop(heap)
                print(f"Heap2: {heap}")


        res = []
        for i in range(k):
            res.append(heapq.heappop(heap)[1])

        print(f"res: {res}")
        return res



nums = [3,2,2,1,1,1]
k = 2
groupAnagrams(nums, k)
