# Get a true or false value
import sys
a=int(sys.argv[1])
b=int(sys.argv[2])
c=int(sys.argv[3])
inorder= a > b > c or a < b < c
print(inorder)

