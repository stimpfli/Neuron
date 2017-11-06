#ifndef NETWORK_H
#define NETWORK_H


#include <vector>
#include <array>
#include "Neuron.hh"

/** modelize a network ,contain:
 * all neurons of the network
 * the global time 
 * initialise the links between neurons 
 * create the neurons 
 **/
class Network
{
	private:
	std::vector <Neuron> neurons;	///< All neurons of the simulation
	double t;						///< the global time of the simulation
	double eta;						///< Eta of the simulation
	double g;						///< g of the simulation
	void initExitatory();
	void initInhibitory();
	void initLinks();
	void transmit(size_t i);
	
	public:
	Network(double g = G,double eta = Eta );
	void update();
	double countConnectionE (int numNeuron) ;
	double countConnectionI (int numNeuron) ;
	double getWeight (int numNeuron);
	double getG ();
	
};


#endif
