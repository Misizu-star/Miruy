#include "miruy.h"
#include <vector>
#include <iostream>

using namespace miruy;

std::string StateToString(State state)
{
    switch (state) {
        case State::INIT: return "INIT";
        case State::HOLD: return "HOLD";
        case State::EXEC: return "EXEC";
        case State::TERM: return "TERM";
        case State::READY: return "READY";
        case State::EXCPT: return "EXCPT";
        default: return "UNKNOW";
    }
}

void fun2()
{
    Fiber::ptr f2(new Fiber([]() { std::cout << "f2 exec" << std::endl; }));
    f2->swapIn();
    std::cout << "f2 exit" << std::endl;
}

void fun()
{
    sleep(1);
    // LOG_INFO(LOGGER("system"), "in fiber " + std::to_string(Fiber::GetId()));
    Fiber::YieldToRead();
    sleep(1);
}

void test_fiber()
{
    Fiber::ptr f1(new Fiber(fun2));
    f1->swapIn();
    std::cout << "f1 exit" << std::endl;
}

void test_scheduler()
{
    Scheduler sc(4);
    sc.setName("main");
    sc.start();
    std::vector<std::function<void()>> tasks;
    for (int i = 0; i < 10; ++i)
        tasks.push_back(fun);
        sc.schedule(tasks.begin(), tasks.end());
    sc.stop();
}

void test_sleep()
{
    IOManager iom(2, "main");
    iom.schedule([](){
        LOG_INFO(LOGGER("system"), "ready to sleep 5s");
        sleep(5);
        LOG_INFO(LOGGER("system"), "already sleep");
    });

    iom.schedule([](){
        LOG_INFO(LOGGER("system"), "ready to sleep 6s");
        sleep(6);
        LOG_INFO(LOGGER("system"), "already sleep");
    });
    
    iom.stop();
}

int main()
{
    Config::LoadFromYaml("./log.yaml");

    // swapcontext()内部错误，暂时为实现协程内使用协程
    // test_fiber(); 

    LOG_INFO(LOGGER("system"), "start");
    // test_scheduler();
    test_sleep();
    LOG_INFO(LOGGER("system"), "exit");

    return 0;
}