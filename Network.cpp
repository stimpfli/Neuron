#include "Network.h"
#include <iostream>
#include <random>
#include <cassert>


const double StepStop (TStop/h);


//CONSTRUCTEUR
/**
 * CONSTRUIT LES LIENS ENTRE LES NEURONES  
 * CONSTRUIT TOUS LES NEURONES DE LA SIMULATION 
 */

Network:: Network (double g, double eta)
 : t(0) , eta(eta), g(g)//, links (NbNeur)
{
	initExitatory();
	initInhibitory();
	assert(neurons.size() == Ni+Ne);
	initLinks();
	
}

/**
 * DIRIGE TOUTE LA SIMULATION A TRAVERS TOUS LES NEURONES
 * appelle transmit qui gère la transmition du spike aux autres neurones connecté
 * appelle store spike qui va enregistrer le temps et le numéros du neuron
 */
void Network:: update()
{

	do {
			for (size_t i (0);i < Ni+Ne;++i)
			{
				assert(t<StepStop);
				assert(i<neurons.size());
				if(neurons[i].update(1 , i,g,eta))
				{
					transmit(i);
				}
			}
			++t;
			
	}
	while (t<StepStop);
}

/**
 * parcours le deque de connection du neuron i et transmet le spike
 * @param le nombre du neuron qui transmet 
 */
void Network::transmit(size_t i)
{
	for (size_t j (0); j < neurons[i].getTargetsize() ;++j)
				{
					neurons[neurons[i].getNeuronNum(j)].receive(DelaySteps+t,neurons[i].getJ(),g);
}
}

/**
 *initialise tous les neurones excitateur
 */
void Network:: initExitatory()
{

	for (int i(0); i < Ne; ++i)
	{
		neurons.push_back(Neuron (0.0,Je));
	}
}

/**
 * initialise tous les neurones inhibiteur
 */
void Network:: initInhibitory()
{
	
		double Ji = -Je*g;
	for (int i(0); i < Ni; ++i)
	{

		neurons.push_back(Neuron (0.0,Ji,g));
	}
}

/**
 * genere aléatoirement des liens etre les neurones avec 10% de connection
 */
void Network:: initLinks()
{
	static std::random_device rd ;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<int> distribExit(0,Ne-1);
	static std::uniform_int_distribution<int> distribInhib(Ne,Ne+Ni-1);
	
	for (int i (0) ; i < (Ni+Ne) ; ++i)
	{
		for (int j (0) ; j < Ce ; ++j)
		{
			
			neurons[distribExit(gen)].connect(i);
		}
		
		for (int u (0) ; u < Ci ; ++u)
		{
			neurons[distribInhib(gen)].connect(i);
		}
	}
	
	std::cout<<"hello"<<std::endl;

}
/*
 * connecte le neuron a au neuron b
 * @param l'indice du neuron a 
 * @param l'indice du neuron b
 
void Network:: connect (size_t idA ,size_t idB)
{
	assert(idA <  links.size());
	links[idA].push_back(idB);
}*/

/**
 * @param le neuron i a observer
 * @return le nombre de connection excitatrice au neuron i
 */
double Network:: countConnectionE (int numNeuron)
{
int connections (0) ;
	for (size_t i (0) ; i < neurons.size() ; ++i)
	{
		for(size_t j (0) ; j < neurons[i].getTargetsize() ; ++j )
		if (neurons[i].getJ() == Je and neurons[i].getNeuronNum(j) == numNeuron)
		{
			++connections  ;
		}
	}
return connections ;
	
}

/**
 * @param le neuron i a observer
 * @return le nombre de connection inhibitrice au neuron i
 */
double Network:: countConnectionI (int numNeuron) 
{
	int connections (0) ;
	double Ji = - Je*g;
	for (size_t i (0) ; i < neurons.size() ; ++i)
	{
		for(size_t j (0) ; j < neurons[i].getTargetsize() ; ++j )
		if (neurons[i].getJ() == Ji  and neurons[i].getNeuronNum(j) == numNeuron)
		{
			++connections  ;
		}
	}
return connections ;
	
}

/**
 * @param le neuron i dont on veut savoir le poid 
 * @return le poid associé au neuron i
 */
double Network:: getWeight (int numNeuron)
{
	return neurons[numNeuron].getJ();
}

/**
 * @return Le paramètre g de la simulation 
 **/
double Network:: getG ()
{
	return g;
}
