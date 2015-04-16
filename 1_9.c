#include <stdio.h>
#include <stdbool.h>
//人员x 希望参加的小组n
#define TEAM_LEN 5
#define BIT(x) (1<<(x-1))
int member[][4]={
    {1,2,4,8},
    {2,4,16,8},
    {1,8,16,4}
};
//定义各种连接线c52 = 10
bool  Line[25]={false,};
int line_color[25];//一根线 2个颜色
void initLine(void){
    int i,j,k;
    //遍历所有成员
    for(i=0;i<3;i++){
        //遍历所有成员项
        for(j=0;j<4;j++){
            //遍历所有成员项对
            for(k=j+1;k<4;k++){
                int line = (member[i][j]|member[i][k]);
                Line[line] = true;
            }
        }
    }
}
bool makeColor(int bit,int color){
    int i;
    for(i=0;i<25;i++){
        if(i&BIT(bit)&& Line[i]){
            if(line_color[i]== color){
                    return false;
            }
            else
            {
                line_color[i] = color;
            }
        }
    }
    return true;
}
void printLine(void){
    int i;
    for(i=0;i<25;i++){
        printf("%d:%d\t",i,Line[i]);
        printf("color0:%d\t\n",line_color[i]);
    }
    printf("\n");
}
int main(void){
    initLine();
    int i;
    for(i=1;i<(TEAM_LEN+1);i++){
        if(!makeColor(i,(i)%2+1)){
            printf("error i: %d\n ",i);
            break;
        }   
    }
    printLine();
    return 0;
}
