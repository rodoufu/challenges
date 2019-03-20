package codility.com.lessons.l12euclideanalgorithm;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * 100 + 33 = 69 
 * https://app.codility.com/programmers/lessons/12-euclidean_algorithm/common_prime_divisors/
 */
public class CommonPrimeDivisors {
	private static Map<Long, Boolean> primeCache = new HashMap<>();
	private static Map<Long, Set<Long>> divisoresCache = new HashMap<>();
	private static Map<Long, Set<Long>> primeDivisorsCache = new HashMap<>();
	
	public int solution(int[] A, int[] B) {
		int cont = 0;
		for (int i = 0; i < A.length; i++) {
			final long aMdcB = mdc(A[i], B[i]);
			Set<Long> divisoresA = divisores(A[i]);
			Set<Long> divisoresB = divisores(B[i]);
			{
				Set<Long> divisoresMdc = divisores(aMdcB);
				Set<Long> copDivisoresA = new HashSet<>();
				copDivisoresA.addAll(divisoresA);
				divisoresA.removeAll(divisoresB);
				divisoresA.removeAll(divisoresMdc);
				divisoresB.removeAll(copDivisoresA);
				divisoresB.removeAll(divisoresMdc);
			}
			divisoresA.removeIf(x -> !isPrime(x));
			divisoresB.removeIf(x -> !isPrime(x));
			
			if (divisoresA.isEmpty() && divisoresB.isEmpty()) {
				cont++;
			}
		}
		return cont;
    }
	
	public long mdc(long a, long b) {
		if (a % b == 0) {
			return b;
		} else {
			return mdc(b, a % b);
		}
	}
	
	public Set<Long> primeDivisors(long N) {
		if (primeDivisorsCache.containsKey(N)) {
			HashSet<Long> resposta = new HashSet<>();
			resposta.addAll(primeDivisorsCache.get(N));
			return resposta;
		}
		final long sqrtN = (long) Math.sqrt(N);
		Set<Long> resposta = new HashSet<>();
		for (long i = 1; i <= sqrtN && N > 1; i++) {
			if (N % i == 0 && (i == 1 || isPrime(i))) {
				resposta.add(i);
				long nDivI = N / i;
				if (isPrime(nDivI)) {
					resposta.add(nDivI);
				}
				N = nDivI;
			}
		}
		primeDivisorsCache.put(N, resposta);
		{
			HashSet<Long> resposta2 = new HashSet<>();
			resposta2.addAll(resposta);
			return resposta2;
		}
	}

	public Set<Long> divisores(long N) {
		if (divisoresCache.containsKey(N)) {
			HashSet<Long> resposta = new HashSet<>();
			resposta.addAll(divisoresCache.get(N));
			return resposta;
		}
		final long sqrtN = (long) Math.sqrt(N);
		Set<Long> resposta = new HashSet<>();
		for (long i = 1; i <= sqrtN; i++) {
			if (N % i == 0) {
				resposta.add(i);
				resposta.add(N / i);
			}
		}
		divisoresCache.put(N, resposta);
		{
			HashSet<Long> resposta2 = new HashSet<>();
			resposta2.addAll(resposta);
			return resposta2;
		}
	}
	
	public boolean isPrime(long N) {
		if (primeCache.containsKey(N)) {
			return primeCache.get(N);
		}
		final long sqrtN = (long) Math.sqrt(N);
		int contar = 0;
		for (long i = 1; i <= sqrtN && contar <= 2; i++) {
			if (N % i == 0) {
				contar += i != (N / i) ? 2 : 1; 
			}
		}
		primeCache.put(new Long(N), new Boolean(contar == 2));
		return contar == 2;
	}
}
