# Swap function
def swapList(newList):
  size = len(newList)
  
  # Swapping
  temp = newList[0]
  newList[0] = newList[size - 1]
  newList[size - 1] = temp
  return newList

# Driver code
newList = [1, 35, 9, 56, 24]

print(swapList(newList))