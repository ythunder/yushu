#include <iostream>
#include <stack>
#define A 0
#define B 1
#define C 2
#define D 3

class Operator
{
public:
    Operator(char op, int flag)
        :operator_(op),
        flag_(flag)
    {  }

    ~Operator() {  }
    
    char operator_;
    int flag_;
};

int yunsuan(int a, int b, char op)
{
    int c = 0;
    switch(op)
    {
        case '+':   c = a+b; break;
        case '-':   c = a-b; break;
        case '*':   c = a*b; break;
        case '/':   c = a/b; break;
    }
    return c;
}

int main()
{
    std::string str;
    std::cin >> str;
    int str_len = str.length();

    std::stack<Operator> op;
    std::stack<int> in;
    Operator a('@', A);
    op.push(a);
 
    

    for(int i=0; i<str_len; ++i)
    {
        std::cout << "current op is str[ "<< i << "]  "  << str[i] << std::endl;
        if(str[i] == '(')
        {
            Operator k('(', A);
            op.push(k);
            std::cout << "push_(:" << "(" << std::endl;
        }
        else if(str[i]=='+' || str[i] == '-')
        {
            Operator f = op.top();
            Operator temp(str[i], B);
            if(temp.flag_ >= f.flag_)
            {
                op.push(temp);
                std::cout << "push_+-:"  << temp.operator_ << std::endl;
            }
            else
            {
                Operator o = op.top(); op.pop();
                int n1 = in.top(); in.pop();
                int n2 = in.top(); in.pop();
                in.push(yunsuan(n2, n1, o.operator_));    
                std:: cout << "push_res: " << in.top() << std::endl;
            }
        }
        else if(str[i]=='*' || str[i]=='/')
        {
            Operator temp(str[i], C);
            op.push(temp);
            std::cout << "push_*/:" << temp.operator_ << std::endl;
        }
        else if(str[i] == ')')
        {
            Operator k_right_next = op.top(); op.pop();
            std::cout  << "pop:" << k_right_next.operator_ << std::endl;
            while(k_right_next.operator_ != '(')
            {
                int n1 = in.top(); in.pop();
                int n2 = in.top(); in.pop();
                in.push(yunsuan(n2,n1,k_right_next.operator_));
                std::cout << "push_res:" << in.top();
                k_right_next = op.top(); op.pop();
                std::cout << "pop: " << k_right_next.operator_ << std::endl;

            }
        }
        else
        {
            int p = str[i]-'0';
            in.push(p);
            std::cout << "push_num:" << p << std::endl;
        }
    }

    
                  Operator z = op.top(); op.pop();   std::cout << "pop:" << z.operator_ << std::endl; 
                  std::cout << in.top() << std::endl;

    while(1)
    {
        if(z.operator_ == '@')
        {
            std::cout << "result:" << in.top() << std::endl;
            in.pop();
            return 0;
        }
        int n1 = in.top(); in.pop();   std::cout << "pop:" << n1 << std::endl ;
        int n2 = in.top(); in.pop();   std::cout << "pop:" << n2 << std::endl;
        std::cout << n2 << " " << n1 << " " << z.operator_ << std::endl;
        int aa = yunsuan(n2,n1,z.operator_);
        std::cout << aa << std::endl;
        in.push(aa);
        
        z = op.top(); op.pop(); 
    }
    
}
