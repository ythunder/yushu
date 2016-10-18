/*************************************************************************
	> File Name: MutexLock.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月13日 星期四 22时15分38秒
 ************************************************************************/

 class MutexLock : boost::noncopyable
 {
public:
     MutexLock()
        :holder_(0)
     {  pthread_mutex_init( &mutex_, NULL );  }

     ~MutexLock()
     {
         assert(holder_==0);
         pthread_mutex_destroy(&mutex_);
     }

     bool isLockedByThisThread()
     {
        return holder_ == CurrentThread::tid();    
     }

     /*holder_必须为当前线程*/
     void assertLocked()
     {
         assert(isLockedByThisThread());
     }

     void lock()
     {
         pthread_mutex_lock(&mutex_);   //两行顺序不能换
         holder_ = CurrentThread::tid();
     }

     void unlock()
     {
        holder_ = 0;        //同上，顺序不可改
        pthread_mutex_unlock(&mutex_);
     }

     pthread_mutex_t *getPthreadMutex()
     {
         return &mutex_;
     }

private:
     pthread_mutex_t mutex_;
     pid_t holder_;
 };
