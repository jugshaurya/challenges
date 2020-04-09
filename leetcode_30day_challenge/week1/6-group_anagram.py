class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for ele in strs:
            l = "".join(sorted(ele))
            if(l in d):
                d[l].append(ele)
            else:
                d[l] = [ele]
                
        return list(d.values())
        
        