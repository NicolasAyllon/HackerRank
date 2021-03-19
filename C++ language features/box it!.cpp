#include<bits/stdc++.h>

using namespace std;
// Solution 
class Box {
    // Member variables for length, breadth, and height
    private:
        int l;
        int b;
        int h;
    
    public:
        // Constructor initalized using assignment (=) operator
        // Box(int l = 0, int b = 0, int h = 0) {
        //     this->l = l;
        //     this->b = b;
        //     this->h = h;
        // }
        
        // Alternate constructor with member initialization list
        Box(int l_i, int b_i, int h_i) : l(l_i), b(b_i), h(h_i) {}
        
        // Constructor with no arguments
        Box() {
            l = 0;
            b = 0;
            h = 0;
        }
        
        // Copy constructor
        Box(Box &box) {
            l = box.l;
            b = box.b;
            h = box.h;  
        }
        
        // Get dimensions and volume
        int getLength() { return l; }
        int getBreadth() { return b; }
        int getHeight() { return h; }
        
        // Calculate volume as long long to accomodate large volumes
        long long CalculateVolume() { 
            long long L = l;
            long long B = b;
            long long H = h;
            return L*B*H;
        }
        
        // Implement comparison defined by HackerRank
        bool operator<(Box other) {
            if(l < other.l) {
                return true;
            }
            else if(b < other.b && l == other.l) {
                return true;
            }
            else if(h < other.h && b == other.b && l == other.l) {
                return true;
            }
            else {
                return false;
            }
        }
        // Overload <<
        // operator << must be a friend of Box to access dimensions with dot (.)
        friend ostream& operator<<(ostream& out, Box& b);
};

ostream& operator<<(ostream& out, Box& b) {
    out << b.l << " " << b.b << " " << b.h;
    return out;
}



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


// From HackerRank

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