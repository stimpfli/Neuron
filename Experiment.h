#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "Network.h"

class Experiment 
{
	private:
	double g;    ///< g one parameter of the experiment
	double eta; ///< eta the other parameter of the experiment 
	
	public:
	
	Experiment (double g, double eta );
	void doExperiment () const ;

	
};
#endif
