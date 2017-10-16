#ifndef NEURON_H
#define NEURON_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

//CONSTANTES
const double Vref(0);//mV
const double D(1.5);//ms
const double h (0.1);//ms
const long int DelaySteps(D/h);//steps


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
	Neuron (double V );
	double getPotentiel() const ;
	int getNbSpikes () const;
	bool update (long steps , int i ) ;
	void displayNeuron() const ;
	double getIExt ()const;
	void setIExt(double I);
	void storeSpike (std::ofstream& pikeStorage, int i )const;
	void receive(int deliveryTime);
	void displayBuffer (int i)const;
	};
	
#endif	
