#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>
using namespace std;

void display(const std::array<int, 5> &arr) {
    cout << "[ ";
    for (const auto &i: arr)
    {
        cout << i << " ";
    }
    cout <<"]"<< endl;
}
void test1()
{
    cout << "Test1 =========================" << endl;
    array<int, 5> arr1 {1,2,3,4,5};     // double {{ }} if C++ 11
    array<int, 5> arr2;
    display(arr1);
    display(arr2); // garbage
    arr2 = {10,20,30,40,50};
    display(arr1);
    display(arr2);
    arr1[0] = 10;
    arr2.at(1) = 1000;
    display(arr1);
    display(arr2);
    cout<<arr2.front()<<"<<<>>>"<<arr2.back()<<endl;
}
void test2() // function to test swap and fill
{
    cout<<"Test2 ============================"<<endl;
    array<int,5>arr1{1,2,3,4,5};
    array<int,5>arr2{10,20,30,40,50};
    arr1.fill(0);
    arr2.swap(arr1);
    display(arr1);
    display(arr2);
}
void test3()
{
    cout << "\nTest3 =========================" << std::endl;

    array<int, 5> arr1 {1,2,3,4,5};     // double {{ }} is C++ 11

    int *ptr = arr1.data();
    cout << ptr << std::endl;
    *ptr = 10000;
    
    display(arr1);
}
void test4() {
    cout << "\nTest4 =========================" << endl;

    array<int, 5> arr1 {2,1,4,5,3};     // double {{ }} is C++ 11

    array<int,5>::iterator min_num = min_element(arr1.begin(), arr1.end());
    auto max_num = max_element(arr1.begin(), arr1.end());
    cout << "min: " << *min_num << " , max: " << *max_num << endl;
}
void test5() {
    cout << "\nTest5 =========================" << std::endl;

    array<int, 5> arr1 {2,1,3,3,5};     // double {{ }} is C++ 11

    auto adjacent = adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end()) 
        cout << "Adjacent element found with value: " << *adjacent << endl;
    else 
        cout << "No adjacent elements found" << endl;
}
void test6()
{
    cout<<"Test6 ==========================="<<endl;
    array<int,5>arr1{1,2,3,4,5};
    int sum = accumulate(arr1.begin(),arr1.end(),0);
    cout<<sum<<endl;
}
void test7()
{
    cout<<"Test7 ==========================="<<endl;
    array<int,12>arr{1,2,3,1,3,3,3,3,3,3,1,7};
    int c = count(arr.begin(),arr.end(),3);
    cout<<c<<endl;
}
int main()
{   
    test7();
    return 0;
}
