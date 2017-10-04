#ifndef NEURON_H
#define NEURON_H

#include <fstream>
#include <iostream>
#include <vector>

//CLASSES:
 
class Neuron 
{
	private:
	double potentiel;  
	void storeSpike (std::ofstream& pikeStorage,const double& time)const;
	int nbSpikes;
	std::vector<double> spikesTime;
	bool isRefractory ;
	void updatePotentialAB (const double & time);
	void updatePotential (const double & time);
		
		
	public:
	Neuron (double V = -60);
	double getPotentiel() const ;
	int getNbSpikes () const;
	void update (const double & a ,const double & b ) ;
	void displayNeuron() const ;
	};
	
#endif	
