# Nemergent

## Descripción
Nemergent es una aplicación multi-hilo que genera números aleatorios únicos y los clasifica en listas de pares e impares. El programa muestra una barra de progreso durante la ejecución y maneja correctamente las señales de interrupción.

## Requisitos
- Compilador GCC
- Soporte para hilos POSIX
- Entorno Linux/UNIX

## Instalación
Clona el repositorio y compila el programa:

```bash
git clone https://github.com/nakamavg/NemergenPrueba 
cd Nemergent
make
```

## Uso
El programa puede ejecutarse con las siguientes opciones:

```bash
./Nemergent -h | --help                # Muestra el mensaje de ayuda
./Nemergent -f | --file <archivo_config>  # Ejecuta con el archivo de configuración especificado
```

### Archivo de Configuración
El archivo de configuración debe ser un archivo `.txt` con los siguientes parámetros:

