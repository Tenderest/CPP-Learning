#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
		fstream 读写操作
		ofstream 写操作
		ifstream 都操作
*/
void Fstream() {
	// fstream os("test.txt",ios::in | ios::out);
	fstream  os;
	os.open("test.txt", ios_base::out | ios_base::in);	
	if(!os.is_open()) {
		cout << "file open error" << endl;
		return;
	}
	
	os << "**************" << endl;
	os << "* 姓名: 李明 *" << endl;
	os << "* 年龄: 18   *" << endl;
	os << "**************" << endl;
	
	string buf;
	os.seekp(0);
	while(getline(os, buf)) {
		// cout << "not eof" << endl;
		std::cout << buf << endl;
	}
	
	os.close();
}

void test() {
	fstream os;
	char buffer[BUFSIZ];
	os.open("test.txt",ios::out); // 以写入方式打开文件
	
	if (!os.is_open()) {
		cout << "File open error !" << endl;
		exit(1);
	}
	os << "Hello world" << endl; 
	os.close();
	ifstream ifos;
	ifos.open("test.txt",ios::out);
	if(!ifos.is_open()) {
		cout << "File open error !" << endl;
		exit(1);
	}
	
	while(!ifos.eof()) {
		ifos.getline(buffer,100);
		cout << buffer << endl;
	}
	ifos.close();

	
}

void terst() {
	fstream os;
	char buf[BUFSIZ] ;
	os.open("test.txt",ios::out | ios::in);
	if(!os.is_open()) {
		cout << "open error" << endl;
		return;
	}
	
	
	os << "**************" << endl;
	os << "* 姓名: 李明 *" << endl;
	os << "* 年龄: 18   *" << endl;
	os << "**************" << endl;
	
	os.clear();
}

void strin() {
	string buf;
	fstream os;
	os.open("test.txt",ios::out | ios::in);
	
	if(!os.is_open()) {
		cout << "open error" << endl;
		return;
	}
	
	while(getline(os,buf)) {
		cout << buf << endl;
	}
	os.close();
	
}

void ReadWrite() {
	ofstream outfile("test.txt",ios::out);
	ifstream readfile("test.txt",ios::in);

	if(!readfile.is_open()) {
		cout << "open file error" << endl;
		return;
	}
	
	
	outfile << "hello world" << endl;

	
	string buf;
	while(getline(readfile,buf)) {
		cout << buf << endl;
	}
	//outfile.close() ;
	readfile.close();
}


int main(int argc,char *argv[]) {
	Fstream();
	cout << endl << "-------------------" << endl << endl;
	return 0;
}
