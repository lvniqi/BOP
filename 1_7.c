#include<stdio.h>
int main(void){
#define LEN  5
    int a[LEN] = {4,2,1,6,0};
    int count = 0,i;
    for(i=0;i<LEN-1;i++){
        int j;
        for(j=i;j>=0;j--){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                count++;
                int k;
                for(k=0;k<LEN;k++){
                    printf("--%d\t",a[k]);
                }
                printf("COUNT--: %d\n",count);
            }
        }
    }
    printf("COUNT: %d\n",count);
}
