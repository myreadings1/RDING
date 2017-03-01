#install gnuradio and helpers
sudo apt-get install gnuradio 

#if you get errors about missing gruel and gnuradio-core, this fixes it 
# Also note that you need all of these libraries otherwise some of the gr-baz modules will not build completely
sudo apt-get install gnuradio-dev libboost-all-dev cmake libfftw3-dev libusb-1.0.0-dev swig libuhd-dev libarmadillo-dev

#install rtl-sdr
git clone git://git.osmocom.org/rtl-sdr.git
cd rtl-sdr/
mkdir build
cd build
cmake ../
make
sudo make install


#install gr-baz
git clone git://github.com/balint256/gr-baz.git
cd gr-baz
mkdir build
cd build
cmake ..
make
sudo make install
sudo ldconfig

#copy the blocks into your grc config director
cp ../grc ~/.grc_gnuradio