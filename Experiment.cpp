#include "Experiment.h"
#include <iostream>
#include <limits> 
using namespace std ;

/**
 * initialise l'experience avec les constantes g,eta
 **/
Experiment:: Experiment()
{
 askParameters();

}

/**
 * demande les paramètres de l'experience a l'utilisateur 
 * indication pour une simulation avec état stable eta = 2 g=4
 * 
 **/
void Experiment:: askParameters ()
{
	do{
		if(cin.fail())
			{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n' );
			
			}
			cout<<"Entrer une valeur pour eta (entier entre 0 et 4)"<<std::endl;
			cin>>eta;
		}while (cin.fail() or eta < 0 or eta > 4);
	
	do{
			if(cin.fail())
			{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n' );
			
			}
			cout<<"Entrez une valeur pour g (entre 0 et 8)"<<std::endl;	
			cin>>g;
			}while (cin.fail() or g < 0 or g > 8);
	
}
/**
 * run l'experience crée le network
 **/
void Experiment:: doExperiment ()
{
	Network cortex(g,eta);
	cortex.update();
}
