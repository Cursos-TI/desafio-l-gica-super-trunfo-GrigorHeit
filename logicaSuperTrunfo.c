#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Estrutura da Carta
typedef struct {
    char Estado;
    char Codigo[4];
    char Cidade[41];
    unsigned long int Populacao;
    float Area;
    float PIB;
    int NPontosTuristicos;
    float DensidadePopulacional;
    float PIBperCapita;
    float SuperPoder;
}Carta;

void ExibirCartas(Carta *cartas, int numCartas);

// inicializar a Carta sem Lixo nas Variáveis
Carta InitializeCarta(){
    Carta carta;

    carta.Estado = '\0';
    strcpy(carta.Codigo, "");
    strcpy(carta.Cidade, "");
    carta.Populacao = 0;
    carta.Area = 0.0;
    carta.PIB = 0.0;
    carta.NPontosTuristicos = 0;
    carta.DensidadePopulacional = 0.0;
    carta.PIBperCapita = 0.0;

    return carta;
}

// Funções para Setar as Variáveis da Carta
Carta SetEstado(Carta carta){
    char estado;
    printf("\nDigite o Estado (Uma Letra de A a H): ");
    fflush(stdin);
    scanf(" %c", &estado);
    carta.Estado = estado;
    return carta;
}

Carta SetCodigo(Carta carta){
    char codigo[4];
    printf("\nDigite o Código: ");
    fflush(stdin);
    scanf(" %3s", codigo);
    strcpy(carta.Codigo, codigo);
    return carta;
}

Carta SetCidade(Carta carta){
    char cidade[41];
    printf("\nDigite a Cidade: ");
    fflush(stdin);
    scanf(" %[^\n]", cidade);
    strcpy(carta.Cidade, cidade);
    return carta;
}

Carta SetPopulacao(Carta carta){
    int populacao;
    printf("\nDigite a População: ");
    fflush(stdin);
    scanf("%i", &populacao);
    carta.Populacao = populacao;
    return carta;
}

Carta SetArea(Carta carta){
    float area;
    printf("\nDigite a Área em KM² (Ponto Flutuante Separado por Vírgula): ");
    scanf("%f", &area);
    fflush(stdin);
    carta.Area = area;
    return carta;
}

Carta SetPIB(Carta carta){
    float PIB;
    printf("\nDigite o PIB em Bilhões de Reais (Ponto Flutuante Separado por Vírgula): ");
    scanf("%f", &PIB);
    fflush(stdin);
    carta.PIB = PIB;
    return carta;
}

Carta SetNPontosTuristicos(Carta carta){
    int npontos;
    printf("\nDigite o Número de Pontos Turísticos: ");
    scanf("%i", &npontos);
    fflush(stdin);
    carta.NPontosTuristicos = npontos;
    return carta;
}

Carta SetDensidadePopulacional(Carta carta){
    carta.DensidadePopulacional = (float) carta.Populacao / carta.Area;
    return carta;
}

Carta SetPIBperCapita(Carta carta){
    carta.PIBperCapita = (carta.PIB * (float) 1000000000) / (float) carta.Populacao;
    return carta;
}

Carta SetSuperPoder(Carta carta){
    carta.SuperPoder = 1.0 / (float) carta.Populacao + carta.Area + carta.PIB + (float) carta.NPontosTuristicos + carta.DensidadePopulacional + carta.PIBperCapita;
    return carta;
}

// Função Geral para Setar Todas as Variáveis da Carta
Carta SetCardValues(Carta carta){
    // Set Estado
    carta = SetEstado(carta);
    // Set Código
    carta = SetCodigo(carta);
    // Set Cidade
    carta = SetCidade(carta);
    // Set População
    carta = SetPopulacao(carta);
    // Set Area
    carta = SetArea(carta);
    // Set PIB
    carta = SetPIB(carta);
    // Set Número de Pontos Turísticos
    carta = SetNPontosTuristicos(carta);
    // Cálculo da Densidade Populacional
    carta = SetDensidadePopulacional(carta);
    // Cálculo do PIP per Capita
    carta = SetPIBperCapita(carta);
    // Cálculo do Super Poder
    carta = SetSuperPoder(carta);

    return carta;
}

