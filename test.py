def groupAnagrams(strs):

        dictionary = {}

        for word in strs:
            string = {}
            for char in word:
                string[char] = 1 + string.get(char, 0)

            ##  Hashable type
            freq = tuple(sorted(string.items()))

            if freq not in dictionary:
                 dictionary[freq] = [word]
            else:
                 dictionary[freq].append(word)

        print(f"{list(dictionary.values())}")
        return list(dictionary.values())



strs = ["eat","tea","tan","ate","nat","bat"]
groupAnagrams(strs)
