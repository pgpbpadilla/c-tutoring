from math import ceil

MAX_GRADE=8.0
MIN_GRADE=5.0
MAX_PAYMENT=2900.0/3.0

rates = {
    '5': 0.0,
    '6': 0.33,
    '7': 0.66,
    '8': 1.0,
    '9': 1.1,
    '10': 1.25
}

def weighed_payment(grade):
    return MAX_PAYMENT * rates[str(int(ceil(grade)))]
        


import sys

print sys.argv
grades = sys.argv[1:]

payments = [(g, weighed_payment(float(g))) for g in grades]

print(payments)
print('Total: {}'.format(reduce(lambda x, y: x+y, [p[1] for p in payments], 0)))
