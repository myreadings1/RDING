General info about GNUradio and USRP hardware
----------------------------------------
- When using hardware devices the Throttle MUST be removed from the flow-graph. The hardware device is now responsible for the rate limiting. Mixing hardware device and the Throttle block may break the real-time boundary of your flow-graph required by the device. Underflows or Overflows messages should be produced by the UHD driver in such a case [See this] (http://stackoverflow.com/questions/35445529/gfsk-modulation-demodulation-with-gnu-radio-and-usrp/36352846#36352846)

- General info about GNURadio [see](http://www.ece.uvic.ca/~elec350/grc_doc/ar01s12s01.html)
- Practical code for GNURadio [see](http://www.csun.edu/~skatz/katzpage/sdr_project/sdr/)

Installation
-------------
- Hint missing libs [see] (Installation)