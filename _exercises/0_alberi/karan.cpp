#include <iostream>
void scambia(int& i, int& f) {
    int counter = i;
    i = f;
    f = counter;
}

int linear(int i, const int vett[]) {
    int counter = 0;
    while(i != vett[counter]){
        counter ++;
    }
    return counter;
}

void order(int pre[7], int post[7], int i, int f) { //i and f are?
    if((f - i) < 1) 
        return; 
    int conta = linear(pre[i+1],post);
    if(conta == 0)
        scambia(pre[i], pre[i + 1]);
    else {
        int k = 0;
        while (pre[i + 1 + k] != post[conta + 1]) {
           scambia(pre[i + k], pre[i + k + 1]);
           k++;
        }
    }
    order(pre, post, i , conta - 1);
    order(pre, post, linear(counter, pre) + 1 , f);
}

int main() {
    int pre [7] = {5, 3, 2, 1, 6, 7, 4};
    int post[7] = {2, 6, 7, 1, 3, 4, 5};
    order(pre,post,0,6);
    for(int i = 0; i< 7; i++)
        std::cout<< pre[i];
    return 0;
}