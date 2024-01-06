git config --global user.email "tomkusarvydas@gmail.com"
git config --global user.name "arvtom"

apt-get update
apt-get -y install \
    git g++ nano\
    python3 pip \
    gnuplot libgnuplot-iostream-dev libboost-all-dev
pip install matplotlib numpy

#Get newest version of matplotlib-cpp
cd /home
git clone https://github.com/lava/matplotlib-cpp.git
cd matplotlib-cpp

cd /home && \
git clone https://github.com/dstahlke/gnuplot-iostream.git && \
cd gnuplot-iostream
