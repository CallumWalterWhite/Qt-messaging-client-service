echo ${PASS} | sudo -S dpkg --configure -a
echo ${PASS} | sudo -S apt update
echo ${PASS} | sudo -S apt upgrade -y
echo ${PASS} | sudo -S apt dist-upgrade -y
echo ${PASS} | sudo -S apt autoremove -y
echo ${PASS} | sudo -S apt autoclean -y
echo ${PASS} | sudo -S apt install libtbb-dev build-essential gcc make cmake cmake-gui cmake-curses-gui libssl-dev -y
echo ${PASS} | sudo -S apt install doxygen graphviz libcppunit-dev catch libclang-common-8-dev libclang-common-8-dev -y
echo ${PASS} | sudo -S rm -rf ~/repositories
mkdir -p ~/repositories
cd repositories
git clone https://github.com/eclipse/paho.mqtt.c.git
cd paho.mqtt.c
cmake -Bbuild -H. -DPAHO_WITH_SSL=ON -DPAHO_ENABLE_TESTING=OFF
echo ${PASS} | sudo -S cmake --build build/ --target install
echo ${PASS} | sudo -S ldconfig
cd ~/repositories
git clone https://github.com/eclipse/paho.mqtt.cpp
cd paho.mqtt.cpp
cmake -Bbuild -H. -DPAHO_BUILD_DOCUMENTATION=TRUE -DPAHO_BUILD_SAMPLES=TRUE
echo ${PASS} | sudo -S cmake --build build/ --target install
echo ${PASS} | sudo -S ldconfig
echo ${PASS} | sudo -S updatedb


echo "Installing SQL Connector!"

echo ${PASS} | sudo -S apt install libmysqlcppconn-dev

echo "Installing Mysql!"

echo ${PASS} | sudo -S apt install mysql-server

echo "Installing Rapid JSON!"

echo ${PASS} | sudo -S apt install rapidjson-dev

echo "Installing CPP Unit!"

cd repositories
git clone https://github.com/eclipse/paho.mqtt.c.git
cd cppunit
./autogen.sh
./configure
echo ${PASS} | sudo -S make
echo ${PASS} | sudo -S make install

echo "Finished to updating the machine!"

echo "Please now run the inflation mysql script to create the databases!"

