# include<iostream>
# include<vector>
# include<string>
using namespace std;
struct mypair
{
    public:
    string val;
    int key;

    mypair(int key, string val):val(val), key(key){};
};

class arrayhashmap{
    private:
    vector<mypair *>  buckets;
    public:
    arrayhashmap(){
        buckets = vector<mypair *>(100);
    }

    ~arrayhashmap(){
        for(auto bucket : buckets)
            delete bucket;
        buckets.clear();
    }

    int hashfun(int val){
        int index = val%100;
        return index;
    }     

    string get(int key){
        int index = hashfun(key);
        mypair *p = buckets[index];
        if(p==nullptr)
            return "";
        else
            return p->val; 
    }

    void put(int key, string val){
        mypair *p = new mypair(key, val);
        int index = hashfun(key);
        buckets[index] = p;
    }

    void remove(int key){
        int index = hashfun(key);
        delete buckets[index];
        buckets[index] = nullptr;
    }

    vector<mypair *> mypairset(){
        vector <mypair *> mypairset;
        for(auto mypair : buckets){
            if(mypair!=nullptr)
                mypairset.push_back(mypair);
        }
        return mypairset;
    }

    vector<int> keyset() {
        vector<int> keySet;
        for (mypair *mypair : buckets) {
            if (mypair != nullptr) {
                keySet.push_back(mypair->key);
    }
    }
        return keySet;
    }   
    /* 获取所有值 */
    vector<string> valueset() {
        vector<string> valueSet;
        for (mypair *mypair : buckets) {
            if (mypair != nullptr) {
                valueSet.push_back(mypair->val);
    }
    }
        return valueSet;
    }
    /* 打印哈希表 */
    void print() {
        for (mypair *kv : mypairset()) {
            cout << kv->key << "-> " << kv->val << endl;
        }
    }
    
};
int main(){
    arrayhashmap map;
    map.put(1, "one");
    map.put(2, "two");
    map.put(3, "three");
    map.put(4, "four");
    map.print();
}