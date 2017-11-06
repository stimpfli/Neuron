#include "Neuron.hh"
#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <random>

std::ofstream pikeStorageout("pikeStorage.dat",/*std::ios::app,*/std::ios::trunc); //dossier stockage

//CONSTRUCTEUR 
/**
 * Initialize the time of the neuron and set the time of the last spike to zero 
 * Initialize the ringbuffer with 0 and the size 
 * @param the initial potentiel
 * @param the J of the neuron (Je or Ji)
 */
Neuron:: Neuron (double V , double J, double g )
:potentiel (V),nbSpikes(0),tSpike(0),time(tStart),iExt(0), ringBuffer(DelaySteps+1,0) ,J(J) , test(false)
{
	double Ji =-Je*g;
	assert (J == Je or J == Ji);
}
/**
 * write into the file the time of the neuron 
 * write the number of the neuron 
 * @param the stream to the file 
 */
void Neuron:: storeSpike (std::ofstream& pikeStorage , int i)const
{	
	pikeStorage<<time*h<<"	"<<i<<'\n';
}
/**
 * @return the number of spikes
 */
int Neuron:: getNbSpikes () const
{
	return nbSpikes;
}

/**
 * @return the membrane potential
 */
double Neuron:: getPotentiel()const
{
	return potentiel;
}
/**
 * itarate on the numer of steps 
 * collect the external stimulus ,if in test mode no poisson distribution (external stimulation)
 * if the potential pass theta ( set the potential to Vref):
	* store the time of the last spike
	* add one to the number of spikes
	* set te bool to true 
 * if the neuron spiked and you are during the refractory period:
	* maintain the potential to Vref
 * else:
	* 	change the value of the membrane potential
 * add one to the number of steps
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
			potentiel = Vref;	
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
 *rResolve the differetnial equation of the neuron
 * @param the extarnal stimulus
 */
void Neuron:: updatePotential (double S)
{
	potentiel = exp(-h/Taue)*potentiel + iExt*R*(1-exp(-h/Taue)) + S;

}

/**
 * display on the terminal the neron :
	* his potential
 */
void Neuron:: displayNeuron() const
{
	std::cout<<"V: " <<potentiel<<std::endl;
	
}

/**
 * Store the time in tSpike 
 */
void Neuron:: storeSpikeTime ()
{
	tSpike = time;
}
/**
 * @return the external courant 
 */
double Neuron:: getIExt ()const
{
	return iExt;
}

/**
 * @param The intensity of the courant you want to apply to the neuron 
 */
void Neuron:: setIExt(double I)
{
	iExt = I;
}

/**
 * @returnreturn the real time (ms) of the last spike 
 */
 double Neuron:: getTSpike() const
{
	return tSpike*h;
}
/**
 * manage the reception of the spike 
 * @param the delivery time of the stimulation 
 * @param the J of the neuron that transmit the spike
 * @param the g choosen in the experiment class
 */
void Neuron:: receive(int deliveryTime, double J, double g)
{
	assert(deliveryTime % (DelaySteps+1) <= ringBuffer.size());
	assert(J == -Je*g or J == Je);
	ringBuffer[deliveryTime % (DelaySteps+1)] += J;	
}

/**
 * check if at the time t the neuron have to receive a spike
 * @return the stimulus present in the buffer 
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
 * display the buffer and his content 
 */
void Neuron:: displayBuffer (int n)const
{	
	for(unsigned int i (0);i < ringBuffer.size() ; ++i)
	std::cout<<n<<"n "<<" display "<< ringBuffer[i]<<std::endl;
}

/**
 *@return the J of the neuron Je or Ji  
 */
double Neuron:: getJ() const
{
	return J;
}

/**
 * Set the test mode on  
 */
void Neuron:: testOn()
{
	test = true;
}

/**
 * set the test mode of 
 */
void Neuron:: testOff()
{
	test = false;
}

/**
 * Connect the neuron to neuron i
 * @param the neuron i
 **/
 
void Neuron:: connect(size_t numNeuron)
{
	assert(numNeuron < Ne+Ni);
	targets.push_back(numNeuron);
}

/**
 * @param the place i in the vector of target 
 * @return the index of the neuron corresponding to place i
 **/
 
int Neuron:: getNeuronNum(size_t connectionNum)
{
	assert(connectionNum < targets.size());
	return targets[connectionNum];
}

/**
 * @return the size of the vector of connection 
 */
size_t Neuron:: getTargetsize()
{
	return targets.size();
}

