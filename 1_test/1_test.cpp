// 1_test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Thread.h"

using namespace OpenThreads;


class MyThread: public Thread
{
public:
	virtual void run();
protected:
private:
};

void MyThread::run()
{
	Sleep(2000);
	printf("Out!!!\n");
}

int main()
{

	MyThread thread;

	thread.start();

	printf("sadfsf\n");

	//thread.detach();
	thread.join();


	try
	{
		throw int(1);
		printf("33333\n");
	}
	catch (int e)
	{
		printf("11111\n");
	}

	printf("22222\n");
    return 0;
}

