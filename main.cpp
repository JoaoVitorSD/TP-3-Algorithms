#include <iostream>
#define INF 0x3f3f3f3f

// Para debudar os valores de OPT:
#define DEBUG_MODE false


class Ligas{

public:
    int * list;
    int size;
    Ligas(int size){
        this->list = new int[size];
        this->size = size;
    }
    void readEntries(){
        for(int i=0;i<size;i++){
            std::cin>>list[i];
        }
    }
    int minimium(int demand)
    {
        if (demand == 0)
        {
            return 0;
        }
        int *opt = new int[demand + 1];
        opt[0] = 0;

        for (int i = 1; i <= demand; i++)
        {
            int minimumOpt = INF;
            /* Para cada liga possível, eu vejo qual é a menor combinação possível partindo dos resultados anteriores
            Para a demanda 40, o opt[40] = opt[40-20]+1. Porque com a liga de 20, percebe-se que é a combinação dela 1 vez com opt[20] que a usa uma vez.
            */
            for (int j = 0; j < this->size; j++)
            {
                // Se a liga for maior que o iterador, não faz sentido rodar a iteração, pois não cabe tentar uma liga de 20 para uma demanda de 10, por exemplo
                int liga = this->list[j];
                if (liga > i)
                {
                    continue;
                }
                if (opt[i - liga] != INF)
                {
                    // Testa qual combinação de liga é menor para todas as ligas possíveis
                    bool ligaIsLower = (1 + opt[i - liga]) < minimumOpt;
                    // Se a combinação com a liga j for a menor combinação testada, é considerado que a liga será utilizada na combinação
                    minimumOpt = ligaIsLower ? 1 + opt[i - liga] : minimumOpt;
                }
            }
            if (minimumOpt != INF)
            {
                opt[i] = minimumOpt;
            }
        }
        // Apenas para análise
        if (DEBUG_MODE)
        {
            printOptTable(opt, demand + 1);
        }
        return opt[demand];

    }

    void printOptTable(int opt[], int size)
    {
        for (int i = 1; i < size; i++)
        {
            std::cout << opt[i] << " ";
        }
        return;
    }
};





int main(int argc, char const *argv[]) {

    int qtdTestes, ligasAmount, demand;
    std::cin>> qtdTestes;

    for (int i = 0; i < qtdTestes; i++)
    {
        // Lendo as entradas do teste i
        std::cin>> ligasAmount >>  demand;
        Ligas * ligas =  new Ligas(ligasAmount);
        ligas->readEntries();
        std::cout << ligas->minimium(demand)<<std::endl;
        // Desaloca o array de liga
        delete ligas;
    }
        return 0;
    }
