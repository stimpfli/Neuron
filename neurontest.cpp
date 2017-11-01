#include "gtest/gtest.h"
#include "Network.h"
#include <cmath>
//#include "Constantes.h"
#include <random>


TEST (NeuronTest , MembranePotentialCalculation) {
		Neuron neuron (0,0.1);
		neuron.setIExt(1.0);
		neuron.testOn();
	
		neuron.update(1);
	EXPECT_EQ(20.0*(1.0-exp(-0.1/20.0)),neuron.getPotentiel());
	
	}

TEST (NeuronTest , NegativeMembranePotentialCalculation) {
		Neuron neuron (-20,0.1);
		neuron.setIExt(0);
		neuron.testOn();
		
		neuron.update (100);
	ASSERT_GT (neuron.getPotentiel(),-15);
	}
		

	
TEST (NeuronTest , SpikeTimes) {
		Neuron neuron (0,0.1);
		neuron.setIExt(1.01);
		neuron.testOn();
		std::vector<double> tSpikes;
		int t (0);
		
		do
		{
			
			if (neuron.update(1))
			{

				tSpikes.push_back(neuron.getTSpike());
			}
			++t;
		}while (t < 3000);

		EXPECT_EQ(92.4,tSpikes[0]);
		EXPECT_EQ(186.8,tSpikes[1]);
		EXPECT_EQ(281.2,tSpikes[2]);
	}

TEST (NeuronTest , DelayTest)
{
	int delay (15);
	Neuron n1 (0,Je);
	Neuron n2 (0,Je);
	n1.testOn();
	n2.testOn();
	n1.setIExt(1.01);
	n2.setIExt(0);
	n1.update(924);
	EXPECT_EQ(0,n1.getNbSpikes());
	n1.update(1);
	EXPECT_EQ(1,n1.getNbSpikes());
	EXPECT_EQ(0,n1.getPotentiel());
	n2.receive(delay,Je);
	n2.update(delay);
	EXPECT_EQ(0,n2.getPotentiel());
	n2.update(1);
	EXPECT_EQ(0.1,n2.getPotentiel());
}

TEST (NeuronTest , ExternalCurrentTest )
{
	Neuron neuron (0,Je);
	neuron.setIExt(0);
	neuron.update(924);
	EXPECT_GT(neuron.getNbSpikes(),0);
}

TEST (NetworkTest , CiInhibitoryConnection )
{
	Network test;
	std::random_device rd ;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> randomNeuron(0,Ne+Ni);
	int neuronI = randomNeuron(gen);
	EXPECT_EQ(Ci,test.countConnectionI(neuronI));
}

TEST (NetworkTest , CeExitatoryConnection )
{
	Network test;
	std::random_device rd ;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> randomNeuron(0,Ne+Ni);
	int neuronI = randomNeuron(gen);
	EXPECT_EQ(Ce,test.countConnectionE(neuronI));
}

TEST (NetworkTest , tenPourcentConnection )
{
	Network test;
	std::random_device rd ;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> randomNeuron(0,Ne+Ni);
	int neuronI = randomNeuron(gen);
	EXPECT_EQ(Ce+Ci,test.countConnectionE(neuronI)+test.countConnectionI(neuronI));
}

TEST (NetworkTest , rightWeights )
{
	Network test;
	for (int i (0) ; i < Ne ; ++i)
	{
		EXPECT_EQ(test.getWeight(i),Je);
	}
	for (int i (Ne) ; i < Ne+Ni ; ++i)
	{
		EXPECT_EQ(test.getWeight(i),Ji);
	}
}

int main (int argc, char **argv)
{
	::testing::InitGoogleTest(&argc , argv);
	return RUN_ALL_TESTS();
}
