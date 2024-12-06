import sys
sys.stdout = open("parkour.input2.txt", "w")

print("100000")
for i in range(100000, 0, -1):
  print(f"0 1 {i}")
