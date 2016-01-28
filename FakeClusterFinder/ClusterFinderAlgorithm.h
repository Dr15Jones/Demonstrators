#ifndef DEMONSTRATORS_FAKECLUSTERFINDER_CLUSTERFINDERALGORITHM_H
#define DEMONSTRATORS_FAKECLUSTERFINDER_CLUSTERFINDERALGORITHM_H

// Contains larlite independent parts of fake cluster finding,

#include <vector>

namespace recob {
  class Cluster;
  class Hit;
}

namespace demonstrators {

  class ClusterFinderAlgorithm {
  public:

    void findClusters(std::vector<recob::Hit> const& inputHits,
                      std::vector<recob::Cluster> & outputClusters) const;
  };
}

#endif
