# include <iostream>
# include <vector>
# include <string>
using namespace std;

struct Pair
{
    public:
    string val;
    int key;

    Pair(int key, string val):val(val), key(key){};
};

class hashopenmap{
    private:
    int entendratio;
    vector<Pair *> buckets;
    int capacity;
    double loadthresh;
    int size;
    Pair *TombStone = new Pair(-1,"-1");
    int extendratio = 2;
    public:
    hashopenmap():size(0), capacity(4), entendratio(2), loadthresh(2.0/3.0){
        buckets.resize(capacity);
    }
    ~hashopenmap(){
        for(Pair *pair : buckets){
            if(pair != TombStone)
                delete pair;
        }
        delete TombStone;
    }

    double loadfactor() {
        return (double)size / capacity;
    }

    int hashfun(int key){
        int index = key % capacity;
        return index;
    }

    int findbucket(int key) {
        int index = hashfun(key);
        int isTombStone = -1;
        while(buckets[index] != nullptr){
            if(buckets[index]->key == key){
                if(isTombStone != -1){
                    buckets[isTombStone] = buckets[index];
                    buckets[index] = TombStone;
                    return isTombStone;
                }
                return index;
            }
            if(buckets[index] == TombStone){
                isTombStone = index;
            }
            index = (index + 1) % capacity;
        }
        return isTombStone == -1 ? index : isTombStone;
    }
    void push(int key, string val){
        if (loadfactor() > loadthresh) {
            extend();
        }
        int index = findbucket(key);
            if(buckets[index]!=nullptr && buckets[index]!= TombStone){
                buckets[index]->val = val;
                return;
            }
            else{
                buckets[index] = new Pair(key, val);
                size++;
                return;
            }
    }
    string get(int key){
        int index = findbucket(key);
        if(buckets[index]!=nullptr && buckets[index]!= TombStone){                
            return buckets[index]->val;
        }
        else
        return "";
    }

    void remove(int key){
        int index = findbucket(key);
        if(buckets[index]!=nullptr && buckets[index]!= TombStone){                
            Pair *p = buckets[index];
            buckets[index] = TombStone;
            delete p;
            size --;
        }
    }

    void extend() {
        vector<Pair *> bucketsTmp = buckets;
        capacity *= extendratio;
        buckets = vector<Pair *>(capacity, nullptr);
        size = 0;
        for (Pair *pair : bucketsTmp) {
            if (pair != nullptr && pair != TombStone) {
                push(pair->key, pair->val);
                delete pair;
            }
        }
    }

    void print() {
        for (Pair *pair : buckets) {
            if (pair == nullptr) {
                cout << "nullptr" << endl;
            } else if (pair == TombStone) {
                cout << "TOMBSTONE" << endl;
            } else {
                cout << pair->key << " -> " << pair->val << endl;
            }
        }
    }
 };

int main(){
    hashopenmap map;
    map.push(1,"1");
    map.push(2,"2");
    map.push(3,"3");
    map.push(4,"4");
    map.push(5,"5");
    map.print();
    map.remove(3);
    map.print();
}
