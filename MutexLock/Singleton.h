/*************************************************************************
	> File Name: Singleton.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月17日 星期一 13时56分42秒
 ************************************************************************/

template<typename T>
pthread_once_t Singleton<T>::ponce_=PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::value_ = NULL;

template<typename T>
class Singleton : boost :: noncopyable
{
public:    
    static T& instance()
    {
        pthread_once(&ponce_, &Singleton::init);
        return *value_;
    }

private:
    Singleton();
    ~Singleton();

    static void init()
    {
        value_ = new T();
    }
private:
    static pthread_once_t ponce_;
    static T* value_;
};
