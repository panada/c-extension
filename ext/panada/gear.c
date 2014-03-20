
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Panada_Gear) {

	ZEPHIR_REGISTER_CLASS(Panada, Gear, panada, gear, panada_gear_method_entry, 0);

	zend_declare_property_null(panada_gear_ce, SL("uriObj"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(panada_gear_ce, SL("config"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(panada_gear_ce, SL("firstUriPath"), "Home", ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Panada_Gear, __construct) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_9 = NULL, *_10 = NULL;
	zval _0, *_3, *_4 = NULL, *_5, *_6, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 32767);
	ZEPHIR_CALL_FUNCTION(NULL, "error_reporting", &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 3);
	zephir_array_fast_append(_2, this_ptr);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "loader", 1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_4, panada_resources_config_ce, "main", NULL);
	zephir_check_call_status();
	//missing
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, panada_resources_uri_ce);
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("uriObj"), _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("uriObj"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_7, _6, "getclass",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_8, "ucwords", &_9, _7);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("firstUriPath"), _8 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "controllerhandler", &_10);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic loader to load instantiated class.
 *
 * @param  string $file Class namespace.
 * @return void
 */
PHP_METHOD(Panada_Gear, loader) {

	zephir_nts_static zephir_fcall_cache_entry *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *file = NULL, *folder = NULL, *prefix, *_0, *_1, *_2, *_3, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8, *_9, *_10, *_11, *_12, _13, _14, *_15 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);

	ZEPHIR_SEPARATE_PARAM(file);


	ZEPHIR_INIT_VAR(prefix);
	zephir_fast_explode_str(prefix, SL("\\"), file, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_0, prefix, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_0, "Models")) {
			ZEPHIR_INIT_VAR(folder);
			ZEPHIR_GET_CONSTANT(folder, "APP");
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "Libraries")) {
			ZEPHIR_INIT_NVAR(folder);
			ZEPHIR_GET_CONSTANT(folder, "APP");
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "Controllers")) {
			ZEPHIR_INIT_NVAR(folder);
			ZEPHIR_GET_CONSTANT(folder, "APP");
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "Resources")) {
			ZEPHIR_INIT_NVAR(folder);
			ZEPHIR_GET_CONSTANT(folder, "GEAR");
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "Drivers")) {
			ZEPHIR_INIT_NVAR(folder);
			ZEPHIR_GET_CONSTANT(folder, "GEAR");
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "Modules")) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_2, _1, SL("main"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_3, _2, SL("module"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_OBS_NVAR(folder);
			zephir_array_fetch_string(&folder, _3, SL("path"), PH_NOISY TSRMLS_CC);
			break;
		}
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_2, _1, SL("main"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (!(zephir_array_isset_string(_2, SS("namespace")))) {
			ZEPHIR_INIT_VAR(_4);
			object_init_ex(_4, panada_resources_runexception_ce);
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_SVS(_5, "Resource ", file, " not available!");
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _5);
			zephir_check_call_status();
			zephir_throw_exception(_4 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_3, _6, SL("main"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_string(&_7, _3, SL("namespace"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_long(&_8, prefix, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (!(zephir_array_isset(_7, _8))) {
			ZEPHIR_INIT_LNVAR(_4);
			object_init_ex(_4, panada_resources_runexception_ce);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_SVS(_5, "Resource ", file, " not available!");
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _5);
			zephir_check_call_status();
			zephir_throw_exception(_4 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_10, _9, SL("main"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_string(&_11, _10, SL("namespace"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(folder);
		ZEPHIR_OBS_VAR(_12);
		zephir_array_fetch_long(&_12, prefix, 0, PH_NOISY TSRMLS_CC);
		zephir_array_fetch(&folder, _11, _12, PH_NOISY TSRMLS_CC);
		break;
	} while(0);

	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "\\", 0);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_STRING(&_14, "/", 0);
	ZEPHIR_CALL_FUNCTION(&_15, "str_ireplace", &_16, &_13, &_14, file);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_4);
	ZEPHIR_CONCAT_VVS(_4, folder, _15, ".php");
	ZEPHIR_CPY_WRT(file, _4);
	if (!((zephir_file_exists(file TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_LNVAR(_4);
		object_init_ex(_4, panada_resources_runexception_ce);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "Resource ", file, " not available!");
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _5);
		zephir_check_call_status();
		zephir_throw_exception(_4 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_require_zval(file TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Hendle the controller calling process.
 *
 * The steps is:
 *  - Does alias controller are defined in main config?
 *  - If not, is sub-controller exists?
 *  - If not, module with this name exists?
 *  - If all fault, then throw 404.
 *
 *  @return void
 */
PHP_METHOD(Panada_Gear, controllerHandler) {

	zend_class_entry *_8;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_12 = NULL, *_19 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *instance, *request = NULL, *method = NULL, *classFile, *controllerNamespace, *_0, *_1, *_2, *_4, *_5, *_6 = NULL, *_7 = NULL, *_9, *_10 = NULL, _11, *_13, *_14, *_15, *_16, *_17 = NULL, *_18;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("firstUriPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(controllerNamespace);
	ZEPHIR_CONCAT_SV(controllerNamespace, "Controllers\\", _0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "APP");
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("firstUriPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(classFile);
	ZEPHIR_CONCAT_VSVS(classFile, _1, "Controllers/", _2, ".php");
	if (!((zephir_file_exists(classFile TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "subcontrollerhandler", &_3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("uriObj"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&method, _4, "getmethod",  NULL);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("uriObj"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&request, _5, "getrequests",  NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(request))) {
		ZEPHIR_INIT_VAR(request);
		array_init(request);
	}
	if (!(zephir_class_exists(controllerNamespace, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_6);
		object_init_ex(_6, panada_resources_runexception_ce);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SVSV(_7, "Class ", controllerNamespace, "  not found in ", classFile);
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, _7);
		zephir_check_call_status();
		zephir_throw_exception(_6 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	_8 = zend_fetch_class(Z_STRVAL_P(controllerNamespace), Z_STRLEN_P(controllerNamespace), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(instance, _8);
	if (zephir_has_constructor(instance TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL);
		zephir_check_call_status();
	}
	if (!((zephir_method_exists(instance, method TSRMLS_CC)  == SUCCESS))) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("uriObj"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_10, _9, "path",  NULL);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_11);
		ZVAL_LONG(&_11, 1);
		ZEPHIR_CALL_FUNCTION(&request, "array_slice", &_12, _10, &_11);
		zephir_check_call_status();
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_14, _13, SL("main"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_string(&_15, _14, SL("alias"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_OBS_VAR(method);
		zephir_array_fetch_string(&method, _15, SL("method"), PH_NOISY TSRMLS_CC);
		if (!((zephir_method_exists(instance, method TSRMLS_CC)  == SUCCESS))) {
			ZEPHIR_INIT_LNVAR(_6);
			object_init_ex(_6, panada_resources_runexception_ce);
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("uriObj"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_17, _16, "getmethod",  NULL);
			zephir_check_call_status();
			_18 = zephir_fetch_nproperty_this(this_ptr, SL("firstUriPath"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SVSV(_7, "Method ", _17, " does not exists in controller ", _18);
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, _7);
			zephir_check_call_status();
			zephir_throw_exception(_6 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "run", &_19, instance, method, request);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Panada_Gear, subControllerHandler) {



}

/**
 * Call the controller's method
 *
 * @param  object $instance
 * @param  string $method
 * @param  array  $request
 * @return void
 */
PHP_METHOD(Panada_Gear, run) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *instance, *method, *request, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &instance, &method, &request);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	zephir_array_fast_append(_1, instance);
	zephir_array_fast_append(_1, method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(_0, _1, request);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

