#include<bits/stdc++.h>
using namespace std;

// without header gaurds redefinition will give error
#include"Car.cpp"
#include"engine.cpp"

class vehicle : public Car , public engine
{
    public:
    vehicle()
    {
        cout<<"Vehicle constructor called"<<endl;
    }
};