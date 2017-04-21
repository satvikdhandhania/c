/* Replace the 12th and 13th bits of number 1 with that of the
 * lowermost bits of Num2. Numbers are 32bit
 * E.g. Num1 = 2048
 *  Num2 = 3
 */

#include<stdio.h>
int main()
{
    unsigned num1 = 2069;
    unsigned num2 = 3;

    unsigned mask = 0b11111111111;
    mask = mask&num1;
    printf("\nMask: %u",mask);
    num1 = num1>>13;
    printf("\nnum1 shifted right: %u",num1);
    num2 = (num2<<30)>>30;
    printf("\nNum2 Lower Bits: %u",num2);
    num1 = num1<<2;
    num1 = num1|num2;   
    num1 = (num1<<11)|mask;
    printf("%u",num1);

    return 1;
}

