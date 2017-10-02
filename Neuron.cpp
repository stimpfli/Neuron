#include "Neuron.h"
#include <string>
#include <iostream>
#include <cmath>

//CONSTANTES
const double Iext (10);
std::ofstream pikeStorageout("pikeStorage.dat",std::ios::app);
//std::ifstream pikeStoragein("pikeStorage.dat",std::ios::in);
const int h (1);
const double tau(20);
const double R(1);
const double tStart(0);
const double tStop(100);

Neuron:: Neuron (double V)
:potentiel (V) , isRefractory(false)
{}

void Neuron:: storeSpike (std::ofstream& pikeStorage, double time)
{
	pikeStorage<<potentiel ;
	pikeStorage<<time<<std::endl;
	++nbSpikes;
}

int Neuron:: getNbSpikes ()
{
	return nbSpikes;
}

double Neuron:: getPotentiel()
{
	return potentiel;
}

void Neuron:: update (double a,double b)
{
	double time (tStart);
	while (time < tStop)
	{
		if (isRefractory )
			{
				potentiel = -60;
				isRefractory=false;
			}
		else if (potentiel >= -30)
		{
			storeSpike(pikeStorageout,time);
			spikesTime.push_back(time);
			isRefractory = true;
			std::cout<<"temps :"<<time<<std::endl;
			std::cout<<"V :"<<potentiel<<std::endl;
			
		}
		if(a <= time and b >= time )
		{
			updatePotentialAB(time);
		}
		else 
		{
			
		}
		time += h;

		
	};
	
}

void Neuron:: updatePotentialAB (const double & time)
{
	potentiel = exp(-h/tau)*potentiel + Iext*R*(1-exp(-h/tau));
}

void Neuron:: updatePotential (const double & time)
{
	potentiel = exp(-h/tau)*potentiel;
}
/*void Neuron:: displayNeuron()
{
	std::cout<<"V: " potentiel
}*/
