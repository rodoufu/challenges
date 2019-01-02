package codility.com.lessons.l90prime2016challenge;

public class DwarfsRafting {
	public int solution(int N, String S, String T) {
		final Quadrante jangada[][] = new Quadrante[2][];
		jangada[0] = new Quadrante[2];
		jangada[1] = new Quadrante[2];

		for (int i = 0; i < jangada.length; i++) {
			for (int j = 0; j < jangada[i].length; j++) {
				jangada[i][j] = new Quadrante();
				jangada[i][j].disponiveis = N * N / 4;
				jangada[i][j].anoes = 0;
			}
		}

		int dist = 0;

		for (String pos : S.split(" ")) {
			if (pos.trim().length() == 0) {
				break;
			}
			jangada[getLinha(pos, N)][getColuna(pos, N)].disponiveis--;
		}
		for (String pos : T.split(" ")) {
			if (pos.trim().length() == 0) {
				break;
			}
			jangada[getLinha(pos, N)][getColuna(pos, N)].disponiveis--;
			jangada[getLinha(pos, N)][getColuna(pos, N)].anoes++;
		}

		// Balancear
		// Vertical
		if (jangada[0][0].anoes + jangada[0][1].anoes != jangada[1][0].anoes
				+ jangada[1][1].anoes) {
			int diferenca = (jangada[0][0].anoes + jangada[0][1].anoes)
					- (jangada[1][0].anoes + jangada[1][1].anoes);
			if (diferenca > 0) {
				if (jangada[1][0].disponiveis + jangada[1][1].disponiveis > diferenca) {
					return -1;
				}
			} else {
				diferenca *= -1;
				if (jangada[0][0].disponiveis + jangada[0][1].disponiveis > diferenca) {
					return -1;
				}
			}
		}
		// Horizontal
		if (jangada[0][0].anoes + jangada[1][0].anoes != jangada[0][1].anoes
				+ jangada[1][1].anoes) {
			int diferenca = (jangada[0][0].anoes + jangada[1][0].anoes)
					- (jangada[0][1].anoes + jangada[1][1].anoes);
			if (diferenca > 0) {
				if (jangada[0][1].disponiveis + jangada[1][1].disponiveis > diferenca) {
					return -1;
				}
			} else {
				diferenca *= -1;
				if (jangada[0][0].disponiveis + jangada[1][0].disponiveis > diferenca) {
					return -1;
				}
			}
		}

		return dist;
	}

	private int getLinha(String linha, int N) {
		return linha.charAt(0) - '0' - 1 < N / 2 ? 0 : 1;
	}

	private int getColuna(String coluna, int N) {
		return coluna.charAt(0) - 'A' < N / 2 ? 0 : 1;
	}

	private static class Quadrante {
		public int disponiveis;
		public int anoes;
	}
	
	private static class Jangada {
		public final Quadrante quadrante[][] = new Quadrante[2][];
		public Jangada(int N) {
			quadrante[0] = new Quadrante[2];
			quadrante[1] = new Quadrante[2];

			for (int i = 0; i < quadrante.length; i++) {
				for (int j = 0; j < quadrante[i].length; j++) {
					quadrante[i][j] = new Quadrante();
					quadrante[i][j].disponiveis = N * N / 4;
					quadrante[i][j].anoes = 0;
				}
			}
		}
	}
}
