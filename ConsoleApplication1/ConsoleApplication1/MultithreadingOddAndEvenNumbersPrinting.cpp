#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable cv;
int counter = 1;
int maxVal = 100;
void printOdd() {
	while (counter < maxVal) {
		unique_lock<mutex> lock(m);
		cv.wait(lock, [] {return counter % 2 == 1; });
		cout << "Odd: " << counter++ << endl;
		//++counter;
		lock.unlock();
		cv.notify_one();
	}

}

void printEven() {
	while (counter < maxVal) {
		unique_lock<mutex> lock(m);
		cv.wait(lock, [] {return counter % 2 == 0; });
		cout << "Even: " << counter++ << endl;
		//++counter;
		lock.unlock();
		cv.notify_one();
	}
}
atomic<int> count1 = 0;
mutex mtx;
void shared_increment() {
	for (int i = 0; i < 100; i++) {
		mtx.lock();
		cout << this_thread::get_id<<":" << count1++ << endl;
		
		mtx.unlock();
	}
}
//int main() {
//	/*thread t1(printOdd);
//	thread t2(printEven);*/
//	thread t1(shared_increment);
//	thread t2(shared_increment);
//	t1.join();
//	t2.join();
//	cout << "\nCount:" << count1;
//	return 0;
//}
