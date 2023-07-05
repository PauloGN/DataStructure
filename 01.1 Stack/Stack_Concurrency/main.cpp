#include "Stack.h"

std::mutex m;

void AccessAndDelete(P_Stack<int>& rhs)
{
	m.lock();
	if (!rhs.empty())
	{
		int value = rhs.top();
		std::cout << "Value: " << value << std::endl;
		rhs.pop();
	}
	m.unlock();
}


int main()
{
	P_Stack<int> myStack;

	myStack.push(10);

	std::thread thr_1(AccessAndDelete, std::ref(myStack));
	std::thread thr_2(AccessAndDelete, std::ref(myStack));

	thr_1.join();
	thr_2.join();

	return 0;
}




