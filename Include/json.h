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
    
    void operator =(const Json &other);
    bool operator ==(const Json &other);
    bool operator !=(const Json &other);

    Json& operator [](int index); 
    void append(const Json &other);

    Json& operator [](const char *key); 
    Json& operator [](const std::string &key); 

    std::string str() const;
    void copy(const Json &other);
    void clear();

    typedef std::vector<Json>::iterator iterator;
    iterator begin() {
      return m_value.m_array->begin();
    }
    iterator end() {
      return m_value.m_array->end();
    }

    bool is_null() const { return m_type == json_null; }
    bool is_bool() const { return m_type == json_bool; }
    bool is_int() const { return m_type == json_int; }
    bool is_double() const { return m_type == json_double; }
    bool is_string() const { return m_type == json_array; }
    bool is_array() const { return m_type == json_array; }
    bool is_object() const { return m_type == json_bool; }

    bool as_bool() const;
    int as_int() const;
    double as_double() const;
    std::string as_string() const;

    bool has(int index);
    bool has(const char *key);
    bool has(const std::string &key);

    void remove(int index);
    void remove(const char *key);
    void remove(const std::string &key);

    void parse(const std::string &str);

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