// Print dos Valores da Carta
int PrintCardValues(Carta carta){
    printf("\n===================");
    printf("\nEstado: %c", carta.Estado);
    printf("\nCodigo: %s", carta.Codigo);
    printf("\nCidade: %s", carta.Cidade);
    printf("\nPopulação: %i", carta.Populacao);
    printf("\nArea: %.2f km²", carta.Area);
    printf("\nPIB: %.2f Bilhões de reais", carta.PIB);
    printf("\nNumero de Pontos Turísticos: %i", carta.NPontosTuristicos);
    printf("\nDensidade Populacional: %.2f hab/km²", carta.DensidadePopulacional);
    printf("\nPIB per Capita: %.2f reais", carta.PIBperCapita);
    printf("\nSuper Poder: %.2f", carta.SuperPoder);
    printf("\n===================");
    return 0;
}

// Funções de comparação retornam 1 se a primeira carta tiver o valor maior, 2 se a segunda tiver o valor maior e 0 se for igual

int CompararPopulacao(Carta carta1, Carta carta2){
    if (carta1.Populacao > carta2.Populacao){
        return 1;
    } else if (carta1.Populacao < carta2.Populacao){
        return 2;
    }
    return 0;
}

int CompararArea(Carta carta1, Carta carta2){
    if (carta1.Area > carta2.Area){
        return 1;
    } else if (carta1.Area < carta2.Area){
        return 2;
    }
    return 0;
}

int CompararPIB(Carta carta1, Carta carta2){
    if (carta1.PIB > carta2.PIB){
        return 1;
    } else if (carta1.PIB < carta2.PIB){
        return 2;
    }    
    return 0;
}

int CompararNumeroDePontosTuristicos(Carta carta1, Carta carta2){
    if (carta1.NPontosTuristicos > carta2.NPontosTuristicos){
        return 1;
    } else if (carta1.NPontosTuristicos < carta2.NPontosTuristicos){
        return 2;
    }    
    return 0;
}

int CompararDensidadePopulacional(Carta carta1, Carta carta2){
    if (carta1.DensidadePopulacional < carta2.DensidadePopulacional){
        return 1;
    } else if (carta1.DensidadePopulacional > carta2.DensidadePopulacional){
        return 2;
    }    
    return 0;
}

int CompararPIBPerCapita(Carta carta1, Carta carta2){
    if (carta1.PIBperCapita > carta2.PIBperCapita){
        return 1;
    } else if (carta1.PIBperCapita < carta2.PIBperCapita){
        return 2;
    }    
    return 0;
}

int CompararSuperPoder(Carta carta1, Carta carta2){
    if (carta1.SuperPoder > carta2.SuperPoder){
        return 1;
    } else if (carta1.SuperPoder < carta2.SuperPoder){
        return 2;
    }    
    return 0;
}

void ExibirResultados(Carta carta1, Carta carta2, int var, int resultado){
    // var -> 1 = População, 2 = Área, 3 = PIB, 4 = Número de Pontos Turísticos, 5 = Densidade Demográfica, 6 = PIB per Capita, 7 = Super Poder
    printf("\n======================================");
    if (var == 1){
        printf("\nAtributo Comparado: População");
        printf("\n\t%s\t\t%s", carta1.Cidade, carta2.Cidade);
        printf("\n\t%i\t\t\t%i", carta1.Populacao, carta2.Populacao);
    } else if (var == 2){
        printf("\nAtributo Comparado: Área");
        printf("\n\t%s\t\t%s", carta1.Cidade, carta2.Cidade);
        printf("\n\t%.2f\t\t\t%.2f\tkm²", carta1.Area, carta2.Area);
    } else if (var == 3){
        printf("\nAtributo Comparado: PIB");
        printf("\n\t%s\t\t%s", carta1.Cidade, carta2.Cidade);
        printf("\n\t%.2f\t\t\t%.2f\tBilhões de Reais", carta1.PIB, carta2.PIB);
    } else if (var == 4){
        printf("\nAtributo Comparado: Número de Pontos Turísticos");
        printf("\n\t%s\t\t%s", carta1.Cidade, carta2.Cidade);
        printf("\n\t%i\t\t\t%i", carta1.NPontosTuristicos, carta2.NPontosTuristicos);
    } else if (var == 5){
        printf("\nAtributo Comparado: Densidade Demográfica");
        printf("\n\t%s\t\t%s", carta1.Cidade, carta2.Cidade);
        printf("\n\t%.2f\t\t\t%.2f\thab/km²", carta1.DensidadePopulacional, carta2.DensidadePopulacional);
    } else if (var == 6){
        printf("\nAtributo Comparado: PIB per Capita");
        printf("\n\t%s\t\t%s", carta1.Cidade, carta2.Cidade);
        printf("\n\t%.2f\t\t\t%.2f\treais", carta1.PIBperCapita, carta2.PIBperCapita);
    } else if (var == 7){
        printf("\nAtributo Comparado: Super Poder");
        printf("\n\t%s\t\t%s", carta1.Cidade, carta2.Cidade);
        printf("\n\t%.2f\t\t\t%.2f", carta1.SuperPoder, carta2.SuperPoder);
    }
    if (resultado == 1){
        printf("\nA Carta 1 Venceu!");
    } else if (resultado == 2){
        printf("\nA Carta 2 Venceu!");
    } else {
        printf("\nHouve um empate entre a Carta 1 e a Carta 2!");
    }
}

