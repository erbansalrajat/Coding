#include<bits/stdc++.h>
using namespace std;
class ComplexNumbers
{
  private:
  int real;
  int img;
  public:
  ComplexNumbers(int real, int img)
  {
    this->real=real;
    this->img=img;
  }
  void print()
  {
    cout<<real<<" + "<<img<<"i";
  }
  void add(ComplexNumbers c2)
  {
    this->real+=c2.real;
    this->img+=c2.img;
  }
  void multiply(ComplexNumbers c3)
  {
    this->real=this->real*c3.real + (this->img*c3.img)*(-1);
    this->img=this->real*c3.img + (c3.real*this->img);
  }
  float magnitude()
  {
    float mag=sqrt(real*real+ img*img);
    return mag;
  }
};
int main()
{
 ComplexNumbers x(3,4);
 ComplexNumbers y(6,8);
 ComplexNumbers z(7,24);
 cout<<"X is = ";
 x.print();
 cout<<endl;
 cout<<"Y is = ";
 y.print();
 cout<<endl;
 cout<<"Z is = ";
 z.print();
 cout<<endl;
 cout<<"Magnitude of x : " <<x.magnitude()<<endl;
 cout<<"Magnitude of y : " <<y.magnitude()<<endl;
 cout<<"Magnitude of z : " <<z.magnitude()<<endl;
 x.add(y);
 cout<<"X is = ";
 x.print();
 cout<<" after adding y to it. "<<endl;
 y.multiply(z);
 cout<<"Y is = ";
 y.print();
 cout<<" after multiplying z to it. "<<endl;
 return 0;
}
