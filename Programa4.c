#include <stdio.h>
#include <stdlib.h>
#define NUM_PUEBLOS 100
#define NUM_BEBIDAS 8

// Función para inicializar la matriz
void inicializar_matriz(int arr[NUM_PUEBLOS][NUM_BEBIDAS])
{
    for (int i = 0; i < NUM_PUEBLOS; i++)
        for (int j = 0; j < NUM_BEBIDAS; j++)
            arr[i][j] = 0;
    printf("Se inicializó la matriz de forma correcta.\n");
}

// Función para llenar la matriz con información del usuario
void leer_consumo(int arr[NUM_PUEBLOS][NUM_BEBIDAS])
{
    int bebida, litros;
    for (int i = 0; i < NUM_PUEBLOS; i++)
    {
        printf("Introduce las bebidas consumidas por el pueblo %d (-1 para terminar):\n", i + 1);
        scanf("%d", &bebida);
        while (bebida != -1)
        {
            printf("Introduce la cantidad en litros para la bebida %d: ", bebida);
            scanf("%d", &litros);
            arr[i][bebida] = litros;
            printf("Introduce otra bebida: ");
            scanf("%d", &bebida);
        }
    }
}

// Función para calcular el consumo total de cada bebida
void calcular_consumo_total(int arr[NUM_PUEBLOS][NUM_BEBIDAS], int total[])
{
    for (int j = 0; j < NUM_BEBIDAS; j++)
        for (int i = 0; i < NUM_PUEBLOS; i++)
            total[j] += arr[i][j];
}

// Función para determinar la bebida más consumida
void bebida_mas_consumida(int total[], int *bebida, int *max)
{
    *max = 0;
    for (int i = 0; i < NUM_BEBIDAS; i++)
    {
        if (total[i] > *max)
        {
            *max = total[i];
            *bebida = i;
        }
    }
}

// Función para calcular el consumo total de bebidas alcohólicas
void calcular_consumo_filtrado(int arr[NUM_PUEBLOS][NUM_BEBIDAS], int total[])
{
    for (int j = 0; j < NUM_BEBIDAS; j++)
    {
        if (j != 1 && j != 6) // Excluir bebidas no alcohólicas
            for (int i = 0; i < NUM_PUEBLOS; i++)
                total[j] += arr[i][j];
    }
}

// Función para determinar el pueblo que más consume alcohol
void pueblo_mas_consumidor(int arr[NUM_PUEBLOS][NUM_BEBIDAS], int *pueblo, int *max)
{
    int total_pueblos[NUM_PUEBLOS] = {0};
    *max = 0;

    for (int i = 0; i < NUM_PUEBLOS; i++)
        for (int j = 0; j < NUM_BEBIDAS; j++)
            if (j != 1 && j != 6) // Excluir bebidas no alcohólicas
                total_pueblos[i] += arr[i][j];

    for (int i = 0; i < NUM_PUEBLOS; i++)
    {
        if (total_pueblos[i] > *max)
        {
            *max = total_pueblos[i];
            *pueblo = i;
        }
    }
}

// Función principal
int main()
{
    int arr[NUM_PUEBLOS][NUM_BEBIDAS];
    int total[NUM_BEBIDAS] = {0};
    int total_filtrado[NUM_BEBIDAS] = {0};
    int bebida, max, max2, max3, pueblo;

    inicializar_matriz(arr);
    leer_consumo(arr);

    calcular_consumo_total(arr, total);
    bebida_mas_consumida(total, &bebida, &max);
    printf("La bebida %d es la más consumida con %d litros.\n", bebida, max);

    calcular_consumo_filtrado(arr, total_filtrado);
    bebida_mas_consumida(total_filtrado, &bebida, &max2);
    printf("La bebida %d (sin incluir no alcohólicas) es la más consumida con %d litros.\n", bebida, max2);

    pueblo_mas_consumidor(arr, &pueblo, &max3);
    printf("El pueblo %d consume más alcohol con %d litros.\n", pueblo, max3);

    return 0;
}
