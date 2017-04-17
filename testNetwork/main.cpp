#include <iostream>
#include "client.h"
#include "server.h"
int main(void)
{
	/*
		1. DEFINO SI EMPIEZO O ESCUCHO
		2. ARMAR SECUENCIA(que animacion quiere y en que secuencia de maquina)
		3. ESCUCHAR como Server.Me llega paquete, muestro la animacion.Paso a ser cliente y luego de enviar el paquete vuelvo a ser Server
		4. PASAR ANIMACION
		5. MANDAR PAQUETE(#) como Client */
	//const char * direction = "192.168.2.154";
	//client Client;
	//Client.startConnection(direction);
	asioTcpClient("25.98.79.94"); 
	Sleep(10000);

}