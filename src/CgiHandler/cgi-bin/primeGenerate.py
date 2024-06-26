import itertools
import sys

def iter_primes():
     # an iterator of all numbers between 2 and +infinity
     numbers = itertools.count(2)

     # generate primes forever
     while True:
         # get the first number from the iterator (always a prime)
         prime = next(numbers)
         yield prime

         # this code iteratively builds up a chain of
         # filters...slightly tricky, but ponder it a bit
         numbers = filter(prime.__rmod__, numbers)

# Read from stdin
limit = int(sys.stdin.readline())

for p in iter_primes():
    if p > 100:
        break
    print(p, end='  ')
