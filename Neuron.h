#ifndef NEURON_H
#define NEURON_H

#include <fstream>
#include <iostream>
#include <vector>

//CONSTANTES:
const double Iext (10);
std::ofstream pikeStorageout("pikeStorage.dat",std::ios::app);
//std::ifstream pikeStoragein("pikeStorage.dat",std::ios::in);
const int h (1);
const double tau(20);
const double R(1);
const double tStart(0);
const double tStop(100);

//CLASSES:
 
class Neuron 
{
	private:
	double potentiel;  
	void storeSpike (std::ofstream& pikeStorage, double time);
	int nbSpikes;
	std::vector<double> spikesTime;
	bool isRefractory ;
		
		
	public:
	Neuron (double V );
	double getPotentiel();
	int getNbSpikes ();
	void update (double a,double b);
	void updatePotentialAB (const double & time);
	void updatePotential (const double & time);
	};
	
#endif	
