General info about GNUradio and USRP hardware
----------------------------------------
- When using hardware devices the Throttle MUST be removed from the flow-graph. The hardware device is now responsible for the rate limiting. Mixing hardware device and the Throttle block may break the real-time boundary of your flow-graph required by the device. Underflows or Overflows messages should be produced by the UHD driver in such a case [See this] (http://stackoverflow.com/questions/35445529/gfsk-modulation-demodulation-with-gnu-radio-and-usrp/36352846#36352846)

- General info about GNURadio [see](http://www.ece.uvic.ca/~elec350/grc_doc/ar01s12s01.html)
- Practical code for GNURadio [see](http://www.csun.edu/~skatz/katzpage/sdr_project/sdr/)

Installation
-------------
- Hint missing libs:
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
