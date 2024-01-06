apt-get update
apt-get -y install git g++ python3 pip nano gnuplot libgnuplot-iostream-dev
pip install matplotlib numpy

#Get newest version of matplotlib-cpp
cd /home
git clone https://github.com/lava/matplotlib-cpp.git
cd matplotlib-cpp

cd /home && \
git clone https://github.com/dstahlke/gnuplot-iostream.git && \
cd gnuplot-iostream