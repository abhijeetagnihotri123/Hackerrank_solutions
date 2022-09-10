#include <iostream>
using namespace std;
class shape // Abstract Class
{
    protected:
        int width;
        int height;
    public:
        virtual int getArea() = 0; //pure virtual function
        void setWidth(int w)
        {
            this->width = w;
        }
        void setHeight(int h)
        {
            this->height = h;
        }
        virtual ~shape()
        {
            cout<<"Destroying shape\n";
        }
};
class rectange:public shape
{
    public:
    rectange()
    {
        cout<<"Constructing a rectangle\n";
    }
    int getArea()
    {
        return (width*height);
    }
    ~rectange(){cout<<"Destroying Rectangle\n";}
};
class triangle: public shape
{
    public:
    triangle()
    {
        cout<<"Constructing a triangle\n";
    }
    int getArea()
    {
        return (width*height)>>1;
    }
    ~triangle(){cout<<"Destroying Triangle\n";}
};
int main()
{       
    rectange r;
    triangle t;
    r.setHeight(5);
    r.setWidth(20);
    cout<<r.getArea()<<endl;
    return 0;
}