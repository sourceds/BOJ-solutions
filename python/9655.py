import sys
n = int(sys.stdin.readline())
ans = n // 3 + n % 3
if ans % 2 == 0:
    print('CY')
else:
    print('SK')
