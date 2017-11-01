#ifndef NETWORK_H
#define NETWORK_H


#include <vector>
#include "Neuron.hh"

class Network
{
	private:
	std::vector <Neuron> neurons;	///< le tableau de neuronesque le cortex contient
	double t;						///< le temps global de la simulation 
	void initExitatory();
	void initInhibitory();
	void initLinks();
	void transmit(int i);
	
	public:
	Network();
	void update();
	double countConnectionE (int numNeuron) ;
	double countConnectionI (int numNeuron) ;
	double getWeight (int numNeuron);
	
	
	
	
	
	
};


#endif
