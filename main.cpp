#include <iostream>
#define INF 0x3f3f3f3f


int sumMinimium(const int *ligas, int size,  int demand )
{
    if(demand == 0){return 0;}
    int * opt = new int[demand+1];
    opt[0] = 0;

    for (int i = ligas[0]; i <= demand; i++)
    {
        int minimumOpt = INF;
        for (int j = 0; j < size; j++)
        {
            if(ligas[j]>i){continue;}
            if (opt[i - ligas[j]] != INF)
            {
                //Testa qual combinação de liga é menor para todas as ligas possíveis
               minimumOpt = minimumOpt < (1 + opt[i - ligas[j]]) ? minimumOpt : 1 + opt[i - ligas[j]];
            }
        }
        if(minimumOpt!=INF){
            opt[i] = minimumOpt;
        }
    }

    return opt[demand];
}
int main(int argc, char const *argv[]) {

    int qtdTestes, ligasAmount, demand;
    std::cin>> qtdTestes;

    for (int i = 0; i < qtdTestes; i++)
    {
        // Lendo as entradas do teste i
        std::cin>> ligasAmount >>  demand;
        int *ligas = new int[ligasAmount];
        for (int j = 0; j < ligasAmount; j++)
        {
            std::cin >> ligas[j];
        }
        std::cout << sumMinimium(ligas, ligasAmount ,demand)<<std::endl;
        // Desaloca o array de liga
        delete ligas;
    }
        return 0;
    }
