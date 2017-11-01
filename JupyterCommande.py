import numpy as np
import pylab as pl 

data = np.genfromtxt('pikeStorage.dat') 

select = np.array([d for d in data if d[1] < 100 ])
data1 = select.transpose()
pl.scatter(data1[0],data1[1],alpha=0.8,edgecolors='none');
pl.xlabel('Time (ms)')
pl.ylabel(u'NumNeuron')
pl.show();

n,bins,patches = pl.hist(data1[0],50,normed = 0 , alpha = 0.75)
pl.xlabel('Time (ms)')
pl.ylabel(u'Rate (Hz)')
pl.show(); 
