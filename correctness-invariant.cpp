#include <stdio.h>

void insertionSort(int N, int arr[]) {
    int i,j;
    int value;
    for(i=1;i<N;i++)
    {
        j=i;
        while(j>0 && arr[j]<arr[j-1])
        {
            value=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=value;
            j=j-1;
        }
    }
    for(j=0;j<N;j++)
    {
        printf("%d",arr[j]);
        printf(" ");
    }    
}
int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}
