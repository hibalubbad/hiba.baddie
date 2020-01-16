import random
import sys
def generate_sequences(n,m):
    l = ['A','C','G','T']
    lst = []
    for i in range(n):
        s = ''
        for j in range(m):
            r = random.randint(0,3)
            s += l[r]
        lst.append(s)
    return lst

def fastlcs(X, Y, memo = {}):
    '''returns a tuple containing the length and the LCS string'''
    m = len(X)
    n = len(Y)
    if (m, n) in memo:
        result = memo[(m, n)]
    elif m == 0 or n == 0:
        result = (0, '')
    elif X[m-1] == Y[n-1]:
        length, seq = fastlcs(X[0:m-1], Y[0:n-1], memo)
        result = (length+1, seq + X[m-1] )
    else:
        lengthWithX, seqX = fastlcs(X, Y[0:n-1], memo)
        lengthWithY, seqY = fastlcs(X[0:m-1], Y, memo)
        if lengthWithX > lengthWithY:
            result = (lengthWithX, seqX)
        else:
            result = (lengthWithY, seqY)
    memo[(m, n)] = result
    return result

n = int(sys.argv[1])
m = int(sys.argv[2])
lst = generate_sequences(n,m)
X,Y = lst[0],lst[1]

print('LCS(',X,',',Y,') = ',fastlcs(X,Y))