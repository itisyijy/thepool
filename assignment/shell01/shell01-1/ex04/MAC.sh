ifconfig | grep -w 'ether' | tr -d ' ' | tr -d '\t' | tr -d 'ether'
