#include <iostream>
#include <functional>

using namespace std;

class Timer
{
public:
	Timer();
	Timer(std::function<void()> foo);
	
	void operation();

	void set(std::function<void()> foo);

private:
	std::function<void()> action;
};

Timer::Timer()
{
}

Timer::Timer(std::function<void()> foo)
	: action(foo)
{
}

void Timer::set(std::function<void()> foo)
{
	action = foo;
}

void Timer::operation() {
	if (action) {
		action();
	} else {
		cout << "Function empty" << endl;
	}
}

class Base
{
public:
	Base() : timer([this]()->void{operation();}) {
	}

	void operation() {
		cout << "Base function call from timer" << endl;
	}

//private:
	Timer timer;
};

int main() {
	Base().timer.operation();
	
	return 0;
}
