#!/bin/bash
LOGFILE=$1
# Contadores
INFO=0
WARN=0
ERROR=0
DEBUG=0
# Leyendo el archivo linea por linea
while read -r linea; do
  nivel=$(echo "$linea" | awk '{print $4}')
  # Evaluar con case
  case "$nivel" in
    INFO)
      ((INFO++))
      ;;
    WARN)
      ((WARN++))
      ;;
    ERROR)
      ((ERROR++))
      ;;
    DEBUG)
      ((DEBUG++))
      ;;
    *)
      echo "Nivel desconocido: $nivel"
  esac
done < "$LOGFILE"

# Mostrar resumen
echo ""
echo "Resumen de logs:"
echo "----------------"
echo "INFO : $INFO"
echo "WARN : $WARN"
echo "ERROR: $ERROR"
echo "DEBUG: $DEBUG"
