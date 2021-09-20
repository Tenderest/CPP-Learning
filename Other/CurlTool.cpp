#include <iostream>
#include <cstring>
#include "CurlTool.h"

int main(void)
{
    ff::Request request;
    
    while (true)
    {
        request.input();

        // // URL 后面没有任何东西就是 GET 不带数据
        // if (request.GET_Filter())
        // {
        //     // url 非空
        //     // 空格，有空格的 URL 可能有错误
        //     // 没有空格
        //     std::cout << "Repeat: " << request.getURL() << std::endl;
        //     if (request.getGetFlag())
        //     {
        //         if (request.getGetDataFlag())
        //         {
        //             // GET 带数据
        //             std::cout << "GET DATA" << std::endl;
        //         }
        //         else if (request.POST_Filter())
        //         {
        //             // POST 请求
        //             std::cout << "POST" << std::endl;
        //             if (request.getPostFlag())
        //             {
        //                 // 其他请求
        //                 std::cout << "OTHER(DELETE ...)" << std::endl;
        //             }
        //         }
        //         else
        //         {
        //             // GET 请求
        //             std::cout << "NORMAL GET" << std::endl;
        //         }
        //     }
        // }
        
        request.conditional();
        request.reset();
    }
    return 0;
    // {"username": "linghu", "password": 123}
}
