#include "client.h"


int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	logger = log_create ( " tp0.log " , " Hola soy un log en log_create " , 1 , LOG_LEVEL_INFO ) ;

	leer_consola (logger ) ;

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config

	config = config_create ( " cliente.config " ) ;

	valor = config_get_string_value ( config , "CLAVE" ) ;

	log_info (logger, valor);

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje ( valor , conexion ) ;
	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente

	log_destroy ( logger ) ;
	config_destroy ( config ) ;
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;


	// El resto, las vamos leyendo y logueando hasta recibir un string vacío

    do {
		leido = readline("> ");      // Lee la entrada del usuario

        if (strcmp((leido), "") ) {
            log_info(logger, leido);  // Loguea si no está vacío
        }
        
    } while ( strcmp(leido, "") );

	free(leido);  // Libera la memoria asignada por readline
	
	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