Carta *MockCartas(){
    static Carta cartas[2];
    // Carta 1
    cartas[0] = InitializeCarta();
    cartas[0].Estado = 'A';
    strcpy(cartas[0].Codigo, "01");
    strcpy(cartas[0].Cidade, "Dois Irmãos");
    cartas[0].Populacao = 30709;
    cartas[0].Area = 132.0;
    cartas[0].PIB = 2.3;
    cartas[0].NPontosTuristicos = 13;
    cartas[0] = SetDensidadePopulacional(cartas[0]);
    cartas[0] = SetPIBperCapita(cartas[0]);
    cartas[0] = SetSuperPoder(cartas[0]);

    // Carta 2
    cartas[1] = InitializeCarta();
    cartas[1].Estado = 'B';
    strcpy(cartas[1].Codigo, "03");
    strcpy(cartas[1].Cidade, "Novo Hamburgo");
    cartas[1].Populacao = 227000;
    cartas[1].Area = 224.0;
    cartas[1].PIB = 9.282;
    cartas[1].NPontosTuristicos = 13;
    cartas[1] = SetDensidadePopulacional(cartas[1]);
    cartas[1] = SetPIBperCapita(cartas[1]);
    cartas[1] = SetSuperPoder(cartas[1]);

    return cartas;
}

void SetCartas(Carta *cartas, int NumCartas){
    for (int i = 0; i < NumCartas; i++){
        cartas[i] = InitializeCarta();
        printf("\nDigite os valores para a carta %i:", i+1);
        cartas[i] = SetCardValues(cartas[i]);
    }
}

void ExibirCartas(Carta *cartas, int numCartas){
    printf("\nPrintando %i Cartas", numCartas);
    printf("\n===================");
    for (int i = 0; i < numCartas; i++){
        printf("\nCarta %i:", i+1);
        PrintCardValues(cartas[i]);
    }
}

int *RemoveUmElemento(int *array, int tamanho, int elemento){
    // Remove o primeiro valor encontrado que é igual ao elemento
    int newSize = tamanho - 1;
    int *newArray = (int *) malloc(newSize * sizeof(int));
    int j = 0;
    int found = 0;
    for (int i = 0; i < tamanho; i++){
        if (array[i] != elemento || found){
            newArray[j] = array[i];
            j++;
        } else if (array[i] == elemento){
            found = 1;
        }
    }
    return newArray;
}

int *AdicionarElemento(int *array, int tamanho, int elemento){
    // Adiciona um elemento no final do array
    int newSize = tamanho + 1;
    int *newArray = (int *) malloc(newSize * sizeof(int));
    for (int i = 0; i < tamanho; i++){
        newArray[i] = array[i];
    }
    newArray[newSize - 1] = elemento;
    return newArray;
}

int VerificarElemento(int *array, int tamanho, int elemento){
    // Verifica se um elemento existe no array
    if (tamanho == 0 || array == NULL){
        return 0;
    }
    for (int i = 0; i < tamanho; i++){
        if (array[i] == elemento){
            return 1;
        }
    }
    return 0;
}

