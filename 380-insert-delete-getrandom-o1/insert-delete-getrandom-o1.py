class RandomizedSet(object):
    setDict = None
    def __init__(self):
        self.setDict = {}

    def insert(self, val):
        if self.setDict.get(val):
            return False
        self.setDict[val] = 1
        return True      

    def remove(self, val):
        if self.setDict.get(val):
            self.setDict.pop(val)
            return True
        return False

    def getRandom(self):
        return random.choice(self.setDict.keys())
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()