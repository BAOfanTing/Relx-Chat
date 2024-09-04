#ifndef SINGLETON_H
#define SINGLETON_H
#include <global.h>

// 单例模式模板类
template <typename T>
class Singleton {
protected:
    // 私有构造函数，防止外部实例化
    Singleton() = default;

    // 删除拷贝构造函数，防止拷贝
    Singleton(const Singleton<T>&) = delete;

    // 删除赋值操作符，防止赋值
    Singleton& operator=(const Singleton<T>& st) = delete;

    // 静态成员变量，用于保存单例的实例
    static std::shared_ptr<T> _instance;
public:
    // 获取单例实例的静态成员函数
    static std::shared_ptr<T> GetInstance(){
        // 使用 std::once_flag 和 std::call_once 保证线程安全地初始化实例
        static std::once_flag s_flag;
        std::call_once(s_flag,[&](){
            // 初始化单例实例
            _instance = std::shared_ptr<T>(new T);
        });

        return _instance;
    }
    // 打印单例实例的地址
    void PrintAddress(){
        std::cout << _instance.get()<< std::endl;
    }

    ~Singleton(){
        std::cout << "this is singleton destruct"<< std::endl;
    }
};

//由于 _instance 是一个静态成员变量，它必须在类外定义。
template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;












#endif // SINGLETON_H
