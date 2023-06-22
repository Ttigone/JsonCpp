#include "json.h"
#include <iostream>
using namespace css::json;

using std::cout;
using std::endl;

int main()
{
    // Json v1;
    // Json v2 = true;
    // Json v3 = 123;
    // Json v4 = 1.23;
    // Json v5 = "Hello world";

    // bool b = v2;
    // int i = v3;
    // double f = v4;
    // const std::string & s = v5;
    // std::cout << b << std::endl << i << std::endl << f << std::endl << s << std::endl;
    Json arr;
    arr[0] = true;
    arr[1] = 123;

    arr.append(1.23);
    arr.append("hello world");
    
    // cout << arr.str() << endl;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << it->str() << endl;
    }

    // bool b = arr[0];
    // int i = arr[1];
    // double f = arr[2];
    // const std::string &s = arr[3];   

    // Json obj;
    // // 把  true 存储到 string键值 为 "bool"
    // obj["bool"] = true;    // json_object 是 map 类型 第一个 string 是索引值, 第二个是 Json 格式类型
    // obj["int"] = 123;
    // obj["double"] = 1.23;
    // obj["str"] = "hello world";
    // cout << obj.str() << endl;

    

}