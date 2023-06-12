#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT_COUNT 200

int min(int x, int y);
int max(int x, int y);
int sum(int x, int y);

int forAll(int *tab, int elemenCount, int (*func) (int, int));

int main(int argc, char const *argv[])
{
    int (*functionPointers[3]) (int, int) = {max, min, sum};
    int functionId, elemenCount;
    int *numbers;
    int i;

    printf("wybierz funkcje:\n0.MAX\n1.MIN\n2.SUM\n");
    scanf("%d", &functionId);
    if(functionId < 0 || functionId > 2) {
        return 1;
    }

    printf("podaj ilosc elementow tablicy: ");
    scanf("%d", &elemenCount);
    if ( elemenCount < 0 || elemenCount > MAX_ELEMENT_COUNT)
    {
        return 1;
    }
    printf("podaj elementy: \n");
    numbers = malloc(sizeof(int) * elemenCount);
    for (i = 0; i < elemenCount; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("Wynikiem jest: %d\n", forAll(numbers,elemenCount,functionPointers[functionId]));
    free(numbers);
    return 0;
}

int forAll(int *tab, int elemenCount, int (*func) (int, int)) {
    int i;
    int res = tab[0];
    for (i = 1; i < elemenCount; i++)
    {
        res = (*func)(res,tab[i]);
    }
    return res;
}

int min(int x, int y) {
    return y < x? y : x;
}

int max(int x, int y) {
    return y > x? y : x;
}

int sum(int x, int y) {
    return (x + y);
}
