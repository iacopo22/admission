from collections import defaultdict

def groupAnagrams(strs):

        res = defaultdict()
        for s in strs:
            sortedS = ''.join(sorted(s))
            res[sortedS].append(s)

        print(f"{list(res.values())}")
        return list(res.values())



strs = ["eat","tea","tan","ate","nat","bat"]
groupAnagrams(strs)
