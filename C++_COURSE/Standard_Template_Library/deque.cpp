#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void display(const std::deque<int> &d) {
    std::cout << "[";
    for (const auto &elem: d)
        std::cout << elem << " ";
    std::cout <<  "]"<< std::endl;
}

void test()
{
    vector<int>v{1,2,3,4,5,6,7,8,9,10};
    deque<int>d;
    copy(v.begin(),v.end(),front_inserter(d));
    display(d);
    d.clear();
    copy(v.begin(),v.end(),back_inserter(d));
    display(d);
    d.clear();
}
int main()
{   
    test();
    return 0;
}