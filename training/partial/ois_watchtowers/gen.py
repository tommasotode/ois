import sys, random
sys.stdout = open("input2.txt", "w")
print("10")
print(*(random.randint(1, 5) for _ in range(10)))
