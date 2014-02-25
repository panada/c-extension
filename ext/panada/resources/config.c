
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/require.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/exception.h"


/**
 * Handler for configuration.
 *
 * @author  Iskandar Soesman <k4ndar@yahoo.com>
 * @link    http://panadaframework.com/
 * @license http://www.opensource.org/licenses/bsd-license.php
 * @since   version experimental
 * @package Resources
 */
ZEPHIR_INIT_CLASS(Panada_Resources_Config) {

	ZEPHIR_REGISTER_CLASS(Panada\\Resources, Config, panada, resources_config, panada_resources_config_method_entry, 0);

	zend_declare_property_null(panada_resources_config_ce, SL("config"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Panada_Resources_Config, _cache) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *cfg = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);
	ZEPHIR_INIT_VAR(cfg);
	array_init(cfg);


	_0 = zephir_fetch_static_property_ce(panada_resources_config_ce, SL("config") TSRMLS_CC);
	if (!(zephir_array_isset(_0, name))) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_GET_CONSTANT(_1, "PANADA_APP");
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VSVS(_2, _1, "config/", name, ".php");
		if (zephir_require_zval(_2 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CALL_FUNCTION(&cfg, "call_user_func", NULL, name);
		zephir_check_call_status();
		RETURN_CCTOR(cfg);
	} else {
		_3 = zephir_fetch_static_property_ce(panada_resources_config_ce, SL("config") TSRMLS_CC);
		zephir_array_fetch(&_4, _3, name, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Panada_Resources_Config, debug) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);

	if (!name) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "main", 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PANADA_APP");
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSVS(_1, _0, "config/", name, ".php");
	if (zephir_require_zval(_1 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	//missing empty
	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Panada_Resources_Config, main) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "main", 0);
	ZEPHIR_RETURN_CALL_SELF("_cache", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Panada_Resources_Config, session) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "session", 0);
	ZEPHIR_RETURN_CALL_SELF("_cache", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Panada_Resources_Config, cache) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "cache", 0);
	ZEPHIR_RETURN_CALL_SELF("_cache", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Panada_Resources_Config, database) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "database", 0);
	ZEPHIR_RETURN_CALL_SELF("_cache", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Panada_Resources_Config, __callStatic) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL;
	zval *name_param = NULL, *arguments_param = NULL, *_0, *_1, *_2, *file, *e = NULL, *_3, *_4, *_5, *_6 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &arguments_param);

	zephir_get_strval(name, name_param);
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(arguments);
		array_init(arguments);
	} else {
		zephir_get_arrval(arguments, arguments_param);
	}


	_0 = zephir_fetch_static_property_ce(panada_resources_config_ce, SL("config") TSRMLS_CC);
	if (zephir_array_isset(_0, name)) {
		_1 = zephir_fetch_static_property_ce(panada_resources_config_ce, SL("config") TSRMLS_CC);
		zephir_array_fetch(&_2, _1, name, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_GET_CONSTANT(_3, "PANADA_APP");
	ZEPHIR_INIT_VAR(file);
	ZEPHIR_CONCAT_VSVS(file, _3, "config/", name, ".php");

	/* try_start_1: */

		if (!((zephir_file_exists(file TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_INIT_VAR(_4);
			object_init_ex(_4, panada_resources_runexception_ce);
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_SVS(_5, "Config file in ", file, " does not exits");
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _5);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception(_4 TSRMLS_CC);
			goto try_end_1;

		}
		ZEPHIR_RETURN_CALL_SELF("_cache", NULL, name);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	ZEPHIR_CPY_WRT(e, EG(exception));
	if (zephir_is_instance_of(e, SL("RunException") TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		ZEPHIR_CALL_METHOD(&_6, e, "getmessage", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(NULL, panada_resources_runexception_ce, "outputerror", NULL, _6);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

