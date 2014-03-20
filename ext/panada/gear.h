
extern zend_class_entry *panada_gear_ce;

ZEPHIR_INIT_CLASS(Panada_Gear);

PHP_METHOD(Panada_Gear, __construct);
PHP_METHOD(Panada_Gear, loader);
PHP_METHOD(Panada_Gear, controllerHandler);
PHP_METHOD(Panada_Gear, subControllerHandler);
PHP_METHOD(Panada_Gear, run);

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_gear_loader, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_gear_run, 0, 0, 3)
	ZEND_ARG_INFO(0, instance)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(panada_gear_method_entry) {
	PHP_ME(Panada_Gear, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Panada_Gear, loader, arginfo_panada_gear_loader, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Gear, controllerHandler, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Panada_Gear, subControllerHandler, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Panada_Gear, run, arginfo_panada_gear_run, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
