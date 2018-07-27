#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void solution1();
int simpleHash(char string[]);


int main() {

    solution1();

    return 0;
}

int simpleHash(char string[]){

    int i = 0;
    int sum = 0;
    while(string[i]!='\0'){
        sum+=(int)string[i];
        i++;
    }
    return sum;

}

void solution1(){

    char str[255] = "";
    printf("Введите строку для расчета простого ХЕШа: \n");
    scanf("%s",&str);

    printf("ХЕШ строки: %d", simpleHash(str));

}