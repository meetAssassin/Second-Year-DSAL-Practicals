class Set:
    def __init__(self, numOfElements):
        self.s = []
        for i in range(numOfElements):
            element = int(input(f"Enter {i + 1} element: "))
            self.add(element)

    # def getSet(self):
    #     return self.s
    
    def add(self, element):
        if element not in self.s:
            self.s.append(element)

    def remove(self, element):
        if element in self.s:
            self.s.remove(element)
        
    def length(self):
        return len(self.s)
    
    def union(self, setB):
        newSet = self
        for element in setB:
            if element not in self.s:
                newSet.add(element)
        return newSet
    
    def intersection(self, setB):
        newSet = Set(0)
        for i in range (len(self.s)):
            for j in range(len(setB.s)):
                if self.s[i] == setB.s[j]:
                    newSet.add(self.s[i])
        return newSet
    
    def difference(self,setB):
        newSet = Set(0)
        for element in self.s:
            if element not in setB:
                newSet.add(element)
        return newSet
    
    def __iter__(self):
        return iter(self.s)
    
# Create Set Function

def createSet():
    n = int(input("Enter number of elements in Set: "))
    s = Set(n)
    return s

# Driver Code
print("Create Set A")
s1 = createSet()
print(s1.s)
ans = True

while(ans):
    print("\nMENU\n")
    print("1. Add")
    print("2. Remove")
    print("3. Size")
    print("4. Union")
    print("5. Intersection")

    choice = int(input("Enter choice: "))
    match choice:
        case 1:
            element = int(input("Enter number to add: "))
            s1.add(element)
            print(s1.s)
        case 2:
            element = int(input("Enter number to remove: "))
            s1.remove(element)
            print(s1.s)
        case 3:
            print(f"Length of set is: {s1.length()}")
        case 4:
            print("Create new set for Union")
            s2 = createSet()
            s3 = s1.union(s2)
            print(s3.s)
        case 5:
            print("Create new set for Intersection")
            s2 = createSet()
            s3 = s1.intersection(s2)
            print(s3.s)
        
        

# # s1.add(5)
# # print(s1.s)
# # print(f"Length of set is: {s1.length()}")

# # s1.remove(5)
# # print(s1.s)



# s2 = createSet()
# print(s2.s)

# # s3 = s1.union(s2)
# # print(s3.s)

# # s3 = s1.intersection(s2)
# # print(s3.s)

# s3 = s1.difference(s2)
# print(s3.s)