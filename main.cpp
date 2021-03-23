#include <iostream>
#include "headers/funct.cpp"

using namespace std;


int main(){

    int qntdEscalas, qntdMaxDescontos, maxTempo;

    cin >> qntdEscalas >> qntdMaxDescontos >> maxTempo; //Leitura da primeira linha de entrada do problema

    int *descontoArray = new int[qntdMaxDescontos]; //Vetor com os descontos cumulativos
    int *timeArray = new int[qntdEscalas]; int *priceArray = new int[qntdEscalas]; //Vetorres com o tempo e o preço das escalas.

    //Inicializando os vetores de desconto, e escalas com os valores digitados.
    for (int i = 0; i < qntdMaxDescontos; i++)
    {
        cin >> descontoArray[i];
    }
    for (int i = 0; i < qntdEscalas; i++)
    {
        cin >> timeArray[i] >> priceArray[i];
    }
    
    //Transformando array em descontos cumulativos
    for (int i = 1; i < qntdMaxDescontos; i++)
    {
        descontoArray[i] = descontoArray[i] + descontoArray[i-1];
    }
    
    dynamic_minimal_cost(qntdEscalas, qntdMaxDescontos, maxTempo, descontoArray, timeArray, priceArray);

}