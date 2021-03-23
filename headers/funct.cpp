#include <iostream>

void debug_vec(int *vector, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

//Retorna o custo da viagem a partir de uma escala.
int calcula_custo(int escala, int qntdEscalas, int qntdMaxDescontos, int maxTempo, int *descontoArray, int *timeArray, int *priceArray)
{
    int posFinalArray = qntdEscalas - 1;

    //Quanddo tem apenas uma escala
    if(escala == posFinalArray)
    {   
        return priceArray[escala]; //Array de preços minimo é igual ao preço da escala;
    }
    else
    {
        int tempoAcumulado = 0; int precoAcumulado = 0; int caminhamento = 0;

        for (int i = escala; i <= posFinalArray; i++)
        {
            if(tempoAcumulado >= maxTempo || caminhamento == qntdMaxDescontos-1)
            {   
 
                caminhamento = 1;
                tempoAcumulado = 0;
                precoAcumulado += priceArray[i];
                
            }
            else
            {
                precoAcumulado += priceArray[i] * (100-descontoArray[caminhamento])/100;
                tempoAcumulado += timeArray[i];
                caminhamento++;
                
            }

        }
        return precoAcumulado;
        
    }

}

void dynamic_minimal_cost(int qntdEscalas, int qntdMaxDescontos, int maxTempo, int *descontoArray, int *timeArray, int *priceArray)
{
    
    //int *custosArray = new int[qntdEscalas];

    int posFinalArray = qntdEscalas - 1; //Indice final do array de escalas
    
    for (int i = posFinalArray; i >= 0; i--)
    {
        int newCusto = calcula_custo(i ,qntdEscalas, qntdMaxDescontos, maxTempo, descontoArray, timeArray, priceArray);
        std::cout << newCusto << " ";
    }
}