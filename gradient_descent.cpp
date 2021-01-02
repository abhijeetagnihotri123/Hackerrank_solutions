//This is a sample program to run gradient descent on a dataset

#include <iostream>
#include <vector>
using namespace std;

void gradient_descnet(int &,double[],double[],double&,double&,double&);
int main()
{
    double x[10]={92,56,88,70,80,49,65,35,66,67};
    double y[10]={98,68,81,80,83,52,66,30,68,73};
    int n = 100000;
    double m = 0.0;
    double b = 0.0;
    double learning_rate = 0.01;
    gradient_descnet(n,x,y,m,b,learning_rate);
    cout<<m<<" "<<b;
    return 0;
}

void gradient_descnet(int &num_iterations,double x[10],double y[10],double &m,double &b,double &learning_rate)
{
    double y_pred[10] = {0};
    int i=0;
    double sum1,sum2,md,bd;
    while(i<num_iterations)
    {
        sum1 = sum2 = 0;
        for(int j=0;j<10;j++)
        {
            y_pred[j] = m*x[j]+b;
        }
        for(int j=0;j<10;j++)
        {
            sum1 += -(y[j]-y_pred[j])*x[j];
            sum2 += -(y[j]-y_pred[j]);
        }
        md = sum1/10;
        bd = sum2/10;
        m = m - learning_rate * md;
        b = b - learning_rate * bd;
        i = i+1;
    }
}