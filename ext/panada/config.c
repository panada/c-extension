
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Panada_Config) {

	ZEPHIR_REGISTER_CLASS(Panada, Config, panada, config, panada_config_method_entry, 0);


	return SUCCESS;

}

PHP_METHOD(Panada_Config, main) {


	RETURN_STRING("ini static", 1);

}

