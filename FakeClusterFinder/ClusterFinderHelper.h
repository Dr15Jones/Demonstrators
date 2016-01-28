#ifndef DEMONSTRATORS_FAKECLUSTERFINDER_CLUSTERFINDERHELPER_H
#define DEMONSTRATORS_FAKECLUSTERFINDER_CLUSTERFINDERHELPER_H

// Contains larlite dependent parts of cluster finding,
// which is getting the vector<recoB::Hit> and
// vector<recob:Cluster> from the storage_manager.
// Then this invokes the ClusterFinderAlgorithm
// to do the work of actually constructing the
// clusters from the hits.

#include <string>

namespace larlite {
  class storage_manager;
}

namespace demonstrators {

  class ClusterFinderHelper {
  public:

    void findClusters(larlite::storage_manager& storage,
                      std::string const& hitProducerName) const;
  };
}
#endif
