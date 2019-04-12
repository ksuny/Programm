// Сравнение методов сортировки
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
int pq = 0, ps = 0, sq = 0, ss = 0, n = 10000;
void sorts(double *a, int n)
{
    if (n == 1){return;}
    int i, k = 0;
    double max = INT_MIN, t = 0;
    for(i = 0; i < n; i++)
    {
        if (a[i] > max){max = a[i]; k = i;}
        ss++;
    }
    if(k != 0){t = a[0]; a[0] = a[k]; a[k] = t; ps++;}
    sorts(a + 1, n - 1);
}
void swap(double *mas, int i, int j)
{
    double t;
    t = mas[i];
    mas[i] = mas[j];
    mas[j] = t;
}
int min(double a, double b, double c)
{
    if(a <= b && a <= c){return 1;}
    else if(b <= a && b <= c){return 2;}
    else{return 3;}
}
void sortq(double *a, int n)
{
    if(n < 2){return;}
    int i = n/2 - 1;
    for(i = n/2 - 1; i > -1; i--)
    {
        sq += 2;
        if(min(a[i], a[2 * i], a[2 * i + 1]) == 2){swap(a, i, 2 * i); pq++;}
        else if(min(a[i], a[2 * i], a[2 * i + 1]) == 3){swap(a, i, 2 * i + 1); pq++;}
    }
    swap(a, 0, n - 1); pq++;
    sortq(a, n - 1);
}
void rnd(double *a, double *b)
{

    int i;
    for(i = 0; i < n; i++)
    {
        a[i] = rand() * ((rand() & 1) ? -1 : 1) / 100.0;
        b[i] = a[i];
        //printf("%f ", a[i]);
    }
}
void up(double *a, double *b)
{
    int i;
    for(i = 0; i < n; i++)
    {
        a[i] = i / 100.0;
        b[i] = a[i];
    }
}
void down(double *a, double *b)
{
    int i;
    for(i = n; i > 0; i--)
    {
        a[n - i] = i / 100.0;
        b[n - i] = a[n - i];
    }
}
int main(void)
{
    srand(time(NULL));
    int i;
    double *masq, *mass;
    masq = malloc(sizeof(double) * n);
    mass = malloc(sizeof(double) * n);
    down(mass, masq);
    sortq(masq, n);
    sorts(mass, n);
    printf("\n");
    printf("%d %d \n%d %d", ss, sq, ps, pq);

    pq = 0; ps = 0; sq = 0; ss = 0;
    up(mass, masq);
    sortq(masq, n);
    sorts(mass, n);
    printf("\n");
    printf("%d %d \n%d %d", ss, sq, ps, pq);

    pq = 0; ps = 0; sq = 0; ss = 0;
    rnd(mass, masq);
    sortq(masq, n);
    sorts(mass, n);
    printf("\n");
    printf("%d %d \n%d %d", ss, sq, ps, pq);

    pq = 0; ps = 0; sq = 0; ss = 0;
    rnd(mass, masq);
    sortq(masq, n);
    sorts(mass, n);
    printf("\n");
    printf("%d %d \n%d %d", ss, sq, ps, pq);
    return 0;
}
