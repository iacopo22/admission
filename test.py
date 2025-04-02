def groupAnagrams(strs):
        

        res = defaultdict(list)
        for s in strs:
            sortedS = ''.join(sorted(s))
            res[sortedS].append(s)
        return list(res.values())



strs = ["eat","tea","tan","ate","nat","bat"]
groupAnagrams(strs)
