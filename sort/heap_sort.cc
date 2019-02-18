#include <utility>

inline int left(int i){return 2*i+1;}
inline int right(int i){return 2*i+2;}

void max_heapify(int *array,int i,int n){
    if(right(i)>n) return;
    if(right(i)==n){
        if(array[i]<array[left(i)]){
            std::swap(array[i],array[left(i)]);
        }
        return;
    }
    if(array[left(i)]>array[right(i)]){
        if(array[i]<array[left(i)]){
            std::swap(array[i],array[left(i)]);
            max_heapify(array,left(i),n);
        }
    }else{
        if(array[i]<array[right(i)]){
            std::swap(array[i],array[right(i)]);
            max_heapify(array,right(i),n);
        }
    }

}

//n>=2
void build_min_heap(int *array,int n){
    for(int i=n/2-1;i>=0;i--){
        max_heapify(array,i,n);
    }
}
#include <iostream>


void heap_sort(int *array,int n){
    if(n<=1) return;
    build_min_heap(array,n);
    for(int i=n-1;i>0;i--){
        std::swap(array[0],array[i]);
        max_heapify(array,0,i);
    }
}