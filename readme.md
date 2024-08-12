# Medición de Distancia y Alarma con Buzzer usando HC-SR04 y Arduino

Este proyecto mide la distancia a un objeto utilizando el sensor ultrasónico HC-SR04 y un Arduino. Si la distancia es menor a 0.5 metros, se activa un buzzer que parpadea más rápidamente a medida que la distancia se reduce. Si la distancia es menor a 0.15 metros, el buzzer se mantiene encendido.

## Componentes Necesarios

- Arduino (por ejemplo, Uno, Nano, Mega)
- Sensor ultrasónico HC-SR04
- Buzzer pasivo
- Cables de conexión
- Protoboard (opcional)

## Diagrama de Conexión

- **Pin Trig** del HC-SR04 -> **Pin Digital 6** en Arduino
- **Pin Echo** del HC-SR04 -> **Pin Digital 7** en Arduino
- **Pin VCC** del HC-SR04 -> **5V** en Arduino
- **Pin GND** del HC-SR04 -> **GND** en Arduino
- **Pin Positivo del Buzzer** -> **Pin Digital 8** en Arduino
- **Pin Negativo del Buzzer** -> **GND** en Arduino

## Explicación del Código

Este código mide la distancia a un objeto usando el sensor HC-SR04 y ajusta el parpadeo de un buzzer en función de la distancia medida. Si la distancia es menor a 0.5 metros, el buzzer emite un sonido intermitente que se vuelve más rápido a medida que el objeto se acerca. Si la distancia es menor a 0.15 metros, el buzzer se mantiene encendido.

### Variables Clave

- `trigPin`: Pin conectado al pin Trig del sensor HC-SR04.
- `echoPin`: Pin conectado al pin Echo del sensor HC-SR04.
- `buzzerPin`: Pin conectado al buzzer pasivo.
- `duration`: Variable que almacena la duración del pulso de eco.
- `distance`: Variable que almacena la distancia calculada en metros.
- `delayTime`: Tiempo de espera entre los parpadeos del buzzer, basado en la distancia.

### Configuración

1. Configurar `trigPin` como salida, `echoPin` como entrada, y `buzzerPin` como salida.
2. Iniciar la comunicación serial a 9600 baudios para monitorear la distancia medida.

### Bucle Principal

1. Enviar un pulso ultrasónico desde el `trigPin`.
2. Medir la duración del pulso recibido en el `echoPin`.
3. Calcular la distancia en metros basada en la duración del pulso.
4. Si la distancia es menor a 0.5 metros, ajustar la frecuencia del parpadeo del buzzer en función de la distancia.
5. Si la distancia es menor a 0.15 metros, mantener el buzzer encendido.
6. Si la distancia es mayor a 0.5 metros, asegurarse de que el buzzer esté apagado.

## Cómo Usar

1. Conecta los componentes según el diagrama de conexión.
2. Sube el código a tu Arduino.
3. Abre el Monitor Serial (Ctrl+Shift+M en el IDE de Arduino) y configura la tasa de baudios a 9600.
4. Observa las lecturas de distancia en metros que se muestran y escucha el comportamiento del buzzer.

## Ejemplo de Salida

```bash
Distance: 0.75 m
Distance: 0.76 m
Distance: 0.75 m
```
(Sonido del buzzer dependiendo de la distancia medida)

## Notas

- El sensor HC-SR04 tiene un rango típico de 2 cm a 400 cm.
- La precisión de las lecturas puede verse afectada por factores como la temperatura y la superficie del objeto.
- Asegúrate de que el buzzer esté correctamente conectado al pin especificado para emitir los sonidos.

## Licencia

Este proyecto es de código abierto y está disponible bajo la [Licencia MIT](LICENSE).
