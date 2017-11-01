#ifndef NEURON_HH
#define NEURON_HH

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <deque>


//CONSTANTES
const double Vref(0);//mV
const double D(1.5);//ms
const double h (0.1);//ms
const long int DelaySteps(D/h);//steps
const double Ne (10000);//nbNeuron
const double Ni (2500);//nbNeuron
const double Ci (Ni/10);//nbConnection
const double Ce (Ne/10);//nbConnection
const double Je (0.1);//mV
const double g (5);
const double Ji (-Je*g);//mV
const double Taue(20);//ms
const double R(20);//G Ohm
const double tStart(0);//ms
const double TStop(1000);//ms
const double Teta(20);//mV
const double Taurps(2.0);//ms
const long refractorySteps(Taurps/h);//steps
const double Eta(2);
const double NuThr (Teta/(Ce*Je*Taue)); //1/ms
const double NuExt(Eta*Ce*NuThr); //1/ms
const double Lambda (NuExt*h);//1/steps



//CLASSES:
 
class Neuron 
{
	private:
	double potentiel;  ///< le potentiel du neuron
	int nbSpikes;	   ///< le nombre de spike du neuron
	long tSpike;	   ///< le temps du dernier spike 
	int time;		   ///< le temps local du neuron
	double iExt;	   ///< le courant extérieur 
	std::vector<double> ringBuffer ; ///< le buffer circulaire
	double J;		   ///< le poids du neuron 
	bool test;		   ///< si le neuron est mode test ou non 
	std::deque <int> targets; ///< le tableau de neuron auxquel notre neuron et lié 
	
	void updatePotential (double S);
	void storeSpikeTime ();
	double stimule();

	
		
		
	public:
	
	Neuron (double V , double J );
	double getPotentiel() const ;
	int getNbSpikes () const;
	bool update (long steps , int i =0 ) ;
	void displayNeuron() const ;
	double getIExt ()const;
	double getTSpike() const;
	void setIExt(double I);
	void storeSpike (std::ofstream& pikeStorage, int i )const;
	void receive(int deliveryTime , double J);
	void displayBuffer (int i)const;
	double getJ()const;
	void testOn();
	void testOff();
	void connect(size_t numNeuron);
	int getNeuronNum(size_t connectionNum);
	size_t getTargetsize();
	};
	
#endif	