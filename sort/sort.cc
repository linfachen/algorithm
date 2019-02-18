#include <iostream>
#include <algorithm>
#include "sort.h"

int * gen_data(int n){
    int * data = (int *)malloc(2*n* sizeof(int));
    for(int i=0;i<n;i++){
        *(data+i)= *(data+n+i)=rand()%(2*n);
    }
    std::sort(data+n,data+2*n);
    return data;
}

void check_result(int *array,int n){
    int error_count = 0;
    for(int i=0;i<n;i++){
        if(*(array+i)!=*(array+n+i)){
            std::cout<<"[i]="<<i <<" [arrry0]="<<*(array+i)<<" [arrry1]="<<*(array+n+i)<<std::endl;
            error_count++;
        }
        if(error_count==20) return;
    }
}


int main(){
    std::cout<<"******************sort test******************"<<std::endl;
    int array_len = 2451253;
    int * array = gen_data(array_len);

//    for(int i=0;i<array_len;i++){
//        std::cout<<*(array+i)<<std::endl;
//    }
    heap_sort(array,array_len);
    check_result(array,array_len);
    free(array);
}