class Dq{
public:
    std::pair<int,int> *_data;
    int first;
    int last;
    int k;
    int size;
    
    Dq(int _k){
        _data = (std::pair<int,int> *) malloc(sizeof(std::pair<int,int>)*_k);
        size = first = last = 0;
        k = _k;
    }
    
    ~Dq(){
        free(_data);
    }
    
    std::pair<int,int> &front(){
        return _data[first];
    }
    
    std::pair<int,int> &back(){
        return last==0 ? _data[k-1]:_data[last-1];
    }    
    
    void push_front(std::pair<int,int> x){
        size++;
        first--;
        if(first<0) first = k-1;
        _data[first] = x;
    }
    
    void push_back(std::pair<int,int> x){
        size++;
        _data[last++] = x;
        if(last==k) last = 0;
    }    
    
    void pop_front(){
        size--;
        first++;
        if(first==k) first = 0;
    }
    
    void pop_back(){
        size--;
        last--;
        if(last<0) last = k-1;
    }
    
    bool empty(){
        return size==0;
    }
};