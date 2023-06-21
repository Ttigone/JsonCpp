#pragma once

#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <sstream>
namespace css {
  namespace json {

class Json {
public:
    enum Type {
        json_null = 0,
        json_bool,
        json_int,
        json_double,
        json_string,
        json_array,
        json_object
    };

    Json();
    Json(bool value);
    Json(int value);
    Json(double value);
    Json(const char *value);
    Json(const std::string &value);
    Json(Type type);
    Json(const Json &other);

    operator bool();
    operator int();
    operator double();
    operator std::string();

    Json& operator[](int index); 
    void append(const Json &other);

    std::string str() const;
private:
    union Value {
        bool m_bool;
        int m_int;
        double m_double; 
        std::string *m_string;
        std::vector<Json> *m_array;
        std::map<std::string, Json> *m_object;
    };

    Type m_type;
    Value m_value; 
};





  }

}
