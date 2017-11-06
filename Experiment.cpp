#include "Experiment.h"
#include <iostream>
#include <limits> 
using namespace std ;

/**
 * Initialise the Experiment with his g and eta 
 **/
Experiment:: Experiment()
{
 askParameters();

}

/**
 * ask the user to enter the parameter g and eta 
 **/
void Experiment:: askParameters ()
{
	do{
		if(cin.fail())
			{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n' );
			
			}
			cout<<"Choose your value for ETA (intenger between  0 and 4)"<<std::endl;
			cin>>eta;
		}while (cin.fail() or eta < 0 or eta > 4);
	
	do{
			if(cin.fail())
			{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n' );
			
			}
			cout<<"Choose your value for g (intenger between  0 and 8)"<<std::endl;	
			cin>>g;
			}while (cin.fail() or g < 0 or g > 8);
	
}
/**
 * Run the experiment 
 **/
void Experiment:: doExperiment ()
{
	Network cortex(g,eta);
	cortex.update();
}
