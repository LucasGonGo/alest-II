#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

void sort(int values[], int total);

void sort(int values[], int total)
{
    for(int i=0; i<total; i++) {
        char trocou = 0;
        for(int j=0; j<total-i-1; j++) {
            if(values[j] > values[j+1]) {
               int temp = values[j];
               values[j] = values[j+1];
               values[j+1] = temp;
               trocou = 1;
            }
        }
        if(!trocou) break;
    }
}

int main()
{
    int data[MAX];
    for(int i=0; i<MAX; i++)
        data[i] = rand()%(MAX*10);
    long start = clock();
    sort(data, MAX);
    long end = clock();
    printf("Tempo para %d elementos: %ld ns\n", MAX,(end-start));


    //for(int i=0; i<MAX; i++)
    //  printf("%d ", data[i]);
    //printf("\n");


    for(int i=0; i<MAX; i++)
        data[i] = i;
    long start1 = clock();
    sort(data, MAX);
    long end1 = clock();
    printf("Tempo para %d elementos: %ld ns\n", MAX,(end1-start1));


    for(int i=0; i<MAX; i++)
        data[i] = MAX-1-i;
    long start2 = clock();
    sort(data, MAX);
    long end2 = clock();
    printf("Tempo para %d elementos: %ld ns\n", MAX,(end2-start2));
}
