# ========================================================= #
#                                                           #
#                   NTL-install script                      #
#                                                           #
#   This script install the NTL, GMP and gf2x libs to use   #
# in sshared project.                                       #
#   This script works for 64bits UNIX-like systems. For     #
# more instructions, access the official NTL docs.          #
#                                                           #
#   ERRORS: See the error section                           #
#                                                           #
# ========================================================= #

# INSTALL DIR
INSTALL_DIR='ntl_install'
# VERSIONS
NTL='ntl-10.3.0'
GMP='gmp-6.1.2'
GF2X='gf2x-1.1'

# Setup
mkdir ${INSTALL_DIR}
cd ${INSTALL_DIR}

# < DOWNLOAD >
echo 'Downloading files...'
# NTL
wget http://www.shoup.net/ntl/${NTL}.tar.gz
# GMP
wget https://gmplib.org/download/gmp/${GMP}.tar.bz2
# gf2x
wget http://gforge.inria.fr/frs/download.php/file/30873/${GF2X}.tar.gz
echo 'Download done!'
# < \DOWNLOAD >

# < EXTRACT >
echo 'Extract files...'
# NTL
tar -xvzf ${NTL}.tar.gz
# GMP
tar -jzvf ${GMP}.tar.bz2
# gf2x
tar -xvzf ${GF2X}.tar.gz
echo 'Extract done!'
# < \EXTRACT >

# < INSTALL >
echo 'Install section...'
# < GMP >
    echo 'Installing GMP'
    cd ${GMP}
    ./configure --prefix=$HOME/sw
    make
    make check
    make install
    # return to root directory
    cd ..
    echo 'Installing GMP done!'
# < \GMP >
# < GF2X >
    echo 'Installing gf2x'
    cd ${GF2X}
    ./configure --prefix=$HOME/sw ABI=64 CFLAGS='-m64 -O2'
    make
    make check
    make install
    echo 'Symbolic links creation'
    sudo ln -s $HOME/sw/lib/libgf2x.so.1.0.0 /usr/lib/libgf2x.so.1.0.0
    sudo ln -s $HOME/sw/lib/libgf2x.so.1.0.0 /usr/lib/libgf2x.so.1
    sudo ln -s $HOME/sw/lib/libgf2x.so.1.0.0 /usr/lib/libgf2x.so
    # return to root directory
    cd ..
    echo 'Installing gf2x done!'
# < \GF2x >
# < NTL >
    echo 'Installing NTL (this may take some time)'
    cd ${NTL}/src
    ./configure PREFIX=$HOME/sw NTL_GF2X_LIB=on GF2X_PREFIX=$HOME/sw GMP_PREFIX=$HOME/sw
    make
    make check
    make install
    # return to root directory
    cd ../..
    echo 'Installing NTL done!'
# < \GF2x >

# Cleanup
cd ..
rm -rf ${INSTALL_DIR}

echo 'Install done! :)'
# < \INSTALL >

# ========================================================= #
#                                                           #
#                   POSSIBLE ERRORS                         #
#                                                           #
#   If you find any errors on install, try run these        #
# commands:                                                 #
#   sudo apt-get install m4                                 #
#   sudo apt-get install g++                                #
#                                                           #
# ========================================================= #
