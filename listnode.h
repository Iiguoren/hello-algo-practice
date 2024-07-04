struct listnode{
    int value;
    listnode *next;
    listnode(int num) : value(num), next(nullptr) {};
    ~listnode(){};
};

void insert(listnode *n0, listnode *p);
void printlistnode(listnode *head);
listnode *find(listnode *n0, int val);