import sys
from larlite import larlite as fmwk
import ROOT

man=fmwk.storage_manager()
man.set_io_mode(man.kREAD)
man.add_in_filename("fakeclusters.root")
man.set_verbosity(fmwk.msg.kDEBUG)
man.open()

while man.next_event() :

    my_larsoftclusters = man.get_data(fmwk.data.kLarSoftCluster, "fakecluster");

    print "larsoft clusters size = {}, element 0 NHits = {}, element 1 NHits = {}".format(my_larsoftclusters.product().size(), my_larsoftclusters.product().at(0).NHits(), my_larsoftclusters.product().at(1).NHits())

man.close()

