#include <iostream>


//x div 5

#define M 0x66666667

int magic_div(int x){
    return (uint64_t(x)*M)>>33;
}


int f(int x){
    int res = 0;
    while(x/=5){
        res += x;
    }
    return res;
}





int main(){
//    std::cout<<magic_div(126)<<std::endl;
//    std::cout<<magic_div(26)<<std::endl;
//    std::cout<<magic_div(5)<<std::endl;
    for(int i=620;i<630;i++){
        std::cout<<"["<<i<<"]="<<f(i)<<std::endl;
    }
}