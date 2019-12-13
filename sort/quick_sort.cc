//
// Created by spinors on 19-12-13.
//
#include <iostream>


int partition(int *array,int first,int last){
    int povit = array[last];
    int i = first - 1;
    while(first<last){
        if(array[first]<povit){
            i++;
            std::swap(array[first],array[i]);
        }
        first++;
    }

    std::swap(array[last],array[i+1]);
    return i + 1;
}


void _quick_sort(int *array,int first,int last){
    int mid = partition(array,first,last);
    if(last-mid>1) _quick_sort(array,mid+1,last);
    if(mid-first>1) _quick_sort(array,first,mid-1);
}


void quick_sort(int *array,int n){
    _quick_sort(array,0,n-1);
}


