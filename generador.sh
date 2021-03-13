#!/bin/bash

#Autor: Cindy Gatica
#Fecha: 12/03/2021
#Tipo de archivo: Script de bash
#Para ejecutar ./generador.sh
#Resumen: Script que crea automaticamente un archivo para programar en c

#bienvenida
echo"**Generador de archivos C**"
#obtener y validar el nombre del archivo
read -p "Ingrese el nombre del archivo c:" nombre
filename=$nombre".c"
if [ -z $nombre ]; then
        echo "no ingreso un nombre"
        exit 2
fi
#Informacion usuario Linux
autor=$(whoami)
fecha=$(date)
compilador=$(gcc --version|head -n 1)
#Compilado=$(gcc nombre.c -o nombre)

#Contenido del archivo
echo "/*" > $filename #se agrega /* al inicio del archivo
echo "Autor: " $autor >> $filename #autor obtenido se agrega en filename
echo "Compilador :"$compilador >> $filename # agregamos Compilador:+la informacion obtenida por la variable compilador
echo Para compilar: gcc -o $nombre $filename >> $filename
echo "Fecha: " $fecha >> $filename
echo "Librerias: stdio,(otras) " >> $filename
echo "Resumen: (en blanco) " >> $filename
echo "Entrada: (en blanco) " >> $filename
echo "Salida: (en blanco) " >> $filename
echo "*/" >> $filename
