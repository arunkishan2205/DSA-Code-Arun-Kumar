
#include<stdio.h>
int binarysearch(int a[],int n, int key){
    int low=0;
    int high=n-1;
    while(low<=high){
    int mid=low+high/2;
    if(a[mid]==key){
        printf("%d",mid);
    }
    else if(key<a[mid]){
        high=mid-1;
    }
    else{
        low=mid+1;
    }
    }
return (-1);
}
void main(){
    int a[100],i,n,key;
    printf("enter the number of elements of array");
    scanf("%d",&n);
    printf("Enter elements");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the number to search");
    scanf("%d",&key);
    binarysearch(a,n,key);
}

