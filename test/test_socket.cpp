#include <iostream>
#include "miruy.h"

using namespace miruy;

void test01()
{
    Address::ptr addr = Address::LookupAny("www.baidu.com:80");
    std::cout << addr->toString() << std::endl;

    Socket::ptr sock = Socket::CreateTCP(addr);

    if (!sock->connect(addr)) {
        std::cout << "connect error" << std::endl;
        return;
    }

    std::cout << sock->toString() << std::endl;

    if (sock->send("GET / HTTP/1.0\r\n\r\n", 20) < 0) {
        std::cout << "send error" << std::endl;
        return;
    }

    char* buf = new char[10240];
    if (sock->recv(buf, 10240) < 0) {
        std::cout << "recv error" << std::endl;
        return;
    }
    std::cout << std::endl << buf << std::endl;
    delete[] buf;
}

int main()
{
    // test01();
    IOManager iom;
    iom.schedule(test01);
    return 0;
}