
extern zend_class_entry *panada_resources_config_ce;

ZEPHIR_INIT_CLASS(Panada_Resources_Config);

PHP_METHOD(Panada_Resources_Config, _cache);
PHP_METHOD(Panada_Resources_Config, main);
PHP_METHOD(Panada_Resources_Config, __callStatic);

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_resources_config__cache, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_resources_config___callstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(panada_resources_config_method_entry) {
	PHP_ME(Panada_Resources_Config, _cache, arginfo_panada_resources_config__cache, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE)
	PHP_ME(Panada_Resources_Config, main, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Panada_Resources_Config, __callStatic, arginfo_panada_resources_config___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
