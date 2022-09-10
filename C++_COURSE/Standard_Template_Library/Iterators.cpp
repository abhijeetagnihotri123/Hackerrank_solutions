#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;
void display(const std::vector<int> &vec) {
    std::cout << "[ ";
    for (auto const &i: vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}
void test1()
{
    vector<int>vec{1,2,3,4};
    auto it = vec.rbegin();
    while(it != vec.rend())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}
int main()
{   
    test1();
    return 0;
}