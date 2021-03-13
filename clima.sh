#!/bin/bash

clim=$(curl wttr.in/Guatemala) #declarando variable la cual contiene la informacion del clima de Guatemala.
touch climaG.txt  #creando el archivo que guardara el curl wttr.in/Guatemala
echo "$clim" > climaG.txt #escribiendo la informacion de la variable climacurl al archivo climaG.txt
head -7 climaG.txt #Leyendo las primeras 7 lineas del archivo
rm climaG.txt #borrando el archivo
