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
	void storeSpike (std::ofstream& pikeStorage, double time);
	int nbSpikes;
	std::vector<double> spikesTime;
	bool isRefractory ;
	void updatePotentialAB (const double & time);
	void updatePotential (const double & time);
		
		
	public:
	Neuron (double V );
	double getPotentiel();
	int getNbSpikes ();
	void update (double a,double b);
	//void displayNeuron();
	};
	
#endif	
