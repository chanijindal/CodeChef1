#include <stdio.h>
#define SIZE 100

void init_weights(int w[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++)
        w[i] = 0;
}

int partition(int arr[SIZE], int l, int u)
{
    int i, j, v, temp = 0;
    v = arr[l];
    
    i = l+1;
    j = u;
    
    do
    {
        do
        {
            i++;
        }while(arr[i] < v && i <= u);
        
        do
        {
            j--;
        }while(v < arr[j]);
        
        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
    }while(i < j);
    
    arr[l] = arr[j];
    arr[j] = v;
    
    return (j);
}

void quicksort(int arr[SIZE], int l, int u)
{
    int pivot;
    
    if (l < u) {
        pivot = partition(arr, l, u);
        quicksort(arr, l, pivot);
        quicksort(arr, pivot+1, u);
    }
}

int main() {
    int i, j, k = 0, weights[SIZE], T, N, K, sum1, sum2;
    
    //Number of test cases
	printf("\n Enter the no of test cases");
    scanf ("%d", &T);
	printf("Case 1");
    
    //For each test case
    do {
        init_weights(weights);
        sum1 = sum2 = 0;
        
        //Values of N and K
		printf("\n Enter the values of N and K");
        scanf ("%d %d", &N, &K);
        
        //Weights
		printf("\n Enter N weights");
        for (j = 0; j < N; j++)
            scanf ("%d", &weights[j]);
        
        quicksort (weights, 0, N);
        
        if (K > N/2)
            K = N - K;
        
        for (i = 0; i < K; i++)
            sum1 += weights[i];
        
        for (j = K; j < N; j++)
            sum2 += weights[j];
        
        printf ("%d\n", (sum2-sum1));
		printf("\nCase %d",k+1);
		k++;
    }while (k != T);
    
    return 0;
}
