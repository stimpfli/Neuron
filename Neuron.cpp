#include "Neuron.h"
#include <string>
#include <iostream>
#include <cmath>

//CONSTANTES
const double Iext (10);
std::ofstream pikeStorageout("pikeStorage.dat",std::ios::app);
//std::ifstream pikeStoragein("pikeStorage.dat",std::ios::in);
const int h (1);
const double Taue(20);
const double R(10);
const double tStart(0);
const double tStop(10);
const double Vref(10);
const double Teta(20);
const double Taurps(2);

Neuron:: Neuron (double V)
:potentiel (V) , isRefractory(false)
{}

void Neuron:: storeSpike (std::ofstream& pikeStorage,const double & time)const
{
	pikeStorage<<potentiel ;
	pikeStorage<<"  ";
	pikeStorage<<time<<std::endl;
}

int Neuron:: getNbSpikes () const
{
	return nbSpikes;
}

double Neuron:: getPotentiel()const
{
	return potentiel;
}

void Neuron:: update (const double & a ,const double & b)
{
	double time (tStart);
	while (time < tStop)
	{
		if (isRefractory )
			{
				potentiel = Vref;
				isRefractory=false;
			/*std::cout<<"temps :"<<time<<std::endl;
			std::cout<<"V :"<<potentiel<<std::endl;*/
			}
		else if (potentiel >= Teta )
		{
			storeSpike(pikeStorageout,time);
			spikesTime.push_back(time);
			isRefractory = true;
			++nbSpikes;

			
		}
		if(a <= time and b >= time )
		{
			updatePotentialAB(time);
		}
		else 
		{
			
		}
		time += h;
		displayNeuron();

		
	};
	
}

void Neuron:: updatePotentialAB (const double & time)
{
	potentiel = exp(-h/Taue)*potentiel + Iext*R*(1-exp(-h/Taue));
}

void Neuron:: updatePotential (const double & time)
{
	potentiel = exp(-h/Taue)*potentiel;
}
void Neuron:: displayNeuron() const
{
	std::cout<<"V: " <<potentiel<<std::endl;
	if (isRefractory)
	{
		std::cout<<" is Refractory"<<std::endl;
	}
}
