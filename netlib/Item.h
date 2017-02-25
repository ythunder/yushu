/*************************************************************************
	> File Name: Item.h
	> Author: 
	> Mail: 
	> Created Time: 2017年02月24日 星期五 00时27分33秒
 ************************************************************************/


#pragma once

#include <string>
#include <memory>


class Item;
typedef std::shared_ptr<Item> ItemPtr;   //Item 指针

class Item
{
public:
    ItemPtr makeItem(std::string key, std::string value)
    {
        return make_shared<Item>(key, value);
    }

    Item(std::string key, std::string value)

    ~Item()
    {
        ::free(data_);    
    }
    
private:

    int totalLen() const { return kaylen_ + valuelen_; }

    int keylen_;
    int valuelen_;
    int receivedBytes_;
    size_t hash_;
    char* data_;
};
