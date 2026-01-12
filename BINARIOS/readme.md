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

# Movemos el binario a /usr/bin (ruta estándar de ejecutables)
```bash
mv CheckApiV2ray /usr/bin/CheckApiV2ray
```
# Le damos permisos de ejecución
```bash
chmod +x /usr/bin/CheckApiV2ray
```
```bash
nano /etc/systemd/system/checkapi.service
```

Ejemplo de Uso
Si tu servidor es 144.22.43.189 y ejecutaste el script en el puerto 909:

Petición:

HTTP

(http://144.22.43.189:909/?uuid=a29d475a-d028-4b67-817a-5d3cea7693a8)
Respuestas JSON
✅ Usuario encontrado y fecha válida: Devuelve el número de días restantes.

JSON

{
  "name": "ChumoGH",
  "days": 100,
  "date": "2026-04-22",
  "status": "active",
  "message": "Usuario Activo"
}

❌ Usuario no encontrado, expirado o error:

JSON

{
  "name": null,
  "days": null,
  "date": null,
  "status": "not_found",
  "message": "Usuario no encontrado"
}
