// queue.cpp -- Queue and Customer methods
#include "queue.h"
#include <cstdlib> // (or stdlib.h) for rand()

// 队列的方法 Queue methods
Queue::Queue (int qs) : qsize(qs) // 创建具有qs限制的队列 create queue with a qs limit
{
        front = rear = NULL; // or nullptr
        items = 0;
}
Queue::~Queue()
{
        Node * temp;
        while ( front != NULL )      // 当队列尚未为空时 while queue is not yet empty
        {
                temp = front;        // 保存前项的地址 save address of front item
                front = front->next; // 将指针重置为下一个项目 reset pointer to next item
                delete temp;         // 删除以前的front delete former front
        }
}
bool Queue::isempty () const
{
        return items == 0;
}
bool Queue::isfull () const
{
        return items == qsize;
}
int Queue::queuecount () const
{
        return items;
}
// 将项目添加到队列 Add item to queue
bool Queue::enqueue (const Item & item) // 将项目添加到结尾 add item to end
{
        if ( isfull() )
        {
                return false;
        }
        Node * add = new Node;    // 创建节点 create node
        // 失败时，新抛出std::bad_alloc异常 on failure, new throws std::bad_alloc exception
        add->item = item;         // 设置节点的指针 set node pointers
        add->next = NULL;         // or nullptr;
        items ++;
        if ( front == NULL )      // 如果队列是空的 if queue is empty,
        {
                front = add;      // 将项目放在队首 place item at front
        }
        else
        {
                rear->next = add; // 否则放在后面 else place at rear
        }
        rear = add;               // 后方指向新节点 have rear point to new node
        return true;
}
// 将前一项放入项变量并从队列中删除
// Place front item into item variable and remove from queue
bool Queue::dequeue (Item & item)       // 从队首删除项目 remove item from front
{
        if ( front == NULL )
        {
                return false;
        }
        item = front->item;  // 将项目设置为队列中的第一项 set item to first item in queue
        items --;
        Node * temp = front; // 保存第一项的位置 save location of first item
        front = front->next; // 将front重置为下一个项目 reset front to next item
        delete temp;         // 删除原第一项 delete former first item
        if ( items == 0 )
        {
                rear = NULL;
        }
        return true;
}

// 时间设置为1-3范围内的随机值 time set to a random value in the range 1-3
void Customer::set (long when)
{
        processtime = std::rand() % 3 + 1;
        arrive = when;
}
