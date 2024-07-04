# include<vector>
# include<iostream>
using namespace std;

struct Pair
{
    public:
    string val;
    int key;

    Pair(int key, string val):val(val), key(key){};
};

class listhashmap{
    private:
    int entendratio;
    vector<vector<Pair *>> buckets;
    int capacity;
    double loadthresh;
    int size;

    public:
    listhashmap():size(0), capacity(4), entendratio(2), loadthresh(2.0/3.0){
        buckets.resize(capacity);
    }
    ~listhashmap(){
        for(auto &bucket:buckets){ //这里引用的用法避免了拷贝
            for(auto p : bucket){
                delete p;}
                }
    }

    int hashfun(int key){
        int index = key%capacity;
        return index;
    }  

    double loadfactor() {
        return (double)size / (double)capacity;
    }

    string get(int key){
        int index = hashfun(key);
        for(Pair *p : buckets[index]){
            if(p->key == key)
                return p->val;
        }
        return "";
    }

    void put(int key, string val)
    {
        if(loadfactor() > loadthresh){
            extend();
            }
        int index = hashfun(key);
        for(Pair *p : buckets[index]){
            if(p->key == key){
                p->val = val;
                return;
            }
        }
        buckets[index].push_back(new Pair(key, val));
        size++;
    }

    void remove(int key){
        int index = hashfun(key);
        auto &bucket = buckets[index];
        for(int i=0; i<bucket.size(); i++){
            if(bucket[i]->key == key){
                Pair *tmp = bucket[i];
                bucket.erase(bucket.begin()+i);
                delete tmp;
                size--;
                return;
            }
        }
    }

    void extend(){
        vector<vector<Pair *>> bucketsTmp = buckets;
        capacity *= entendratio;
        buckets.clear();
        buckets.resize(capacity);
        for(auto &bucket : bucketsTmp){
            for(Pair *p : bucket){
                put(p->key, p->val);
                delete p;
            }
        }
    }

    void print() {
    for (auto &bucket : buckets) {
        cout << "[";
        for (Pair *pair : bucket) {
            cout << pair->key << "-> " << pair->val << ", ";
            }
        cout << "]\n";
    }
 }
};

int main(){
    listhashmap map;
    map.put(1, "one");
    map.put(2, "two");
    map.put(3, "three");
    map.put(4, "four");
    map.print();
}