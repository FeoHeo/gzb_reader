#!bin/bash
cd light_ws/

source devel/setup.bash
echo "Script executed"
echo
echo "do rosrun light_ACK ack_mqtt to run ack for light "

echo "do rosrun reader light_core_reader to read light emitted"