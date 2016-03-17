//
//  MyNetwork.cpp
//  lcglcg
//
//  Created by 李春光 on 16/3/15.
//
//

#include "MyNetwork.h"

MyNetwork::MyNetwork()
{
    
    client = SocketIO::connect("127.0.0.1:8888", *this);
    
    
    // client->setTag("init socket");
    //4.初始化的时候设置一个监听器：使用on监听事件和获取接收到的数据
//    
//    client->on("loginresult",[=](SIOClient *client,const std::string &data) {
//        
//        //使用C++匿名函数实现
//        log("login result is :%s",data.c_str());
//    });
//    
    // client->send("hello socket.io");
    client->emit("login","[{\"name\":\"myname\",\"pwd\":\"mypwd\"}]");
}

//bool MyNetwork::init()
//{
//
//    printf("MyNetwork::init2\n");
//    return true;
//}

//socket连接时调用
void MyNetwork::onConnect(SIOClient* client)
{
    log("onConnect");
    log("%s connect",client->getTag());
}

//收到数据时调用
void MyNetwork::onMessage(SIOClient* client, const std::string& data)
{
    log("onMessage");
    log("%s received content is:%s",client->getTag(),data.c_str());
}

//连接错误或接收到错误信号时调用
void MyNetwork::onError(SIOClient* client, const std::string& data)
{
    log("onClose");
    log("%s is closed",client->getTag());
}

//socket关闭时调用
void MyNetwork::onClose(SIOClient* client)
{
    
    log("onError");
    // log("%s error is:%s",client->getTag(),data.c_str());
}









