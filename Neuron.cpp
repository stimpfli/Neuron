#include "Neuron.h"
#include <string>
#include <iostream>
#include <cmath>

//CONSTANTES
const double Taue(20);//ms
const double R(20);//G Ohm
const double tStart(0);//ms
const double Teta(20);//mV
const double Taurps(2.0);//ms
const long refractorySteps(Taurps/h);//steps
const int J(0.1);//mV

//CONSTRUCTEUR 
/*
 * INITIALISE LE BUFFER A SA TAILLE REMPLIS DE 0
 * "" V A SA VALEUR PASSE EN PARAM
 * INITIALISE LE TEMPS DU NEURON ET MET LE TEMPS DU 1ER SPIKE 0
 */
Neuron:: Neuron (double V)
:potentiel (V),tSpike(0),time(tStart) , ringBuffer(DelaySteps+1,0)
{}
/*
 * ECRIS TOUTE LES VALEURS DANS LE DOSSIER PASSER EN PARAM
 * ECRIS A COTÉ LE NUMÉROS ASSOCIÉ AU NEURON
 */
void Neuron:: storeSpike (std::ofstream& pikeStorage , int i)const
{
	pikeStorage<<potentiel ;
	pikeStorage<<"  n"<<i<<"	";
	pikeStorage<<time*h<<std::endl;
}
/*
 * RETURN LE NBDESPIKES
 */
int Neuron:: getNbSpikes () const
{
	return nbSpikes;
}

/*
 * RETOURNE LE POTENTIEL MEMBRANAIRE
 */
double Neuron:: getPotentiel()const
{
	return potentiel;
}
/*
 * RETOURNE UN BOOL = TRUE SI SPIKE FALSE SINON 
 * PREND L NOMBRE DE STEPS ET LA POSITION DU NEURON DANS LA SIMULATION
 * ITÈRE SUR LE NOMBRE DE STEPS 
 * SI LE POTENTIEL DEPASSE THETA ( VREFRACTORY ):
	*  STORE LE TEMPS DU DERNIER SPIKE
	* INCREMENTE COMPTEUR DE SPIKE 
	* MET LE BOOL A TRUE 
	* SI DEBUG COUT LE SPIKE LA PLACE DU NEURON ET LE TEMPS
 * SI IL Y A EU UN SPIKE AVANT ETT QUE L'ON SE TROUVE DANS LE REFRACTORY TIME:
	* MAINTIENT LE POTENTIEL A 0 mV 
	* EN MODE DEBUG AFFICHE QUEL NEURON EST DANS CE MODE
 * SINON:
	* 	MODIFIE LA VALEUR DU POTENTIEL 
	* EN MODE DEBUG AFFICHE QU'IL EST DANS CETTE PARTIE DE LA BOUCLE 
 *AUGMENTE LES STEPS DE SIMULATION DE 1
 
 */
bool Neuron:: update (long steps , int i)
{
	if (steps == 0){return false;}
	bool spikes (false);
	const long tStop(time + steps);
	
	while (time < tStop)
	{
		if (potentiel >= Teta )
		{
			storeSpikeTime();
			++nbSpikes;
			spikes =true;
			//std::cout <<"Spike	n"<<i<<"	"<<time*0.1<<"ms"<<std::endl;
		}
		if (tSpike > 0 and time - tSpike < refractorySteps )
		{
		 potentiel = 0;	
		// std::cout<<"n"<<i<<" Refractory  "<<std::endl;
		}	
		else 
		{
			updatePotential();
		
		//std::cout<<"Icrease  n"<<i<<std::endl;

		}
		//displayBuffer(i);
		//std::cout<<"n"<<i<<"  "<< ringBuffer[0]<<ringBuffer[1]<<ringBuffer[2]<<ringBuffer[3]<<"	rang "<<time % (D+1)<<"	p "<<potentiel<<"	2"<<std::endl;
		++time;
	};
	return spikes;
	
}

/*
 * RESOUT L'EQUATION DIFFERENTIELLE DU POTENTIEL DE LA MEMBRANE 
 * EN MODE DEBUG AFFICHE SI AU TEMPS T LE NEURON EST STIMULÉ PAR UN AUTRE 
   DANS CE CAS ,IL DIT A QUEL MOMENT IL EST STIMLÉ
 * COMPARER CETTE VALEUR AU DERNIER SPIKE DU NEURON RELIE PERMET DE 
   SAVOIR SI LE DELAI EST BON ET SI LE BUFFER CORRECTEMENT IMPLEMENTE
 */
void Neuron:: updatePotential ()
{
	int stimulus (0);
	stimulus = stimule();
	potentiel = exp(-h/Taue)*potentiel + iExt*R*(1-exp(-h/Taue)) + stimulus*J;
	if (stimulus > 0)
	{
		std::cout<<stimulus<<" stimule " <<"	"<<time<<std::endl;
	}
}

/*
 * AFFICHE SUR LE TERMINAL LE NEURON :
	* SON POTENTIEL 
 */
void Neuron:: displayNeuron() const
{
	std::cout<<"V: " <<potentiel<<std::endl;
	
}

/*
 * ENREGISTE LE TEMPS TIME EN STEPS DANS LE TEMPS DU DERNIER SPIKE LORSQUE APPELE 
 */
void Neuron:: storeSpikeTime ()
{
	tSpike = time;
}
/*
 * RETURNE LE TEMPS EN STEPS DU DERNIER SPIKE
 */
double Neuron:: getIExt ()const
{
	return iExt;
}

/*
 * RENTRE DANS IEXT A VALEUR PASSÉE EN PARAM 
 */
void Neuron:: setIExt(double I)
{
	iExt = I;
}

/*
 * RETOURNE LE TEMPS RÉEL DU DERNIER SPIKE 
 */
 double Neuron:: getTSpike() const
{
	return tSpike*h;
}
/*
 * GERE LA RECEPTION DU STIMULUS ET ENREGISTRE DANS LE BUFFER CE DERNIER
 */
void Neuron:: receive(int deliveryTime)
{
	++ringBuffer[deliveryTime % (DelaySteps+1)];
	//std::cout << "receive1  "<<name<<"	"<<deliveryTime % (DelaySteps+1)<<"	"<<ringBuffer[0]<<ringBuffer[1]<<ringBuffer[2]<<ringBuffer[3];
	
}

/*
 * VERIFIE SI AU MOMENT T , LE NEURON REÇOIT UN STIMULUS
 * SI C'EST LE CAS IL RETOURNE LE STIMULUS 
 */
int Neuron:: stimule()
{
	int t(time);
	int tpm (0);
	tpm = ringBuffer[t % (DelaySteps+1)];
	
	if(ringBuffer[t % (DelaySteps+1)] > 0)
	{
		ringBuffer[t % (DelaySteps+1)] = 0;
	}
	return tpm ;
}

/*
 * AFFICHE SUR LE TEMINAL LE BUFFER ET TOUT CE QU'IL CONTIENT 
 */
void Neuron:: displayBuffer (int i)const
{
	std::cout<<i<<"n "<<" display "<< ringBuffer[0]<<ringBuffer[1]<<ringBuffer[2]<<ringBuffer[3]<<std::endl;
}
