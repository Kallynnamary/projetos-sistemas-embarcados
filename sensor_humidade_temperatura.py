# Sensor de humidade e temperatura integrando arduino e phyton

# -*- coding: utf-8 -*-
import serial
from serial.tools import list_ports 

#Determinando as portas seriais disponiveis na maquina
# Entao, obtemos a lista de portas seriais e escolhemos manualmente
# a porta com index 1.

selectedPortIndex =1;
selectedDevice ="";

ports = list_ports.comports();
print("Avaiable ports:\n%s"%"\n".join(["\t%d: %s"%
(portIndex,str(ports[portIndex])) for portIndex inrange(len(ports))]));

selectedDevice = ports[selectedPortIndex].device;
print("Selected device: %s"%selectedDevice);

ser = serial.Serial(selectedDevice,57600);

# Cada execução lê uma linha da porta serial
# e separada os dois valores (umidade e temperatura)
# imprimindo no prompt
try:
    for line in ser:
        try:
            entry = line.decode("utf-8").split("\t");
            humidity =float(entry[0]);
            temperature =float(entry[1]);
            print(u"T: %gºC H:%g%%"%(temperature,humidity));
            except ValueErroras e:
                print("E: %s"%line);
                except IndexErroras e:
                    print("E: %s"%line);
                except KeyboardInterrupt:
                    
                    # Ao abortar a execução do programa esta exception é chamada
                    # deve-se então fechar a porta serial para novas comunicações 
                    ser.close();
                    except:
                    
                    #Caso seja um erro não especificado é importante fechar a porta
                    # serial para permitir comunicação futura 
                    ser.close();
                    