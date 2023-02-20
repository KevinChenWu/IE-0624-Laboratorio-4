#!/usr/bin/python3

import serial
import paho.mqtt.client as mqtt
import json

def on_connect(client, userdata, flag, rc):
	if not rc:
		print("Conexión exitosa")
	else:
		print(f"Conexión no exitosa, código={rc}")

def on_disconnect(client, userdata, flag, rc):
	if not rc:
		print("Desconexión exitosa")
	else:
		print(f"Desconexión mediante código={rc}")

ser = serial.Serial("/dev/ttyACM0", 115200, timeout = 1) 
print("Se ha conectado al puerto serial /dev/ttyACM0")

client = mqtt.Client("seismograph_client")
client.on_connect = on_connect
client.on_disconnect = on_disconnect

server = "iot.eie.ucr.ac.cr"
port = 1883
topic = "v1/devices/me/telemetry"
token = "JgLPkaWbe68gWbvJX994"

client.username_pw_set(token)
client.connect(server, port)

dictionary = dict()

while True:
	line = ser.readline().decode("utf-8")
	line = line.replace("\r", "").replace("\n", "")
	line = line.split(",")
	if len(line) == 4:
		dictionary["X"] = line[0]
		dictionary["Y"] = line[1]
		dictionary["Z"] = line[2]
		dictionary["Battery"] = line[3]
		if float(line[3]) < 7:
			dictionary["Low Battery"] = "Yes"
		else:
			dictionary["Low Battery"] = "No"
		msg = json.dumps(dictionary)
		print(msg)
		client.publish(topic, msg)