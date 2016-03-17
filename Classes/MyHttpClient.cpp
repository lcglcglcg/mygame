////
////  MyNetwork.cpp
////  lcglcg
////
////  Created by 李春光 on 16/3/15.
////
////
//
//#include "MyHttpClient.h"
//
//
////void MyHttpClient::get_send()
////{
////    HttpRequest *request = new  HttpRequest();
////    request->setUrl("http://188.188.2.238");
////
////    request->setRequestType(HttpRequest::Type::GET);
////    request->setResponseCallback(this, httpresponse_selector(MyNetwork::post_recv));
////
////    HttpClient::getInstance()->send(request);
////    request->release();
////}
//
//void MyHttpClient::post_send(const char *hero_name, int hero_index, int hero_x, int hero_y, int hero_status, int map_x, int map_y)
//{
//    HttpRequest* request = new HttpRequest();
//    request->setUrl("http://188.188.2.238");
//    
//    request->setRequestType(HttpRequest::Type::POST);
//    request->setResponseCallback(this, httpresponse_selector(::MyHttpClient::post_recv));
//    
//    char buffer[128];
//    int size = sprintf(buffer, "%s,%d,%d,%d,%d,%d,%d", hero_name, hero_index, hero_x, hero_y, hero_status, map_x, map_y);
//    request->setRequestData(buffer, size);
//    
//    HttpClient::getInstance()->send(request);
//    request->release();
//}
//
//void MyHttpClient::post_recv(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response)
//{
//    
//    if (!response) {
//        return;
//    }
//    
//    if (!response->isSucceed()) {
//        return;
//    }
//    
//    std::vector <char> *p_str = response->getResponseData();
//    std::string buffer(p_str->begin(), p_str->end());
//    
//    // fprintf(stdout, "%s\n", buffer.c_str());
//    json_parse(buffer.c_str());
//}
//
//void MyHttpClient::json_parse(const char *buffer)
//{
//    //json 文档
//    rapidjson::Document _doc;
//    _doc.Parse(buffer);
//    
//    if(!_doc.IsObject())
//        return;
//    
//    //是否有此成员
//    if(!_doc.HasMember("entities"))
//        return;
//    
//    // 通过[]取成员值,再根据需要转为array,int,double,string
//    const rapidjson::Value &pArray = _doc["entities"];
//    
//    //是否是数组
//    if(!pArray.IsArray())
//        return;
//    
//    for (rapidjson::SizeType i = 0; i < pArray.Size(); i++) {
//        
//        const rapidjson::Value &p = pArray[i];
//        if(p.HasMember("entity")) {
//            
//            const rapidjson::Value &valueEnt = p["entity"];
//            if(valueEnt.HasMember("TapOpposite") && valueEnt.HasMember("Interval") && valueEnt.HasMember("BallNum")) {
//                
//                const rapidjson::Value &tapOpposite = valueEnt["TapOpposite"];
//                int tapOp = tapOpposite.GetInt();      //得到int值
//                
//                const rapidjson::Value &interval = valueEnt["Interval"];
//                float inter = interval.GetDouble();  //得到float,double值
//                
//                const rapidjson::Value &ballNum = valueEnt["BallNum"];
//                int ball = ballNum.GetInt();      //得到int值
//                
//                printf("[TapOpposite=%d][Interval=%f][BallNum=%d]\n", tapOp, inter, ball);
//            }
//            
//        } else {
//            
//            return;
//        }
//        
//    }
//}
//
//
//
//
//
//
