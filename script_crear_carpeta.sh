#!/bin/bash
mkdir /$1 2>/dev/null
if [ $? -ne 0 ]; then
  echo "Error al crear carpeta. Permisos insuficientes."
  exit 1
fi