int *MenuEscolhaAtributos(){
    int QuantidadeAtributosEscolhidos = 0;
    char NumeroEscolhido = '\0';
    int *NumerosEscolhidos;
    while (1)
    {
        printf("\nDigite os números dos atributos que deseja adicionar ou remover da comparação: ");
        if (!VerificarElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, 1)) {
            printf("\n1 = População");
        }
        if (!VerificarElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, 2)) {
            printf("\n2 = Área");
        }
        if (!VerificarElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, 3)) {
            printf("\n3 = PIB");
        }
        if (!VerificarElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, 4)) {
            printf("\n4 = Número de Pontos Turísticos");
        }
        if (!VerificarElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, 5)) {
            printf("\n5 = Densidade Populacional");
        }
        if (!VerificarElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, 6)) {
            printf("\n6 = PIB per Capita");
        }
        if (!VerificarElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, 7)) {
            printf("\n7 = Super Poder");
        }
        printf("\nSelecione 9 para CANCELAR e 0 para FINALIZAR a escolha de atributos.\n");
        printf("\nNúmeros Escolhidos: ");
        for (int i = 0; i < QuantidadeAtributosEscolhidos; i++){
            printf("%i ", NumerosEscolhidos[i]);
        }
        NumeroEscolhido = getchar();
        if(NumeroEscolhido == 48){
            break;
        }
        printf("\nNúmero Escolhido: %c", NumeroEscolhido);
        if (NumeroEscolhido > 48 && NumeroEscolhido < 56){
            if (!VerificarElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, NumeroEscolhido - 48)){
                NumerosEscolhidos = AdicionarElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, NumeroEscolhido - 48);
                QuantidadeAtributosEscolhidos++;
            } else if (VerificarElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, NumeroEscolhido - 48)){
                NumerosEscolhidos = RemoveUmElemento(NumerosEscolhidos, QuantidadeAtributosEscolhidos, NumeroEscolhido - 48);
                QuantidadeAtributosEscolhidos--;
            } else {
                printf("\nNúmero inválido. Digite um número entre 1 e 7 ou pressione ESC para finalizar: ");
                continue;
            }
        } else if (NumeroEscolhido == 57){
            exit(0);
            break;
        } else {
            printf("\nNúmero inválido. Digite um número entre 1 e 7 ou pressione ESC para finalizar: ");
            continue;
        }
    }

    int tamanho = QuantidadeAtributosEscolhidos;
    static int NEscolhidos[10];

    for (int i = 0; i < tamanho; i++){
        NEscolhidos[i] = NumerosEscolhidos[i];
    }

    free(NumerosEscolhidos);

    printf("\nAtributos escolhidos: ");
    for (int i = 0; i < tamanho; i++){
        printf("%i ", NEscolhidos[i]);
    }
    NEscolhidos[9] = tamanho; // Guardando o tamanho do array no final
    return NEscolhidos;
}

float somaAtributos(Carta carta){
    return (float)carta.Populacao + carta.Area + carta.PIB + (float)carta.NPontosTuristicos + carta.DensidadePopulacional + carta.PIBperCapita + carta.SuperPoder;
}

