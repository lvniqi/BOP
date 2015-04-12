#include<stdio.h>
#include<stdbool.h>
#define BOOK_LEN 5
typedef struct _books{
    int book[BOOK_LEN];
    int len;
}books;
void sort(books* book){
    int i,j;
    for(i=0;i<book->len;i++){
        for(j=i;j>0;j--){
            if(book->book[j]>book->book[j-1]){
                int temp = book->book[j];
                book->book[j] = book->book[j-1];
                book->book[j-1] = temp;
            }
            else{
                break;
            }
        }
    }
}
void init(books* book){
    int i;
    book->len = BOOK_LEN;
    sort(book);
    for(i=BOOK_LEN-1;i>= 0;i--){
        if(book->book[i] == 0){
            book->len--;
        }
    }
}
void print(books book){
    int i;
    for(i=0;i<BOOK_LEN;i++){
        printf("book%d:\t%d\n",i,book.book[i]);
    }
    printf("len:\t%d\n",book.len);
}
bool check_zero(books book){
    if(book.len){
        return false;
    }
    return true;
}
double min(double* temp){
    int i;
    double rst = temp[0];
    for(i=1;i<BOOK_LEN;i++){
        if(temp[i]< rst){
            rst = temp[i];
        }
    }
    return rst;
}
books find_next(books book,int type){
    int i;
    for(i=0;i<type;i++){
        book.book[i] -=1;
    }
    int cnt = 0;
    for(i=0;i<BOOK_LEN;i++){
        if(book.book[i] != 0){
            cnt++;
        }
    }
    sort(&book);
    book.len = cnt;
    printf("----%d-----\n",type);
    print(book); 
    return book;
}
double getmin(books book){
    if(check_zero(book)){
        return 0;
    }
    else{
        double temp[5] = {0};
        switch(book.len){
            case 5:{
                       temp[0] = 5*8*0.75+getmin(find_next(book,5));
                       temp[1] = 4*8*0.8+getmin(find_next(book,4));
                       temp[2] = 3*8*0.9+getmin(find_next(book,3));
                       temp[3] = 2*8*0.95+getmin(find_next(book,2));
                       temp[4] = 8+getmin(find_next(book,1));
                       break;
                   }
            case 4:{
                       temp[1] = 4*8*0.8+getmin(find_next(book,4));
                       temp[2] = 3*8*0.9+getmin(find_next(book,3));
                       temp[3] = 2*8*0.95+getmin(find_next(book,2));
                       temp[4] = 8+getmin(find_next(book,1));
                       temp[0] = temp[1];
                       break;
                   }
            case 3:{
                       temp[2] = 3*8*0.9+getmin(find_next(book,3));
                       temp[3] = 2*8*0.95+getmin(find_next(book,2));
                       temp[4] = 8+getmin(find_next(book,1));
                       temp[1] = temp[2];
                       temp[0] = temp[1];
                       break;
                   }
            case 2:{
                       temp[3] = 2*8*0.95+getmin(find_next(book,2));
                       temp[4] = 8+getmin(find_next(book,1));
                       temp[2] = temp[3];
                       temp[1] = temp[2];
                       temp[0] = temp[1];
                       break;
                   }
            case 1:{
                       temp[4] = 8+getmin(find_next(book,1));
                       temp[3] = temp[4];
                       temp[2] = temp[3];
                       temp[1] = temp[2];
                       temp[0] = temp[1];
                       break;
                   }
        } 
        return min(temp);
    }
}
int main(void){
    books book = {
        .book = {1,1,2,2,2},
        .len = 0
    };
    init(&book);    
    print(book);
    printf("min:%lf\n",getmin(book));
    return 0;
}
