#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include<sys/time.h>

int findRoots(int a , int b ,long int c); //aX2 + bX + c
void printSequence(int s, int e);


int main()
{

    struct timeval st, et;
    gettimeofday(&st,NULL);

    int n = 10000;
    long int c;
    int e;

    for(int s=1 ; s<= n ; s++)
    {
        c = (-1*s*s) + s - 2*n ;
        e = findRoots(1,1,c);
        if(e>0 && e > s)
            printSequence(s,e);
    }

    gettimeofday(&et,NULL);
    int elapsed = ((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec);
    printf("time: %d milli seconds\n",elapsed/1000);

    return 0;
}


int findRoots(int a , int b ,long int c)
{
    double root = sqrtl(1-(4*c));
    long int r ;
    if(root == (long int) root)
    {
        r = (long int) root;
        return  (-1+ r)/(2);
    }
    else return -1;
}

void printSequence(int s, int e)
{
    printf("start of sequence: %d to %d\n", s ,e);
    for(int i=s; i<=e ; i++)
        printf("%d  ",i);
    printf("\nend of sequence\n\n");
}
