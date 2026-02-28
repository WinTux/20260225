#!/bin/bash
# Uso de condicionales
if [ -f "/etc/hosts" ]; then
  echo "El archivo hosts existe."
  echo ""
else
  echo "No existe el archivo."
fi
if [ -d "$HOME/Documentos/cosas" ]; then
  echo "La carpeta cosas existe."
  echo ""
else
  echo "No existe la carpeta."
fi

if [ "$USER" == "rusok" ]; then
  echo "¡Buenas noches estimado!"
fi

if [ "$EUID" -ne 0 ]; then
  echo "El script debe ejecutarse con SUDO"
  exit 1
fi
