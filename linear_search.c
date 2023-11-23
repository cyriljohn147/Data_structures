#include<stdio.h>

int main() {
    int arr[10]={1,2,3,4,5,6,67,0};
    int num,status=0;
    scanf("%d",&num);
    for(int i=0;i<10;i++) {
        if(arr[i]==num) {
            status=1;
            printf("Element found at %d\n",i);
            break;
        }
    }

    if(status==0)
        printf("Not found");
}