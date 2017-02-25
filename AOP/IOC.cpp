/*************************************************************************
	> File Name: IOC.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月24日 星期五 17时54分57秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <functional>
#include <boost/any.hpp>

using namespace std;

class IocContainer
{
public:
    IocContainer(void) {  }
    ~IocContainer(void) {  }

    template<class T, typename Depend>
    void RegisterType(const std::string& strKey)  
    {
        //通过闭包擦除了参数类型
        std::function<T* ()> function = []{ return new T(new Depend()); };
        RegisterType(strKey, function);
    }

    template<class T>
    T* Resolve(const std::string& strKey)
    {
        if(m_creatorMap.find(strKey) == m_creatorMap.end()) {
            return nullptr;
        } 
        boost::any resolver = m_creatorMap[strKey];
        std::function<T* ()> function = resolver.boost::any_cast<std::function<T* ()> >();

        return function();
    }


    template<class T>
    std::shared_ptr<T> ResolveShared(const std::string& strKey)
    {
        T* t = Resolve<T>(strKey);
        
        return std::shared_ptr<T>(t);
    }

private:
    void RegisterType(const std::string& strKey, boost::any constructor)
    {
        if(m_creatorMap.find(strKey) != m_creatorMap.end())
        {
            throw std::invalid_argument("this key has already exist!");
        }

        //通过any擦出不同类型的构造器
        m_creatorMap.emplace(strKey, constructor);
    }

    unordered_map<std::string, boost::any> m_creatorMap;
};
