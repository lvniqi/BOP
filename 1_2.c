#include <stdio.h>
#define REG_A(a)    (0x0f&(a))
#define SET_REG_A(a,b)  {(a) = ((a)&0xf0)+(b);}
#define ADD_REG_A(a)    {(a) = ((a)&0xf0)+REG_A(a)+1;}
#define REG_B(b)    (((0xf0)&(b))>>4)
#define SET_REG_B(a,b)  {(a) = ((a)&0x0f)+((b)<<4);}
#define ADD_REG_B(a)    {(a) = ((a)&0x0f)+((REG_B(a)+1)<<4);}
typedef unsigned char u8;

int main(void){
    u8 temp;
    SET_REG_A(temp,0);
    while(REG_A(temp)<9){
        SET_REG_B(temp,0);
        while(REG_B(temp)<9){
            if(REG_A(temp) != REG_B(temp)){
                printf("%d,%d\n",REG_A(temp),REG_B(temp));
            }
            ADD_REG_B(temp);
        }
        ADD_REG_A(temp);
    }
    return 0;
}
