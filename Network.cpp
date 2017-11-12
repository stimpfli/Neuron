#include "Network.h"
#include <iostream>
#include <random>
#include <cassert>


const double StepStop (TStop/h);


//CONSTRUCTEUR
/**
 * implement the links between the neuron
 * Build all neuron of the simulation
 */

Network:: Network (double g, double eta)
 : t(0) , eta(eta), g(g)
{
	initExitatory();
	initInhibitory();
	assert(neurons.size() == Ni+Ne);
	initLinks();
	
}

/**
 * Run the main simulation 
 * Call transmit 
 **/
void Network:: update()
{

	do {
			for (size_t i (0);i < Ni+Ne;++i)
			{
				assert(t<StepStop);
				assert(i<neurons.size());
				if(neurons[i].update(1 , i,g,eta))
				{
					transmit(i);
				}
			}
			++t;
			
	}
	while (t<StepStop);
}

/**
 * Transmit the last spike to all connected neuron 
 * @param the id of the neuron that transmit
 */
void Network::transmit(size_t i)
{
	Neuron ni (neurons[i]);
	size_t size ( ni.getTargetsize());
	for (size_t j (0); j < size ;++j)
				{
					neurons[ni.getNeuronNum(j)].receive(DelaySteps+t,ni.getJ(),g);
}
}

/**
 * Initialize the excitatory neuron 
 */
void Network:: initExitatory()
{

	for (int i(0); i < Ne; ++i)
	{
		neurons.push_back(Neuron (0.0,Je));
	}
}

/**
 * Initialize the inhibitory neuron 
 */
void Network:: initInhibitory()
{
	
		double Ji = -Je*g;
	for (int i(0); i < Ni; ++i)
	{

		neurons.push_back(Neuron (0.0,Ji,g));
	}
}

/**
 * Generate randomly the links between Neuron
 */
void Network:: initLinks()
{
	static std::random_device rd ;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<int> distribExit(0,Ne-1);
	static std::uniform_int_distribution<int> distribInhib(Ne,Ne+Ni-1);
	
	for (int i (0) ; i < (Ni+Ne) ; ++i)
	{
		for (int j (0) ; j < Ce ; ++j)
		{
			
			neurons[distribExit(gen)].connect(i);
		}
		
		for (int u (0) ; u < Ci ; ++u)
		{
			neurons[distribInhib(gen)].connect(i);
		}
	}
	
	std::cout<<"hello"<<std::endl;

}

/**
 * @param the id of the neuron to observe
 * @return the number of excitatory neuron connected to neuron numNeuron
 */
double Network:: countConnectionE (int numNeuron)
{
int connections (0) ;
	for (size_t i (0) ; i < neurons.size() ; ++i)
	{
		for(size_t j (0) ; j < neurons[i].getTargetsize() ; ++j )
		if (neurons[i].getJ() == Je and neurons[i].getNeuronNum(j) == numNeuron)
		{
			++connections  ;
		}
	}
return connections ;
	
}

/**
 * @param the id of the neuron to observe
 * @return the number of inhibitory neuron connected to neuron numNeuron
 */
double Network:: countConnectionI (int numNeuron) 
{
	int connections (0) ;
	double Ji = - Je*g;
	for (size_t i (0) ; i < neurons.size() ; ++i)
	{
		for(size_t j (0) ; j < neurons[i].getTargetsize() ; ++j )
		if (neurons[i].getJ() == Ji  and neurons[i].getNeuronNum(j) == numNeuron)
		{
			++connections  ;
		}
	}
return connections ;
	
}

/**
 * @param the neuron you want to know the J
 * @return The J of the neuron 
 */
double Network:: getWeight (int numNeuron)
{
	return neurons[numNeuron].getJ();
}

/**
 * @return The parameter g of the simulation  
 **/
double Network:: getG ()
{
	return g;
}
