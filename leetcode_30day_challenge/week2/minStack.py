class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.arr = []

    def push(self, x: int) -> None:
        if(len(self.arr) == 0):
            self.arr.append((x, x))
        else:
            minEle = min(x, self.getMin())
            self.arr.append((x, minEle))

    def pop(self) -> None:
        if(len(self.arr) == 0):
            return  # not given in the question what to do with this case
        self.arr.pop()

    def top(self) -> int:
        if(len(self.arr) == 0):
            return -1  # not given in the question what to do with this case
        return self.arr[-1][0]

    def getMin(self) -> int:
        if(len(self.arr) == 0):
            return -1  # not given in the question what to do with this case
        return self.arr[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
