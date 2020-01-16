import random

n = int(input())
count = 0
for i in range(n):
    x = random.uniform(0,1)
    y = random.uniform(0,1)
    if x**2 + y**2 <= 1:
       count +=1
pi = (count/ n )*4        
print(pi)
        
# as the value of n increases the value of pi becomes more accurate
