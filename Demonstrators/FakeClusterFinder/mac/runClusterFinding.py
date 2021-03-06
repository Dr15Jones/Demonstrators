import sys
from ROOT import larlite
import ROOT

man=larlite.storage_manager()
man.set_io_mode(man.kBOTH)

# you can generate the input file using
# core/DataFormat/bin/simple_write.cc
man.add_in_filename("trial.root")

man.set_out_filename("fakeclusters.root")
man.set_verbosity(larlite.msg.kDEBUG)
man.open()

while man.next_event() :

    man.set_id(man.run_id(), man.subrun_id(), man.event_id())

    helper = ROOT.demonstrators.ClusterFinderHelper()

    helper.findClusters(man, "test")

man.close()
