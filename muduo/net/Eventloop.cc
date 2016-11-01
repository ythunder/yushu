

void 
EventLoop::loop()
{
    assert(!looping_);
    assertInLoopThread();  //如果不在I/O线程中则退出循环
    looping_ = true;
    quit_ = false;
    LOG_TRACE << "EventLoop " << this << "start looping";

    while(!quit_)
    {
        activeChannels_.clear();
        pollReturnTime_ = poller_->poll(kPollTimeMs, &activeChannels_);
        ++iteration_;
        if(Logger::logLevel() <= Logger::TRACE)
        {
            printActiveChannels();
        }
        eventHandling_ = true;   //正在处理事件
        for(ChannelList::iterator it= activeChannels_.begin(); it != activeChannels_.end(); ++i)
        {
            currentActiveChannel_ = *it;
            currentActiveChannel_->hanleEvent(pollReturnTime_);
        }
        currentActiveChannel_ = NULL;
        eventHandling_ = false;
        doPendingFunctors();
    }
    LOG_TRACE << "EventLoop " << this << "stop looping ";
    looping_ = false;
}

void
EventLoop::quit()
{
    quit_ = true;
    if(!isInLoopThread())
    {
        wakeup();
    }
}

void
EventLoop::runInLoop(const Functor& cb)
{
   if(isInLoopThread()) 
    {
        cb();
    }
    else
    {
        queueInLoop(cb);
    }
}

void 
EventLoop::queueInLoop(const FUnctor& cb)
{
    {
        MutexLockGuard lock(mutex_);
        pendingFunctors_.push_back(cb);
    }
    if(!isInLoopThread() || callingPendingFunctors_)
    {
        wakeup();
    }
}

size_t 
EventLoop::queueSize() const
{
    MutexLockGuard lock(mutex_);
    return pendingFunctors_.size();
}


