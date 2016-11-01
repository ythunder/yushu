/*************************************************************************
	> File Name: Date.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月25日 星期二 13时03分59秒
 ************************************************************************/

#ifndef MUDUO_BASE_DATE_H
#define MUDUO_BASE_DATE_H

#include "copyable.h"
#include "Types.h"

struct tm;
namespace muduo
{
class Date : public muduo::copyable
{
public:
    struct YearMonthDay
    {
        int year;
        int month;
        int day;
    };

    static const int kDaysPerWeek = 7;
    static const int kJulianDayOf1907_01_01;

    Date()
        :julianDayNumber_(0)
    {  }

    Date(int year, int month, int day);

    explicit Date(int julianDayNumber)
        :julianDayNumber_(julianDayNumber)
    {  }

    explicit Date(const struct tm&);

    bool valid() const { return julianDayNumber_ > 0; }

    void swap(Date& that)
    {
        std::swap(julianDayNumber_, that.julianDayNumber_);
    }

    string toIsoString() const;

    struct YearMonthDay yearMonthDay() const;

    int year() const  
    {
        return yearMonthDay().year;
    }

    int month() const
    {
        return yearMonthDay().month;
    }

    int day() const
    {
        return yearMonthDay().day;
    }

    int weekDay() const
    {
        return (julianDayNumber_ + 1) % kDaysPerWeek;
    }

    int julianDayNumber() const
    {
        return julianDayNumber_;
    }
private:
    int julianDayNumber_;
};

inline bool operator<(Date x, Date y)
{
    return x.julianDayNumber() < y.julianDayNumber();
}

inline bool operator==(Date x, Date y)
{
    return x.julianDayNumber() == y.julianDayNumber();
}

}
#endif
