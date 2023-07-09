#include<iostream>
using namespace std;

class fraction
{
	int num,deno;
	public:
		void readF();
		void displayF();
		fraction addF(fraction f2);
		
		//opt overloading
		fraction operator *(fraction f2);
		
		//opt overloading of PREDEFINED class used friend
		friend void operator>>(istream &in,fraction &f);
		friend void operator<<(istream &out,fraction f);
};
void operator<<(istream &out,fraction f){
	cout<<f.num<<"/"<<f.deno;
}

void operator>>(istream &in,fraction &f){
	cout<<"Enter the num and deno\n";
	in>>f.num>>f.deno;
}
fraction fraction::operator *(fraction f2)
{
	fraction f3;
	f3.num = (num * f2.deno) + (deno * f2.num);
	f3.deno = deno * f2.deno;
	return f3;
}

void fraction::readF(){
	cout<<"Enter the numerator and denominator";
	cin>>num>>deno;
}
void fraction::displayF(){
	cout<<"The Fraction is :";
	cout<<num<<"/"<<deno;
}
fraction fraction::addF(fraction f2){
	fraction f3;
	
	f3.num = num + f2.num;
	f3.deno= deno + f2.deno;
	return f3;
} 
int main()
{
	fraction f1,f2,f3,f4;
	f1.readF();
	f1.displayF();
	
	f2.readF();
	f2.displayF();
	
	
    f3 = f1.addF(f2);		//calls
	f3.displayF();
	
	
	f3 = f1 * f2;			//Operation like normal PDT op PDT
	f3.displayF();
	
	cin>>f4; 				// calling a class obj like a normal pdt
	f4.displayF();
	//cout<<f4;
	return 0;
}
