cat > hello_driver.c <<'EOF'
#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>

static int
hello_driver_handler(module_t mod, int event, void *arg)
{
    int error = 0;

    switch (event) {
    case MOD_LOAD:
        printf("hello_driver: modul dimuat\n");
        break;

    case MOD_UNLOAD:
        printf("hello_driver: modul dilepas\n");
        break;

    case MOD_SHUTDOWN:
        printf("hello_driver: sistem sedang dimatikan\n");
        break;

    case MOD_QUIESCE:
        break;

    default:
        error = EOPNOTSUPP;
        break;
    }

    return (error);
}

static moduledata_t hello_driver_mod = {
    "hello_driver",
    hello_driver_handler,
    NULL
};

DECLARE_MODULE(hello_driver, hello_driver_mod,
    SI_SUB_DRIVERS, SI_ORDER_MIDDLE);
EOF
