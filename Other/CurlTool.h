#include <iostream>
#include <string>
#include <algorithm>

namespace ff {
    class Request
    {
    private:
        std::string* url;
        std::string* post_data;
        // char protocol;
        bool GET_FLAG = false;
        bool GET_DATA_FLAG = false;
        bool POST_FLAG = false;
        
    public:
        Request();
        ~Request();
    private:
        inline bool getGetFlag() { return this->GET_FLAG; }
        inline bool getGetDataFlag() { this->GET_has_data(); return this->GET_DATA_FLAG; }
        inline bool getPostFlag() { return this->POST_FLAG; }
        inline void input_GET(std::string* in_url) { std::getline(std::cin, *in_url); GET_FLAG = true; }
        inline void input_POST_DATA(std::string* in_url) { std::getline(std::cin, *in_url); }
        inline bool input_is_null(std::string* in_url) { return !in_url->length(); }
        inline std::string& getURL() { return *(this->url); }

        bool URL_is_null()
        {
            if (input_is_null(url))
            {
                std::cout << "没有输入 URL !" << std::endl;
                return false;
            }
            return true;
            // return url->length();
        }

        bool URL_space()
        {
            if (url->find(' ') != std::string::npos)
            {
                // 有空格的 URL 可能有错误
                std::cout << "URL 有空格，可能有错误，请检查后重新输入。" << std::endl;
                return false;
            }
            return true;
        }

        bool GET_Filter()
        {
            GET_has_data();
            return this->URL_is_null() && this->URL_space();
        }

        bool POST_Filter()
        {
            POST_has_data();
            return true;
        }

        int trim_get_count(std::string* com)
        {
            int tmp = 0;
            for (auto i = com->begin(); i != com->end(); i++)
            {
                if (*i == '&')
                {
                    tmp ++;
                }
            }
            return tmp;
        }

        int trim_post_count(std::string* com)
        {
            int tmp = 0;
            for (auto i = com->begin(); i != com->end(); i++)
            {
                if (*i == '"')
                {
                    tmp ++;
                }
            }
            return tmp;
        }

        bool send_request(std::string* send_url, std::string* data = nullptr)
        {
            // this->replace_char(send_url, data);
            // 两条数据都需要转义处理
            // &   ""
            char get_char = '&';
            char post_char = '"';
            int position = 0;
            std::string command = "curl ";

            
            if (nullptr == data)
            {
                // GET request
                // & cmd bash 都需要转义
                // int count_get = trim_get_count(send_url);
                // while (count_get)
                // {
                //     position = send_url->find(get_char, position);
                //     send_url->insert(position, "\\", 1);
                //     send_url->insert(position, "\\", 1);
                //     position += 4;
                //     count_get --;
                // }

                // 使用双引号括起来就不用转义 & 了
                command.append("\""); // linux & win
                command.append(*send_url);
                command.append("\""); // linux & win
                std::cout << command.c_str() << std::endl;
                system(command.c_str());
                return true;
            }
            else
            {
                // POST request
                int count_post = trim_post_count(data);
                position = 0;
                while (count_post)
                {
                    position = data->find(post_char, position);
                    data->insert(position, "\\", 1);
                    position+=2;
                    count_post --;
                }
                
                // command.append("-X POST -d '"); // linux
                command.append("-X POST -d \""); // linux & win
                command.append(*data);
                // command.append("' "); // linux
                command.append("\" "); // linux & win
                command.append(*send_url);

                std::cout << data->c_str() << std::endl;
                std::cout << command.c_str() << std::endl;
                system(command.c_str());
                return true;
            }
            return false;
        }
        
        void reset_flag()
        {
            this->GET_FLAG = false;
            this->GET_DATA_FLAG = false;
            this->POST_FLAG = false;
        }

        void GET_has_data()
        {
            if (url->find('?') != std::string::npos) // 不等于特殊标记为找到
            {
                GET_DATA_FLAG = true;
            }
        }

        void POST_has_data()
        {
            if (input_is_null(post_data)) // 空的没有数据
            {
                // std::cout << "没有输入 POST 数据。" << std::endl;
                POST_FLAG = false;
            }
            else
            {
                POST_FLAG = true;
            }
        }


    public:
        inline void reset() { this->reset_flag(); }
        void input()
        {
            std::cout << std::endl;
            std::cout << "输入 URL 地址：";
            std::flush(std::cout);
            input_GET(url);
            std::cout << "输入 body 数据（空表示没有）：";
            std::flush(std::cout);
            input_POST_DATA(post_data);
        }

        void conditional()
        {
            // URL 后面没有任何东西就是 GET 不带数据
            if (this->GET_Filter() && this->POST_Filter())
            {
                // url 非空 没有空格
                // 空格，有空格的 URL 可能有错误
                std::cout << "Repeat: " << *(this->url) << std::endl;
                if (GET_FLAG)
                {
                    if (POST_FLAG)
                    {
                        // 输入了 POST 数据
                        // POST 请求
                        std::cout << "POST" << std::endl;
                        this->send_request(this->url, this->post_data);
                        // if (POST_FLAG)
                        // {
                        //     // 其他请求
                        //     std::cout << "OTHER(DELETE ...)" << std::endl;
                        // }
                        // execute

                        
                    }
                    else if (GET_DATA_FLAG)
                    {
                        // 没有输入 POST 数据

                        // GET 带数据
                        std::cout << "GET DATA" << std::endl;
                        // execute
                        this->send_request(this->url);
                    }
                    else
                    {
                        // GET 请求
                        std::cout << "NORMAL GET" << std::endl;
                        // execute
                        this->send_request(this->url);
                    }
                }
            }
        }
        
    };
    
    Request::Request()
    {
        url = new std::string;
        post_data = new std::string;
    }
    
    Request::~Request()
    {
        delete url;
        delete post_data;
    }
    
}
