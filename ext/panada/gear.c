
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
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Panada_Gear) {

	ZEPHIR_REGISTER_CLASS(Panada, Gear, panada, gear, panada_gear_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Panada_Gear, __construct) {



}

PHP_METHOD(Panada_Gear, ask) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, _2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Panada\\Resources\\Config::database", 0);
	ZEPHIR_CALL_USER_FUNC_ARRAY(_0, &_2, _1);
	zend_print_zval(_0, 0);
	ZEPHIR_MM_RESTORE();

}

