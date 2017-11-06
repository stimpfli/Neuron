#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "Network.h"
/**
 * Créate the experiment 
 * Contain g and eta 

 **/
class Experiment 
{
	private:
	double g;    ///< The parameter g of the experiment 
	double eta; ///<  The parameter eta of the experiment 
	void askParameters ();
	
	public:
	
	Experiment ();
	void doExperiment ();

	
};
#endif
