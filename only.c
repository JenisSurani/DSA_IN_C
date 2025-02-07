#include <stdio.h>
int main()
{
    int a=10;
    int b=30;
    printf("%d and %d\n",a,b);

    a=a^b; // 10^20
    b=a^b; // (10^20)^20 = 10^0=10
    a=a^b;//(10^20)^10=20^0=20

    // XORing a number with itself results in 0 and XORing anything with 0 gives the original number,
    printf("%d and %d",a,b);
    return 0;
}


/*
Authour:Jenish Surani
Purpose: Swapping two numbers using xor operator ^
Date: 10/10/2024
*/

// 
/*
The XOR operator works on individual bits as follows:

0 ^ 0 = 0
1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1*/