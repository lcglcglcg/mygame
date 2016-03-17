//
//  MyNetwork.hpp
//  lcglcg
//
//  Created by 李春光 on 16/3/15.
//
//

#ifndef MyNetwork_hpp
#define MyNetwork_hpp

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "network/SocketIO.h"

USING_NS_CC;
using namespace network;

class MyNetwork : public SocketIO::SIODelegate
{
public:
    MyNetwork();
    // virtual bool init();
    // CREATE_FUNC(MyNetwork);
    
    //socket连接时调用
    void onConnect(SIOClient* client);
    
    //收到数据时调用
    void onMessage(SIOClient* client, const std::string& data);
    
    //连接错误或接收到错误信号时调用
    void onError(SIOClient* client, const std::string& data);
    
    //socket关闭时调用
    void onClose(SIOClient* client);
    
    SIOClient *client;
};

#endif /* MyNetwork_hpp */




