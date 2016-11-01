/*************************************************************************
	> File Name: types.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月25日 星期二 00时35分47秒
 ************************************************************************/

#ifndef MUDUO_BASE_TYPES_H
#define MUDUO_BASE_TYPES_H

#include <stdint.h>
#ifdef MUDUO_STD_STRING    //如果有定义某个宏
#include <string>
#else
#include <ext/vstring.h>
#include <ext/vstring_fwd.h>
#endif

#ifdef NDEUBG
#include <assert.h>
#endif

#ifdef MUDUO_STD_STRING
using std:string;
#else
typedef __gnu_cxx::__sso_string string;
#endif

template<typename To, typename From>
/*类型转换，From为子类，To为基类*/
inline To implicit_cast(From const &f)
{
    return f;
}

template<typename To, typename From>
inline To down_cast(From* f)
{
    if(false)
    {
        implicit_cast<From*, To>(0);
    }
#if !defined(NDEBUG) && !defined(GOOGLE_PROTOBUF_NO_RTTI)
    assert(f == NULL || dynamic_cast<To>(f) != NULL);   //dynamic_cast转换运算符，需要目标类型和源对象有继承关系，只有从子类到基类的转换才返回成功，否则为空
    #endif
    return static_cast<To>(f);
}
#endif
