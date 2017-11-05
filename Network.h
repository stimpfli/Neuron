#ifndef NETWORK_H
#define NETWORK_H


#include <vector>
#include <array>

#include "Neuron.hh"

//const size_t NbNeur (Ne+Ni);
/**La classe represente un réseau , tous les neurones qu'il contient 
 * et le temps spécifique 
 * il initialise le réseau entre neurones 
 * et crée les neurones
 **/
class Network
{
	private:
	std::vector <Neuron> neurons;	///< le tableau de neuronesque le cortex contient
	double t;						///< le temps global de la simulation 
	void initExitatory();
	void initInhibitory();
	void initLinks();
	void transmit(size_t i);
	double eta;						///< le parametre eta de la simulation 	
	double g;						///< le parametre g de la simulation 
	//std::vector<std::deque <int>> links ; ///< le tableau de connections
	
	public:
	Network(double g = G,double eta = Eta );
	void update();
	double countConnectionE (int numNeuron) ;
	double countConnectionI (int numNeuron) ;
	double getWeight (int numNeuron);
	double getG ();
	//void connect (size_t idA ,size_t idB);
	
	
	
	
	
	
};


#endif
