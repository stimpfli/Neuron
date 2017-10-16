#ifndef NETWORK_H
#define NETWORK_H

#include "Neuron.h"
#include <vector>

//CONSTANTES
const int NbNeuron (2);//neurons
const double tStop(5000);//ms


class Network
{
	private:
	std::vector <Neuron> neurons;
	std::vector <std::vector<bool> > linked;
	int t;
	
	public:
	Network();
	void update();
	void transmit(int i);
	
	
	
};


#endif
