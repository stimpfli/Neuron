#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "Network.h"
/**
 * Crée l'experience demande différente constante pour créel'éxperience 
 * de notre choix 
 * parametres g et eta modifiables

 **/
class Experiment 
{
	private:
	double g;    ///< g one parameter of the experiment
	double eta; ///< eta the other parameter of the experiment 
	void askParameters ();
	
	public:
	
	Experiment ();
	void doExperiment ();

	
};
#endif
