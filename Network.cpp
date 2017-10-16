#include "Network.h"
#include <iostream>
//CONSTANTES 
std::ofstream pikeStorageout("pikeStorage.dat",std::ios::app); //dossier stockage

//CONSTRUCTEUR
/*
 * CONSTRUIT LES LIENS ENTRE LES NEURONES TABLES DE CORRES 
 * CONSTRUIT TOUS LES NEURONES DE LA SIMULATION 
 */

Network:: Network ()
 : linked (NbNeuron , std::vector<bool>(NbNeuron , false )) , t(0)
{
	neurons.push_back(Neuron(0));
	neurons.push_back(Neuron(0));
	linked[0][1] = true;
}

/*
 * DIRIGE TOUTE LA SIMULATION A TRAVERS TOUS LES NEURONES
 */
void Network:: update()
{
	double iStart(1000);
	double iStop(4000);
	std::cout<<"Entrez la borne inf du temps de simulation : iStart = "<<std::endl;
	std::cin>>iStart;
	std::cout<<"Entrez la borne sup du temps de simulation : Istop = "<<std::endl;
	std::cin>>iStop;
	
	do {
			for (size_t i (0);i < linked.size();++i)
			{
				
				if (t<iStart or t>iStop)
				{
					neurons[0].setIExt(0);
				}
				else 
				{
					neurons[0].setIExt(1.01);
				}
				neurons[1].setIExt(0);
				if(neurons[i].update(1 , i))
				{
					transmit(i);
				}
			
				neurons[i].storeSpike(pikeStorageout,i);
			}
			++t;
	}
	while (t<tStop);
}


void Network::transmit(int i)
{
	for (size_t j (1);j < linked[i].size();++j)
				{
					if (linked[i][j])
					neurons[j].receive(DelaySteps+t);
				}
}
