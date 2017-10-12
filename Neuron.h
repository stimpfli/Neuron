#ifndef NEURON_H
#define NEURON_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

//CONSTANTES
const double Vref(0);
const int D(3);

//CLASSES:
 
class Neuron 
{
	private:
	double potentiel;  
	int nbSpikes;
	long tSpike;
	void updatePotential ();
	void storeSpikeTime ();
	int time;
	double iExt;
	std::vector<int> ringBuffer ;
	int stimule();
	
		
		
	public:
	Neuron (double V , std::string name );
	double getPotentiel() const ;
	int getNbSpikes () const;
	bool update (long steps) ;
	void displayNeuron() const ;
	double getIExt ()const;
	void setIExt(double I);
	void storeSpike (std::ofstream& pikeStorage)const;
	void receive(int deliveryTime);
	std::string name;
	void displayBuffer ()const;
	};
	
#endif	
