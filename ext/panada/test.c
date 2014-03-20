
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
#include "kernel/array.h"
#include "kernel/object.h"

ZEPHIR_INIT_CLASS(Panada_Test) {

	ZEPHIR_REGISTER_CLASS(Panada, Test, panada, test, panada_test_method_entry, 0);

	zend_declare_property_null(panada_test_ce, SL("arr"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Panada_Test, __construct) {

	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 6);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 2);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 3);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 4);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("arr"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("arr"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Panada_Test, get) {


	RETURN_MEMBER(this_ptr, "arr");

}

PHP_METHOD(Panada_Test, get2) {


	RETURN_MEMBER(this_ptr, "arr");

}

