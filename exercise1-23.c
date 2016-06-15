#include<stdio.h>

void rcomment(int c);
void incomment(void);
void echo_quote(int c);

int main(void)
{
    int c,d;

    printf(" To Check /* Quoted String */ \n");

    while((c=getchar())!=EOF)
        rcomment(c);

    return 0;
}

void rcomment(int c){

}
