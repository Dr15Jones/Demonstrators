#include "Demonstrators/FakeClusterFinder/ClusterFinderAlgorithm.h"

#include "lardataobj/RecoBase/Hit.h"
#include "lardataobj/RecoBase/Cluster.h"

namespace demonstrators {

  void ClusterFinderAlgorithm::findClusters(std::vector<recob::Hit> const& inputHits,
                                            std::vector<recob::Cluster> & outputClusters) const {

    // As a physics cluster finding algorithm, this is all nonsense.
    // This class exists only to test higher level software and
    // is not a real cluster finding algorithm.
    // It is used in a demonstration of how one might port an
    // algorithm from larlite to larsoft, and continue to develop
    // it in larlite.  For this purpose, it is enough that the
    // algorithm uses recob::Hit and constructs some recob::Cluster
    // objects and puts them in the output cluster vector.
    // It does this.

    float averagePeakTime = 0.0;
    for (auto const& hit : inputHits) {
      averagePeakTime += hit.PeakTime();
    }
    averagePeakTime = averagePeakTime / inputHits.size();

    unsigned int nHits = inputHits.size();

    recob::Cluster cluster(averagePeakTime,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           0.0,
                           nHits,
                           0.0,
                           0.0,
                           0,
                           static_cast<geo::View_t>(0),
                           geo::PlaneID()
                           );
    outputClusters.push_back(cluster);
    outputClusters.push_back(cluster);
  }
}
