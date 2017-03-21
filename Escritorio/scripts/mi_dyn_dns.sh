#!/bin/bash

LUGAR="enlace"
IP=`curl ipecho.net/plain`

echo "<p><a href='http://$IP'>$LUGAR</a></p>" > /tmp/$LUGAR.html

curl --no-epsv --user u977517742:password -T /tmp/$LUGAR.html ftp://ftp.enzogt.esy.es/lugares/$LUGAR.html
