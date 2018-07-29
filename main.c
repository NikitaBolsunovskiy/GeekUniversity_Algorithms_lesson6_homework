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

void preOrderTravers(Node *root){
    if (root){
        printf("%d   ", root->data);
        fflush(stdout);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}
void inOrderTravers(Node *root){
    if (root){
        inOrderTravers(root->left);
        printf("%d   ", root->data);
        fflush(stdout);
        inOrderTravers(root->right);
    }
}
void postOrderTravers(Node *root){
    if (root){
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d   ", root->data);
        fflush(stdout);
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

    char str[] = "";
    printf("Введите строку для расчета простого ХЕШа: \n");
    scanf("%s",str);

    printf("ХЕШ строки: %d", simpleHash(str));

}

void readComandLine(const  char * comandLine, char *filePath, int *orderVar){
    int i = 0;
    while (comandLine[i]!= '\0'){

        if (comandLine[i]=='/'){
            i++;
            if(comandLine[i]=='f'){
                i++;
                i++;
                int j = 0;
                while (comandLine[i]!= '/') {
                    filePath[j] = comandLine[i];
                    i++;
                    j++;
                }
            } else if (comandLine[i] == 'v'){
                i++;
                i++;
                if (comandLine[i] == '1'){
                    *orderVar = 1;
                } else if (comandLine[i] == '2'){
                    *orderVar = 2;
                } else if (comandLine[i] == '3'){
                    *orderVar = 3;
                } else {
                    *orderVar = -1;
                }
            }
        } else{
            i++;
        }
    }
}

Node *getNodeByValue(Node *root, T value) {
    while (root) {
        if (root->data > value) {
            root = root->left;
            continue;
        } else if (root->data < value) {
            root = root->right;
            continue;
        } else {
            return root;
        }
    }
    return NULL;
}

void solution2(){

    char filePath[] = "";
    int orderVar = 0;

    printf("Введите команду для чтения файла с данными двоичного дерева и порядком обхода. \n");
    printf("путь к файлу: [Полный путь к файлу с расширением].\n");
    scanf("%s",filePath);
    printf("Вариант обхода: [вариает обхода: 1 - pre-order, 2 - in-order, 3 - post-order].\n");
    scanf("%d",&orderVar);

    fflush(stdout);
//    printf("FilePath: %s\n",filePath);
//    printf("Order variant: %d\n",orderVar);

    Node *Tree = NULL;
    FILE *file = fopen(filePath,"r");
    if (file==NULL) {
        puts("Не удалось открыть Файл!");
        exit(1);
    }
    int count;
    fscanf(file,"%d",&count);
    int i;
    for (i = 0; i < count; ++i) {
        int value;
        fscanf(file,"%d",&value);
        insert(&Tree,value);
    }
    fclose(file);
    printTree(Tree);
    printf("\nОбход: \n");
    if (orderVar == 1){
        preOrderTravers(Tree);
    } else if (orderVar == 2){
        inOrderTravers(Tree);
    } else if (orderVar == 3) {
        postOrderTravers(Tree);
    }

    Node * tmp = getNodeByValue(Tree,-7);

    if (tmp == NULL) {
        printf("\nне найден элемент.\n");
    } else {
        printf("\nнайденный элемент: %d\n",tmp->data);
    }
}