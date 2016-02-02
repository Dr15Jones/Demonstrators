# ======================================================================
#  Demonstrators main build file
#
#  cd .../path/to/build/directory
#  source .../path/to/Demonstrators/ups/setup_for_development
#  cmake [-DCMAKE_INSTALL_PREFIX=/install/path]
#        -DCMAKE_BUILD_TYPE=$CETPKG_TYPE
#        $CETPKG_SOURCE
#  make
#  make test
#  make install
#  make package (builds distribution tarfile)
# ======================================================================


# ----------------------------------------------------------------------
# Describe build tool requirements:

cmake_minimum_required(VERSION 2.8)  # use cmake 2.8 or later

# ----------------------------------------------------------------------
# Describe product:

project(Demonstrators)

# cetbuildtools contains our cmake modules
set( CETBUILDTOOLS_VERSION $ENV{CETBUILDTOOLS_VERSION} )
if( NOT CETBUILDTOOLS_VERSION )
  message( FATAL_ERROR "ERROR: setup cetbuildtools to get the cmake modules" )
endif()
set( CMAKE_MODULE_PATH $ENV{CETBUILDTOOLS_DIR}/Modules ${CMAKE_MODULE_PATH} )

include(CetCMakeEnv)
cet_cmake_env()

cet_set_compiler_flags(DIAGS VIGILANT
  WERROR
  NO_UNDEFINED
  EXTRA_FLAGS -pedantic
  )
cet_report_compiler_flags()

# ----------------------------------------------------------------------
# Describe build prerequisites:


find_ups_product (lardatalite)
find_ups_product (cetbuildtools)

# ----------------------------------------------------------------------
# Describe source tree layout:

add_subdirectory( ${PROJECT_NAME} )  # source code
add_subdirectory( ups )              # ups files

# ----------------------------------------------------------------------
# Packaging utility

include(UseCPack)

#
# ======================================================================
