# https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/

def solution(N, P, Q):
    if len(P) == 0:
        return []
    num_divisors = [2] * (N+1)
    num_divisors[0] = num_divisors[1] = 1

    i = 2
    while i * i <= N:
        if num_divisors[i] != 2:
            # not prime
            i += 1
            continue

        k = i * i
        while k <= N:
            num_divisors[k] += num_divisors[i] - 1
            if k // i != i:
                num_divisors[k] += num_divisors[k // i] - 1
            k += i
        i += 1
    
    # print(f"num_divisors: {[x for x in range(N+1)]}")
    # print(f"num_divisors: {num_divisors}")

    semi_primes = [0] * (N+1)
    for j in range(1, len(num_divisors)):
        semi_primes[j] = semi_primes[j - 1]
        if num_divisors[j] == 3 or num_divisors[j] == 4:
            semi_primes[j] += 1

    # print(f"semi_primes:  {semi_primes}")
    resp = [0] * len(P)
    for j in range(len(P)):
        # print(f"p: {P[j]}, q: {Q[j]}")
        resp[j] = semi_primes[Q[j]] - semi_primes[P[j] - 1]

    return resp
