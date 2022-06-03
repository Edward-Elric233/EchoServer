// Copyright(C), Edward-Elric233
// Author: Edward-Elric233
// Version: 1.0
// Date: 2022/6/2
// Description: 
#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "muduo/net/TcpServer.h"
#include "muduo/net/EventLoop.h"
#include "muduo/net/InetAddress.h"
#include "muduo/net/TcpConnection.h"
#include "muduo/net/Buffer.h"
#include "muduo/base/Timestamp.h"
#include "utils.h"

#include <iostream>
#include <string>

class Server {
    muduo::net::TcpServer tcpServer_;
public:
    Server(muduo::net::EventLoop *eventLoop,
           const muduo::net::InetAddress &listenAddr,
           const std::string &nameArg) : tcpServer_(eventLoop, listenAddr, nameArg) {
        tcpServer_.setConnectionCallback(std::bind(&Server::onConnectionCallback, this, std::placeholders::_1));
        tcpServer_.setMessageCallback(std::bind(&Server::onMeesageCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
        tcpServer_.start();
    }

    void onConnectionCallback(const muduo::net::TcpConnectionPtr &connPtr) {

    }

    void onMeesageCallback(const muduo::net::TcpConnectionPtr& connPtr,
                           muduo::net::Buffer* buffer,
                           muduo::Timestamp timestamp) {
        std::string receive_string = buffer->retrieveAllAsString();
        utils::print(timestamp.toFormattedString(), "from", connPtr->localAddress().toIpPort(), ":", receive_string);

        connPtr->send(receive_string.data(), receive_string.size());
    }
};


#endif //SERVER_SERVER_H
