#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>

static int eventHandler(struct module *module, int event, void 
*addInfo){

	if(event == MOD_LOAD){
		uprintf("Hello world!\n");
	}
	return 0;
}


static moduledata_t data = {
	"hello_world",
	eventHandler,
	NULL
};

DECLARE_MODULE(hello_world, data, SI_SUB_DRIVERS, 
SI_ORDER_MIDDLE);
