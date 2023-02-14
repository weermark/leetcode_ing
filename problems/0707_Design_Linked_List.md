# 707. Design Linked List

[leetcode題目連結](https://leetcode.com/problems/design-linked-list/)

定義: 設計鏈結類別，提供幾個函式。

## 解題

### 想法一:

做法: 單向鏈結，虛擬頭。

程式:

```c++
// success

class MyNode{
private:
    int val;
    MyNode* next;
    friend class MyLinkedList;
public:   
    MyNode(int val){
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList {
private:
    MyNode* dummyHead;
    int size;

    bool outOfList(int index){
        return index > size - 1;
    }
    
    MyNode* findNode(int index){
        ++index;
        MyNode* node = dummyHead;
        for(; index > 0; --index)
            node = node->next;
        return node;
    }
    
    void insertNode(MyNode* prev, MyNode* newNode){
        newNode->next = prev->next;
        prev->next = newNode;
    }
    
    void deleteNode(MyNode* prev, MyNode* nodeToDelete){
        prev->next = nodeToDelete->next;
        delete nodeToDelete;
    }

public:
    MyLinkedList() {
        dummyHead = new MyNode(-1);
        size = 0;
    }

    // time:  O(n)
    // space: O(1)
    void printList(){
        for(MyNode* cur = dummyHead->next; cur != NULL; cur = cur->next){
            cout << cur->val << " ";
        }
        cout << endl;
    }

    // time:  O(n)
    // space: O(1)
    int get(int index) {
        if(outOfList(index))    return -1;
        
        MyNode* current = findNode(index);
        return current->val;
    }
    
    // time:  O(1)
    // space: O(1)
    void addAtHead(int val) {
        MyNode* newNode = new MyNode(val);
        insertNode(dummyHead, newNode);
        ++size;
    }
    
    // time:  O(n)
    // space: O(1)
    void addAtTail(int val) {
        MyNode* newNode = new MyNode(val);
        // find the last Node
        MyNode* lastNode = findNode(size - 1);
        lastNode->next = newNode;
        ++size;
    }
    
    // time:  O(n)
    // space: O(1)
    void addAtIndex(int index, int val) {
        // index can before last ndoe
        if(outOfList(index) && index != size)    return;
        
        MyNode* newNode = new MyNode(val);
        // the node's index before target is index - 1
        MyNode* prev = findNode(index - 1);
        insertNode(prev, newNode);
        ++size;
    }
    
    // time:  O(n)
    // space: O(1)
    void deleteAtIndex(int index) {
        if(outOfList(index))    return;
        
        // the node's index before target is index - 1
        MyNode* prev = findNode(index - 1);
        deleteNode(prev, prev->next);
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

省思: 

注意以下三種情況
1. 鏈結為空
2. 加入的節點在頭
3. 加入的節點在尾
鑒於以上三點，可用虛擬頭避免錯誤。另外，使用 size 能減少很多例外處理的程式。