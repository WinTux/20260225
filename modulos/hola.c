#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pepe");
MODULE_DESCRIPTION("Este es un simple ejemplo de modulos");

/* Función que se ejecuta al cargar el módulo */
static int __init mi_modulo_init(void)
{
    printk(KERN_INFO "Modulo Hola: cargado correctamente.\n");
    return 0;  // 0 indica que se cargó sin errores
}

/* Función que se ejecuta al descargar el módulo */
static void __exit mi_modulo_exit(void)
{
    printk(KERN_INFO "Modulo Hola: descargado correctamente.\n");
}

/* Macros que registran las funciones */
module_init(mi_modulo_init);
module_exit(mi_modulo_exit);
