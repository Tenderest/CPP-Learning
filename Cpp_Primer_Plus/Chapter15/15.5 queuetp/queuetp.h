// queuetp.h -- queue template with a nested class
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class Item>
class QueueTP
{
private:
	enum {Q_SIZE = 10};
	// Node is a nested class definition Node是一个嵌套的类定义
	class Node
	{
	public:
		Item item;
		Node * next;
		Node (const Item & i) : item(i), next(0) {}
	};
	Node * front;    // pointer to front of Queue 指向队列前面的指针
	Node * rear;     // pointer to rear of Queue 指向队列后面的指针
	int items;       // current number of items in Queue 队列中的当前项目数
	const int qsize; // maximum number of items in Queue 队列中的最大项目数
	QueueTP (const QueueTP & q) : qsize(0) {}
	QueueTP & operator= (const QueueTP & q) {return *this;}

public:
	QueueTP (int qs = Q_SIZE);
	~QueueTP ();
	bool isempty () const
	{
		return items == 0;
	}
	bool isfull () const
	{
		return items == qsize;
	}
	int queuecount () const
	{
		return items;
	}
	bool enqueue (const Item & item); // add item to end
	bool dequeue (Item & item);     // remove item from front
};

// QueueTP methods
// QueueTP 方法
template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP ()
{
	Node * temp;
	while (front != 0)       // while queue is not yet empty 当队列尚未为空时
	{
		temp = front;        // save address of front item 保存前项的地址
		front = front->next; // reset pointer to next item 将指针重置为下一个项目
		delete temp;         // delete former front 删除前一个front
	}
}

// Add item to queue
// 将项目添加到队列
template <class Item>
bool QueueTP<Item>::enqueue(const Item &item)
{
	if (isfull())
	{
		return false;
	}
	Node * add = new Node(item); // create node 创建节点
	// on failure, new throws std::bad_alloc exception
	// 失败时，new抛出std::bad_alloc异常
	items ++;
	if (front == 0)  // if queue is empty, 如果队列为空，
	{
		front = add; // place item at front 则将项目放在front
	}
	else
	{
		rear->next = add; // else place at rear 否则放在后面，
	}
	rear = add;           // have rear point to new node 有后点到新节点
	return true;
}

// Place front item into item variable and remove from queue
// 将前面的项放入项变量中并从队列中移除
template <class Item>
bool QueueTP<Item>::dequeue(Item &item)
{
	if (front == 0)
	{
		return false;
	}
	item = front->item;  // set item to first item in queue 将项目设置为队列中的第一项
	items --;
	Node * temp = front; // save location of first item 保存第一项的位置
	front = front->next; // reset front to next item 将front重置为下一个项目
	delete temp;         // delete former first item 删除先前的第一项
	if (items == 0)
	{
		rear = 0;
	}
	return true;
}

#endif