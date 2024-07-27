#include<stdlib.h>
#include<iostream>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
    int l, b, h;
    
    public:
    
    Box()
    {
        l = 0, b = 0, h = 0;
    }
    
    Box(int x, int y, int z)
    {
        l = x, b = y, h = z;
    }
    
    Box(Box &obj)
    {
        l = obj.l, b = obj.b, h = obj.h;
    }
    
    int getLength()
    {
        return l;
    }
    
    int getBreadth()
    {
        return b;
    }
    
    int getHeight()
    {
        return h;
    }
    
    long long CalculateVolume()
    {
        return static_cast<long long>(l) * b * h;
    }
    
    bool operator < (Box &obj)
    {
        if(l < obj.l)
        {
            return true;
        }
        
        else if (b < obj.b && l == obj.l)
        {
            return true;
        }
        
        else if(h < obj.h && b == obj.b && l == obj.l)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
    
    friend ostream &operator << (ostream &os, const Box &obj1)
    {
        os << obj1.l << " " << obj1.b << " " << obj1.h;
        return os;
    }
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}