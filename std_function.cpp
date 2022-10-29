#include<iostream>
#include<functional>
#include<any>
#include<memory>

using namespace std;

// void print_num(int i)
// {
//     cout << i << endl;
// }

class Timer
{
    public:
        int userdata;
        explicit Timer(const function<void(const std::any&)> user_data)
        {
            userdata = std::any_cast<int>(user_data);
            cout << "Init timer data: " << endl;
        }
};

class Conversation
{
    public:
        int va;
    public:
        Timer p2_timer_;
    public:
        explicit Conversation(int a):
        va(a),
        p2_timer_([this](const std::any& user_data){print_num(user_data);})
        {
            cout << "Init Success" << endl;
        }
        void print_va()
        {
            cout << "this is function print_va" << endl;
            //cout << va << endl;
        }
        void print_num(const std::any& i)
        {
            cout << std::any_cast<int>(i) << endl;
        }
};


int main()
{

    // function<void(int)> f_display_1 = print_num;
    // function<void(int)> f_display_2 = [](int x){print_num(x);};

    // f_display_1(-20);
    // f_display_2(-44);

    Conversation c1(11);
    c1.print_va();
    cout << (c1.va);
    cout << "END" ;

    return 0;
}