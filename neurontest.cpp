#include "gtest/gtest.h"
#include "Neuron.h"
#include "Network.h"
#include <cmath>


TEST (NeuronTest , MembranePotentialCalculation) {
		Neuron neuron (0);
		neuron.setIExt(1.0);
	
		neuron.update(1);
	EXPECT_EQ(20.0*(1.0-exp(-0.1/20.0)),neuron.getPotentiel());
	
	}
	
TEST (NeuronTest , SpikeTimes) {
		Neuron neuron (0);
		neuron.setIExt(1.01);
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

int main (int argc, char **argv)
{
	::testing::InitGoogleTest(&argc , argv);
	return RUN_ALL_TESTS();
}
