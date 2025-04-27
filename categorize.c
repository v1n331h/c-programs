#include<stdio.h>

void sort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j= i+1; j<n; j++ ){
            if(arr[i]>arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("The sorted elements:");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }printf("\n");
}

void categorize(int arr[], int n){
    int group1[20], group2[20], group3[20], group4[20];
    int g1 = 0, g2 = 0, g3 = 0, g4 = 0;

    // Categorize numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] < 10) {
            group1[g1++] = arr[i];
        } else if (arr[i] < 20) {
            group2[g2++] = arr[i];
        } else if (arr[i] < 30) {
            group3[g3++] = arr[i];
        } else if (arr[i] < 100) {
            group4[g4++] = arr[i];
        }
    }

    // Sort each group
    printf("Group 1 (Less than 10): ");
    sort(group1, g1);
    printf("Group 2 (10 to 19): ");
    sort(group2, g2);
    printf("Group 3 (20 to 29): ");
    sort(group3, g3);
    printf("Group 4 (30 to 99): ");
    sort(group4, g4);
}
int main(){
    int n;
    printf("Enter the total number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort( arr, n);
    categorize(arr,n);
    
    return 0;
}