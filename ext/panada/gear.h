
extern zend_class_entry *panada_gear_ce;

ZEPHIR_INIT_CLASS(Panada_Gear);

PHP_METHOD(Panada_Gear, main);
PHP_METHOD(Panada_Gear, setArr);
PHP_METHOD(Panada_Gear, ask);
PHP_METHOD(Panada_Gear, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_panada_gear_setarr, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(panada_gear_method_entry) {
	PHP_ME(Panada_Gear, main, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Gear, setArr, arginfo_panada_gear_setarr, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Gear, ask, NULL, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Gear, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
