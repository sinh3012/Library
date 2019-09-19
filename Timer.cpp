#include <iostream>
#include <functional>

using namespace std;

class Timer
{
public:
	Timer();
	Timer(std::function<void()> f);
	
	void operation();

	void set(std::function<void()> f);

private:
	std::function<void()> action;
};

Timer::Timer()
	: action()
{
}

Timer::Timer(std::function<void()> f)
	: action(f)
{
}

void Timer::set(std::function<void()> f)
{
	action = f;
}

void Timer::operation() {
	if (action) {
		action();
	} else {
		cout << "Functiom empty" << endl;
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
