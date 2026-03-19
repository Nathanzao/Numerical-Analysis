#include <iostream>
#include <vector>

using Matriz = std::vector<std::vector<double>>;
using Vetor = std::vector<double>;

Vetor eliminacaoDeGauss(Matriz A, Vetor b) {
    int n = A.size();

    // Eliminando os valores abaixo.
    for (int k = 0; k < n - 1; k++) { // Só vai até a linha 2. Se fosse para a linha 3, iria olhar para uma linha onde não tem. 
        for (int i = k + 1; i < n; i++) {
            
            double m = A[i][k] / A[k][k]; // Multiplicador da primeira linha.
            
            // Vai deixando os zeros e substituindo.
            for (int j = k; j < n; j++) {
                A[i][j] = A[i][j] - m * A[k][j];
            }
            
            // Atualiza o vetor b
            b[i] = b[i] - m * b[k];
        }
    }

    Vetor x(n, 0.0); // x = [0, 0, 0];
    
    for (int i = n - 1; i >= 0; i--) { // começa do último para o X vir sendo preenchido pelo que tem menor variável.
        double soma = 0.0;
        for (int j = i + 1; j < n; j++) {
            soma += A[i][j] * x[j];
        }
        x[i] = (b[i] - soma) / A[i][i];
    }

    return x;
}

int main() {
    Matriz A = { // do exemplo.
        {4.0, 12.0, -16.0},
        {12.0, 37.0,  -43.0},
        {-16.0, -43.0,  98.0}
    };

    Vetor b = {1.0, 2.0, 3.0};

    Vetor x = eliminacaoDeGauss(A, b);

    std::cout << "Vetor solucao x:\n[ ";
    for (double valor : x) {
        std::cout << valor << " ";
    }
    std::cout << "]\n";

    return 0;
}