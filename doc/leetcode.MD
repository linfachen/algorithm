#leetcode 笔记
##1.异或操作满足：
1.结合律：
$$a\bigoplus b \bigoplus c = a \bigoplus (b \bigoplus c)$$
2.交换律：
$$a\bigoplus b = b \bigoplus a$$
3.0是么元，自身是自己的逆元：
$$a\bigoplus a = 0$$
$$a\bigoplus 0 = a$$

##2.高级io
```c++
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
```

##3.开放寻址法的简单的hash表
```c++
#define UN_ABLE 0
#define k 3

class hash_table{
public:
    int *_data;
    int _size;
    size_t _bucket;
    
    hash_table(int n);
    ~hash_table();
    size_t size(){return _size;};
    void insert(int val);
    int* find(int val);
};


std::hash<int> hash_int;


hash_table::hash_table(int n){
    _data = (int*)malloc(n*k*sizeof(int));
    _bucket = n*k;
    _size = n;
    memset(_data,0,n*k*sizeof(int));
}

hash_table::~hash_table(){
    free(_data);
}

inline void hash_table::insert(int val){
    size_t hash_value = hash_int(val);
    for(size_t i=0;i<_bucket;i++){
        if(*(_data+(hash_value+i)%_bucket)==UN_ABLE || *(_data+(hash_value+i)%_bucket)==val){
            *(_data+(hash_value+i)%_bucket)=val;
            return;
        }
    }
}


inline int *hash_table::find(int val){
    size_t hash_value = hash_int(val);
    for(size_t i=0;i<_bucket;i++){
        if(*(_data+(hash_value+i)%_bucket)==val){
            return _data+(hash_value+i)%_bucket;
        }else if(*(_data+(hash_value+i)%_bucket)==UN_ABLE){
            return nullptr;
        }
    }
    return nullptr;
}


```

##4.辗转相除法求最大公约数
```c++
int gcd(int x,int y){
    if(x<y) std::swap(x,y);
    while(y){
        int temp = x%y;
        x = y;
        y = temp;
    }
    return x;
}

```
