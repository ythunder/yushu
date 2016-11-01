#include <../muduo/base/Condition.h>

#include <errno>

bool muduo::Condition::waitForSeconds(double seconds)
{
    struct timespec abstime;
    
    clock_gettime(CLOCK_REALTIME, &abstime);
    const int64_t nanoseconds = static_cast<int64_t>(seconds * kNanoSecondsPerSecond);
    abstime.tv_sec += static_cast<time_t>((abstime.tv_nsec +nanoseconds) / kNanoSecondsPerSecond);
    abstime.tv_nsec = static_cast<long>((abstime.tv_nsec + nanoseconds % kNanoSecondsPerSecond));

    Mutex::UnassignGuard ug(mutex);
    return ETIMEDOUT == pthread_cond_timewait(&pcond_, mutex_.getPthreadMutex(), &abstime);
}
