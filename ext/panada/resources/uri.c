
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Panada_Resources_Uri) {

	ZEPHIR_REGISTER_CLASS(Panada\\Resources, Uri, panada, resources_uri, panada_resources_uri_method_entry, 0);

	zend_declare_property_null(panada_resources_uri_ce, SL("pathUri"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(panada_resources_uri_ce, SL("baseUri"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(panada_resources_uri_ce, SL("defaultController"), "Home", ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Panada_Resources_Uri, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zval *selfArray, *pathInfo, *selfKey = NULL, *_SERVER, *_0, *_1, *_2, _3, *_4, _6 = zval_used_for_init, *_7 = NULL, *_9, *_10 = NULL, *_11, *_12, *_13 = NULL, *_14;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(pathInfo);
	ZVAL_STRING(pathInfo, "", 1);

	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string(_SERVER, SS("ORIG_PATH_INFO"))) {
		ZEPHIR_OBS_VAR(pathInfo);
		zephir_array_fetch_string(&pathInfo, _SERVER, SL("ORIG_PATH_INFO"), PH_NOISY TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(selfArray);
	ZEPHIR_INIT_VAR(_0);
	zephir_array_fetch_string(&_1, _SERVER, SL("PHP_SELF"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, pathInfo);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/", 0);
	zephir_fast_trim(_0, _2, &_3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_fast_explode_str(selfArray, SL("/"), _0, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_GET_CONSTANT(_4, "INDEX_FILE");
	ZEPHIR_CALL_FUNCTION(&selfKey, "array_search", &_5, _4, selfArray);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, ((zephir_get_numberval(selfKey) + 1)));
	ZEPHIR_CALL_FUNCTION(&_7, "array_slice", &_8, selfArray, &_6);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pathUri"), _7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "ishttps",  NULL);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_BNVAR(_9);
		ZVAL_STRING(_9, "https://", 1);
	} else {
		ZEPHIR_INIT_BNVAR(_9);
		ZVAL_STRING(_9, "http://", 1);
	}
	zephir_update_property_this(this_ptr, SL("baseUri"), _9 TSRMLS_CC);
	zephir_array_fetch_string(&_11, _SERVER, SL("HTTP_HOST"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_FUNCTION(&_13, "array_slice", &_8, selfArray, &_6, selfKey);
	zephir_check_call_status();
	zephir_fast_join_str(_12, SL("/"), _13 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_VVS(_14, _11, _12, "/");
	zephir_update_property_this(this_ptr, SL("baseUri"), _14 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Does this site use https?
 *
 * @return boolean
 */
PHP_METHOD(Panada_Resources_Uri, isHttps) {

	zend_bool _3;
	zval *_SERVER, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string(_SERVER, SS("HTTPS"))) {
		ZEPHIR_INIT_VAR(_0);
		zephir_array_fetch_string(&_1, _SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_fast_strtolower(_0, _1);
		if (ZEPHIR_IS_STRING(_0, "on")) {
			RETURN_MM_BOOL(1);
		}
		zephir_array_fetch_string(&_2, _SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_2, 1)) {
			RETURN_MM_BOOL(1);
		}
	}
	_3 = zephir_array_isset_string(_SERVER, SS("SERVER_PORT"));
	if (_3) {
		zephir_array_fetch_string(&_1, _SERVER, SL("SERVER_PORT"), PH_NOISY | PH_READONLY TSRMLS_CC);
		_3 = ZEPHIR_IS_LONG(_1, 443);
	}
	if (_3) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Clean the 'standard' model query.
 *
 * @param string
 * @return string
 */
PHP_METHOD(Panada_Resources_Uri, removeQuery) {

	zval *path = NULL, *pathAr;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);

	ZEPHIR_SEPARATE_PARAM(path);


	ZEPHIR_INIT_VAR(pathAr);
	zephir_fast_explode_str(pathAr, SL("?"), path, LONG_MAX TSRMLS_CC);
	if (zephir_fast_count_int(pathAr TSRMLS_CC) > 0) {
		ZEPHIR_OBS_NVAR(path);
		zephir_array_fetch_long(&path, pathAr, 0, PH_NOISY TSRMLS_CC);
	}
	RETURN_CCTOR(path);

}

/**
 * Break the string given from extractUriString() into class, method and request.
 *
 * @param    integer
 * @return  string
 */
PHP_METHOD(Panada_Resources_Uri, path) {

	zval *segment = NULL, *path, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &segment);

	if (!segment) {
		segment = ZEPHIR_GLOBAL(global_false);
	}


	if (ZEPHIR_IS_FALSE(segment)) {
		RETURN_MM_MEMBER(this_ptr, "pathUri");
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pathUri"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&path, _0, segment, 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_GET_CONSTANT(_1, "INDEX_FILE");
		if (!ZEPHIR_IS_EQUAL(path, _1)) {
			RETURN_CTOR(path);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get class name from the url.
 *
 * @return  string
 */
PHP_METHOD(Panada_Resources_Uri, getClass) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uriString = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(&uriString, this_ptr, "path", NULL, _0);
	zephir_check_call_status();
	if (zephir_is_true(uriString)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "stripuristring", NULL, uriString);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			RETURN_CCTOR(uriString);
		} else {
			RETURN_MM_BOOL(0);
		}
	} else {
		RETURN_MM_MEMBER(this_ptr, "defaultController");
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get method name from the url.
 *
 * @return  string
 */
PHP_METHOD(Panada_Resources_Uri, getMethod) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *defaultMethod = NULL, *uriString = NULL, *_0, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultMethod);

	if (!defaultMethod) {
		ZEPHIR_INIT_VAR(defaultMethod);
		ZVAL_STRING(defaultMethod, "index", 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	ZEPHIR_CALL_METHOD(&uriString, this_ptr, "path", NULL, _0);
	zephir_check_call_status();
	_1 = zephir_is_true(uriString);
	if (_1) {
		_1 = !ZEPHIR_IS_EMPTY(uriString);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "stripuristring", NULL, uriString);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			RETURN_CCTOR(uriString);
		} else {
			RETURN_MM_STRING("", 1);
		}
	} else {
		RETURN_CCTOR(defaultMethod);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get "GET" request from the url.
 *
 * @param    int
 * @return  array
 */
PHP_METHOD(Panada_Resources_Uri, getRequests) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *segment = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &segment);

	if (!segment) {
		ZEPHIR_INIT_VAR(segment);
		ZVAL_LONG(segment, 2);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "path", NULL, segment);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "path",  NULL);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("array_slice", &_1, _0, segment);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Cleaner for class and method name
 *
 * @param string
 * @return boolean
 */
PHP_METHOD(Panada_Resources_Uri, stripUriString) {

	zval *uri, *_0, *_1, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "/[^a-zA-Z0-9_.-]/", 0);
	zephir_preg_match(_1, &(_1), &_2, uri, _0, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(_1))) {
		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
	}
	RETURN_MM();

}

/**
 * Setter for default controller
 *
 * @param string $defaultController
 * @return void
 */
PHP_METHOD(Panada_Resources_Uri, setDefaultController) {

	zval *defaultController;

	zephir_fetch_params(0, 1, 0, &defaultController);



	zephir_update_property_this(this_ptr, SL("defaultController"), defaultController TSRMLS_CC);

}

/**
 * Getter for default controller
 */
PHP_METHOD(Panada_Resources_Uri, getDefaultController) {


	RETURN_MEMBER(this_ptr, "defaultController");

}

/**
 * Getter for baseUri
 *
 * @return string
 */
PHP_METHOD(Panada_Resources_Uri, getBaseUri) {


	RETURN_MEMBER(this_ptr, "baseUri");

}

