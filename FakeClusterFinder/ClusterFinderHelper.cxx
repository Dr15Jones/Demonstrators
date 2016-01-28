#include "ClusterFinderHelper.h"

#include "ClusterFinderAlgorithm.h"
#include "DataFormat/storage_manager.h"
#include "DataFormat/wrapper.h"

#include <vector>

namespace recob {
  class Cluster;
  class Hit;
}


namespace demonstrators {

  void ClusterFinderHelper::findClusters(larlite::storage_manager& storage,
                                         std::string const& hitProducerName) const {

    auto hits = storage.get_data<larlite::wrapper<std::vector<recob::Hit> > >(hitProducerName);

    auto clusters = storage.get_data<larlite::wrapper<std::vector<recob::Cluster> > >("fakecluster");

    demonstrators::ClusterFinderAlgorithm algorithm;
    algorithm.findClusters(*hits->product(), *clusters->product());
  }
}
