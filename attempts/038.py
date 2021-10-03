import sys

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a%b)

def lcm(a, b):
    return a * b // gcd(a, b)

for s in sys.stdin:
    a, b = [int(_s) for _s in s.split()]

    ans = int(lcm(a, b))
    print("Large" if ans > 1000000000000000000 else ans)

