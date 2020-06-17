// stacktp.h -- a stack template
#ifndef STACKTP_H_
#define STACKTP_H_

template <class Type>

class Stack
{
        private:
                enum {MAX = 10}; // constant specific to class 类特有常数
                Type items[MAX]; // hold stack items 保存堆栈项
                int top;         // index for top stack item 顶部堆栈项的索引
        public:
                Stack ();
                bool isempty ();
                bool isfull ();
                bool push (const Type & item); // add item to stack 将项目添加到堆栈
                bool pop (Type & item);        // pop top into item 弹出顶部到item变量
};

template <class Type>
Stack<Type>::Stack ()
{
        top = 0;
}

template <class Type>
bool Stack<Type>::isempty ()
{
        return top == 0;
}

template <class Type>
bool Stack<Type>::isfull ()
{
        return top == MAX;
}

template <class Type>
bool Stack<Type>::push (const Type & item)
{
        if ( top < MAX )
        {
                items[top ++] = item;
                return true;
        }
        else
        {
                return false;
        }
}

template <class Type>
bool Stack<Type>::pop (Type & item)
{
        if ( top > 0 )
        {
                item = items[-- top];
                return true;
        }
        else
        {
                return false;
        }
}

#endif
