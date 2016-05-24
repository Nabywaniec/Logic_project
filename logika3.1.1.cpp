#include <iostream>
#include <cstdlib>
using namespace std;

int function(int a[6])
{
	if(a[0]==0 || a[1]==0 || a[2]==0 || a[3]==0 ||  a[4]==0 || a[5]==0){
		cout << "Niepoprawne argumenty";
		cout << endl;
		return 0;
	}	
		
	if(a[0]>a[1] and a[2]!=0 and ( a[3]%a[1]==1  or  a[4]%a[0]!=0 or a[5]%a[3]==2) )
		return ((a[1]-a[0]) + a[2]%a[1] + a[0]%a[1]+ a[3]%a[4]);
		else return (a[0]-a[1]);

}

int main(int argc, char **argv)
{
	if(argc<7)
	{
		cout<<"Niepoprawna ilosc argumentow.Powinno byc ich 6!"<<endl;
		return 0;
	}
	int arg[6];
	for(int i=0; i<6; i++)
	{
		arg[i]=atoi(argv[i+1]);
	}
	cout<<function(arg)<<endl;

	return 0;
}
