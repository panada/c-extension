
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
#include "kernel/object.h"
#include "kernel/fcall.h"

ZEPHIR_INIT_CLASS(Panada_Gear) {

	ZEPHIR_REGISTER_CLASS(Panada, Gear, panada, gear, panada_gear_method_entry, 0);

	zend_declare_property_null(panada_gear_ce, SL("arr"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Panada_Gear, main) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	add_assoc_stringl_ex(_0, SS("nama"), SL("kandar"), 1);
	zephir_update_property_this(this_ptr, SL("arr"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "arr");

}

PHP_METHOD(Panada_Gear, setArr) {

	zval *key, *val;

	zephir_fetch_params(0, 2, 0, &key, &val);



	zephir_update_property_array(this_ptr, SL("arr"), key, val TSRMLS_CC);
	RETURN_THISW();

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

PHP_METHOD(Panada_Gear, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("arr"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

