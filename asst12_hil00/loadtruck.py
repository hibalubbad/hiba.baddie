

class Item:
    def __init__(self,typ,value,volume):
        self.tp = typ
        self.value = value
        self.volume = volume
    def __str__(self):
        s = self.tp +': '+ str(self.value)+'$'+str(self.volume)+' m^3'
        return s
    def getValue(self):
        return self.value
    def getVolume(self):
        return self.volume

class Truck:
    def __init__(self,i,maxvol):
        self.id = i
        self.volume = maxvol
        self.items = None
    def __str__(self):
        s = self.id + ': '+str(self.volume)+'m^3'
        return s
    def loadbf(items):
        def chooseBest(pset, maxVolume, getVal, getVolume):
        bestVal = 0
        bestSet = None
        for items in pset:
            itemsVal = 0
            itemsVolume = 0
            for item in items:
                itemsVal += getVal(item)
                itemsVolume += getVolume(item)
            if itemsVolume <= maxVolume and itemsVal > bestVal:
                bestVal = itemsVal
                bestSet = items
        return (bestSet, bestVal)

    def loaddp(toConsider, avail, memo = {}):
        if (len(toConsider), avail) in memo:
            result = memo[(len(toConsider), avail)]
        elif toConsider == [] or avail == 0:
            result = (0, ())
        elif toConsider[0].getWeight() > avail:
            result = fastMaxVal(toConsider[1:], avail, memo)
        else:
            nextItem = toConsider[0]
            withVal, withToTake = fastMaxVal(toConsider[1:], avail - nextItem.getWeight(), memo)
            withVal += nextItem.getValue()
            withoutVal, withoutToTake = fastMaxVal(toConsider[1:], avail, memo)
            if withVal > withoutVal:
                result = (withVal, withToTake + (nextItem,))
            else:
                result = (withoutVal, withoutToTake)
        memo[(len(toConsider), avail)] = result
        return result

    def loadgreedy(items, maxVolume, keyFunction):
        itemsCopy = sorted(items, key=keyFunction, reverse = True)
        result = []
        totalValue = 0.0
        totalWeight = 0.0
        for i in range(len(itemsCopy)):
            if (totalWeight + itemsCopy[i].getWeight()) <= maxVolume:
                result.append(itemsCopy[i])
                totalWeight += itemsCopy[i].getWeight()
                totalValue += itemsCopy[i].getValue()
        return (result, totalValue)
