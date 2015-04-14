#include<stdio.h>
#define LEN 10
int user[LEN] = {1,2,3,4,5,5,4,2,4,3};
//fun1
int fun_1(void){
    int i,j;
    unsigned int sum_min=0xffff;
    //假设停在i楼
    for(i=0;i<6;i++){
        int sum = 0;
        for(j=0;j<LEN;j++){
            if(user[j]>i){
                sum += user[j]-i;
            }
            else{
                sum += i-user[j];
            }
        }
        if(sum_min >sum){
            sum_min = sum;
        }
    }
    return sum_min;
}
//fun2
int fun_2(void){
    int i,minfloor = 0,sum_min;
    //假设楼层在0
    for(i=0;i<LEN;i++){
        sum_min += user[i];
    }
    int temp_add;
    int BF,AF,F;
    for(i=1;i<6;i++){
        if()
    }
    
    
}
int main(void){
   printf("%d\n",fun_1());
}
