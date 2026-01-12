# CheckApiV2ray - API de Validación de Usuarios

Una herramienta ligera y eficiente para consultar la vigencia (días restantes) de usuarios V2Ray directamente desde el archivo `config.json`. Diseñada para integrarse con paneles web, bots de Telegram o sistemas de monitoreo externos.

## 🚀 Características
- **Multi-arquitectura:** Binarios disponibles para `x86_64` (Intel/AMD) y `aarch64` (ARM/Raspberry Pi).
- **Flexible:** Permite definir puerto de escucha y ruta del archivo de configuración.
- **Respuesta JSON:** Formato estándar para fácil integración.
- **Modo Debug:** Visualización de peticiones en consola para depuración.

---

## 📥 Instalación en Linux

Elige la arquitectura de tu servidor (VPS) para descargar el binario correcto.

### Opción A: Arquitectura x86_64 y ARM64 (Estándar VPS)

# 1. Descargar el binario
```bash
wget https://raw.githubusercontent.com/ChumoGH/ADMcgh/main/BINARIOS/x86_64/CheckApiV2ray -O /usr/bin/CheckApiV2ray
```

# 2. Dar permisos de ejecución
```bash
chmod +x /usr/bin/CheckApiV2ray
```

# Sintaxis: CheckApiV2ray [PUERTO] [RUTA_CONFIG] [RUTA_USER]
```bash
CheckApiV2ray 909 /root/v2ray/config.json
```

http://<TU_IP>:<PUERTO>/?uuid=<UUID_DEL_USUARIO>

# Le damos permisos de ejecución
Paso 1: Ubicar el ejecutable
```bash
chmod +x /usr/bin/CheckApiV2ray
```

Paso 2: Crear el archivo del servicio
```bash
nano /etc/systemd/system/checkapi.service
```
Pega el siguiente contenido dentro del editor. Nota la línea ExecStart: ahí es donde configuramos el puerto, las rutas y la redirección del log al archivo que pediste.
```bash
[Unit]
Description=API V2Ray Check Service ChumoGH
After=network.target

[Service]
Type=simple
User=root
# Reiniciar automáticamente si falla
Restart=always
# Esperar 3 segundos antes de reiniciar
RestartSec=3

# --- COMANDO DE EJECUCIÓN ---
# Sintaxis: /bin/sh -c 'COMANDO PUERTO RUTA_JSON RUTA_USER >> ARCHIVO_LOG 2>&1'
# Aquí configuramos puerto 909 y las rutas que definiste.
ExecStart=/bin/sh -c '/usr/bin/CheckApiV2ray 909 /etc/v2ray/config.json /etc/v2r/user >> /var/log/v2ray.auth.log 2>&1'

[Install]
WantedBy=multi-user.target
```

# 1. Recargar el demonio de systemd para que lea el nuevo archivo
```bash
systemctl daemon-reload
```
# 2. Habilitar el servicio (para que arranque al encender el VPS)
```bash
systemctl enable checkapi.service
```
# 3. Iniciar el servicio ahora mismo
```bash
systemctl start checkapi.service
```

# PARA VER LOS LOGS
```bash
tail -f /var/log/v2ray.auth.log
```

##OPCIONAL 

```bash
nano /etc/logrotate.d/checkapi
```

Esto hará que el log se limpie cada día y solo guarde los últimos 7 días.

```bash
/var/log/v2ray.auth.log {
    daily
    rotate 7
    compress
    missingok
    notifempty
    copytruncate
}
```



Ejemplo de Uso
Si tu servidor es 144.22.43.189 y ejecutaste el script en el puerto 909:

Petición:

HTTP : (http://144.22.43.189:909/?uuid=a29d475a-d028-4b67-817a-5d3cea7693a8)

Respuestas JSON
✅ Usuario encontrado y fecha válida: Devuelve el número de días restantes.

JSON
```bash
{
  "name": "ChumoGH",
  "days": 100,
  "date": "2026-04-22",
  "status": "active",
  "message": "Usuario Activo"
}
```

❌ Usuario no encontrado, expirado o error:

JSON
```bash
{
  "name": null,
  "days": null,
  "date": null,
  "status": "not_found",
  "message": "Usuario no encontrado"
}
```