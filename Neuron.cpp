#include "Neuron.hh"
#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <random>

std::ofstream pikeStorageout("pikeStorage.dat",/*std::ios::app,*/std::ios::trunc); //dossier stockage

//CONSTRUCTEUR 
/**
 * INITIALISE LE TEMPS DU NEURON ET MET LE TEMPS DU 1ER SPIKE 0
 * INITIALISE LE BUFFER A SA TAILLE REMPLIS DE 0
 *@param Le voltage intitial et le J du neurone (Je ou Ji)
 */
Neuron:: Neuron (double V , double J, double g )
:potentiel (V),nbSpikes(0),tSpike(0),time(tStart),iExt(0), ringBuffer(DelaySteps+1,0) ,J(J) , test(false)
{
	double Ji =-Je*g;
	assert (J == Je or J == Ji);
}
/**
 * ECRIS TOUTE LES VALEURS DANS LE DOSSIER PASSER EN PARAM
 * ECRIS A COTÉ LE NUMÉROS ASSOCIÉ AU NEURON
 * @param un stream vers un fichier
 */
void Neuron:: storeSpike (std::ofstream& pikeStorage , int i)const
{	
	pikeStorage<<time*h<<"	"<<i<<'\n';
}
/**
 * @return le nb de spikes
 */
int Neuron:: getNbSpikes () const
{
	return nbSpikes;
}

/**
 * @return le potentiel membranaire
 */
double Neuron:: getPotentiel()const
{
	return potentiel;
}
/**
 * ITÈRE SUR LE NOMBRE DE STEPS 
 * VERIFIE LES STIMULUS EXTERNE SI EN MODE TEST , STIMULATION DE L'EXTERIEUR DE LA SIMULATION NE SONT PAS PRIS EN COMPTE (VOIR GOOGLE TEST)
 * SI LE POTENTIEL DEPASSE THETA ( VREFRACTORY ):
	*  STORE LE TEMPS DU DERNIER SPIKE
	* INCREMENTE COMPTEUR DE SPIKE 
	* MET LE BOOL A TRUE 
 * SI IL Y A EU UN SPIKE AVANT ETT QUE L'ON SE TROUVE DANS LE REFRACTORY TIME:
	* MAINTIENT LE POTENTIEL A 0 mV 
 * SINON:
	* 	MODIFIE LA VALEUR DU POTENTIEL 
 *AUGMENTE LES STEPS DE SIMULATION DE 1
 * @return true si le neuron a spiké
 * @param la position du neuron dans le cortex (simulation) , le nombre de steps
 */
bool Neuron:: update (long steps , int i,double g, double eta )
{
	
	if (steps == 0){return false;}
	bool spikes (false);
	double timeStop(time + steps);			
	
	double Lambda = NuThr*eta*Ce*h;
	assert ( Lambda >= 1 and  Lambda <= 2 );
	static std::poisson_distribution<> poisson(Lambda); //Frequence in mV/steps
	static std::random_device rd ;
	static std::mt19937 gen(rd());
	
	
	while (time < timeStop)
	{ 
		double stimulus (0);
		if(!test)
		{
			stimulus = stimule() + Je * poisson(gen)  ;
		
		}
		
		else 
		{
			stimulus = stimule();
		}
		
		if (potentiel >= Teta )
		{
			storeSpikeTime();
			++nbSpikes;
			spikes = true;
		storeSpike(pikeStorageout,i);
		
		}
		if (tSpike > 0 and time - tSpike < refractorySteps )
		{
			potentiel = 0;	

		}	
		else 
		{
			updatePotential(stimulus);

		}
	
		++time;
	};
	return spikes;
	
}

/**
 * RESOUT L'EQUATION DIFFERENTIELLE DU POTENTIEL DE LA MEMBRANE 
 * @param les stimulus de l'extérieur 
 */
void Neuron:: updatePotential (double S)
{
	potentiel = exp(-h/Taue)*potentiel + iExt*R*(1-exp(-h/Taue)) + S;

}

/**
 * AFFICHE SUR LE TERMINAL LE NEURON :
	* SON POTENTIEL 
 */
void Neuron:: displayNeuron() const
{
	std::cout<<"V: " <<potentiel<<std::endl;
	
}

/**
 * ENREGISTE LE TEMPS TIME EN STEPS DANS LE TEMPS DU DERNIER SPIKE LORSQUE APPELE 
 */
void Neuron:: storeSpikeTime ()
{
	tSpike = time;
}
/**
 * @return l'intensité du courant 
 */
double Neuron:: getIExt ()const
{
	return iExt;
}

/**
 * @param l'intensité que l'on veut soumettre au neuron 
 */
void Neuron:: setIExt(double I)
{
	iExt = I;
}

/**
 * @return le temps réel du dernier spike
 */
 double Neuron:: getTSpike() const
{
	return tSpike*h;
}
/**
 * GERE LA RECEPTION DU STIMULUS ET ENREGISTRE DANS LE BUFFER CE DERNIER
 * @param le moment ou ce spike doit etre transmit et le poids de ce dernier 
 */
void Neuron:: receive(int deliveryTime, double J, double g)
{
	assert(deliveryTime % (DelaySteps+1) <= ringBuffer.size());
	assert(J == -Je*g or J == Je);
	ringBuffer[deliveryTime % (DelaySteps+1)] += J;	
}

/**
 * VERIFIE SI AU MOMENT T , LE NEURON REÇOIT UN STIMULUS
 * @return le stimulus dans le buffer au temps t (venant des autres neurons)
 */
double Neuron::stimule()
{
	
	int t(time);
	double tpm (0);
	assert(t % (DelaySteps+1) < ringBuffer.size());
	tpm = ringBuffer[t % (DelaySteps+1)];
	ringBuffer[t % (DelaySteps+1)] = 0;
	return tpm ;
}

/**
 * AFFICHE SUR LE TEMINAL LE BUFFER ET TOUT CE QU'IL CONTIENT 
 */
void Neuron:: displayBuffer (int n)const
{	
	for(unsigned int i (0);i < ringBuffer.size() ; ++i)
	std::cout<<n<<"n "<<" display "<< ringBuffer[i]<<std::endl;
}

/**
 *@return le J du neuron (Ji ou Je) 
 */
double Neuron:: getJ() const
{
	return J;
}

/**
 * Passe le neuron en mode test 
 */
void Neuron:: testOn()
{
	test = true;
}

/**
 * sors le neuron du mode test 
 */
void Neuron:: testOff()
{
	test = false;
}

/**
 * Connecte le neuron au neuronI
 * @param Le numero du neuron connecté a this 
 **/
 
void Neuron:: connect(size_t numNeuron)
{
	assert(numNeuron < Ne+Ni);
	targets.push_back(numNeuron);
}

/**
 * @param la i eme place dans le tableau de connection
 * @return le numero du neuron correpondant a la connection connectionNum
 **/
 
int Neuron:: getNeuronNum(size_t connectionNum)
{
	assert(connectionNum < targets.size());
	return targets[connectionNum];
}

/**
 * @return la taille du vecteur de connection 
 */
size_t Neuron:: getTargetsize()
{
	return targets.size();
}

