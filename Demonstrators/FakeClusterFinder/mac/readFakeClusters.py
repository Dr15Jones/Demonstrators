import sys
from ROOT import larlite
import ROOT

man=larlite.storage_manager()
man.set_io_mode(man.kREAD)
man.add_in_filename("fakeclusters.root")
man.set_verbosity(larlite.msg.kDEBUG)
man.open()

while man.next_event() :

    my_larsoftclusters = man.get_data(larlite.data.kLarSoftCluster, "fakecluster");

    print "larsoft clusters size = {}, element 0 NHits = {}, element 1 NHits = {}".format(my_larsoftclusters.product().size(), my_larsoftclusters.product().at(0).NHits(), my_larsoftclusters.product().at(1).NHits())

man.close()

