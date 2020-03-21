// placenew2.cpp -- new, placement new, no delete
#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class JustTesting
{
        private:
                string words;
                int number;
        public:
                JustTesting (const string & s = "JustTesting", int n = 0)
                {
                        words = s;
                        number = n;
                        cout << words << " constructed\n";
                }
                ~JustTesting()
                {
                        cout << words << " destructoyed\n";
                }
                void Show () const
                {
                        cout << words << ", " << number << endl;
                }
};

int main(void)
{
        char * buffer = new char[BUF];      // 获得一块内存 get a brock of memory
        JustTesting * pc1, * pc2;
        pc1 = new (buffer) JustTesting;     // 将对象放入缓冲区 place object in buffer
        pc2 = new JustTesting("Heap1", 20); // 将对象放置在堆中 place object on heap

        cout << "Memory block addresses:\n" << "buffer: " << (void *) buffer
             << "    heap: " << pc2 << endl;
        cout << "Memory contents:\n";
        cout << pc1 << ": ";
        pc1->Show();
        cout << pc2 << ": ";
        pc2->Show();

        JustTesting * pc3, * pc4;
        // 修复放置新位置 fix placement new location
        pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Bad Idea", 6);
        pc4 = new JustTesting("Heap2", 10);

        cout << "Memory contents:\n";
        cout << pc3 << ": ";
        pc3->Show();
        cout << pc4 << ": ";
        pc4->Show();

        delete pc2;          // 释放Heap1 free Heap1
        delete pc4;          // 释放Heap2 free Heap2
        // 显式销毁放置新对象 explicitly destroy placement new objects
        pc3->~JustTesting(); // 销毁pc3指向的对象 destroy object pointed to by pc3
        pc1->~JustTesting(); // 销毁pc1指向的对象 destroy object pointed to by pc1
        delete buffer;       // 释放缓冲区 free buffer
        cout << "Done!\n";
        return 0;
}
