from math import sqrt
import sys
a = int(sys.argv[1])
b = int(sys.argv[2])
c = int(sys.argv[3])

d = sqrt(b**2 - 4 * a * c)
print(int((-b+d) / (2*a)))
print(int((-b-d) / (2*a)))
