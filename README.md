# Monitor de Hosts con systemd (monitor@.service)

Este proyecto permite monitorear la disponibilidad de un host (por ejemplo, `google.com`) usando un servicio plantilla de **systemd** que ejecuta un script en bucle infinito y registra el resultado en un log independiente por instancia.

---

## Estructura

- Script: `/usr/local/bin/monitor-instance.sh`
- Servicio plantilla: `/etc/systemd/system/monitor@.service`
- Logs: `/var/log/monitor-<host>.log`

---

## Crear el script de monitoreo

Crear el archivo y cambiar permisos de ejecución
```bash
sudo chmod +x /usr/local/bin/monitor-instance.sh
```
## Recargar systemd

Cada vez que se crea o modifica un servicio:
```bash
sudo systemctl daemon-reload
``` 
## Iniciar un servicio:
```bash
sudo systemctl start monitor@google.com
```
## Habilitar inicio automático al arrancar el sistema
```bash
sudo systemctl enable monitor@google.com
```
