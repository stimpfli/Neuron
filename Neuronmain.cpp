#include "Neuron.h"
#include <iostream>
using namespace std;

const double tStop(5000);
std::ofstream pikeStorageout("pikeStorage.dat",std::ios::app);

int main()
{
	double iStart(1000);
	double iStop(4000);
	cout<<"Entrez la borne inf du temps de simulation : iStart = "<<endl;
	cin>>iStart;
	cout<<"Entrez la borne sup du temps de simulation : Istop = "<<endl;
	cin>>iStop;
	Neuron *n1ptr = new Neuron (Vref,"n1");
	Neuron *n2ptr = new Neuron (Vref,"n2");
	vector<vector <Neuron *> > neurons{{n1ptr,n2ptr},{n2ptr,n1ptr}};
	for(int t(0); t < tStop;++t)
	{
		for (size_t i (0);i < neurons.size();++i)
		{
			
			if (t<iStart or t>iStop)
			{
				neurons[i][0]->setIExt(0);
			}
			else 
			{
				neurons[i][0]->setIExt(30);
			}
			if(neurons[i][0]->update(1))
			{
				for (size_t y (1);y < neurons[i].size();++y)
				{
					neurons[i][y]->receive(D+t);
				}
				
			}
			
			neurons[i][0]->storeSpike(pikeStorageout);
		}
	}
	delete n1ptr;
	delete n2ptr;
		
}
