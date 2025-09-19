class DataStream {
    private:
        unsigned int size=0;
        int target,windowSize;

public:
    DataStream(int value, int k) {
        this->target=value;
        this->windowSize=k;

    }
    
    bool consec(int num) {
        if(num!=target) this->size=0;
        else ++this->size;
        return this->size >=windowSize;
        
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */