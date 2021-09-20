#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mu;
std::condition_variable conditionVariable;
bool flag = false; // true 可以读取然后输出
char buffer[11] = {};
std::ifstream input;

void read(char *buffer) {
	input.open("/home/liyunfeng/ab.txt", std::ios::in);
	std::unique_lock<std::mutex> uniqueLock(mu);
        std::cout << "开始读取" << std::endl;
	while (true) // 没有到文件结尾继续读取
	{
		// 进入阻塞状态
		conditionVariable.wait(uniqueLock, [&]{return flag == false;}); // read false wait
		input.get(buffer, 11, EOF);
		flag = true;
		// 唤醒输出线程
		conditionVariable.notify_one(); // 唤醒 put
		if (input.eof()) { // 到文件结尾结束
			break;
		}
	}
}

void put(char *buffer) {
	// 显示数组
	std::unique_lock<std::mutex> uniqueLock(mu);
	while (true) {
		// wait(uniqueLock, true)进入等待
		conditionVariable.wait(uniqueLock, [&]{return flag == true;}); // put false wait
		std::cout << buffer << std::endl; // 输出
		flag = false; // 设置为不可输出
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 休眠一秒
		conditionVariable.notify_one(); // 唤醒read线程
		if (input.eof()) { // 到文件结尾结束
			break;
		}
	}
	std::cout << "读取完毕" << std::endl;

}

int main(void) {
	std::thread th1(read, buffer);
	std::thread th2(put, buffer);
	th1.join();
	th2.join();

	return 0;
}
