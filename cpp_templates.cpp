//TEMPLATES Enable us to define generic classes and functions and thus provides support for generic programming.
#include<iostream>
using namespace std;
//CLASS TEMPLATES
//first with no templates

class vector
{
    int *v;
    int size;
    public:
        // create NULL vector
        vector(int m)
        {
            size=m;
            v= new int[size];
            for(int i=0;i<size;i++)
            {
                v[i]=0;
            }
        }
        //create vector from array
        vector(int *a)
        {
            for(int i=0;i<size;i++)
            {
                v[i]=a[i];
            }
        }
        //scalar product
        int operator*(vector &y)
        {
            int sum=0;
            for(int i=0;i<size;i++)
            {
                sum+=this->v[i]* y.v[i];
            }
            return sum;
        }
        void display()
        {
            for(int i=0;i<size;i++)
            {
                cout<<v[i]<<", ";
            }
            cout<<endl;
        }
};
//Above is an small implementation of vector. we can create a vector of size n, create vector from an regular array and perform scalar product.

int main()
{
    int a[3]={1,2,3};
    int b[3]={4,5,6};
    vector v1(3);
    vector v2(3);       //2 null vectors of size n
    v1=a;
    v2=b;
    v1.display();
    v2.display();
    cout<<v1*v2<<endl;

    return 0;
}
