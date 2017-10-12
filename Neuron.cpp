#include "Neuron.h"
#include <string>
#include <iostream>
#include <cmath>

//CONSTANTES
const double h (0.1);
const double Taue(20);
const double R(20);
const double tStart(0);
const double Teta(20);
const double Taurps(0.2);
const long refractorySteps(Taurps/h);
const int J(1);


Neuron:: Neuron (double V , std::string name)
:potentiel (V),tSpike(0),time(tStart) , ringBuffer(D+1,0), name(name)
{}

void Neuron:: storeSpike (std::ofstream& pikeStorage)const
{
	pikeStorage<<potentiel ;
	pikeStorage<<"  "<<name<<"	";
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

bool Neuron:: update (long steps)
{
	if (steps == 0){return false;}
	bool spikes (false);
	const long tStop(time + steps);
	//std::cout<<name<<"  "<< ringBuffer[0]<<ringBuffer[1]<<ringBuffer[2]<<ringBuffer[3]<<"	rang "<<time % (D+1)<<"	p "<<potentiel<<"	1"<<std::endl;	
	
	while (time < tStop)
	{
		if (potentiel >= Teta )
		{
			storeSpikeTime();
			++nbSpikes;
			spikes =true;
			std::cout <<"Spike	"<<name<<"	"<<time<<std::endl;
		}
		if (tSpike > 0 and time - tSpike < refractorySteps )
		{
		 potentiel = 0;	
		 std::cout<<"Refractory  "<<std::endl;
		}	
		else 
		{
			updatePotential();
		
		std::cout<<"Icrease  "<<std::endl;

		}
		displayBuffer();
		std::cout<<name<<"  "<< ringBuffer[0]<<ringBuffer[1]<<ringBuffer[2]<<ringBuffer[3]<<"	rang "<<time % (D+1)<<"	p "<<potentiel<<"	2"<<std::endl;
		++time;
	};
	return spikes;
	
}

void Neuron:: updatePotential ()
{
	int stimulus (0);
	stimulus = stimule();
	potentiel = exp(-h/Taue)*potentiel + iExt*R*(1-exp(-h/Taue)) + stimulus*J;
	if (stimulus > 0)
			{
				std::cout<<stimulus<<"stimule"<<tSpike<<"	"<<time<<std::endl;
			}
}

void Neuron:: displayNeuron() const
{
	std::cout<<"V: " <<potentiel<<std::endl;
	
}

void Neuron:: storeSpikeTime ()
{
	tSpike = time;
}

double Neuron:: getIExt ()const
{
	return iExt;
}

void Neuron:: setIExt(double I)
{
	iExt = I;
}

void Neuron:: receive(int deliveryTime)
{
	++ringBuffer[deliveryTime % (D+1)];
	std::cout << "receive1  "<<name<<"	"<<deliveryTime % (D+1)<<"	"<<ringBuffer[0]<<ringBuffer[1]<<ringBuffer[2]<<ringBuffer[3];
	
}

int Neuron:: stimule()
{
	int t(time);
	int tpm (0);
	tpm = ringBuffer[t % (D+1)];
	
	if(ringBuffer[t % (D+1)] > 0)
	{
		ringBuffer[t % (D+1)] = 0;
	}
	return tpm ;
}

void Neuron:: displayBuffer ()const
{
	std::cout<<name<<" display "<< ringBuffer[0]<<ringBuffer[1]<<ringBuffer[2]<<ringBuffer[3]<<std::endl;
}