void EscolherECompararAtributos(Carta carta1, Carta carta2){
    int PontosCarta1 = 0;
    int PontosCarta2 = 0;
    int *ptrAtributosEscolhidos = MenuEscolhaAtributos();
    int QuantidadeAtributosEscolhidos = ptrAtributosEscolhidos[9];
    int resultadoComparacaoIndividual = 0;
    float valoresSomaCarta1[10] = {0};
    float valoresSomaCarta2[10] = {0};
    char valbuffer[100] = "";
    char stringResultadoNomes[255] = "\n=================================\nAtributos escolhidos:\n=================================\n";
    char stringResultadoValores[255] = "\n=================================\nValores dos Atributos:\n=================================\n";
    for (int i = 0; i < QuantidadeAtributosEscolhidos; i++){
        switch (ptrAtributosEscolhidos[i])
        {
        case 1:
            resultadoComparacaoIndividual = CompararPopulacao(carta1, carta2);
            strcpy(valbuffer, "");
            sprintf(valbuffer, "População: %i x %i\n", carta1.Populacao, carta2.Populacao);
            strcat(stringResultadoNomes, "População ");
            strcat(stringResultadoValores, valbuffer);
            valoresSomaCarta1[i] = carta1.Populacao;
            valoresSomaCarta2[i] = carta2.Populacao;
            break;
        case 2:
            strcpy(valbuffer, "");
            sprintf(valbuffer, "Área: %.2f x %.2f\n", carta1.Area, carta2.Area);
            strcat(stringResultadoNomes, "Área ");
            strcat(stringResultadoValores, valbuffer);
            valoresSomaCarta1[i] = carta1.Area;
            valoresSomaCarta2[i] = carta2.Area;
            break;
        case 3:
            strcpy(valbuffer, "");
            resultadoComparacaoIndividual = CompararPIB(carta1, carta2);
            sprintf(valbuffer, "PIB: %.2f x %.2f\n", carta1.PIB, carta2.PIB);
            strcat(stringResultadoNomes, "PIB ");
            strcat(stringResultadoValores, valbuffer);
            valoresSomaCarta1[i] = carta1.PIB;
            valoresSomaCarta2[i] = carta2.PIB;
            break;
        case 4:
            strcpy(valbuffer, "");
            resultadoComparacaoIndividual = CompararNumeroDePontosTuristicos(carta1, carta2);
            sprintf(valbuffer, "Número de Pontos Turísticos: %i x %i\n", carta1.NPontosTuristicos, carta2.NPontosTuristicos);
            strcat(stringResultadoNomes, "Número de Pontos Turísticos ");
            strcat(stringResultadoValores, valbuffer);
            valoresSomaCarta1[i] = carta1.NPontosTuristicos;
            valoresSomaCarta2[i] = carta2.NPontosTuristicos;
            break;
        case 5:
            strcpy(valbuffer, "");
            resultadoComparacaoIndividual = CompararDensidadePopulacional(carta1, carta2);
            sprintf(valbuffer, "Densidade Populacional: %.2f x %.2f\n", carta1.DensidadePopulacional, carta2.DensidadePopulacional);
            strcat(stringResultadoNomes, "Densidade Populacional ");
            strcat(stringResultadoValores, valbuffer);
            valoresSomaCarta1[i] = carta1.DensidadePopulacional;
            valoresSomaCarta2[i] = carta2.DensidadePopulacional;
            break; 
        case 6:
            strcpy(valbuffer, "");
            resultadoComparacaoIndividual = CompararPIBPerCapita(carta1, carta2);
            sprintf(valbuffer, "PIB per Capita: %.2f x %.2f\n", carta1.PIBperCapita, carta2.PIBperCapita);
            strcat(stringResultadoNomes, "PIB per Capita ");
            strcat(stringResultadoValores, valbuffer);
            valoresSomaCarta1[i] = carta1.PIBperCapita;
            valoresSomaCarta2[i] = carta2.PIBperCapita;
            break;
        case 7:
            strcpy(valbuffer, "");
            resultadoComparacaoIndividual = CompararSuperPoder(carta1, carta2);
            sprintf(valbuffer, "Super Poder: %.2f x %.2f\n", carta1.SuperPoder, carta2.SuperPoder);
            strcat(stringResultadoNomes, "Super Poder ");
            strcat(stringResultadoValores, valbuffer);
            valoresSomaCarta1[i] = carta1.SuperPoder;
            valoresSomaCarta2[i] = carta2.SuperPoder;
            break;
        default:
            break;
        }
        if (resultadoComparacaoIndividual == 1){
            PontosCarta1++;
        } else if (resultadoComparacaoIndividual == 2){
            PontosCarta2++; 
        }
    }

    float somaValoresCarta1 = 0;
    float somaValoresCarta2 = 0;
    for (int i = 0; i < QuantidadeAtributosEscolhidos; i++){
        somaValoresCarta1 += (float)valoresSomaCarta1[i];
        somaValoresCarta2 += (float)valoresSomaCarta2[i];
    }

    printf("\n======================================");
    printf("\nResultados da Comparação das Cidades %s(carta 1) e %s(carta 2):", carta1.Cidade, carta2.Cidade);
    printf("%s", stringResultadoNomes);
    printf("%s", stringResultadoValores);
    printf("\nPontos da Carta 1: %i", PontosCarta1);
    printf("\nPontos da Carta 2: %i", PontosCarta2);
    printf("\nSoma dos Valores da Carta 1: %.2f", somaValoresCarta1);
    printf("\nSoma dos Valores da Carta 2: %.2f", somaValoresCarta2);
    if (PontosCarta1 > PontosCarta2){
        printf("\nA Carta 1 Venceu em relação aos pontos individuais!");
    } else if (PontosCarta1 < PontosCarta2){
        printf("\nA Carta 2 Venceu em relação aos pontos individuais!");
    } else {
        printf("\nHouve um empate entre a Carta 1 e a Carta 2 em relação aos pontos individuais!");
    }
    if (somaValoresCarta1 > somaValoresCarta2){
        printf("\nA Carta 1 Venceu em relação à soma dos valores dos atributos!");
    } else if (somaValoresCarta1 < somaValoresCarta2){
        printf("\nA Carta 2 Venceu em relação à soma dos valores dos atributos!");
    } else {
        printf("\nHouve um empate entre a Carta 1 e a Carta 2 em relação à soma dos valores dos atributos!");
    }

}

int main(){
    setlocale(LC_ALL, "Portuguese");
    Carta cartas[2];
    int NumCartas = sizeof(cartas) / sizeof(Carta);

    // Setar Cartas
    // cartas = SetCartas(cartas);

    cartas[0] = MockCartas()[0];
    cartas[1] = MockCartas()[1];

    //ExibirCartas(cartas, NumCartas);

    //CompararAtributos(cartas[0], cartas[1]);

    EscolherECompararAtributos(cartas[0], cartas[1]);

    return 0;
}