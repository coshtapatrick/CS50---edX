from cs50 import get_int

h = -1

while h<1 or h>8:
    h = get_int("Height: ")
for i in range(h):
    n = i + 1
    print(' ' * (h - n), end="")
    print('#'* n)
