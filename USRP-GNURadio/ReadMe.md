- Notes on Xlating FIR filter [see] (http://andrej-mohar.com/frequency-xlating-fir-filter-and-channeling-basics-in-gnuradio)
- See (https://www.youtube.com/watch?v=v7qjeUFxVwQ)
- To explain aliasing, sampling, and low pass filter (all are related).. See (https://www.youtube.com/watch?v=KT_xYgjM7L8)
- Sampling BT signale:
sudo ./rx_samples_to_file --type float --nsamps 2000000 --rate 2000000 --freq 2404000000 --gain 45 --bw 10000000 
- gr-bluetooth:
./btrx --freq 2441000000 -i usrp_samples.dat

- ./rx_multi_samples_1  --nsamps 2000000 --rate 2000000 --freq 2404000000 --gain 45 --channels 0,1

- GFSK Modulation
http://www.indigresso.com/wiki/doku.php?id=opentag:radios:testing_with_gnuradio
- RF-Tap
https://rftap.github.io/blog/2016/09/01/rftap-wifi.html
- GFSK modulation
https://www.reddit.com/r/DSP/comments/3u614q/gnu_radio_gfsk_modulation_rate_deviation/
- GFSK GNURadio
http://www.indigresso.com/wiki/doku.php?id=opentag:radios:testing_with_gnuradio
- Set max memory
sudo sysctl -w kernel.shmmax=2147483648
- B210 Overflow problem
https://github.com/EttusResearch/uhd/issues/58
- Overflow problem can be solved by selecting a fast computer with fast HDD like SSD. 

- I Q Data 1) http://whiteboard.ping.se/SDR/IQ, 2) http://www.ni.com/tutorial/4805/en/, 3) http://www.fourier-series.com/IQMod/index.html
