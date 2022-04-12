#include <stdio.h>
#include <math.h>

int a;
int b;
int sum = 0;
int i = 0;

void to_decimal(void)
{
    char c;
    if((c = getchar()) != '\n'){ 
        to_decimal();
        sum += ((c -'0')%39)*pow(a,i);
        i++;
    }
    return;
}
char num_to_char(int num){
    if(num<10){
        return (char)('0'+num);
    }
    else{
        return (char)('a'+num - 10 );
    }
}
void from_decimal(int num){
    if(num > 0){
        int tmp = num % b;
        from_decimal(num/b);
        printf("%c",num_to_char(tmp));
    }
}

int main(void)
{
    printf("Please enter the numbers base:\n");
    scanf("%d", &a);
    printf("Enter the desired base:\n");
    scanf("%d", &b);
    printf("Enter a number: \n");
    getchar();
    to_decimal();
    printf("The number in base %d is:\n",b);
    from_decimal(sum);
    return 1;
}