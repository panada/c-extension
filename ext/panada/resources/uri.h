
extern zend_class_entry *panada_resources_uri_ce;

ZEPHIR_INIT_CLASS(Panada_Resources_Uri);

PHP_METHOD(Panada_Resources_Uri, __construct);
PHP_METHOD(Panada_Resources_Uri, isHttps);
PHP_METHOD(Panada_Resources_Uri, removeQuery);
PHP_METHOD(Panada_Resources_Uri, path);
PHP_METHOD(Panada_Resources_Uri, getClass);
PHP_METHOD(Panada_Resources_Uri, getMethod);
PHP_METHOD(Panada_Resources_Uri, getRequests);
PHP_METHOD(Panada_Resources_Uri, stripUriString);
PHP_METHOD(Panada_Resources_Uri, getDefaultController);
PHP_METHOD(Panada_Resources_Uri, getBaseUri);

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_resources_uri_removequery, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_resources_uri_path, 0, 0, 0)
	ZEND_ARG_INFO(0, segment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_resources_uri_getmethod, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultMethod)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_resources_uri_getrequests, 0, 0, 0)
	ZEND_ARG_INFO(0, segment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_resources_uri_stripuristring, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(panada_resources_uri_method_entry) {
	PHP_ME(Panada_Resources_Uri, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Panada_Resources_Uri, isHttps, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Resources_Uri, removeQuery, arginfo_panada_resources_uri_removequery, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Resources_Uri, path, arginfo_panada_resources_uri_path, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Resources_Uri, getClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Resources_Uri, getMethod, arginfo_panada_resources_uri_getmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Resources_Uri, getRequests, arginfo_panada_resources_uri_getrequests, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Resources_Uri, stripUriString, arginfo_panada_resources_uri_stripuristring, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Resources_Uri, getDefaultController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Resources_Uri, getBaseUri, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
