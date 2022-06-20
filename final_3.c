#include <stdio.h>
#include <stdbool.h>

int number = 5;
const int INF = 10000000;

// s t x y z
char path_name[5] = {'s', 't', 'x', 'y', 'z'};
int arr[5][5] = {
    {0, 3, INF, 5, INF},
    {INF, 0, 6, 2, INF},
    {INF, INF, 0 ,INF, 2},
    {INF, 1, 4, 0, 6},
    {3, INF, 7, INF, 0}
};
bool v[5];
int d[5];

int getSmall(){
    int min = INF;
    int index = 0;
    for (int i=0; i<number; i++){
        if(d[i] < min && !v[i]){
            min = d[i];
            index = i;
        }
    }
    return index;
}
void pathOrder(int n){
    if(n==0)
        printf("path : s\n");
    else if(n==1)
        printf("path : s -> t\n");
    else if(n==2)
        printf("path : s -> y\n");
    else if(n==3)
        printf("path : s -> y -> x\n");
    else
        printf("path : s -> y -> z\n");
}

void dijk(int start){
    for (int i=0; i<number; i++){
        d[i] = arr[start][i];
    }
    v[start] = true;
    for(int i=0; i<number-2; i++){
        int current = getSmall();
        v[current] = true;
        for(int j=0; j<5; j++){
            if(!v[j]){
                if(d[current] + arr[current][j] < d[j]){
                    d[j] = d[current] + arr[current][j];
                }
            }
        }
    }
}


int main(void){
    dijk(0);
    for (int i=0; i<number; i++){
        printf("%c : %d \n", path_name[i], d[i]);
        pathOrder(i);
        printf("\n");
    }
}