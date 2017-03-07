- Notes on Xlating FIR filter [see] (http://andrej-mohar.com/frequency-xlating-fir-filter-and-channeling-basics-in-gnuradio)
- Sampling BT signale:
sudo ./rx_samples_to_file --type float --nsamps 2000000 --rate 2000000 --freq 2404000000 --gain 45 --bw 10000000 
- gr-bluetooth:
./btrx --freq 2441000000 -i usrp_samples.dat
