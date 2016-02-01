#include "DataFormat/storage_manager.h"
#include "FakeClusterFinder/ClusterFinderHelper.h"

int main(){

  larlite::storage_manager storage;

  storage.set_verbosity(larlite::msg::kDEBUG);

  storage.set_io_mode(larlite::storage_manager::kBOTH);

  storage.add_in_filename("trial.root");
  storage.set_out_filename("fakeclusters.root");

  storage.open();

  while (storage.next_event()) {

    storage.set_id(storage.run_id(), storage.subrun_id(), storage.event_id());

    demonstrators::ClusterFinderHelper helper;

    helper.findClusters(storage, "test");
  }

  storage.close();

  return 0;
}
