#include <string>
#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "miruy.h"

using namespace miruy;

int sock = 0;

void test_fiber()
{
    sock = ::socket(AF_INET, SOCK_STREAM, 0);
    std::cout << sock << std::endl;
    int ret = ::fcntl(sock, F_SETFL, O_NONBLOCK);

    sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = ::htons(443);
    inet_pton(AF_INET, "183.232.231.174", &sin.sin_addr.s_addr);

    if (::connect(sock, (const sockaddr*)&sin, sizeof(sin))) {
        IOManager::GetThis()->addEvent(sock, Event::READ, []() {
            LOG_INFO(LOGGER("system"), "read callback!");  //
            ;
        });
        IOManager::GetThis()->addEvent(sock, Event::WRITE, []() {
            LOG_INFO(LOGGER("system"), "write callback!");
            // IOManager::GetThis()->cancelEvent(sock, Event::READ);
            // IOManager::GetThis()->cancelAll(sock);
            IOManager::GetThis()->cancelAll(sock);
            close(sock);
        });
        std::cout << "closed" << std::endl;
    } else {
        LOG_INFO(LOGGER("system"), "connect error");
    }
}

void test01()
{
    IOManager iom(1, "main");
    iom.schedule(test_fiber);
}

void test_timer()
{
    IOManager iom(2, "main");
    Timer::ptr t1 = iom.addTimer(
        1000,
        [&t1]() {
            LOG_INFO(LOGGER("system"), "hello timer");
            static int i = 0;
            if (i++ == 5)
                t1->reset(2000, true);
            if (i == 7)
                t1->cancel();
        },
        true);
}

void test_hook()
{
    IOManager iom(1, "main");
    iom.schedule([]() {
        LOG_INFO(LOGGER("system"), "ready sleep");
        ::sleep(2);
        LOG_INFO(LOGGER("system"), "sleep 2");
    });

    iom.schedule([]() {
        LOG_INFO(LOGGER("system"), "ready sleep");
        ::sleep(3);
        LOG_INFO(LOGGER("system"), "sleep 3");
    });
}

void test_sock()
{
    miruy::set_hook_enable(true);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(80);
    inet_pton(AF_INET, "183.232.231.174", &sin.sin_addr.s_addr);

    LOG_INFO(LOGGER("system"), "begin connect");

    int ret = connect(sock, (const sockaddr*)&sin, sizeof(sin));
    if (ret) {
        LOG_ERROR(LOGGER("system"), "connect failed ret = " + std::to_string(ret));
        close(sock);
        return;
    }
    const char data[] = "GET / HTTP/1.0\r\n\r\n";
    ret = send(sock, data, strlen(data), 0);
    if (ret < 0) {
        LOG_ERROR(LOGGER("system"), "send msg error");
        close(sock);
        return;
    }
    LOG_INFO(LOGGER("system"), "send ret = " + std::to_string(ret));

    char* buff = new char[20480];
    memset(buff, 0, 20480);
    ret = recv(sock, buff, 20480, 0);
    if (ret < 0) {
        LOG_ERROR(LOGGER("system"), "recv error, ret = " + std::to_string(ret));
        close(sock);
        return;
    }
    // LOG_INFO(LOGGER("system"), buff);
    std::cout << buff << std::endl;
    delete[] buff;
    close(sock);
}

int main()
{
    Config::LoadFromYaml("./log.yaml");
    std::cout << "start" << std::endl;
    // test_hook();
    // test_sock();
    miruy::IOManager iom;
    iom.schedule(test_sock);
    std::cout << "end" << std::endl;
    return 0;
}
