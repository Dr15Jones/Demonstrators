//
// cint script to generate libraries
// Declare namespace & classes you defined
// #pragma statement: order matters! Google it ;)
//

#ifdef __ROOTCLING__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ namespace demonstrators+;
#pragma link C++ class     demonstrators::ClusterFinderAlgorithm+;
#pragma link C++ class     demonstrators::ClusterFinderHelper+;
//ADD_NEW_CLASS ... do not change this line
#endif
