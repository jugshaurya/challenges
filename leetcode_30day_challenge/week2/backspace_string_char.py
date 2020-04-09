class Solution:
    def isEmpty(self, st):
        return len(st) == 0

    def backspaceCompare(self, S: str, T: str) -> bool:
        stackS = []
        for ele in S:
            if(ele == "#"):
                if(not self.isEmpty(stackS)):
                    stackS.pop()
            else:
                stackS.append(ele)

        stackT = []
        for ele in T:
            if(ele == "#"):
                if(not self.isEmpty(stackT)):
                    stackT.pop()
            else:
                stackT.append(ele)

        return "".join(stackS) == "".join(stackT)
