#include "Server.h"
#include <iostream>

int main() {
    muduo::net::EventLoop eventLoop;
    muduo::net::InetAddress address(6789);
    Server server(&eventLoop, address, "Server");
    eventLoop.loop();
    return 0;
}
