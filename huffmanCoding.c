#include <stdio.h>
#include <stdlib.h>
struct node {
    double val;
    int code;
    struct node * parent;
    struct node * left;
    struct node * right;
    int sym;
};

void sort(double * arr, int n) {
   int i, j;
   double tmp; 
   for (i = 0; i < n-1; i++) {     
       for (j = 0; j < n-i-1; j++) {  
           if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
           }
       }
   }
}

struct node ** huffTree(double * arr, int n) {
    int i;
    struct node * init = (struct node *)malloc(sizeof(struct node));
    struct node * initL = (struct node *)malloc(sizeof(struct node));
    struct node * initR = (struct node *)malloc(sizeof(struct node));
    struct node * * nodes = (struct node * *)malloc(sizeof(struct node) * (n+1));

    initL->code = 0;
    initL->left = initL->right = NULL;    
    initL->val = arr[1];
    initL->sym = 1;

    initR->code = 1;
    initR->left = initR->right = NULL;    
    initR->val = arr[0];
    initR->sym = 1;

    initL->parent = initR->parent = init;
    init->parent = NULL;
    init->val = (arr[0] + arr[1]);
    init->left = initL; 
    init->right = initR;

    nodes[0] = initR;
    nodes[1] = initL;

    for (i = 2; i < n; i++) {
        struct node * tmp = (struct node *)malloc(sizeof(struct node));
        struct node * tmp2 = (struct node *)malloc(sizeof(struct node));

        tmp2->left = tmp2->right = NULL;
        tmp2->val = arr[i];
        tmp2->sym = 1;
        if (init->val <= arr[i]) {
            tmp->right = init; 
            tmp->left = tmp2;
            init->code = 1;
            tmp2->code = 0;
        } else {
            tmp->left = init;
            tmp->right = tmp2; 
            init->code = 0;
            tmp2->code = 1;
        }
        tmp->val = init->val + tmp2->val;
        init->parent = tmp2->parent = tmp;
        tmp->parent = NULL;
        nodes[i] = tmp2;
        init = tmp;
    }

    return nodes;
}

void getCode(struct node * n) {
    int code[50];
    int i = 0;
    while(1) {
        if (n->parent != NULL) {
            code[i++] = n->code;
            n = n->parent;
        } else {
            break;
        }
    }

    while (i > 0) {
        printf("%d", code[--i]);
    }
    printf("\n");

}

int main() {
    int i;
    double arr[] = {0.4, 0.2, 0.2, 0.1, 0.07, 0.03};
    sort(arr, 6);

    struct node ** nodes = huffTree(arr, 6);
    struct node * x = nodes[4];

    for (i = 5; i >= 0; i--) {
        printf("%f: ", arr[i]);
        getCode(nodes[i]);
    }
    

    return 0;
}
