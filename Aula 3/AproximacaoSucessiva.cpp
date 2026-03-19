#include <iostream>
#include <cmath>       // Para std::abs e std::max
#include <functional>  // Para std::function
#include <iomanip> // Para facilitar COUT

double derivada(std::function<double(double)> f, double x, double h = 1e-5) { // Função padrão para encontrar a derivada.
    return (f(x + h) - f(x - h)) / (2 * h);
}

bool verificaPsi(std::function<double(double)> psi, double xInicial){ // Verificando a função perfeita.
    return std::abs(derivada(psi, xInicial)) < 1;
}

void aproximacaoSucessiva(std::function<double(double)> psi, double xInicial, double e, int maxIt){
    double xk = xInicial;
    double xk_1;
    
    for(int k = 1; k < maxIt; k++){ // k = 1 porque pediram.
        xk_1 = psi(xk);

        if((std::abs(xk_1 - xk) / std::max((double) 1, std::abs(xk_1))) < e){ // Preciso avisar que o 1 é double.
            std::cout << "Na iteracao " << k << ", achamos: " << std::fixed << std::setprecision(5) << xk_1 << "\n";
            return;
        }

        xk = xk_1;
    }
}

int main(){
    std::cout << "O codigo seguira o exemplo x²-x-2.";

    int escolha;
    std::function<double(double)> funcaoEscolhida;

    std::cout << "Escolha a funcao, com o x ja isolado, para o metodo:\n";
    std::cout << "1. f(x) = x^2 - 4\n";
    std::cout << "2. f(x) = sin(x) - x/2\n";
    std::cout << "3. f(x) = e^x - 3x\n";
    std::cout << "Digite sua opcao: ";
    std::cin >> escolha;

    switch (escolha) {
        case 1:
            funcaoEscolhida = [](double x) { return std::sqrt(x + 2.0); };
            break;
        case 2:
            funcaoEscolhida = [](double x) { return 2.0 * std::sin(x); };
            break;
        case 3:
            funcaoEscolhida = [](double x) { return std::exp(x) / 3.0; };
            break;
        default:
            std::cout << "Opcao invalida!\n";
            return 1;
    }

    double xInicial, e;
    int maxIteracoes;

    std::cout << "\nDigite o chute inicial (x0): ";
    std::cin >> xInicial;
    std::cout << "Digite a precisao (exemplo: 0.001): ";
    std::cin >> e;
    std::cout << "Digite o maximo de iteracoes permitidas: ";
    std::cin >> maxIteracoes;

    if(verificaPsi(funcaoEscolhida, xInicial)){
        std::cout << "Passou no resultado do modulo.";
        aproximacaoSucessiva(funcaoEscolhida, xInicial, e, maxIteracoes);
    }else{
        std::cout << "Erro. Nao passou no teste do modulo. Escolha outra funcao.\n";
        return -1;
    }

return 0;
}