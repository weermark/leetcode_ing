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
    int _val;
    MyNode* _next;
    friend class MyLinkedList;
public:   
    MyNode(int val){
        this->_val = val;
        _next = NULL;
    }
};

class MyLinkedList {
private:
    MyNode* _dummyHead;
    int _size;

    bool outOfList(int index){
        return index > _size - 1;
    }
    
    MyNode* findNode(int index){
        ++index;
        MyNode* node = _dummyHead;
        for(; index > 0; --index)
            node = node->_next;
        return node;
    }
    
    void insertNode(MyNode* prev, MyNode* newNode){
        newNode->_next = prev->_next;
        prev->_next = newNode;
    }
    
    void deleteNode(MyNode* prev, MyNode* nodeToDelete){
        prev->_next = nodeToDelete->_next;
        delete nodeToDelete;
    }

public:
    MyLinkedList() {
        _dummyHead = new MyNode(-1);
        _size = 0;
    }

    // time:  O(n)
    // space: O(1)
    void printList(){
        for(MyNode* cur = _dummyHead->_next; cur != NULL; cur = cur->_next){
            cout << cur->_val << " ";
        }
        cout << endl;
    }

    // time:  O(n)
    // space: O(1)
    int get(int index) {
        if(outOfList(index))    return -1;
        
        MyNode* current = findNode(index);
        return current->_val;
    }
    
    // time:  O(1)
    // space: O(1)
    void addAtHead(int val) {
        MyNode* newNode = new MyNode(val);
        insertNode(_dummyHead, newNode);
        ++_size;
    }
    
    // time:  O(n)
    // space: O(1)
    void addAtTail(int val) {
        MyNode* newNode = new MyNode(val);
        // find the last Node
        MyNode* lastNode = findNode(_size - 1);
        lastNode->_next = newNode;
        ++_size;
    }
    
    // time:  O(n)
    // space: O(1)
    void addAtIndex(int index, int val) {
        // index can before last ndoe
        if(outOfList(index) && index != _size)    return;
        
        MyNode* newNode = new MyNode(val);
        // the node's index before target is index - 1
        MyNode* prev = findNode(index - 1);
        insertNode(prev, newNode);
        ++_size;
    }
    
    // time:  O(n)
    // space: O(1)
    void deleteAtIndex(int index) {
        if(outOfList(index))    return;
        
        // the node's index before target is index - 1
        MyNode* prev = findNode(index - 1);
        deleteNode(prev, prev->_next);
        --_size;
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