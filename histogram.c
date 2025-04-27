#include <stdio.h>

void frequency(int arr[],int freq[], int n){
    for(int i=0; i<n; i++){
        freq[arr[i]-1]++;
    }
}
void histogram( int freq[], int n){
    printf("\n");
    printf("------- FREQUENCY HISTORAM--------\n");
    for(int i=0; i<n; i++){
        printf("  %d: ",i+1);
        for(int j=0; j<freq[i]; j++){
            printf("* ");
        }
    printf("\n");
    }
}

int main() {
        //reading the array:
        int n;
        printf("Enter the number of values: ");
        scanf("%d", &n);
        int arr[n], freq[n];
        for(int i=0; i<n; i++){
        freq[i]=0;
        arr[i] =0;
        }
        printf("Enter the values between 1 and %d\n", n);
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }printf("\n");
        printf("The values entered are: ");
        for(int i=0; i<n; i++){
            printf("%d ", arr[i]);
        }printf("\n");
        
        
        // calculating frequency:
        frequency( arr,freq, n);
        
        // printing histogram:
        histogram(freq, n);

    return 0;
}