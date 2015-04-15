#include<stdio.h>
#define LEN 10
int user[LEN] = {1,2,3,2,5,5,4,6,6,6};
//fun1
typedef struct _rst
{
    int sum_min;
    int floor;
}rst;
rst fun_1(void){
    int i,j;
    rst rst1 = {.sum_min=0x7fff,.floor = 0,};
    //假设停在i楼
    for(i=1;i<7;i++){
        int sum = 0;
        for(j=0;j<LEN;j++){
            if(user[j]>i){
                sum += user[j]-i;
            }
            else{
                sum += i-user[j];
            }
        }
        if(rst1.sum_min >sum){
            rst1.sum_min = sum;
            rst1.floor = i;
        }
    }
    return rst1;
}
//fun2
rst fun_2(void){
    int i;
    rst rst2={.sum_min=0,.floor=1};
    int temp[6]={0,};
    int BF = 0,AF=0,F=0;
    //假设楼层在0
    for(i=0;i<LEN;i++){
        temp[user[i]-1]++;
        rst2.sum_min += user[i]-1;
        AF++;
    }
    F=temp[0];
    AF-=F;    
    for(i=1;i<6;i++){
        printf("%d %d %d\n",BF,F,AF);
        int dif = AF-BF-F;
        if(dif<=0){
            break;
        }
        else{
            rst2.sum_min-=dif;
            BF+=F;
            F=temp[i];
            AF-=F;
            rst2.floor=i+1;
        }
    }
    return rst2; 
}
int main(void){
   printf("%d %d\n",fun_1().floor,fun_1().sum_min);
   printf("%d %d\n",fun_2().floor,fun_2().sum_min);
}
