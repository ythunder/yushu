/*************************************************************************
	> File Name: hello_program_option.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年01月16日 星期一 13时16分06秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <boost/program_options.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    using namespace boost::program_options;

    options_description desc("Allowed options");   //声明需要的选项

    desc.add_options()    //此函数返回了定义了operator()的特殊的代理对象
        ("help,h", "produce help message")   //参数依次为选项名，选项值，以及选项的描述
        ("person,p", value<string>()->default_value("world"), "who");

    variables_map vm;   //用来存储选项值
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if(vm.count("help")) {
        cout << desc;
        return 0;
    }
    cout << "Hello " << vm["person"].as<string>() << endl;
    return 0;
}
