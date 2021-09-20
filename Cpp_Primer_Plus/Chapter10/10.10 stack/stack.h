// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;
class Stack
{
private:
        enum {MAX = 10}; // 类特有常数 constont specific to class
        Item items[MAX]; // 将堆栈物品 holds stack items
        int top; // 最上层项目的索引 index for top stack item
public:
        Stack();
        bool isempty () const;
        bool isfull () const;
        // 如果堆栈已经满了，push()返回false，否则返回true push() returns false if stack already full, true otherwise
        bool push (const Item & item); // 将项目添加到堆栈 add item to stack
        // 如果堆栈已经为空，则pop()返回false，否则返回true pop() returns false if stack already empty, true otherwise
        bool pop (Item & item); // 弹出顶部到项目 pop top into item
};

#endif
