#include "Neuron.h"
#include <iostream>
using namespace std;

int main()
{
	double a(0);
	double b(0);
	cout<<"Entrez la borne inf du temps de simulation : a = "<<endl;
	cin>>a;
	cout<<"Entrez la borne sup du temps de simulation : b = "<<endl;
	cin>>b;
	Neuron n1(-60);
	n1.update(a,b);
	
}
