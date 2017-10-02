#include "Neuron.h"
#include <string>
#include <iostream>
#include <cmath>

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
			isRefractory = true;
			
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
