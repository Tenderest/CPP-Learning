// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
// 此队列将包含客户项目 This queue will contain Customer items

class Customer
{
        private:
                long arrive;     // 客户到达时间 arrival time for customer
                int processtime; // 客户的处理时间 processing time for customer
        public:
                Customer () { arrive = processtime = 0; }
                void set(long when);
                long when () const { return arrive; }
                int ptime () const { return processtime; }
};

typedef Customer Item;

class Queue
{
        private:
                // 类作用域定义 class scope definitions
                // Node是此类的局部嵌套结构定义
                // Node is a nested structure definition local to this class
                struct Node
                {
                        Item item;
                        struct Node * next;
                };
                enum { Q_SIZE = 10 };
                // 私有类成员 private class members
                Node * front;    // 指向队列前端的指针 pointer to front of Queue
                Node * rear;     // 指向队列尾部的指针 pointer to rear of Queue
                int items;       // 队列中的当前项目数 current number of items in Queue
                const int qsize; // 队列中的最大项目数 maximum number of items in Queue
                // 防止公共复制的抢先定义 preemptive definitions to prevent public copying
                Queue (const Queue & q) : qsize(0) { }
                Queue & operator= (const Queue & q) { return *this; }
        public:
                Queue (int qs = Q_SIZE); // 创建具有qs限制的队列 create queue with a qs limit
                ~Queue();
                bool isempty () const;
                bool isfull () const;
                int queuecount () const;
                bool enqueue (const Item & item); // 将项目添加到结尾 add item to end
                bool dequeue (Item & item);       // 从前面删除项目 remove item from front
};

#endif
