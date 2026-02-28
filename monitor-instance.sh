#!/bin/bash
TARGET="$1"
LOG="/var/log/monitor-$TARGET.log"
echo "Iniciando monitoreo de $TARGET a las $(date)" >> "$LOG"

while true; do
  if ping -c 1 -W 2 "$TARGET" > /dev/null; then
    echo "$(date): $TARGET está activo" >> "$LOG"
  else
    echo "$(date): ERROR - $TARGET no responde" >> "$LOG"
  fi
  sleep 10
done
