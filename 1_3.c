#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
int m_nCakeCnt;
int m_nMaxSwap;
int* m_CakeArray;
int* m_SwapArray;
int* m_ReverseArray;
int* m_ReverseSwapArray;
int m_nSearch;//当前搜索次数信息  
//寻找当前翻转的上界
int UpperBound(int nCakeCnt){
    return nCakeCnt*2;
}
//寻找当前翻转的下界
int LowerBound(int* pCakeArray,int nCakeCnt){
    int temp,ret = 0;
    int i;
    for(i=1;i<nCakeCnt;i++){
        //确定两个相邻烙饼在尺寸上是否相邻
        temp = pCakeArray[i]-pCakeArray[i-1];
        if(temp==1||temp==-1){
            ;
        }
        else{
            ret++;
        }
    }
    return ret;
}
bool isSorted(int* pCakeArray,int nCakeCnt){
    int i;
    for(i=1;i<nCakeCnt;i++){
        if(pCakeArray[i-1] > pCakeArray[i]){
            return false;
        }
    }
    return true;
}
//翻转ReverseArray
void Reverse(int nBegin,int nEnd){
    assert(nEnd > nBegin);
    int i,j,t;
    //翻转
    for(i=nBegin,j=nEnd;i<j;i++,j--){
        t = m_ReverseArray[i];
        m_ReverseArray[i] = m_ReverseArray[j];
        m_ReverseArray[j] = t;
    }
}
void init(int* pCakeArray,int nCakeCnt){
    assert(pCakeArray != NULL);
    assert(nCakeCnt>0);
    //复制烙饼数 
    m_nCakeCnt = nCakeCnt; 
    //复制烙饼数组
    m_CakeArray = (int*)malloc(nCakeCnt*sizeof(int));
    assert(m_CakeArray != NULL);
    int i;
    for(i=0;i<nCakeCnt;i++){
        m_CakeArray[i] = pCakeArray[i];
    }
    //得到最大交换次数
    m_nMaxSwap = UpperBound(m_nCakeCnt);
    //初始化交换结果数组
    m_SwapArray = (int*)malloc((m_nMaxSwap+1)*sizeof(int));
    assert(m_SwapArray !=NULL);
    //初始化中间交换结果信息
    m_ReverseArray = (int*)malloc(m_nCakeCnt*sizeof(int));
    assert(m_ReverseArray != NULL);
    for(i=0;i<nCakeCnt;i++){
        m_ReverseArray[i] = pCakeArray[i];
    }
    m_ReverseSwapArray = (int*)malloc(m_nMaxSwap*sizeof(int));
}

void Search(int step){
    int i,nEstimate;
    m_nSearch++;
    //估计这次搜索所需要的最小交换次数
    nEstimate = LowerBound(m_ReverseArray,m_nCakeCnt);
    //超过最大交换次数 退出
    if(step+nEstimate > m_nMaxSwap){
        return;
    }
    //如果已经排完序 直接输出结果
    if(isSorted(m_ReverseArray,m_nCakeCnt)){
        if(step < m_nMaxSwap){
            m_nMaxSwap = step;
            int i;
            for(i=0;i<m_nMaxSwap;i++){
                m_SwapArray[i] = m_ReverseSwapArray[i];
            }
        }
        return;
    }
    //递归进行翻转
    for(i=1;i<m_nCakeCnt;i++){
        Reverse(0,i);
        m_ReverseSwapArray[step] = i;
        Search(step+1);
        Reverse(0,i);
    }
}
int main(void){
#define TEST_LEN 10
    int test[TEST_LEN] = {1,2,4,3,5,7,6,10,9,8};
    init(test,TEST_LEN);
    m_nSearch = 0;
    Search(0);
    int i;
    for(i=0;i<m_nMaxSwap;i++){
        printf("%d:%d\n",i,m_SwapArray[i]);
    }
    return 0;
}
