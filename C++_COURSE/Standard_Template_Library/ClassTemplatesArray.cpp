#include <string>
#include <vector>
#include <iostream>
using namespace std;

template<typename T,int N>
class Array
{
    private:
        int size{N};
        T values[N];
        friend ostream &operator<<(ostream &os,const Array<T,N>&arr)
        {
            os<<"[";
            for(int i=0;i<arr.get_size()-1;i++)
            {
                os<<arr.values[i]<<", ";
            }
            os<<arr.values[arr.get_size()-1]<<"]";
            return os;
        }
    public:
        Array() = default;
        Array(T init_value)
        {
            for(auto &val : this->values)
            {
                val = init_value;
            }
        }
        void fill(T value)
        {
            for(auto &val : this->values)
            {
                val = value;
            }
        }
        int get_size() const
        {
            return this->size;
        }
        T &operator[](int index)
        {
            return this->values[index];
        }
};
int main()
{   
    Array<int,5>arr;
    cout<<arr.get_size()<<endl;
    Array<double,10>arr1(3.14);
    for(int i=0;i<arr1.get_size();i++)
    {
        arr1[i] = (i<<1)+(i>>1);
    }
    cout<<arr1<<endl;
    arr1.fill(123.132);
    cout<<arr1<<endl;
    return 0;
}