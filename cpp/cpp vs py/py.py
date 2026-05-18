import time

def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

if __name__ == "__main__":
    n = 1000
    start = time.time()
    result = factorial(n)
    end = time.time()
    print(f"Factorial computed in {end - start:.6f} seconds")