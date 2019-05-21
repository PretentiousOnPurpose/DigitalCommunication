#include <stdio.h>
#include <stdlib.h>
struct node {
    double val;
    int code;
    struct node * parent;
    struct node * left;
    struct node * right;
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

struct node * huffTree(double * arr, int n) {
    int i;
    struct node * init = (struct node *)malloc(sizeof(struct node));
    struct node * initL = (struct node *)malloc(sizeof(struct node));
    struct node * initR = (struct node *)malloc(sizeof(struct node));

    initL->code = 0;
    initL->left = initL->right = NULL;    
    initL->val = arr[1];

    initR->code = 1;
    initR->left = initR->right = NULL;    
    initR->val = arr[0];

    initL->parent = initR->parent = init;
    init->parent = NULL;
    init->val = (arr[0] + arr[1]);
    init->left = initL; 
    init->right = initR;

    for (i = 2; i < n; i++) {
        struct node * tmp = (struct node *)malloc(sizeof(struct node));
        struct node * tmp2 = (struct node *)malloc(sizeof(struct node));

        tmp2->left = tmp2->right = NULL;
        tmp2->val = arr[i];
        
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
        init = tmp;
    }

    return init;
}

int main() {
    double arr[] = {0.4, 0.2, 0.2, 0.1, 0.07, 0.03};
    sort(arr, 6);

    struct node * tree = huffTree(arr, 6);
    printf("%f\n", tree->val);    

    return 0;
}
