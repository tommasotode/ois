import random

r = sorted(random.randint(1, 1000000000) for _ in range(4997))

with open("input3.txt", "w") as i:
  print("5000", file=i)
  print("1 1000000000 1 ", end="", file=i)
  print(*r, file=i)

with open("output3.txt", "w") as o:
  print("1999999998 0 1999999998 ", end="", file=o)
  for i, h in enumerate(r):
    print(f"{2999999998 + 999999999 * i - h} ", end="", file=o)
  print(file=o)
