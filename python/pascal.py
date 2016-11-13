import sys

f = lambda n: reduce(lambda x, y: x*y, [i for i  in xrange(1, n+1)], 1)
c = lambda n, k: f(n) / ( f(k) * f(n-k) )
p = lambda row, col: c(row, col)
pascal_up_to = lambda n: [ [p(i, j) for j in xrange(i+1)] for i in xrange(n+1) ]

args = sys.argv[1:]
max = 5 if len(args) == 0 else int(args[0])

for l in pascal_up_to(max):
    print l
