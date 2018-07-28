#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void solution1();
int simpleHash(const char * s);

void solution2();
typedef int T;
typedef struct Node{
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

void printTree(Node *root){
    if(root){
        printf("%d",root->data);
        if (root->left || root->right){
            printf("(");
            if (root->left){
                printTree(root->left);
            } else {
                printf("NULL");
            }
            printf(",");
            if (root->right){
                printTree(root->right);
            } else {
                printf("NULL");
            }
            printf(")");
        }
    }
}

Node * getFreeNode(T value, Node * parent){
    Node * tmp = malloc(sizeof(Node));
    tmp->data = value;
    tmp->left = tmp->right = NULL;
    tmp->parent = parent;
    return tmp;
}

void insert(Node **head, T value){

    Node *tmp = NULL;
    if (*head == NULL){
        *head = getFreeNode(value,NULL);
        return;
    }
    tmp = *head;
    while(tmp){
        if(value > tmp->data){
            if(tmp->right){
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(value,tmp);
                return;
            }
        } else if(value < tmp->data){
            if(tmp->left){
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeNode(value,tmp);
                return;
            }
        } else {
            exit(2);
        }
    }
}


int main() {

    //solution1();
    solution2();

    return 0;
}

int simpleHash(const char *s){

    int i = 0;
    int sum = 0;
    while(s[i]!='\0'){
        sum+=(int)s[i];
        i++;
    }
    return sum;

}

void solution1(){

    char * str = "";
    printf("Введите строку для расчета простого ХЕШа: \n");
    scanf("%s",str);

    printf("ХЕШ строки: %d", simpleHash(str));

}

void solution2(){

}